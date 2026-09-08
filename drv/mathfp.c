/*
 * Copyright (c) 2017, Freescale Semiconductor, Inc.
 * Copyright 2018-2020,2022,2024-2026 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#include "fsl_common.h"
#include "mathfp.h"
#include "stdbool.h"

/*******************************************************************************
 * Definitions
 ******************************************************************************/
/* constants for fixed point atan2 approximation function */
#define addfac ((int16_t)0x10EF)
#define zp273 ((int16_t)0x045E)
#define neg_zp273   ((int16_t)(-1118))  /* two's complement of 0x045E, within int16_t range */
#define piover2     ((int16_t)0x1921)
#define neg_piover2 ((int16_t)(-6433))  /* two's complement of 0x1921, within int16_t range */
#define pi          ((int16_t)0x3243)
#define neg_pi      ((int16_t)(-12868)) /* two's complement of 0xCDBC, within int16_t range */

#define USE_FPINLINE (1)
#define NUMQBITS (12U) /* define the number of fractional bits to be used. Leaves 3 integer bits & a sign bit */

#if (USE_FPINLINE == 1) /* use inline functions instead of macros */
static inline int16_t FPERRORCHECK(int16_t x, int16_t y)
{
    int16_t retval = 0; /* non-error return */
    if (((y == 0) && (x == 0)) || ((x > 4095) || (x < -4096) || (y > 4095) || (y < -4096)))
    {
        retval = (int16_t)(-1); /* invalid return value indicating an error (-1 == 0xFFFF in two's complement) */
    }
    return retval;
};

static inline int16_t FPABS(int16_t x)
{
    int16_t retval = x; /* positive return value */
    if (x < 0)
    {
        if (x == -32768)
        {
            retval = 32767; /* special case, manually negate -32768 to +32767 */
        }
        else
        {
            retval = -(x); /* negative return value */
        }
    }
    return retval;
};

static inline int16_t FPADD(int16_t x, int16_t y)
{
    /* Perform addition in int32 to avoid implicit narrowing on return (CERT INT31-C).
     * Inputs are bounded to 12-bit Q-format range by FPERRORCHECK so no overflow occurs. */
    return (int16_t)((int32_t)x + (int32_t)y);
};

static inline int16_t FPSUB(int16_t x, int16_t y)
{
    /* Perform subtraction in int32 to avoid implicit narrowing on return (CERT INT31-C).
     * Inputs are bounded to 12-bit Q-format range by FPERRORCHECK so no underflow occurs. */
    return (int16_t)((int32_t)x - (int32_t)y);
};

static inline int16_t FPMUL(int16_t x, int16_t y, uint8_t q)
{
    /* Multiply in int32, divide by power-of-2 scale factor (avoids signed shift per MISRA 10.1).
     * Inputs are bounded to 12-bit Q-format range by FPERRORCHECK so no overflow occurs. */
    uint32_t shift_val = (uint32_t)1U << (uint32_t)q;
    int32_t retval = ((int32_t)x * (int32_t)y) / (int32_t)(shift_val);
    return (int16_t)retval;
};

static inline int16_t FPDIV(int16_t x, int16_t y, uint8_t q)
{
    /* Scale numerator in int32 by multiplying by power-of-2 scale factor (avoids signed shift
     * per MISRA 10.1). Inputs bounded to +/-4095 and q=12, so max scaled value is
     * 4095 * 4096 = 16,773,120 which fits in int32. Division is always y/x or x/y where
     * the larger operand is the denominator, so result fits in int16_t range. */
    uint32_t shift_val = (uint32_t)1U << (uint32_t)q;
    int32_t retval = ((int32_t)x * (int32_t)(shift_val)) / (int32_t)y;
    return (int16_t)retval;
};

static inline int16_t INNERCALC(int16_t iqd, int16_t sgz, uint8_t q)
{
    /* Implements the core calculation for the 4 octant appproximations */
    /* in the form of A*(B+(C*D)) */
    int16_t retval = FPMUL(iqd, sgz, q);
    retval         = FPADD(addfac, retval);
    return FPMUL(iqd, retval, q);
}

#else
/* macros for fixed point math in 16 bit signed integers */
#define FPABS(x) ((x) < 0 ? (int16_t)(~((uint16_t)x)) + 1 : (x))
#define FPADD(x, y) ((x) + (y))
#define FPSUB(x, y) ((x) - (y))
#define FPMUL(x, y, q) (((x) * (y)) >> (q))
#define FPDIV(x, y, q) (((x) << (q)) / (y))

/* custom inner calculation macro for atan approximation */
#define INNERCALC(iqd, sgz, q) (FPMUL((iqd), FPADD(addfac, FPMUL((sgz), (iqd), (q))), q))

#define FPERRORCHECK(x, y)  \
    do  \
    {    \
    ((((y == 0) && (x == 0)) || ((x > 4095) || (x < -4096) || (y > 4095) || (y < -4096))), 0xFFFF,0) \
    } \
    while(false); \
        
#endif

/*******************************************************************************
 * Variables
 ******************************************************************************/

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
static int16_t calculate_octant_1_8(int16_t x, int16_t y);
static int16_t calculate_octant_2_3(int16_t x, int16_t y);
static int16_t calculate_octant_4_5(int16_t x, int16_t y);
static int16_t calculate_octant_6_7(int16_t x, int16_t y);

/*******************************************************************************
 * Code
 ******************************************************************************/
/* This is a fixed point implementation of the arctan function as described in "Efficient Approximations */
/* for the Arctangent Function", by Sreeraman Rajan, Sichun Wang, Robert Inkol, and Alain Joyal in */
/* IEEE SIGNAL PROCESSING MAGAZINE, MAY 2006 */
int16_t atan2fp(int16_t y, int16_t x)
{
#if (NUMQBITS >= 16U)
#error "Invalid number of fractional bits."
#endif
    
    bool calc_done = false; /* flag to control whether to perform approximation or if the error checks have triggered */
    int16_t retval;
    int16_t absx   = FPABS(x);
    int16_t absy   = FPABS(y);

    /* handle error cases and cases that will cause divide by zero in approximation equations */
    /* Input validation for 12-bit fractional + sign bit format */
    retval = FPERRORCHECK(x, y);
    if (retval == 0)  /* no errors in the inputs */
    {
        /* handle special cases that fall directly on X or Y axis */
        if (x == 0)
        {
            retval    = ((y > 0) ? piover2 : neg_piover2);
            calc_done = true; /* prevent any further evaluations */
        }

        if (y == 0)
        {
            retval    = ((x > 0) ? 0 : pi);
            calc_done = true; /* prevent any further evaluations */
        }

        /* 4 quadrant approximation of atan() function */
        if ((x > 0) && (x >= absy) && !calc_done) /* equation #1 */
        {
            retval    = calculate_octant_1_8(x, y);
            calc_done = true; /* prevent any further evaluations */
        }

        if ((y > 0) && (y >= absx) && !calc_done) /* equation #2 */
        {
            retval    = calculate_octant_2_3(x, y);
            calc_done = true; /* prevent any further evaluations */
        }

        if ((x < 0) && (absx >= absy) && !calc_done) /* equation #3 */
        {
            retval    = calculate_octant_4_5(x, y);
            calc_done = true; /* prevent any further evaluations */
        }

        if ((y < 0) && (absy >= absx) && !calc_done) /* equation #4 */
        {
            retval = calculate_octant_6_7(x, y);
        }
    }

    return retval;
}

static int16_t calculate_octant_1_8(int16_t x, int16_t y)
{
    int16_t iqdiv;     /* I/Q or Q/I, depending upon which equation is being calculated */
    int16_t sgn_zp273; /* holds sign(I)*0.273 or sign(Q)*0x273 */
    iqdiv = FPDIV(y, x, NUMQBITS);
    if (y < 0) /* choose 0.273 (or negated) factor so that FPADD can be used in all INNERCALC calls */
    {
        sgn_zp273 = zp273;
    }
    else
    {
        sgn_zp273 = neg_zp273;
    }

    return INNERCALC(iqdiv, sgn_zp273, NUMQBITS);
}

static int16_t calculate_octant_2_3(int16_t x, int16_t y)
{
    int16_t iqdiv;     /* I/Q or Q/I, depending upon which equation is being calculated */
    int16_t sgn_zp273; /* holds sign(I)*0.273 or sign(Q)*0x273 */
    iqdiv = FPDIV(x, y, NUMQBITS);
    if (x < 0) /* choose 0.273 (or negated) factor so that FPADD can be used in all INNERCALC calls */
    {
        sgn_zp273 = zp273;
    }
    else
    {
        sgn_zp273 = neg_zp273;
    }

    return FPSUB(piover2, INNERCALC(iqdiv, sgn_zp273, NUMQBITS));
}

static int16_t calculate_octant_4_5(int16_t x, int16_t y)
{
    int16_t iqdiv;     /* I/Q or Q/I, depending upon which equation is being calculated */
    int16_t sgn_zp273; /* holds sign(I)*0.273 or sign(Q)*0x273 */
    int16_t pifac;
    iqdiv = FPDIV(y, x, NUMQBITS);
    if (y < 0) /* choose 0.273 (or negated) factor so that FPADD can be used in all INNERCALC calls */
    {
        sgn_zp273 = neg_zp273;
        pifac     = neg_pi;
    }
    else
    {
        sgn_zp273 = zp273;
        pifac     = pi;
    }

    return FPADD(pifac, INNERCALC(iqdiv, sgn_zp273, NUMQBITS));
}

static int16_t calculate_octant_6_7(int16_t x, int16_t y)
{
    int16_t iqdiv;     /* I/Q or Q/I, depending upon which equation is being calculated */
    int16_t sgn_zp273; /* holds sign(I)*0.273 or sign(Q)*0x273 */
    iqdiv = FPDIV(x, y, NUMQBITS);
    if (x < 0) /* choose 0.273 (or negated) factor so that FPADD can be used in all INNERCALC calls */
    {
        sgn_zp273 = neg_zp273;
    }
    else
    {
        sgn_zp273 = zp273;
    }

    return FPSUB(neg_piover2, INNERCALC(iqdiv, sgn_zp273, NUMQBITS));
}

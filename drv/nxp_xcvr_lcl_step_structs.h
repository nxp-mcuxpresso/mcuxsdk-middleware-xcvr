/*
** ###################################################################
**     Processor:
**     Build:               b250326
**
**     Abstract:
**         This header file implements peripheral memory map for
**         nxp_xcvr_lcl_step_structs processor.
**
**     Copyright 1997-2016 Freescale Semiconductor, Inc.
**     Copyright 2016-2025 NXP
**     SPDX-License-Identifier: BSD-3-Clause
**
**     http:                 www.nxp.com
**     mail:                 support@nxp.com
**
**     Revisions:
**
** ###################################################################
*/
#ifndef NXP_XCVR_LCL_STEP_STRUCTS_H
/* clang-format off */
#define NXP_XCVR_LCL_STEP_STRUCTS_H
/* clang-format on */

/*!
 * @file nxp_xcvr_lcl_step_structs.h
 * @version 0.0
 * @date 0-00-00
 * @brief Peripheral memory map for nxp_xcvr_lcl_step_structs
 *
 * This header file implements peripheral memory map for
 * nxp_xcvr_lcl_step_structs processor.
 */


/* ----------------------------------------------------------------------------
   -- MCU activation
   ---------------------------------------------------------------------------- */

/* Check if another memory map has not been also included */
#if (defined(MCU_ACTIVE))
  #error nxp_xcvr_lcl_step_structs memory map: There is already included another memory map. Only one memory map can be included.
#endif /* (defined(MCU_ACTIVE)) */
#define MCU_ACTIVE

#include <stdint.h>

/* Manually written split of common header and union for access */
/* Manually created COMMON header type for all modes (to match updates in structure definitions */
typedef struct
{
    __IO uint16_t CHANNEL_NUM;    /**< Channel number for the step., offset: 0x0 */
    __IO uint16_t STEP_CFG;       /**< Configuration for the step., offset: 0x2 */
    __IO uint16_t STEP_CFO;       /**< CFO setting for the step, offset: 0x4 */
    __IO uint16_t HPM_CAL_FACTOR; /**< HPM CAL factor to apply for the step., offset: 0x6 */
    __IO uint16_t CTUNE_MANUAL;   /**< CTUNE manual to inject for the step., offset: 0x8 */
    __IO uint16_t PHASE_ADD;      /**< Phase adder for the step., offset: 0xA */
} COM_MODE_CFG_HDR_Type;

typedef union
{
    COM_MODE_CFG_HDR_Type header;
    uint32_t U32_data[3];
} COM_MODE_CFG_HDR_UNION_Type;

#if defined(NXP_RADIO_GEN) && (NXP_RADIO_GEN >= 475)
/* KW43 PKT RAM step CONFIG and RESULT structures */

/* ----------------------------------------------------------------------------
   -- Device Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup Peripheral_access_layer Device Peripheral Access Layer
 * @{
 */


/*
** Start of section using anonymous unions
*/

// #error Not supported compiler type

/* ----------------------------------------------------------------------------
   -- COM_MODE_013_CFG_HDR Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup COM_MODE_013_CFG_HDR_Peripheral_Access_Layer COM_MODE_013_CFG_HDR Peripheral Access Layer
 * @{
 */

/** COM_MODE_013_CFG_HDR - Register Layout Typedef */
typedef struct {
  __IO uint16_t CHANNEL_NUM;                       /**< Channel number for the step., offset: 0x0 */
  __IO uint16_t STEP_CFG;                          /**< Configuration for the step., offset: 0x2 */
  __IO uint16_t STEP_CFO;                          /**< CFO setting for the step, offset: 0x4 */
  __IO uint16_t HPM_CAL_FACTOR;                    /**< HPM CAL factor to apply for the step., offset: 0x6 */
  __IO uint16_t CTUNE_MANUAL;                      /**< CTUNE manual to inject for the step., offset: 0x8 */
  __IO uint16_t PHASE_ADD;                         /**< Phase adder for the step., offset: 0xA */
  __IO uint32_t AA_INIT;                           /**< Access address for the initiator (first half step)., offset: 0xC */
  __IO uint32_t AA_REFL;                           /**< Access address for the reflector (second half step)., offset: 0x10 */
} COM_MODE_013_CFG_HDR_Type;

/* ----------------------------------------------------------------------------
   -- COM_MODE_013_CFG_HDR Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup COM_MODE_013_CFG_HDR_Register_Masks COM_MODE_013_CFG_HDR Register Masks
 * @{
 */

/*! @name CHANNEL_NUM - Channel number for the step. */
/*! @{ */

#define COM_MODE_013_CFG_HDR_CHANNEL_NUM_CHANNEL_NUM_MASK (0xFFFFU)
#define COM_MODE_013_CFG_HDR_CHANNEL_NUM_CHANNEL_NUM_SHIFT (0U)
/*! CHANNEL_NUM - Channel number for the step. */
#define COM_MODE_013_CFG_HDR_CHANNEL_NUM_CHANNEL_NUM(x) (((uint16_t)(((uint16_t)(x)) << COM_MODE_013_CFG_HDR_CHANNEL_NUM_CHANNEL_NUM_SHIFT)) & COM_MODE_013_CFG_HDR_CHANNEL_NUM_CHANNEL_NUM_MASK)
/*! @} */

/*! @name STEP_CFG - Configuration for the step. */
/*! @{ */

#define COM_MODE_013_CFG_HDR_STEP_CFG_MODE_MASK  (0x3U)
#define COM_MODE_013_CFG_HDR_STEP_CFG_MODE_SHIFT (0U)
/*! MODE - Mode for the step
 *  0b00..Frequency Compensation Step (Mode 0)
 *  0b01..Pk-Pk step (Mode 1)
 *  0b10..Tn-Tn step (Mode 2)
 *  0b11..Pk-Tn-Tn-Pk step (Mode 3)
 */
#define COM_MODE_013_CFG_HDR_STEP_CFG_MODE(x)    (((uint16_t)(((uint16_t)(x)) << COM_MODE_013_CFG_HDR_STEP_CFG_MODE_SHIFT)) & COM_MODE_013_CFG_HDR_STEP_CFG_MODE_MASK)

#define COM_MODE_013_CFG_HDR_STEP_CFG_TONE_EXT_MASK (0xCU)
#define COM_MODE_013_CFG_HDR_STEP_CFG_TONE_EXT_SHIFT (2U)
/*! TONE_EXT - Choice of tone extension for the initiator portion of the step.
 *  0b00..Tone extension is not present for either role TX.
 *  0b01..Tone extension is present for initiator TX only.
 *  0b10..Tone extension is present for reflector TX only.
 *  0b11..Tone extension is present for both roles TX.
 */
#define COM_MODE_013_CFG_HDR_STEP_CFG_TONE_EXT(x) (((uint16_t)(((uint16_t)(x)) << COM_MODE_013_CFG_HDR_STEP_CFG_TONE_EXT_SHIFT)) & COM_MODE_013_CFG_HDR_STEP_CFG_TONE_EXT_MASK)

#define COM_MODE_013_CFG_HDR_STEP_CFG_ANT_PERMUT_MASK (0x1F0U)
#define COM_MODE_013_CFG_HDR_STEP_CFG_ANT_PERMUT_SHIFT (4U)
/*! ANT_PERMUT - Antenna permutation pattern for the step. */
#define COM_MODE_013_CFG_HDR_STEP_CFG_ANT_PERMUT(x) (((uint16_t)(((uint16_t)(x)) << COM_MODE_013_CFG_HDR_STEP_CFG_ANT_PERMUT_SHIFT)) & COM_MODE_013_CFG_HDR_STEP_CFG_ANT_PERMUT_MASK)

#define COM_MODE_013_CFG_HDR_STEP_CFG_ANT_CS_SYNC_MASK (0x600U)
#define COM_MODE_013_CFG_HDR_STEP_CFG_ANT_CS_SYNC_SHIFT (9U)
/*! ANT_CS_SYNC - Antenna cs Sync */
#define COM_MODE_013_CFG_HDR_STEP_CFG_ANT_CS_SYNC(x) (((uint16_t)(((uint16_t)(x)) << COM_MODE_013_CFG_HDR_STEP_CFG_ANT_CS_SYNC_SHIFT)) & COM_MODE_013_CFG_HDR_STEP_CFG_ANT_CS_SYNC_MASK)

#define COM_MODE_013_CFG_HDR_STEP_CFG_EP_ONE_WAY_MASK (0x800U)
#define COM_MODE_013_CFG_HDR_STEP_CFG_EP_ONE_WAY_SHIFT (11U)
/*! EP_ONE_WAY - One way ranging? */
#define COM_MODE_013_CFG_HDR_STEP_CFG_EP_ONE_WAY(x) (((uint16_t)(((uint16_t)(x)) << COM_MODE_013_CFG_HDR_STEP_CFG_EP_ONE_WAY_SHIFT)) & COM_MODE_013_CFG_HDR_STEP_CFG_EP_ONE_WAY_MASK)

#define COM_MODE_013_CFG_HDR_STEP_CFG_T_PM_SEL_MASK (0x1000U)
#define COM_MODE_013_CFG_HDR_STEP_CFG_T_PM_SEL_SHIFT (12U)
/*! T_PM_SEL - Selection of T_PM choices. */
#define COM_MODE_013_CFG_HDR_STEP_CFG_T_PM_SEL(x) (((uint16_t)(((uint16_t)(x)) << COM_MODE_013_CFG_HDR_STEP_CFG_T_PM_SEL_SHIFT)) & COM_MODE_013_CFG_HDR_STEP_CFG_T_PM_SEL_MASK)
/*! @} */

/*! @name STEP_CFO - CFO setting for the step */
/*! @{ */

#define COM_MODE_013_CFG_HDR_STEP_CFO_STEP_CFO_MASK (0xFFFFU)
#define COM_MODE_013_CFG_HDR_STEP_CFO_STEP_CFO_SHIFT (0U)
/*! STEP_CFO - CFO setting for the step. */
#define COM_MODE_013_CFG_HDR_STEP_CFO_STEP_CFO(x) (((uint16_t)(((uint16_t)(x)) << COM_MODE_013_CFG_HDR_STEP_CFO_STEP_CFO_SHIFT)) & COM_MODE_013_CFG_HDR_STEP_CFO_STEP_CFO_MASK)
/*! @} */

/*! @name HPM_CAL_FACTOR - HPM CAL factor to apply for the step. */
/*! @{ */

#define COM_MODE_013_CFG_HDR_HPM_CAL_FACTOR_HPM_CAL_FACTOR_MASK (0xFFFU)
#define COM_MODE_013_CFG_HDR_HPM_CAL_FACTOR_HPM_CAL_FACTOR_SHIFT (0U)
/*! HPM_CAL_FACTOR - HPM CAL factor to apply for the step */
#define COM_MODE_013_CFG_HDR_HPM_CAL_FACTOR_HPM_CAL_FACTOR(x) (((uint16_t)(((uint16_t)(x)) << COM_MODE_013_CFG_HDR_HPM_CAL_FACTOR_HPM_CAL_FACTOR_SHIFT)) & COM_MODE_013_CFG_HDR_HPM_CAL_FACTOR_HPM_CAL_FACTOR_MASK)
/*! @} */

/*! @name CTUNE_MANUAL - CTUNE manual to inject for the step. */
/*! @{ */

#define COM_MODE_013_CFG_HDR_CTUNE_MANUAL_CTUNE_MANUAL_MASK (0x1FFU)
#define COM_MODE_013_CFG_HDR_CTUNE_MANUAL_CTUNE_MANUAL_SHIFT (0U)
/*! CTUNE_MANUAL - CTUNE manual to inject for the step. */
#define COM_MODE_013_CFG_HDR_CTUNE_MANUAL_CTUNE_MANUAL(x) (((uint16_t)(((uint16_t)(x)) << COM_MODE_013_CFG_HDR_CTUNE_MANUAL_CTUNE_MANUAL_SHIFT)) & COM_MODE_013_CFG_HDR_CTUNE_MANUAL_CTUNE_MANUAL_MASK)
/*! @} */

/*! @name PHASE_ADD - Phase adder for the step. */
/*! @{ */

#define COM_MODE_013_CFG_HDR_PHASE_ADD_PHASE_ADD_MASK (0xFFU)
#define COM_MODE_013_CFG_HDR_PHASE_ADD_PHASE_ADD_SHIFT (0U)
/*! PHASE_ADD - Phase adder for the step. */
#define COM_MODE_013_CFG_HDR_PHASE_ADD_PHASE_ADD(x) (((uint16_t)(((uint16_t)(x)) << COM_MODE_013_CFG_HDR_PHASE_ADD_PHASE_ADD_SHIFT)) & COM_MODE_013_CFG_HDR_PHASE_ADD_PHASE_ADD_MASK)
/*! @} */

/*! @name AA_INIT - Access address for the initiator (first half step). */
/*! @{ */

#define COM_MODE_013_CFG_HDR_AA_INIT_AA_INIT_MASK (0xFFFFFFFFU)
#define COM_MODE_013_CFG_HDR_AA_INIT_AA_INIT_SHIFT (0U)
/*! AA_INIT - Access Address. */
#define COM_MODE_013_CFG_HDR_AA_INIT_AA_INIT(x)  (((uint32_t)(((uint32_t)(x)) << COM_MODE_013_CFG_HDR_AA_INIT_AA_INIT_SHIFT)) & COM_MODE_013_CFG_HDR_AA_INIT_AA_INIT_MASK)
/*! @} */

/*! @name AA_REFL - Access address for the reflector (second half step). */
/*! @{ */

#define COM_MODE_013_CFG_HDR_AA_REFL_AA_REFL_MASK (0xFFFFFFFFU)
#define COM_MODE_013_CFG_HDR_AA_REFL_AA_REFL_SHIFT (0U)
/*! AA_REFL - Access Address. */
#define COM_MODE_013_CFG_HDR_AA_REFL_AA_REFL(x)  (((uint32_t)(((uint32_t)(x)) << COM_MODE_013_CFG_HDR_AA_REFL_AA_REFL_SHIFT)) & COM_MODE_013_CFG_HDR_AA_REFL_AA_REFL_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group COM_MODE_013_CFG_HDR_Register_Masks */


/*!
 * @}
 */ /* end of group COM_MODE_013_CFG_HDR_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- COM_MODE_013_RES_BODY Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup COM_MODE_013_RES_BODY_Peripheral_Access_Layer COM_MODE_013_RES_BODY Peripheral Access Layer
 * @{
 */

/** COM_MODE_013_RES_BODY - Register Layout Typedef */
typedef struct {
  __IO uint32_t NADM_ERROR_RSSI;                   /**< Raw NADM or Payload Error and RSSI for the step., offset: 0x0 */
  __IO uint32_t RTT_RESULT;                        /**< Results reported from the PHY RTT block for the step., offset: 0x4 */
  __IO uint32_t CFO_EST;                           /**< CFO estimate for the step., offset: 0x8 */
  __IO uint32_t TIMESTAMP;                         /**< TPM module timestamp for the step., offset: 0xC */
} COM_MODE_013_RES_BODY_Type;

/* ----------------------------------------------------------------------------
   -- COM_MODE_013_RES_BODY Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup COM_MODE_013_RES_BODY_Register_Masks COM_MODE_013_RES_BODY Register Masks
 * @{
 */

/*! @name NADM_ERROR_RSSI - Raw NADM or Payload Error and RSSI for the step. */
/*! @{ */

#define COM_MODE_013_RES_BODY_NADM_ERROR_RSSI_RSSI_NB_MASK (0xFFU)
#define COM_MODE_013_RES_BODY_NADM_ERROR_RSSI_RSSI_NB_SHIFT (0U)
/*! RSSI_NB - Narrowband RSSI measured for the step. 8-bit signedformat. */
#define COM_MODE_013_RES_BODY_NADM_ERROR_RSSI_RSSI_NB(x) (((uint32_t)(((uint32_t)(x)) << COM_MODE_013_RES_BODY_NADM_ERROR_RSSI_RSSI_NB_SHIFT)) & COM_MODE_013_RES_BODY_NADM_ERROR_RSSI_RSSI_NB_MASK)

#define COM_MODE_013_RES_BODY_NADM_ERROR_RSSI_RAW_NADM_FM_CORR_VALUE_MASK (0xFF00U)
#define COM_MODE_013_RES_BODY_NADM_ERROR_RSSI_RAW_NADM_FM_CORR_VALUE_SHIFT (8U)
/*! NADM_FM_CORR_VALUE - NADM FM correlator value */
#define COM_MODE_013_RES_BODY_NADM_ERROR_RSSI_RAW_NADM_FM_CORR_VALUE(x) (((uint32_t)(((uint32_t)(x)) << COM_MODE_013_RES_BODY_NADM_ERROR_RSSI_RAW_NADM_FM_CORR_VALUE_SHIFT)) & COM_MODE_013_RES_BODY_NADM_ERROR_RSSI_RAW_NADM_FM_CORR_VALUE_MASK)

#define COM_MODE_013_RES_BODY_NADM_ERROR_RSSI_RAW_NADM_FM_CORR_VALID_MASK (0x10000U)
#define COM_MODE_013_RES_BODY_NADM_ERROR_RSSI_RAW_NADM_FM_CORR_VALID_SHIFT (16U)
/*! NADM_FM_CORR_VALID - NADM FM correlator valid flag */
#define COM_MODE_013_RES_BODY_NADM_ERROR_RSSI_RAW_NADM_FM_CORR_VALID(x) (((uint32_t)(((uint32_t)(x)) << COM_MODE_013_RES_BODY_NADM_ERROR_RSSI_RAW_NADM_FM_CORR_VALID_SHIFT)) & COM_MODE_013_RES_BODY_NADM_ERROR_RSSI_RAW_NADM_FM_CORR_VALID_MASK)

#define COM_MODE_013_RES_BODY_NADM_ERROR_RSSI_RAW_NADM_FM_SYMB_ERR_VALUE_MASK (0x1E0000U)
#define COM_MODE_013_RES_BODY_NADM_ERROR_RSSI_RAW_NADM_FM_SYMB_ERR_VALUE_SHIFT (17U)
/*! NADM_FM_SYMB_ERR_VALUE - NADM FM symbol error value */
#define COM_MODE_013_RES_BODY_NADM_ERROR_RSSI_RAW_NADM_FM_SYMB_ERR_VALUE(x) (((uint32_t)(((uint32_t)(x)) << COM_MODE_013_RES_BODY_NADM_ERROR_RSSI_RAW_NADM_FM_SYMB_ERR_VALUE_SHIFT)) & COM_MODE_013_RES_BODY_NADM_ERROR_RSSI_RAW_NADM_FM_SYMB_ERR_VALUE_MASK)

#define COM_MODE_013_RES_BODY_NADM_ERROR_RSSI_RAW_NADM_FM_SYMB_ERR_VALID_MASK (0x200000U)
#define COM_MODE_013_RES_BODY_NADM_ERROR_RSSI_RAW_NADM_FM_SYMB_ERR_VALID_SHIFT (21U)
/*! NADM_FM_SYMB_ERR_VALID - NADM FM symbol error valid flag */
#define COM_MODE_013_RES_BODY_NADM_ERROR_RSSI_RAW_NADM_FM_SYMB_ERR_VALID(x) (((uint32_t)(((uint32_t)(x)) << COM_MODE_013_RES_BODY_NADM_ERROR_RSSI_RAW_NADM_FM_SYMB_ERR_VALID_SHIFT)) & COM_MODE_013_RES_BODY_NADM_ERROR_RSSI_RAW_NADM_FM_SYMB_ERR_VALID_MASK)

#define COM_MODE_013_RES_BODY_NADM_ERROR_RSSI_RAW_NADM_PDELTA_MASK (0xFFC00000U)
#define COM_MODE_013_RES_BODY_NADM_ERROR_RSSI_RAW_NADM_PDELTA_SHIFT (22U)
/*! NADM_PDELTA - NADM pdelta value */
#define COM_MODE_013_RES_BODY_NADM_ERROR_RSSI_RAW_NADM_PDELTA(x) (((uint32_t)(((uint32_t)(x)) << COM_MODE_013_RES_BODY_NADM_ERROR_RSSI_RAW_NADM_PDELTA_SHIFT)) & COM_MODE_013_RES_BODY_NADM_ERROR_RSSI_RAW_NADM_PDELTA_MASK)
/*! @} */

/*! @name RTT_RESULT - Results reported from the PHY RTT block for the step. */
/*! @{ */

#define COM_MODE_013_RES_BODY_RTT_RESULT_RTT_VLD_MASK (0x1U)
#define COM_MODE_013_RES_BODY_RTT_RESULT_RTT_VLD_SHIFT (0U)
/*! RTT_VLD - RTT valid status. */
#define COM_MODE_013_RES_BODY_RTT_RESULT_RTT_VLD(x) (((uint32_t)(((uint32_t)(x)) << COM_MODE_013_RES_BODY_RTT_RESULT_RTT_VLD_SHIFT)) & COM_MODE_013_RES_BODY_RTT_RESULT_RTT_VLD_MASK)

#define COM_MODE_013_RES_BODY_RTT_RESULT_RTT_FOUND_MASK (0x2U)
#define COM_MODE_013_RES_BODY_RTT_RESULT_RTT_FOUND_SHIFT (1U)
/*! RTT_FOUND - RTT found status. */
#define COM_MODE_013_RES_BODY_RTT_RESULT_RTT_FOUND(x) (((uint32_t)(((uint32_t)(x)) << COM_MODE_013_RES_BODY_RTT_RESULT_RTT_FOUND_SHIFT)) & COM_MODE_013_RES_BODY_RTT_RESULT_RTT_FOUND_MASK)

#define COM_MODE_013_RES_BODY_RTT_RESULT_RTT_CFO_MASK (0x3FFFCU)
#define COM_MODE_013_RES_BODY_RTT_RESULT_RTT_CFO_SHIFT (2U)
/*! RTT_CFO - RTT Carrier Frequency Offset (CFO) result. */
#define COM_MODE_013_RES_BODY_RTT_RESULT_RTT_CFO(x) (((uint32_t)(((uint32_t)(x)) << COM_MODE_013_RES_BODY_RTT_RESULT_RTT_CFO_SHIFT)) & COM_MODE_013_RES_BODY_RTT_RESULT_RTT_CFO_MASK)

#define COM_MODE_013_RES_BODY_RTT_RESULT_RTT_INT_ADJ_MASK (0xC0000U)
#define COM_MODE_013_RES_BODY_RTT_RESULT_RTT_INT_ADJ_SHIFT (18U)
/*! RTT_INT_ADJ - Integer adjustment reported from the RTT result. */
#define COM_MODE_013_RES_BODY_RTT_RESULT_RTT_INT_ADJ(x) (((uint32_t)(((uint32_t)(x)) << COM_MODE_013_RES_BODY_RTT_RESULT_RTT_INT_ADJ_SHIFT)) & COM_MODE_013_RES_BODY_RTT_RESULT_RTT_INT_ADJ_MASK)

#define COM_MODE_013_RES_BODY_RTT_RESULT_RTT_HAM_DIST_SAT_MASK (0x300000U)
#define COM_MODE_013_RES_BODY_RTT_RESULT_RTT_HAM_DIST_SAT_SHIFT (20U)
/*! RTT_HAM_DIST_SAT - Hamming Distance Saturation from the RTT result. */
#define COM_MODE_013_RES_BODY_RTT_RESULT_RTT_HAM_DIST_SAT(x) (((uint32_t)(((uint32_t)(x)) << COM_MODE_013_RES_BODY_RTT_RESULT_RTT_HAM_DIST_SAT_SHIFT)) & COM_MODE_013_RES_BODY_RTT_RESULT_RTT_HAM_DIST_SAT_MASK)

#define COM_MODE_013_RES_BODY_RTT_RESULT_RTT_P_DELTA_MASK (0xFFC00000U)
#define COM_MODE_013_RES_BODY_RTT_RESULT_RTT_P_DELTA_SHIFT (22U)
/*! RTT_P_DELTA - P-delta value from the RTT result. */
#define COM_MODE_013_RES_BODY_RTT_RESULT_RTT_P_DELTA(x) (((uint32_t)(((uint32_t)(x)) << COM_MODE_013_RES_BODY_RTT_RESULT_RTT_P_DELTA_SHIFT)) & COM_MODE_013_RES_BODY_RTT_RESULT_RTT_P_DELTA_MASK)
/*! @} */

/*! @name CFO_EST - CFO estimate for the step. */
/*! @{ */

#define COM_MODE_013_RES_BODY_CFO_EST_CFO_EST_MASK (0x3FFU)
#define COM_MODE_013_RES_BODY_CFO_EST_CFO_EST_SHIFT (0U)
/*! CFO_EST - Carrier Frequency Offset estimate for the step. Signed 10-bit format. */
#define COM_MODE_013_RES_BODY_CFO_EST_CFO_EST(x) (((uint32_t)(((uint32_t)(x)) << COM_MODE_013_RES_BODY_CFO_EST_CFO_EST_SHIFT)) & COM_MODE_013_RES_BODY_CFO_EST_CFO_EST_MASK)

#define COM_MODE_013_RES_BODY_CFO_EST_RSSI_NB_MASK (0xFF0000U)
#define COM_MODE_013_RES_BODY_CFO_EST_RSSI_NB_SHIFT (16U)
/*! RSSI_NB - Narrowband RSSI measured for the step. 8-bit signedformat. */
#define COM_MODE_013_RES_BODY_CFO_EST_RSSI_NB(x) (((uint32_t)(((uint32_t)(x)) << COM_MODE_013_RES_BODY_CFO_EST_RSSI_NB_SHIFT)) & COM_MODE_013_RES_BODY_CFO_EST_RSSI_NB_MASK)

#define COM_MODE_013_RES_BODY_CFO_EST_SNR_MASK   (0x3F000000U)
#define COM_MODE_013_RES_BODY_CFO_EST_SNR_SHIFT  (24U)
/*! SNR - Narrowband SNR measured for the step. 5-bit unsignedformat. */
#define COM_MODE_013_RES_BODY_CFO_EST_SNR(x)     (((uint32_t)(((uint32_t)(x)) << COM_MODE_013_RES_BODY_CFO_EST_SNR_SHIFT)) & COM_MODE_013_RES_BODY_CFO_EST_SNR_MASK)

#define COM_MODE_013_RES_BODY_CFO_EST_RSSI_VLD_MASK (0x80000000U)
#define COM_MODE_013_RES_BODY_CFO_EST_RSSI_VLD_SHIFT (31U)
/*! RSSI_VLD - Narrowband RSSI valid flag */
#define COM_MODE_013_RES_BODY_CFO_EST_RSSI_VLD(x) (((uint32_t)(((uint32_t)(x)) << COM_MODE_013_RES_BODY_CFO_EST_RSSI_VLD_SHIFT)) & COM_MODE_013_RES_BODY_CFO_EST_RSSI_VLD_MASK)
/*! @} */

/*! @name TIMESTAMP - TPM module timestamp for the step. */
/*! @{ */

#define COM_MODE_013_RES_BODY_TIMESTAMP_TPM_MASK (0xFFFFFFFFU)
#define COM_MODE_013_RES_BODY_TIMESTAMP_TPM_SHIFT (0U)
/*! TPM - Timestamp for the step. */
#define COM_MODE_013_RES_BODY_TIMESTAMP_TPM(x)   (((uint32_t)(((uint32_t)(x)) << COM_MODE_013_RES_BODY_TIMESTAMP_TPM_SHIFT)) & COM_MODE_013_RES_BODY_TIMESTAMP_TPM_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group COM_MODE_013_RES_BODY_Register_Masks */


/*!
 * @}
 */ /* end of group COM_MODE_013_RES_BODY_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- COM_RES_HDR Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup COM_RES_HDR_Peripheral_Access_Layer COM_RES_HDR Peripheral Access Layer
 * @{
 */

/** COM_RES_HDR - Register Layout Typedef */
typedef struct {
  __IO uint8_t STEP_ID;                            /**< STEP_ID for the step., offset: 0x0 */
  __IO uint8_t SIZE_AGC_IDX;                       /**< Result size and AGC index for the step., offset: 0x1 */
  __IO uint16_t PBCD_CTUNE_AA_DET;                 /**< PBCD or CTUNE and AA detection status for the step, offset: 0x2 */
} COM_RES_HDR_Type;

/* ----------------------------------------------------------------------------
   -- COM_RES_HDR Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup COM_RES_HDR_Register_Masks COM_RES_HDR Register Masks
 * @{
 */

/*! @name STEP_ID - STEP_ID for the step. */
/*! @{ */

#define COM_RES_HDR_STEP_ID_STEP_ID_MASK         (0xFFU)
#define COM_RES_HDR_STEP_ID_STEP_ID_SHIFT        (0U)
/*! STEP_ID - STEP_ID for the step. */
#define COM_RES_HDR_STEP_ID_STEP_ID(x)           (((uint8_t)(((uint8_t)(x)) << COM_RES_HDR_STEP_ID_STEP_ID_SHIFT)) & COM_RES_HDR_STEP_ID_STEP_ID_MASK)
/*! @} */

/*! @name SIZE_AGC_IDX - Result size and AGC index for the step. */
/*! @{ */

#define COM_RES_HDR_SIZE_AGC_IDX_TIME_DRIFT_MASK (0x3U)
#define COM_RES_HDR_SIZE_AGC_IDX_TIME_DRIFT_SHIFT (0U)
/*! TIME_DRIFT - TIME DRIFT delta value
 *  0b00..0 us
 *  0b01..+1us
 *  0b11..-1us
 */
#define COM_RES_HDR_SIZE_AGC_IDX_TIME_DRIFT(x)   (((uint8_t)(((uint8_t)(x)) << COM_RES_HDR_SIZE_AGC_IDX_TIME_DRIFT_SHIFT)) & COM_RES_HDR_SIZE_AGC_IDX_TIME_DRIFT_MASK)

#define COM_RES_HDR_SIZE_AGC_IDX_AGC_IDX_MASK    (0xF0U)
#define COM_RES_HDR_SIZE_AGC_IDX_AGC_IDX_SHIFT   (4U)
/*! AGC_IDX - AGC Index reported for the step. */
#define COM_RES_HDR_SIZE_AGC_IDX_AGC_IDX(x)      (((uint8_t)(((uint8_t)(x)) << COM_RES_HDR_SIZE_AGC_IDX_AGC_IDX_SHIFT)) & COM_RES_HDR_SIZE_AGC_IDX_AGC_IDX_MASK)
/*! @} */

/*! @name PBCD_CTUNE_AA_DET - PBCD or CTUNE and AA detection status for the step */
/*! @{ */

#define COM_RES_HDR_PBCD_CTUNE_AA_DET_PBCD_CTUNE_MASK (0x1FFU)
#define COM_RES_HDR_PBCD_CTUNE_AA_DET_PBCD_CTUNE_SHIFT (0U)
/*! PBCD_CTUNE - PBCD or CTUNE for the step. */
#define COM_RES_HDR_PBCD_CTUNE_AA_DET_PBCD_CTUNE(x) (((uint16_t)(((uint16_t)(x)) << COM_RES_HDR_PBCD_CTUNE_AA_DET_PBCD_CTUNE_SHIFT)) & COM_RES_HDR_PBCD_CTUNE_AA_DET_PBCD_CTUNE_MASK)

#define COM_RES_HDR_PBCD_CTUNE_AA_DET_RESULT_SIZE_MASK (0x3E00U)
#define COM_RES_HDR_PBCD_CTUNE_AA_DET_RESULT_SIZE_SHIFT (9U)
/*! RESULT_SIZE - Result length for the step. */
#define COM_RES_HDR_PBCD_CTUNE_AA_DET_RESULT_SIZE(x) (((uint16_t)(((uint16_t)(x)) << COM_RES_HDR_PBCD_CTUNE_AA_DET_RESULT_SIZE_SHIFT)) & COM_RES_HDR_PBCD_CTUNE_AA_DET_RESULT_SIZE_MASK)

#define COM_RES_HDR_PBCD_CTUNE_AA_DET_AA_DET_MASK (0x8000U)
#define COM_RES_HDR_PBCD_CTUNE_AA_DET_AA_DET_SHIFT (15U)
/*! AA_DET - AA detection status reported for the step. */
#define COM_RES_HDR_PBCD_CTUNE_AA_DET_AA_DET(x)  (((uint16_t)(((uint16_t)(x)) << COM_RES_HDR_PBCD_CTUNE_AA_DET_AA_DET_SHIFT)) & COM_RES_HDR_PBCD_CTUNE_AA_DET_AA_DET_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group COM_RES_HDR_Register_Masks */


/*!
 * @}
 */ /* end of group COM_RES_HDR_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- IQ_RES_BODY Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup IQ_RES_BODY_Peripheral_Access_Layer IQ_RES_BODY Peripheral Access Layer
 * @{
 */

/** IQ_RES_BODY - Register Layout Typedef */
typedef struct {
  __IO uint32_t PCT_RESULT[17];                    /**< IQ and TQI result for the step., array offset: 0x0, array step: 0x4 */
} IQ_RES_BODY_Type;

/* ----------------------------------------------------------------------------
   -- IQ_RES_BODY Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup IQ_RES_BODY_Register_Masks IQ_RES_BODY Register Masks
 * @{
 */

/*! @name PCT_RESULT - IQ and TQI result for the step. */
/*! @{ */

#define IQ_RES_BODY_PCT_RESULT_TQI_MASK          (0x3U)
#define IQ_RES_BODY_PCT_RESULT_TQI_SHIFT         (0U)
/*! TQI - Tone Quality Indication (TQI) for the individual path.
 *  0b00..Good quality
 *  0b01..Medium quality
 *  0b10..Low quality
 *  0b11..Reserved
 */
#define IQ_RES_BODY_PCT_RESULT_TQI(x)            (((uint32_t)(((uint32_t)(x)) << IQ_RES_BODY_PCT_RESULT_TQI_SHIFT)) & IQ_RES_BODY_PCT_RESULT_TQI_MASK)

#define IQ_RES_BODY_PCT_RESULT_PCT_I_MASK        (0xFFF0U)
#define IQ_RES_BODY_PCT_RESULT_PCT_I_SHIFT       (4U)
/*! PCT_I - In-phase component of the PCT for the individual path. */
#define IQ_RES_BODY_PCT_RESULT_PCT_I(x)          (((uint32_t)(((uint32_t)(x)) << IQ_RES_BODY_PCT_RESULT_PCT_I_SHIFT)) & IQ_RES_BODY_PCT_RESULT_PCT_I_MASK)

#define IQ_RES_BODY_PCT_RESULT_PCT_VLD_MASK      (0x10000U)
#define IQ_RES_BODY_PCT_RESULT_PCT_VLD_SHIFT     (16U)
/*! PCT_VLD - PCT valid flag. */
#define IQ_RES_BODY_PCT_RESULT_PCT_VLD(x)        (((uint32_t)(((uint32_t)(x)) << IQ_RES_BODY_PCT_RESULT_PCT_VLD_SHIFT)) & IQ_RES_BODY_PCT_RESULT_PCT_VLD_MASK)

#define IQ_RES_BODY_PCT_RESULT_PCT_Q_MASK        (0xFFF00000U)
#define IQ_RES_BODY_PCT_RESULT_PCT_Q_SHIFT       (20U)
/*! PCT_Q - Quadrature component of the PCT for the individual path. */
#define IQ_RES_BODY_PCT_RESULT_PCT_Q(x)          (((uint32_t)(((uint32_t)(x)) << IQ_RES_BODY_PCT_RESULT_PCT_Q_SHIFT)) & IQ_RES_BODY_PCT_RESULT_PCT_Q_MASK)
/*! @} */

/* The count of IQ_RES_BODY_PCT_RESULT */
#define IQ_RES_BODY_PCT_RESULT_COUNT             (17U)


/*!
 * @}
 */ /* end of group IQ_RES_BODY_Register_Masks */


/*!
 * @}
 */ /* end of group IQ_RES_BODY_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- MODE2_3_CFG_BODY Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MODE2_3_CFG_BODY_Peripheral_Access_Layer MODE2_3_CFG_BODY Peripheral Access Layer
 * @{
 */

/** MODE2_3_CFG_BODY - Register Layout Typedef */
typedef struct {
  __IO uint32_t MULTI_ANT_PERMUT_1_8;              /**< Multi Antenna permutation pattern_1_to_8, offset: 0x0 */
  __IO uint32_t MULTI_ANT_PERMUT_9_16;             /**< Multi Antenna permutation pattern_9_to_16, offset: 0x4 */
  __IO uint32_t PHASE_ADD_AP_1_4;                  /**< Phase to add for Antenna path 1 to 4, offset: 0x8 */
  __IO uint32_t PHASE_ADD_AP_5_8;                  /**< Phase to add for Antenna path 5 to 8, offset: 0xC */
  __IO uint32_t PHASE_ADD_AP_9_12;                 /**< Phase to add for Antenna path 9 to 12, offset: 0x10 */
  __IO uint32_t PHASE_ADD_AP_13_16;                /**< Phase to add for Antenna path 13 to 16, offset: 0x14 */
} MODE2_3_CFG_BODY_Type;

/* ----------------------------------------------------------------------------
   -- MODE2_3_CFG_BODY Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MODE2_3_CFG_BODY_Register_Masks MODE2_3_CFG_BODY Register Masks
 * @{
 */

/*! @name MULTI_ANT_PERMUT_1_8 - Multi Antenna permutation pattern_1_to_8 */
/*! @{ */

#define MODE2_3_CFG_BODY_MULTI_ANT_PERMUT_1_8_PERMUT_AP1_MASK (0x7U)
#define MODE2_3_CFG_BODY_MULTI_ANT_PERMUT_1_8_PERMUT_AP1_SHIFT (0U)
/*! PERMUT_AP1 - Antenna Index for Antenna_path 1
 *  0b000..A0
 *  0b001..A1
 *  0b010..A2
 *  0b011..A3
 *  0b100..A4
 *  0b101..A5
 *  0b110..A6
 *  0b111..A7
 */
#define MODE2_3_CFG_BODY_MULTI_ANT_PERMUT_1_8_PERMUT_AP1(x) (((uint32_t)(((uint32_t)(x)) << MODE2_3_CFG_BODY_MULTI_ANT_PERMUT_1_8_PERMUT_AP1_SHIFT)) & MODE2_3_CFG_BODY_MULTI_ANT_PERMUT_1_8_PERMUT_AP1_MASK)

#define MODE2_3_CFG_BODY_MULTI_ANT_PERMUT_1_8_PERMUT_AP2_MASK (0x70U)
#define MODE2_3_CFG_BODY_MULTI_ANT_PERMUT_1_8_PERMUT_AP2_SHIFT (4U)
/*! PERMUT_AP2 - Antenna Index for Antenna_path 2
 *  0b000..A0
 *  0b001..A1
 *  0b010..A2
 *  0b011..A3
 *  0b100..A4
 *  0b101..A5
 *  0b110..A6
 *  0b111..A7
 */
#define MODE2_3_CFG_BODY_MULTI_ANT_PERMUT_1_8_PERMUT_AP2(x) (((uint32_t)(((uint32_t)(x)) << MODE2_3_CFG_BODY_MULTI_ANT_PERMUT_1_8_PERMUT_AP2_SHIFT)) & MODE2_3_CFG_BODY_MULTI_ANT_PERMUT_1_8_PERMUT_AP2_MASK)

#define MODE2_3_CFG_BODY_MULTI_ANT_PERMUT_1_8_PERMUT_AP3_MASK (0x700U)
#define MODE2_3_CFG_BODY_MULTI_ANT_PERMUT_1_8_PERMUT_AP3_SHIFT (8U)
/*! PERMUT_AP3 - Antenna Index for Antenna_path 3
 *  0b000..A0
 *  0b001..A1
 *  0b010..A2
 *  0b011..A3
 *  0b100..A4
 *  0b101..A5
 *  0b110..A6
 *  0b111..A7
 */
#define MODE2_3_CFG_BODY_MULTI_ANT_PERMUT_1_8_PERMUT_AP3(x) (((uint32_t)(((uint32_t)(x)) << MODE2_3_CFG_BODY_MULTI_ANT_PERMUT_1_8_PERMUT_AP3_SHIFT)) & MODE2_3_CFG_BODY_MULTI_ANT_PERMUT_1_8_PERMUT_AP3_MASK)

#define MODE2_3_CFG_BODY_MULTI_ANT_PERMUT_1_8_PERMUT_AP4_MASK (0x7000U)
#define MODE2_3_CFG_BODY_MULTI_ANT_PERMUT_1_8_PERMUT_AP4_SHIFT (12U)
/*! PERMUT_AP4 - Antenna Index for Antenna_path 4
 *  0b000..A0
 *  0b001..A1
 *  0b010..A2
 *  0b011..A3
 *  0b100..A4
 *  0b101..A5
 *  0b110..A6
 *  0b111..A7
 */
#define MODE2_3_CFG_BODY_MULTI_ANT_PERMUT_1_8_PERMUT_AP4(x) (((uint32_t)(((uint32_t)(x)) << MODE2_3_CFG_BODY_MULTI_ANT_PERMUT_1_8_PERMUT_AP4_SHIFT)) & MODE2_3_CFG_BODY_MULTI_ANT_PERMUT_1_8_PERMUT_AP4_MASK)

#define MODE2_3_CFG_BODY_MULTI_ANT_PERMUT_1_8_PERMUT_AP5_MASK (0x70000U)
#define MODE2_3_CFG_BODY_MULTI_ANT_PERMUT_1_8_PERMUT_AP5_SHIFT (16U)
/*! PERMUT_AP5 - Antenna Index for Antenna_path 5
 *  0b000..A0
 *  0b001..A1
 *  0b010..A2
 *  0b011..A3
 *  0b100..A4
 *  0b101..A5
 *  0b110..A6
 *  0b111..A7
 */
#define MODE2_3_CFG_BODY_MULTI_ANT_PERMUT_1_8_PERMUT_AP5(x) (((uint32_t)(((uint32_t)(x)) << MODE2_3_CFG_BODY_MULTI_ANT_PERMUT_1_8_PERMUT_AP5_SHIFT)) & MODE2_3_CFG_BODY_MULTI_ANT_PERMUT_1_8_PERMUT_AP5_MASK)

#define MODE2_3_CFG_BODY_MULTI_ANT_PERMUT_1_8_PERMUT_AP6_MASK (0x700000U)
#define MODE2_3_CFG_BODY_MULTI_ANT_PERMUT_1_8_PERMUT_AP6_SHIFT (20U)
/*! PERMUT_AP6 - Antenna Index for Antenna_path 6
 *  0b000..A0
 *  0b001..A1
 *  0b010..A2
 *  0b011..A3
 *  0b100..A4
 *  0b101..A5
 *  0b110..A6
 *  0b111..A7
 */
#define MODE2_3_CFG_BODY_MULTI_ANT_PERMUT_1_8_PERMUT_AP6(x) (((uint32_t)(((uint32_t)(x)) << MODE2_3_CFG_BODY_MULTI_ANT_PERMUT_1_8_PERMUT_AP6_SHIFT)) & MODE2_3_CFG_BODY_MULTI_ANT_PERMUT_1_8_PERMUT_AP6_MASK)

#define MODE2_3_CFG_BODY_MULTI_ANT_PERMUT_1_8_PERMUT_AP7_MASK (0x7000000U)
#define MODE2_3_CFG_BODY_MULTI_ANT_PERMUT_1_8_PERMUT_AP7_SHIFT (24U)
/*! PERMUT_AP7 - Antenna Index for Antenna_path 7
 *  0b000..A0
 *  0b001..A1
 *  0b010..A2
 *  0b011..A3
 *  0b100..A4
 *  0b101..A5
 *  0b110..A6
 *  0b111..A7
 */
#define MODE2_3_CFG_BODY_MULTI_ANT_PERMUT_1_8_PERMUT_AP7(x) (((uint32_t)(((uint32_t)(x)) << MODE2_3_CFG_BODY_MULTI_ANT_PERMUT_1_8_PERMUT_AP7_SHIFT)) & MODE2_3_CFG_BODY_MULTI_ANT_PERMUT_1_8_PERMUT_AP7_MASK)

#define MODE2_3_CFG_BODY_MULTI_ANT_PERMUT_1_8_PERMUT_AP8_MASK (0x70000000U)
#define MODE2_3_CFG_BODY_MULTI_ANT_PERMUT_1_8_PERMUT_AP8_SHIFT (28U)
/*! PERMUT_AP8 - Antenna Index for Antenna_path 8
 *  0b000..A0
 *  0b001..A1
 *  0b010..A2
 *  0b011..A3
 *  0b100..A4
 *  0b101..A5
 *  0b110..A6
 *  0b111..A7
 */
#define MODE2_3_CFG_BODY_MULTI_ANT_PERMUT_1_8_PERMUT_AP8(x) (((uint32_t)(((uint32_t)(x)) << MODE2_3_CFG_BODY_MULTI_ANT_PERMUT_1_8_PERMUT_AP8_SHIFT)) & MODE2_3_CFG_BODY_MULTI_ANT_PERMUT_1_8_PERMUT_AP8_MASK)
/*! @} */

/*! @name MULTI_ANT_PERMUT_9_16 - Multi Antenna permutation pattern_9_to_16 */
/*! @{ */

#define MODE2_3_CFG_BODY_MULTI_ANT_PERMUT_9_16_PERMUT_AP9_MASK (0x7U)
#define MODE2_3_CFG_BODY_MULTI_ANT_PERMUT_9_16_PERMUT_AP9_SHIFT (0U)
/*! PERMUT_AP9 - Antenna Index for Antenna_path 9
 *  0b000..A0
 *  0b001..A1
 *  0b010..A2
 *  0b011..A3
 *  0b100..A4
 *  0b101..A5
 *  0b110..A6
 *  0b111..A7
 */
#define MODE2_3_CFG_BODY_MULTI_ANT_PERMUT_9_16_PERMUT_AP9(x) (((uint32_t)(((uint32_t)(x)) << MODE2_3_CFG_BODY_MULTI_ANT_PERMUT_9_16_PERMUT_AP9_SHIFT)) & MODE2_3_CFG_BODY_MULTI_ANT_PERMUT_9_16_PERMUT_AP9_MASK)

#define MODE2_3_CFG_BODY_MULTI_ANT_PERMUT_9_16_PERMUT_AP10_MASK (0x70U)
#define MODE2_3_CFG_BODY_MULTI_ANT_PERMUT_9_16_PERMUT_AP10_SHIFT (4U)
/*! PERMUT_AP10 - Antenna Index for Antenna_path 10
 *  0b000..A0
 *  0b001..A1
 *  0b010..A2
 *  0b011..A3
 *  0b100..A4
 *  0b101..A5
 *  0b110..A6
 *  0b111..A7
 */
#define MODE2_3_CFG_BODY_MULTI_ANT_PERMUT_9_16_PERMUT_AP10(x) (((uint32_t)(((uint32_t)(x)) << MODE2_3_CFG_BODY_MULTI_ANT_PERMUT_9_16_PERMUT_AP10_SHIFT)) & MODE2_3_CFG_BODY_MULTI_ANT_PERMUT_9_16_PERMUT_AP10_MASK)

#define MODE2_3_CFG_BODY_MULTI_ANT_PERMUT_9_16_PERMUT_AP11_MASK (0x700U)
#define MODE2_3_CFG_BODY_MULTI_ANT_PERMUT_9_16_PERMUT_AP11_SHIFT (8U)
/*! PERMUT_AP11 - Antenna Index for Antenna_path 11
 *  0b000..A0
 *  0b001..A1
 *  0b010..A2
 *  0b011..A3
 *  0b100..A4
 *  0b101..A5
 *  0b110..A6
 *  0b111..A7
 */
#define MODE2_3_CFG_BODY_MULTI_ANT_PERMUT_9_16_PERMUT_AP11(x) (((uint32_t)(((uint32_t)(x)) << MODE2_3_CFG_BODY_MULTI_ANT_PERMUT_9_16_PERMUT_AP11_SHIFT)) & MODE2_3_CFG_BODY_MULTI_ANT_PERMUT_9_16_PERMUT_AP11_MASK)

#define MODE2_3_CFG_BODY_MULTI_ANT_PERMUT_9_16_PERMUT_AP12_MASK (0x7000U)
#define MODE2_3_CFG_BODY_MULTI_ANT_PERMUT_9_16_PERMUT_AP12_SHIFT (12U)
/*! PERMUT_AP12 - Antenna Index for Antenna_path 12
 *  0b000..A0
 *  0b001..A1
 *  0b010..A2
 *  0b011..A3
 *  0b100..A4
 *  0b101..A5
 *  0b110..A6
 *  0b111..A7
 */
#define MODE2_3_CFG_BODY_MULTI_ANT_PERMUT_9_16_PERMUT_AP12(x) (((uint32_t)(((uint32_t)(x)) << MODE2_3_CFG_BODY_MULTI_ANT_PERMUT_9_16_PERMUT_AP12_SHIFT)) & MODE2_3_CFG_BODY_MULTI_ANT_PERMUT_9_16_PERMUT_AP12_MASK)

#define MODE2_3_CFG_BODY_MULTI_ANT_PERMUT_9_16_PERMUT_AP13_MASK (0x70000U)
#define MODE2_3_CFG_BODY_MULTI_ANT_PERMUT_9_16_PERMUT_AP13_SHIFT (16U)
/*! PERMUT_AP13 - Antenna Index for Antenna_path 13
 *  0b000..A0
 *  0b001..A1
 *  0b010..A2
 *  0b011..A3
 *  0b100..A4
 *  0b101..A5
 *  0b110..A6
 *  0b111..A7
 */
#define MODE2_3_CFG_BODY_MULTI_ANT_PERMUT_9_16_PERMUT_AP13(x) (((uint32_t)(((uint32_t)(x)) << MODE2_3_CFG_BODY_MULTI_ANT_PERMUT_9_16_PERMUT_AP13_SHIFT)) & MODE2_3_CFG_BODY_MULTI_ANT_PERMUT_9_16_PERMUT_AP13_MASK)

#define MODE2_3_CFG_BODY_MULTI_ANT_PERMUT_9_16_PERMUT_AP14_MASK (0x700000U)
#define MODE2_3_CFG_BODY_MULTI_ANT_PERMUT_9_16_PERMUT_AP14_SHIFT (20U)
/*! PERMUT_AP14 - Antenna Index for Antenna_path 14
 *  0b000..A0
 *  0b001..A1
 *  0b010..A2
 *  0b011..A3
 *  0b100..A4
 *  0b101..A5
 *  0b110..A6
 *  0b111..A7
 */
#define MODE2_3_CFG_BODY_MULTI_ANT_PERMUT_9_16_PERMUT_AP14(x) (((uint32_t)(((uint32_t)(x)) << MODE2_3_CFG_BODY_MULTI_ANT_PERMUT_9_16_PERMUT_AP14_SHIFT)) & MODE2_3_CFG_BODY_MULTI_ANT_PERMUT_9_16_PERMUT_AP14_MASK)

#define MODE2_3_CFG_BODY_MULTI_ANT_PERMUT_9_16_PERMUT_AP15_MASK (0x7000000U)
#define MODE2_3_CFG_BODY_MULTI_ANT_PERMUT_9_16_PERMUT_AP15_SHIFT (24U)
/*! PERMUT_AP15 - Antenna Index for Antenna_path 15
 *  0b000..A0
 *  0b001..A1
 *  0b010..A2
 *  0b011..A3
 *  0b100..A4
 *  0b101..A5
 *  0b110..A6
 *  0b111..A7
 */
#define MODE2_3_CFG_BODY_MULTI_ANT_PERMUT_9_16_PERMUT_AP15(x) (((uint32_t)(((uint32_t)(x)) << MODE2_3_CFG_BODY_MULTI_ANT_PERMUT_9_16_PERMUT_AP15_SHIFT)) & MODE2_3_CFG_BODY_MULTI_ANT_PERMUT_9_16_PERMUT_AP15_MASK)

#define MODE2_3_CFG_BODY_MULTI_ANT_PERMUT_9_16_PERMUT_AP16_MASK (0x70000000U)
#define MODE2_3_CFG_BODY_MULTI_ANT_PERMUT_9_16_PERMUT_AP16_SHIFT (28U)
/*! PERMUT_AP16 - Antenna Index for Antenna_path 16
 *  0b000..A0
 *  0b001..A1
 *  0b010..A2
 *  0b011..A3
 *  0b100..A4
 *  0b101..A5
 *  0b110..A6
 *  0b111..A7
 */
#define MODE2_3_CFG_BODY_MULTI_ANT_PERMUT_9_16_PERMUT_AP16(x) (((uint32_t)(((uint32_t)(x)) << MODE2_3_CFG_BODY_MULTI_ANT_PERMUT_9_16_PERMUT_AP16_SHIFT)) & MODE2_3_CFG_BODY_MULTI_ANT_PERMUT_9_16_PERMUT_AP16_MASK)
/*! @} */

/*! @name PHASE_ADD_AP_1_4 - Phase to add for Antenna path 1 to 4 */
/*! @{ */

#define MODE2_3_CFG_BODY_PHASE_ADD_AP_1_4_PHASE_ADD_AP1_MASK (0xFFU)
#define MODE2_3_CFG_BODY_PHASE_ADD_AP_1_4_PHASE_ADD_AP1_SHIFT (0U)
/*! PHASE_ADD_AP1 - Phase to add for Antenna Path 1 */
#define MODE2_3_CFG_BODY_PHASE_ADD_AP_1_4_PHASE_ADD_AP1(x) (((uint32_t)(((uint32_t)(x)) << MODE2_3_CFG_BODY_PHASE_ADD_AP_1_4_PHASE_ADD_AP1_SHIFT)) & MODE2_3_CFG_BODY_PHASE_ADD_AP_1_4_PHASE_ADD_AP1_MASK)

#define MODE2_3_CFG_BODY_PHASE_ADD_AP_1_4_PHASE_ADD_AP2_MASK (0xFF00U)
#define MODE2_3_CFG_BODY_PHASE_ADD_AP_1_4_PHASE_ADD_AP2_SHIFT (8U)
/*! PHASE_ADD_AP2 - Phase to add for Antenna Path 2 */
#define MODE2_3_CFG_BODY_PHASE_ADD_AP_1_4_PHASE_ADD_AP2(x) (((uint32_t)(((uint32_t)(x)) << MODE2_3_CFG_BODY_PHASE_ADD_AP_1_4_PHASE_ADD_AP2_SHIFT)) & MODE2_3_CFG_BODY_PHASE_ADD_AP_1_4_PHASE_ADD_AP2_MASK)

#define MODE2_3_CFG_BODY_PHASE_ADD_AP_1_4_PHASE_ADD_AP3_MASK (0xFF0000U)
#define MODE2_3_CFG_BODY_PHASE_ADD_AP_1_4_PHASE_ADD_AP3_SHIFT (16U)
/*! PHASE_ADD_AP3 - Phase to add for Antenna Path 3 */
#define MODE2_3_CFG_BODY_PHASE_ADD_AP_1_4_PHASE_ADD_AP3(x) (((uint32_t)(((uint32_t)(x)) << MODE2_3_CFG_BODY_PHASE_ADD_AP_1_4_PHASE_ADD_AP3_SHIFT)) & MODE2_3_CFG_BODY_PHASE_ADD_AP_1_4_PHASE_ADD_AP3_MASK)

#define MODE2_3_CFG_BODY_PHASE_ADD_AP_1_4_PHASE_ADD_AP4_MASK (0xFF000000U)
#define MODE2_3_CFG_BODY_PHASE_ADD_AP_1_4_PHASE_ADD_AP4_SHIFT (24U)
/*! PHASE_ADD_AP4 - Phase to add for Antenna Path 4 */
#define MODE2_3_CFG_BODY_PHASE_ADD_AP_1_4_PHASE_ADD_AP4(x) (((uint32_t)(((uint32_t)(x)) << MODE2_3_CFG_BODY_PHASE_ADD_AP_1_4_PHASE_ADD_AP4_SHIFT)) & MODE2_3_CFG_BODY_PHASE_ADD_AP_1_4_PHASE_ADD_AP4_MASK)
/*! @} */

/*! @name PHASE_ADD_AP_5_8 - Phase to add for Antenna path 5 to 8 */
/*! @{ */

#define MODE2_3_CFG_BODY_PHASE_ADD_AP_5_8_PHASE_ADD_AP5_MASK (0xFFU)
#define MODE2_3_CFG_BODY_PHASE_ADD_AP_5_8_PHASE_ADD_AP5_SHIFT (0U)
/*! PHASE_ADD_AP5 - Phase to add for Antenna Path 5 */
#define MODE2_3_CFG_BODY_PHASE_ADD_AP_5_8_PHASE_ADD_AP5(x) (((uint32_t)(((uint32_t)(x)) << MODE2_3_CFG_BODY_PHASE_ADD_AP_5_8_PHASE_ADD_AP5_SHIFT)) & MODE2_3_CFG_BODY_PHASE_ADD_AP_5_8_PHASE_ADD_AP5_MASK)

#define MODE2_3_CFG_BODY_PHASE_ADD_AP_5_8_PHASE_ADD_AP6_MASK (0xFF00U)
#define MODE2_3_CFG_BODY_PHASE_ADD_AP_5_8_PHASE_ADD_AP6_SHIFT (8U)
/*! PHASE_ADD_AP6 - Phase to add for Antenna Path 6 */
#define MODE2_3_CFG_BODY_PHASE_ADD_AP_5_8_PHASE_ADD_AP6(x) (((uint32_t)(((uint32_t)(x)) << MODE2_3_CFG_BODY_PHASE_ADD_AP_5_8_PHASE_ADD_AP6_SHIFT)) & MODE2_3_CFG_BODY_PHASE_ADD_AP_5_8_PHASE_ADD_AP6_MASK)

#define MODE2_3_CFG_BODY_PHASE_ADD_AP_5_8_PHASE_ADD_AP7_MASK (0xFF0000U)
#define MODE2_3_CFG_BODY_PHASE_ADD_AP_5_8_PHASE_ADD_AP7_SHIFT (16U)
/*! PHASE_ADD_AP7 - Phase to add for Antenna Path 7 */
#define MODE2_3_CFG_BODY_PHASE_ADD_AP_5_8_PHASE_ADD_AP7(x) (((uint32_t)(((uint32_t)(x)) << MODE2_3_CFG_BODY_PHASE_ADD_AP_5_8_PHASE_ADD_AP7_SHIFT)) & MODE2_3_CFG_BODY_PHASE_ADD_AP_5_8_PHASE_ADD_AP7_MASK)

#define MODE2_3_CFG_BODY_PHASE_ADD_AP_5_8_PHASE_ADD_AP8_MASK (0xFF000000U)
#define MODE2_3_CFG_BODY_PHASE_ADD_AP_5_8_PHASE_ADD_AP8_SHIFT (24U)
/*! PHASE_ADD_AP8 - Phase to add for Antenna Path 8 */
#define MODE2_3_CFG_BODY_PHASE_ADD_AP_5_8_PHASE_ADD_AP8(x) (((uint32_t)(((uint32_t)(x)) << MODE2_3_CFG_BODY_PHASE_ADD_AP_5_8_PHASE_ADD_AP8_SHIFT)) & MODE2_3_CFG_BODY_PHASE_ADD_AP_5_8_PHASE_ADD_AP8_MASK)
/*! @} */

/*! @name PHASE_ADD_AP_9_12 - Phase to add for Antenna path 9 to 12 */
/*! @{ */

#define MODE2_3_CFG_BODY_PHASE_ADD_AP_9_12_PHASE_ADD_AP9_MASK (0xFFU)
#define MODE2_3_CFG_BODY_PHASE_ADD_AP_9_12_PHASE_ADD_AP9_SHIFT (0U)
/*! PHASE_ADD_AP9 - Phase to add for Antenna Path 9 */
#define MODE2_3_CFG_BODY_PHASE_ADD_AP_9_12_PHASE_ADD_AP9(x) (((uint32_t)(((uint32_t)(x)) << MODE2_3_CFG_BODY_PHASE_ADD_AP_9_12_PHASE_ADD_AP9_SHIFT)) & MODE2_3_CFG_BODY_PHASE_ADD_AP_9_12_PHASE_ADD_AP9_MASK)

#define MODE2_3_CFG_BODY_PHASE_ADD_AP_9_12_PHASE_ADD_AP10_MASK (0xFF00U)
#define MODE2_3_CFG_BODY_PHASE_ADD_AP_9_12_PHASE_ADD_AP10_SHIFT (8U)
/*! PHASE_ADD_AP10 - Phase to add for Antenna Path 10 */
#define MODE2_3_CFG_BODY_PHASE_ADD_AP_9_12_PHASE_ADD_AP10(x) (((uint32_t)(((uint32_t)(x)) << MODE2_3_CFG_BODY_PHASE_ADD_AP_9_12_PHASE_ADD_AP10_SHIFT)) & MODE2_3_CFG_BODY_PHASE_ADD_AP_9_12_PHASE_ADD_AP10_MASK)

#define MODE2_3_CFG_BODY_PHASE_ADD_AP_9_12_PHASE_ADD_AP11_MASK (0xFF0000U)
#define MODE2_3_CFG_BODY_PHASE_ADD_AP_9_12_PHASE_ADD_AP11_SHIFT (16U)
/*! PHASE_ADD_AP11 - Phase to add for Antenna Path 11 */
#define MODE2_3_CFG_BODY_PHASE_ADD_AP_9_12_PHASE_ADD_AP11(x) (((uint32_t)(((uint32_t)(x)) << MODE2_3_CFG_BODY_PHASE_ADD_AP_9_12_PHASE_ADD_AP11_SHIFT)) & MODE2_3_CFG_BODY_PHASE_ADD_AP_9_12_PHASE_ADD_AP11_MASK)

#define MODE2_3_CFG_BODY_PHASE_ADD_AP_9_12_PHASE_ADD_AP12_MASK (0xFF000000U)
#define MODE2_3_CFG_BODY_PHASE_ADD_AP_9_12_PHASE_ADD_AP12_SHIFT (24U)
/*! PHASE_ADD_AP12 - Phase to add for Antenna Path 12 */
#define MODE2_3_CFG_BODY_PHASE_ADD_AP_9_12_PHASE_ADD_AP12(x) (((uint32_t)(((uint32_t)(x)) << MODE2_3_CFG_BODY_PHASE_ADD_AP_9_12_PHASE_ADD_AP12_SHIFT)) & MODE2_3_CFG_BODY_PHASE_ADD_AP_9_12_PHASE_ADD_AP12_MASK)
/*! @} */

/*! @name PHASE_ADD_AP_13_16 - Phase to add for Antenna path 13 to 16 */
/*! @{ */

#define MODE2_3_CFG_BODY_PHASE_ADD_AP_13_16_PHASE_ADD_AP13_MASK (0xFFU)
#define MODE2_3_CFG_BODY_PHASE_ADD_AP_13_16_PHASE_ADD_AP13_SHIFT (0U)
/*! PHASE_ADD_AP13 - Phase to add for Antenna Path 13 */
#define MODE2_3_CFG_BODY_PHASE_ADD_AP_13_16_PHASE_ADD_AP13(x) (((uint32_t)(((uint32_t)(x)) << MODE2_3_CFG_BODY_PHASE_ADD_AP_13_16_PHASE_ADD_AP13_SHIFT)) & MODE2_3_CFG_BODY_PHASE_ADD_AP_13_16_PHASE_ADD_AP13_MASK)

#define MODE2_3_CFG_BODY_PHASE_ADD_AP_13_16_PHASE_ADD_AP14_MASK (0xFF00U)
#define MODE2_3_CFG_BODY_PHASE_ADD_AP_13_16_PHASE_ADD_AP14_SHIFT (8U)
/*! PHASE_ADD_AP14 - Phase to add for Antenna Path 14 */
#define MODE2_3_CFG_BODY_PHASE_ADD_AP_13_16_PHASE_ADD_AP14(x) (((uint32_t)(((uint32_t)(x)) << MODE2_3_CFG_BODY_PHASE_ADD_AP_13_16_PHASE_ADD_AP14_SHIFT)) & MODE2_3_CFG_BODY_PHASE_ADD_AP_13_16_PHASE_ADD_AP14_MASK)

#define MODE2_3_CFG_BODY_PHASE_ADD_AP_13_16_PHASE_ADD_AP15_MASK (0xFF0000U)
#define MODE2_3_CFG_BODY_PHASE_ADD_AP_13_16_PHASE_ADD_AP15_SHIFT (16U)
/*! PHASE_ADD_AP15 - Phase to add for Antenna Path 15 */
#define MODE2_3_CFG_BODY_PHASE_ADD_AP_13_16_PHASE_ADD_AP15(x) (((uint32_t)(((uint32_t)(x)) << MODE2_3_CFG_BODY_PHASE_ADD_AP_13_16_PHASE_ADD_AP15_SHIFT)) & MODE2_3_CFG_BODY_PHASE_ADD_AP_13_16_PHASE_ADD_AP15_MASK)

#define MODE2_3_CFG_BODY_PHASE_ADD_AP_13_16_PHASE_ADD_AP16_MASK (0xFF000000U)
#define MODE2_3_CFG_BODY_PHASE_ADD_AP_13_16_PHASE_ADD_AP16_SHIFT (24U)
/*! PHASE_ADD_AP16 - Phase to add for Antenna Path 16 */
#define MODE2_3_CFG_BODY_PHASE_ADD_AP_13_16_PHASE_ADD_AP16(x) (((uint32_t)(((uint32_t)(x)) << MODE2_3_CFG_BODY_PHASE_ADD_AP_13_16_PHASE_ADD_AP16_SHIFT)) & MODE2_3_CFG_BODY_PHASE_ADD_AP_13_16_PHASE_ADD_AP16_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group MODE2_3_CFG_BODY_Register_Masks */


/*!
 * @}
 */ /* end of group MODE2_3_CFG_BODY_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- MODE2_CFG_HDR Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MODE2_CFG_HDR_Peripheral_Access_Layer MODE2_CFG_HDR Peripheral Access Layer
 * @{
 */

/** MODE2_CFG_HDR - Register Layout Typedef */
typedef struct {
  __IO uint16_t CHANNEL_NUM;                       /**< Channel number for the step., offset: 0x0 */
  __IO uint16_t STEP_CFG;                          /**< Configuration for the step., offset: 0x2 */
  __IO uint16_t STEP_CFO;                          /**< CFO setting for the step, offset: 0x4 */
  __IO uint16_t HPM_CAL_FACTOR;                    /**< HPM CAL factor to apply for the step., offset: 0x6 */
  __IO uint32_t CTUNE_MANUAL;                      /**< CTUNE manual to inject for the step., offset: 0x8 */
} MODE2_CFG_HDR_Type;

/* ----------------------------------------------------------------------------
   -- MODE2_CFG_HDR Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MODE2_CFG_HDR_Register_Masks MODE2_CFG_HDR Register Masks
 * @{
 */

/*! @name CHANNEL_NUM - Channel number for the step. */
/*! @{ */

#define MODE2_CFG_HDR_CHANNEL_NUM_CHANNEL_NUM_MASK (0xFFFFU)
#define MODE2_CFG_HDR_CHANNEL_NUM_CHANNEL_NUM_SHIFT (0U)
/*! CHANNEL_NUM - Channel number for the step. */
#define MODE2_CFG_HDR_CHANNEL_NUM_CHANNEL_NUM(x) (((uint16_t)(((uint16_t)(x)) << MODE2_CFG_HDR_CHANNEL_NUM_CHANNEL_NUM_SHIFT)) & MODE2_CFG_HDR_CHANNEL_NUM_CHANNEL_NUM_MASK)
/*! @} */

/*! @name STEP_CFG - Configuration for the step. */
/*! @{ */

#define MODE2_CFG_HDR_STEP_CFG_MODE_MASK         (0x3U)
#define MODE2_CFG_HDR_STEP_CFG_MODE_SHIFT        (0U)
/*! MODE - Mode for the step
 *  0b00..Frequency Compensation Step (Mode 0)
 *  0b01..Pk-Pk step (Mode 1)
 *  0b10..Tn-Tn step (Mode 2)
 *  0b11..Pk-Tn-Tn-Pk step (Mode 3)
 */
#define MODE2_CFG_HDR_STEP_CFG_MODE(x)           (((uint16_t)(((uint16_t)(x)) << MODE2_CFG_HDR_STEP_CFG_MODE_SHIFT)) & MODE2_CFG_HDR_STEP_CFG_MODE_MASK)

#define MODE2_CFG_HDR_STEP_CFG_TONE_EXT_MASK     (0xCU)
#define MODE2_CFG_HDR_STEP_CFG_TONE_EXT_SHIFT    (2U)
/*! TONE_EXT - Choice of tone extension for the initiator portion of the step.
 *  0b00..Tone extension is not present for either role TX.
 *  0b01..Tone extension is present for initiator TX only.
 *  0b10..Tone extension is present for reflector TX only.
 *  0b11..Tone extension is present for both roles TX.
 */
#define MODE2_CFG_HDR_STEP_CFG_TONE_EXT(x)       (((uint16_t)(((uint16_t)(x)) << MODE2_CFG_HDR_STEP_CFG_TONE_EXT_SHIFT)) & MODE2_CFG_HDR_STEP_CFG_TONE_EXT_MASK)

#define MODE2_CFG_HDR_STEP_CFG_ANT_PERMUT_MASK   (0x1F0U)
#define MODE2_CFG_HDR_STEP_CFG_ANT_PERMUT_SHIFT  (4U)
/*! ANT_PERMUT - Antenna permutation pattern for the step. */
#define MODE2_CFG_HDR_STEP_CFG_ANT_PERMUT(x)     (((uint16_t)(((uint16_t)(x)) << MODE2_CFG_HDR_STEP_CFG_ANT_PERMUT_SHIFT)) & MODE2_CFG_HDR_STEP_CFG_ANT_PERMUT_MASK)

#define MODE2_CFG_HDR_STEP_CFG_ANT_CS_SYNC_MASK  (0x600U)
#define MODE2_CFG_HDR_STEP_CFG_ANT_CS_SYNC_SHIFT (9U)
/*! ANT_CS_SYNC - Antenna cs Sync */
#define MODE2_CFG_HDR_STEP_CFG_ANT_CS_SYNC(x)    (((uint16_t)(((uint16_t)(x)) << MODE2_CFG_HDR_STEP_CFG_ANT_CS_SYNC_SHIFT)) & MODE2_CFG_HDR_STEP_CFG_ANT_CS_SYNC_MASK)

#define MODE2_CFG_HDR_STEP_CFG_EP_ONE_WAY_MASK   (0x800U)
#define MODE2_CFG_HDR_STEP_CFG_EP_ONE_WAY_SHIFT  (11U)
/*! EP_ONE_WAY - One way ranging? */
#define MODE2_CFG_HDR_STEP_CFG_EP_ONE_WAY(x)     (((uint16_t)(((uint16_t)(x)) << MODE2_CFG_HDR_STEP_CFG_EP_ONE_WAY_SHIFT)) & MODE2_CFG_HDR_STEP_CFG_EP_ONE_WAY_MASK)

#define MODE2_CFG_HDR_STEP_CFG_T_PM_SEL_MASK     (0x1000U)
#define MODE2_CFG_HDR_STEP_CFG_T_PM_SEL_SHIFT    (12U)
/*! T_PM_SEL - Selection of T_PM choices. */
#define MODE2_CFG_HDR_STEP_CFG_T_PM_SEL(x)       (((uint16_t)(((uint16_t)(x)) << MODE2_CFG_HDR_STEP_CFG_T_PM_SEL_SHIFT)) & MODE2_CFG_HDR_STEP_CFG_T_PM_SEL_MASK)
/*! @} */

/*! @name STEP_CFO - CFO setting for the step */
/*! @{ */

#define MODE2_CFG_HDR_STEP_CFO_STEP_CFO_MASK     (0xFFFFU)
#define MODE2_CFG_HDR_STEP_CFO_STEP_CFO_SHIFT    (0U)
/*! STEP_CFO - CFO setting for the step. */
#define MODE2_CFG_HDR_STEP_CFO_STEP_CFO(x)       (((uint16_t)(((uint16_t)(x)) << MODE2_CFG_HDR_STEP_CFO_STEP_CFO_SHIFT)) & MODE2_CFG_HDR_STEP_CFO_STEP_CFO_MASK)
/*! @} */

/*! @name HPM_CAL_FACTOR - HPM CAL factor to apply for the step. */
/*! @{ */

#define MODE2_CFG_HDR_HPM_CAL_FACTOR_HPM_CAL_FACTOR_MASK (0xFFFU)
#define MODE2_CFG_HDR_HPM_CAL_FACTOR_HPM_CAL_FACTOR_SHIFT (0U)
/*! HPM_CAL_FACTOR - HPM CAL factor to apply for the step */
#define MODE2_CFG_HDR_HPM_CAL_FACTOR_HPM_CAL_FACTOR(x) (((uint16_t)(((uint16_t)(x)) << MODE2_CFG_HDR_HPM_CAL_FACTOR_HPM_CAL_FACTOR_SHIFT)) & MODE2_CFG_HDR_HPM_CAL_FACTOR_HPM_CAL_FACTOR_MASK)
/*! @} */

/*! @name CTUNE_MANUAL - CTUNE manual to inject for the step. */
/*! @{ */

#define MODE2_CFG_HDR_CTUNE_MANUAL_CTUNE_MANUAL_MASK (0x1FFU)
#define MODE2_CFG_HDR_CTUNE_MANUAL_CTUNE_MANUAL_SHIFT (0U)
/*! CTUNE_MANUAL - CTUNE manual to inject for the step. */
#define MODE2_CFG_HDR_CTUNE_MANUAL_CTUNE_MANUAL(x) (((uint32_t)(((uint32_t)(x)) << MODE2_CFG_HDR_CTUNE_MANUAL_CTUNE_MANUAL_SHIFT)) & MODE2_CFG_HDR_CTUNE_MANUAL_CTUNE_MANUAL_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group MODE2_CFG_HDR_Register_Masks */


/*!
 * @}
 */ /* end of group MODE2_CFG_HDR_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- PAYLOAD_CFG_BODY Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PAYLOAD_CFG_BODY_Peripheral_Access_Layer PAYLOAD_CFG_BODY Peripheral Access Layer
 * @{
 */

/** PAYLOAD_CFG_BODY - Register Layout Typedef */
typedef struct {
  __IO uint32_t AA_INIT;                           /**< Access address used for the Initiator transmission phase, offset: 0x0 */
  __IO uint32_t AA_REF;                            /**< Access address used for the reflector transmission phase, offset: 0x4 */
  struct {                                         /* offset: 0x8, array step: 0x8 */
    __IO uint32_t INIT;                              /**< 32bit word of payload for the initiator for the step., array offset: 0x8, array step: 0x8 */
    __IO uint32_t REFL;                              /**< 32bit word of payload for the reflector for the step., array offset: 0xC, array step: 0x8 */
  } PAYLOAD[4];
} PAYLOAD_CFG_BODY_Type;

/* ----------------------------------------------------------------------------
   -- PAYLOAD_CFG_BODY Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PAYLOAD_CFG_BODY_Register_Masks PAYLOAD_CFG_BODY Register Masks
 * @{
 */

/*! @name AA_INIT - Access address used for the Initiator transmission phase */
/*! @{ */

#define PAYLOAD_CFG_BODY_AA_INIT_AA_INIT_MASK    (0xFFFFFFFFU)
#define PAYLOAD_CFG_BODY_AA_INIT_AA_INIT_SHIFT   (0U)
/*! AA_INIT - Access address sent during Initiator transmission phase (first half step). */
#define PAYLOAD_CFG_BODY_AA_INIT_AA_INIT(x)      (((uint32_t)(((uint32_t)(x)) << PAYLOAD_CFG_BODY_AA_INIT_AA_INIT_SHIFT)) & PAYLOAD_CFG_BODY_AA_INIT_AA_INIT_MASK)
/*! @} */

/*! @name AA_REF - Access address used for the reflector transmission phase */
/*! @{ */

#define PAYLOAD_CFG_BODY_AA_REF_AA_REF_MASK      (0xFFFFFFFFU)
#define PAYLOAD_CFG_BODY_AA_REF_AA_REF_SHIFT     (0U)
/*! AA_REF - Access address sent during Reflector transmission phase (first half step). */
#define PAYLOAD_CFG_BODY_AA_REF_AA_REF(x)        (((uint32_t)(((uint32_t)(x)) << PAYLOAD_CFG_BODY_AA_REF_AA_REF_SHIFT)) & PAYLOAD_CFG_BODY_AA_REF_AA_REF_MASK)
/*! @} */

/*! @name INIT - 32bit word of payload for the initiator for the step. */
/*! @{ */

#define PAYLOAD_CFG_BODY_INIT_PLD_MASK           (0xFFFFFFFFU)
#define PAYLOAD_CFG_BODY_INIT_PLD_SHIFT          (0U)
/*! PLD - One payload word. */
#define PAYLOAD_CFG_BODY_INIT_PLD(x)             (((uint32_t)(((uint32_t)(x)) << PAYLOAD_CFG_BODY_INIT_PLD_SHIFT)) & PAYLOAD_CFG_BODY_INIT_PLD_MASK)
/*! @} */

/* The count of PAYLOAD_CFG_BODY_INIT */
#define PAYLOAD_CFG_BODY_INIT_COUNT              (4U)

/*! @name REFL - 32bit word of payload for the reflector for the step. */
/*! @{ */

#define PAYLOAD_CFG_BODY_REFL_PLD_MASK           (0xFFFFFFFFU)
#define PAYLOAD_CFG_BODY_REFL_PLD_SHIFT          (0U)
/*! PLD - One payload word. */
#define PAYLOAD_CFG_BODY_REFL_PLD(x)             (((uint32_t)(((uint32_t)(x)) << PAYLOAD_CFG_BODY_REFL_PLD_SHIFT)) & PAYLOAD_CFG_BODY_REFL_PLD_MASK)
/*! @} */

/* The count of PAYLOAD_CFG_BODY_REFL */
#define PAYLOAD_CFG_BODY_REFL_COUNT              (4U)


/*!
 * @}
 */ /* end of group PAYLOAD_CFG_BODY_Register_Masks */


/*!
 * @}
 */ /* end of group PAYLOAD_CFG_BODY_Peripheral_Access_Layer */


/*
** End of section using anonymous unions
*/

// #error Not supported compiler type

/*!
 * @}
 */ /* end of group Peripheral_access_layer */

#else
/* KW47 PKT RAM step CONFIG and RESULT structures */

/*!
 * @addtogroup Peripheral_access_layer Device Peripheral Access Layer
 * @{
 */


/*
** Start of section using anonymous unions
*/

// #error Not supported compiler type

/* ----------------------------------------------------------------------------
   -- COM_MODE_013_CFG_HDR Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup COM_MODE_013_CFG_HDR_Peripheral_Access_Layer COM_MODE_013_CFG_HDR Peripheral Access Layer
 * @{
 */

/** COM_MODE_013_CFG_HDR - Register Layout Typedef */
typedef struct {
  __IO uint16_t CHANNEL_NUM;                       /**< Channel number for the step., offset: 0x0 */
  __IO uint16_t STEP_CFG;                          /**< Configuration for the step., offset: 0x2 */
  __IO uint16_t STEP_CFO;                          /**< CFO setting for the step, offset: 0x4 */
  __IO uint16_t HPM_CAL_FACTOR;                    /**< HPM CAL factor to apply for the step., offset: 0x6 */
  __IO uint16_t CTUNE_MANUAL;                      /**< CTUNE manual to inject for the step., offset: 0x8 */
  __IO uint16_t PHASE_ADD;                         /**< Phase adder for the step., offset: 0xA */
  __IO uint32_t AA_INIT;                           /**< Access address for the initiator (first half step)., offset: 0xC */
  __IO uint32_t AA_REFL;                           /**< Access address for the reflector (second half step)., offset: 0x10 */
} COM_MODE_013_CFG_HDR_Type;

/* ----------------------------------------------------------------------------
   -- COM_MODE_013_CFG_HDR Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup COM_MODE_013_CFG_HDR_Register_Masks COM_MODE_013_CFG_HDR Register Masks
 * @{
 */

/*! @name CHANNEL_NUM - Channel number for the step. */
/*! @{ */

#define COM_MODE_013_CFG_HDR_CHANNEL_NUM_CHANNEL_NUM_MASK (0xFFFFU)
#define COM_MODE_013_CFG_HDR_CHANNEL_NUM_CHANNEL_NUM_SHIFT (0U)
/*! CHANNEL_NUM - Channel number for the step. */
#define COM_MODE_013_CFG_HDR_CHANNEL_NUM_CHANNEL_NUM(x) (((uint16_t)(((uint16_t)(x)) << COM_MODE_013_CFG_HDR_CHANNEL_NUM_CHANNEL_NUM_SHIFT)) & COM_MODE_013_CFG_HDR_CHANNEL_NUM_CHANNEL_NUM_MASK)
/*! @} */

/*! @name STEP_CFG - Configuration for the step. */
/*! @{ */

#define COM_MODE_013_CFG_HDR_STEP_CFG_MODE_MASK  (0x3U)
#define COM_MODE_013_CFG_HDR_STEP_CFG_MODE_SHIFT (0U)
/*! MODE - Mode for the step
 *  0b00..Frequency Compensation Step (Mode 0)
 *  0b01..Pk-Pk step (Mode 1)
 *  0b10..Tn-Tn step (Mode 2)
 *  0b11..Pk-Tn-Tn-Pk step (Mode 3)
 */
#define COM_MODE_013_CFG_HDR_STEP_CFG_MODE(x)    (((uint16_t)(((uint16_t)(x)) << COM_MODE_013_CFG_HDR_STEP_CFG_MODE_SHIFT)) & COM_MODE_013_CFG_HDR_STEP_CFG_MODE_MASK)

#define COM_MODE_013_CFG_HDR_STEP_CFG_TONE_EXT_MASK (0xCU)
#define COM_MODE_013_CFG_HDR_STEP_CFG_TONE_EXT_SHIFT (2U)
/*! TONE_EXT - Choice of tone extension for the initiator portion of the step.
 *  0b00..Tone extension is not present for either role TX.
 *  0b01..Tone extension is present for initiator TX only.
 *  0b10..Tone extension is present for reflector TX only.
 *  0b11..Tone extension is present for both roles TX.
 */
#define COM_MODE_013_CFG_HDR_STEP_CFG_TONE_EXT(x) (((uint16_t)(((uint16_t)(x)) << COM_MODE_013_CFG_HDR_STEP_CFG_TONE_EXT_SHIFT)) & COM_MODE_013_CFG_HDR_STEP_CFG_TONE_EXT_MASK)

#define COM_MODE_013_CFG_HDR_STEP_CFG_ANT_PERMUT_MASK (0x1F0U)
#define COM_MODE_013_CFG_HDR_STEP_CFG_ANT_PERMUT_SHIFT (4U)
/*! ANT_PERMUT - Antenna permutation pattern for the step. */
#define COM_MODE_013_CFG_HDR_STEP_CFG_ANT_PERMUT(x) (((uint16_t)(((uint16_t)(x)) << COM_MODE_013_CFG_HDR_STEP_CFG_ANT_PERMUT_SHIFT)) & COM_MODE_013_CFG_HDR_STEP_CFG_ANT_PERMUT_MASK)

#define COM_MODE_013_CFG_HDR_STEP_CFG_ANT_CS_SYNC_MASK (0x600U)
#define COM_MODE_013_CFG_HDR_STEP_CFG_ANT_CS_SYNC_SHIFT (9U)
/*! ANT_CS_SYNC - Antenna cs Sync */
#define COM_MODE_013_CFG_HDR_STEP_CFG_ANT_CS_SYNC(x) (((uint16_t)(((uint16_t)(x)) << COM_MODE_013_CFG_HDR_STEP_CFG_ANT_CS_SYNC_SHIFT)) & COM_MODE_013_CFG_HDR_STEP_CFG_ANT_CS_SYNC_MASK)

#define COM_MODE_013_CFG_HDR_STEP_CFG_EP_ONE_WAY_MASK (0x800U)
#define COM_MODE_013_CFG_HDR_STEP_CFG_EP_ONE_WAY_SHIFT (11U)
/*! EP_ONE_WAY - One way ranging? */
#define COM_MODE_013_CFG_HDR_STEP_CFG_EP_ONE_WAY(x) (((uint16_t)(((uint16_t)(x)) << COM_MODE_013_CFG_HDR_STEP_CFG_EP_ONE_WAY_SHIFT)) & COM_MODE_013_CFG_HDR_STEP_CFG_EP_ONE_WAY_MASK)

#define COM_MODE_013_CFG_HDR_STEP_CFG_T_PM_SEL_MASK (0x1000U)
#define COM_MODE_013_CFG_HDR_STEP_CFG_T_PM_SEL_SHIFT (12U)
/*! T_PM_SEL - Selection of T_PM choices. */
#define COM_MODE_013_CFG_HDR_STEP_CFG_T_PM_SEL(x) (((uint16_t)(((uint16_t)(x)) << COM_MODE_013_CFG_HDR_STEP_CFG_T_PM_SEL_SHIFT)) & COM_MODE_013_CFG_HDR_STEP_CFG_T_PM_SEL_MASK)
/*! @} */

/*! @name STEP_CFO - CFO setting for the step */
/*! @{ */

#define COM_MODE_013_CFG_HDR_STEP_CFO_STEP_CFO_MASK (0xFFFFU)
#define COM_MODE_013_CFG_HDR_STEP_CFO_STEP_CFO_SHIFT (0U)
/*! STEP_CFO - CFO setting for the step. */
#define COM_MODE_013_CFG_HDR_STEP_CFO_STEP_CFO(x) (((uint16_t)(((uint16_t)(x)) << COM_MODE_013_CFG_HDR_STEP_CFO_STEP_CFO_SHIFT)) & COM_MODE_013_CFG_HDR_STEP_CFO_STEP_CFO_MASK)
/*! @} */

/*! @name HPM_CAL_FACTOR - HPM CAL factor to apply for the step. */
/*! @{ */

#define COM_MODE_013_CFG_HDR_HPM_CAL_FACTOR_HPM_CAL_FACTOR_MASK (0xFFFU)
#define COM_MODE_013_CFG_HDR_HPM_CAL_FACTOR_HPM_CAL_FACTOR_SHIFT (0U)
/*! HPM_CAL_FACTOR - HPM CAL factor to apply for the step */
#define COM_MODE_013_CFG_HDR_HPM_CAL_FACTOR_HPM_CAL_FACTOR(x) (((uint16_t)(((uint16_t)(x)) << COM_MODE_013_CFG_HDR_HPM_CAL_FACTOR_HPM_CAL_FACTOR_SHIFT)) & COM_MODE_013_CFG_HDR_HPM_CAL_FACTOR_HPM_CAL_FACTOR_MASK)
/*! @} */

/*! @name CTUNE_MANUAL - CTUNE manual to inject for the step. */
/*! @{ */

#define COM_MODE_013_CFG_HDR_CTUNE_MANUAL_CTUNE_MANUAL_MASK (0x1FFU)
#define COM_MODE_013_CFG_HDR_CTUNE_MANUAL_CTUNE_MANUAL_SHIFT (0U)
/*! CTUNE_MANUAL - CTUNE manual to inject for the step. */
#define COM_MODE_013_CFG_HDR_CTUNE_MANUAL_CTUNE_MANUAL(x) (((uint16_t)(((uint16_t)(x)) << COM_MODE_013_CFG_HDR_CTUNE_MANUAL_CTUNE_MANUAL_SHIFT)) & COM_MODE_013_CFG_HDR_CTUNE_MANUAL_CTUNE_MANUAL_MASK)
/*! @} */

/*! @name PHASE_ADD - Phase adder for the step. */
/*! @{ */

#define COM_MODE_013_CFG_HDR_PHASE_ADD_PHASE_ADD_MASK (0xFFU)
#define COM_MODE_013_CFG_HDR_PHASE_ADD_PHASE_ADD_SHIFT (0U)
/*! PHASE_ADD - Phase adder for the step. */
#define COM_MODE_013_CFG_HDR_PHASE_ADD_PHASE_ADD(x) (((uint16_t)(((uint16_t)(x)) << COM_MODE_013_CFG_HDR_PHASE_ADD_PHASE_ADD_SHIFT)) & COM_MODE_013_CFG_HDR_PHASE_ADD_PHASE_ADD_MASK)
/*! @} */

/*! @name AA_INIT - Access address for the initiator (first half step). */
/*! @{ */

#define COM_MODE_013_CFG_HDR_AA_INIT_AA_INIT_MASK (0xFFFFFFFFU)
#define COM_MODE_013_CFG_HDR_AA_INIT_AA_INIT_SHIFT (0U)
/*! AA_INIT - Access Address. */
#define COM_MODE_013_CFG_HDR_AA_INIT_AA_INIT(x)  (((uint32_t)(((uint32_t)(x)) << COM_MODE_013_CFG_HDR_AA_INIT_AA_INIT_SHIFT)) & COM_MODE_013_CFG_HDR_AA_INIT_AA_INIT_MASK)
/*! @} */

/*! @name AA_REFL - Access address for the reflector (second half step). */
/*! @{ */

#define COM_MODE_013_CFG_HDR_AA_REFL_AA_REFL_MASK (0xFFFFFFFFU)
#define COM_MODE_013_CFG_HDR_AA_REFL_AA_REFL_SHIFT (0U)
/*! AA_REFL - Access Address. */
#define COM_MODE_013_CFG_HDR_AA_REFL_AA_REFL(x)  (((uint32_t)(((uint32_t)(x)) << COM_MODE_013_CFG_HDR_AA_REFL_AA_REFL_SHIFT)) & COM_MODE_013_CFG_HDR_AA_REFL_AA_REFL_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group COM_MODE_013_CFG_HDR_Register_Masks */


/*!
 * @}
 */ /* end of group COM_MODE_013_CFG_HDR_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- COM_MODE_013_RES_BODY Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup COM_MODE_013_RES_BODY_Peripheral_Access_Layer COM_MODE_013_RES_BODY Peripheral Access Layer
 * @{
 */

/** COM_MODE_013_RES_BODY - Register Layout Typedef */
typedef struct {
  __IO uint32_t NADM_ERROR_RSSI;                   /**< Raw NADM or Payload Error and RSSI for the step., offset: 0x0 */
  __IO uint32_t RTT_RESULT;                        /**< Results reported from the PHY RTT block for the step., offset: 0x4 */
  __IO uint32_t CFO_EST;                           /**< CFO estimate for the step., offset: 0x8 */
  __IO uint32_t TIMESTAMP;                         /**< TPM module timestamp for the step., offset: 0xC */
} COM_MODE_013_RES_BODY_Type;

/* ----------------------------------------------------------------------------
   -- COM_MODE_013_RES_BODY Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup COM_MODE_013_RES_BODY_Register_Masks COM_MODE_013_RES_BODY Register Masks
 * @{
 */

/*! @name NADM_ERROR_RSSI - Raw NADM or Payload Error and RSSI for the step. */
/*! @{ */

#define COM_MODE_013_RES_BODY_NADM_ERROR_RSSI_RSSI_NB_MASK (0xFFU)
#define COM_MODE_013_RES_BODY_NADM_ERROR_RSSI_RSSI_NB_SHIFT (0U)
/*! RSSI_NB - Narrowband RSSI measured for the step. 8-bit signedformat. */
#define COM_MODE_013_RES_BODY_NADM_ERROR_RSSI_RSSI_NB(x) (((uint32_t)(((uint32_t)(x)) << COM_MODE_013_RES_BODY_NADM_ERROR_RSSI_RSSI_NB_SHIFT)) & COM_MODE_013_RES_BODY_NADM_ERROR_RSSI_RSSI_NB_MASK)

#define COM_MODE_013_RES_BODY_NADM_ERROR_RSSI_RAW_NADM_FM_CORR_VALUE_MASK (0xFF00U)
#define COM_MODE_013_RES_BODY_NADM_ERROR_RSSI_RAW_NADM_FM_CORR_VALUE_SHIFT (8U)
/*! NADM_FM_CORR_VALUE - NADM FM correlator value */
#define COM_MODE_013_RES_BODY_NADM_ERROR_RSSI_RAW_NADM_FM_CORR_VALUE(x) (((uint32_t)(((uint32_t)(x)) << COM_MODE_013_RES_BODY_NADM_ERROR_RSSI_NADM_FM_CORR_VALUE_SHIFT)) & COM_MODE_013_RES_BODY_NADM_ERROR_RSSI_NADM_FM_CORR_VALUE_MASK)

#define COM_MODE_013_RES_BODY_NADM_ERROR_RSSI_RAW_NADM_FM_CORR_VALID_MASK (0x10000U)
#define COM_MODE_013_RES_BODY_NADM_ERROR_RSSI_RAW_NADM_FM_CORR_VALID_SHIFT (16U)
/*! NADM_FM_CORR_VALID - NADM FM correlator valid flag */
#define COM_MODE_013_RES_BODY_NADM_ERROR_RSSI_RAW_NADM_FM_CORR_VALID(x) (((uint32_t)(((uint32_t)(x)) << COM_MODE_013_RES_BODY_NADM_ERROR_RSSI_NADM_FM_CORR_VALID_SHIFT)) & COM_MODE_013_RES_BODY_NADM_ERROR_RSSI_NADM_FM_CORR_VALID_MASK)

#define COM_MODE_013_RES_BODY_NADM_ERROR_RSSI_RAW_NADM_FM_SYMB_ERR_VALUE_MASK (0x1E0000U)
#define COM_MODE_013_RES_BODY_NADM_ERROR_RSSI_RAW_NADM_FM_SYMB_ERR_VALUE_SHIFT (17U)
/*! NADM_FM_SYMB_ERR_VALUE - NADM FM symbol error value */
#define COM_MODE_013_RES_BODY_NADM_ERROR_RSSI_RAW_NADM_FM_SYMB_ERR_VALUE(x) (((uint32_t)(((uint32_t)(x)) << COM_MODE_013_RES_BODY_NADM_ERROR_RSSI_NADM_FM_SYMB_ERR_VALUE_SHIFT)) & COM_MODE_013_RES_BODY_NADM_ERROR_RSSI_NADM_FM_SYMB_ERR_VALUE_MASK)

#define COM_MODE_013_RES_BODY_NADM_ERROR_RSSI_RAW_NADM_FM_SYMB_ERR_VALID_MASK (0x200000U)
#define COM_MODE_013_RES_BODY_NADM_ERROR_RSSI_RAW_NADM_FM_SYMB_ERR_VALID_SHIFT (21U)
/*! NADM_FM_SYMB_ERR_VALID - NADM FM symbol error valid flag */
#define COM_MODE_013_RES_BODY_NADM_ERROR_RSSI_RAW_NADM_FM_SYMB_ERR_VALID(x) (((uint32_t)(((uint32_t)(x)) << COM_MODE_013_RES_BODY_NADM_ERROR_RSSI_NADM_FM_SYMB_ERR_VALID_SHIFT)) & COM_MODE_013_RES_BODY_NADM_ERROR_RSSI_NADM_FM_SYMB_ERR_VALID_MASK)

#define COM_MODE_013_RES_BODY_NADM_ERROR_RSSI_RAW_NADM_PDELTA_MASK (0xFFC00000U)
#define COM_MODE_013_RES_BODY_NADM_ERROR_RSSI_RAW_NADM_PDELTA_SHIFT (22U)
/*! NADM_PDELTA - NADM pdelta value */
#define COM_MODE_013_RES_BODY_NADM_ERROR_RSSI_RAW_NADM_PDELTA(x) (((uint32_t)(((uint32_t)(x)) << COM_MODE_013_RES_BODY_NADM_ERROR_RSSI_NADM_PDELTA_SHIFT)) & COM_MODE_013_RES_BODY_NADM_ERROR_RSSI_NADM_PDELTA_MASK)
/*! @} */

/*! @name RTT_RESULT - Results reported from the PHY RTT block for the step. */
/*! @{ */

#define COM_MODE_013_RES_BODY_RTT_RESULT_RTT_VLD_MASK (0x1U)
#define COM_MODE_013_RES_BODY_RTT_RESULT_RTT_VLD_SHIFT (0U)
/*! RTT_VLD - RTT valid status. */
#define COM_MODE_013_RES_BODY_RTT_RESULT_RTT_VLD(x) (((uint32_t)(((uint32_t)(x)) << COM_MODE_013_RES_BODY_RTT_RESULT_RTT_VLD_SHIFT)) & COM_MODE_013_RES_BODY_RTT_RESULT_RTT_VLD_MASK)

#define COM_MODE_013_RES_BODY_RTT_RESULT_RTT_FOUND_MASK (0x2U)
#define COM_MODE_013_RES_BODY_RTT_RESULT_RTT_FOUND_SHIFT (1U)
/*! RTT_FOUND - RTT found status. */
#define COM_MODE_013_RES_BODY_RTT_RESULT_RTT_FOUND(x) (((uint32_t)(((uint32_t)(x)) << COM_MODE_013_RES_BODY_RTT_RESULT_RTT_FOUND_SHIFT)) & COM_MODE_013_RES_BODY_RTT_RESULT_RTT_FOUND_MASK)

#define COM_MODE_013_RES_BODY_RTT_RESULT_RTT_CFO_MASK (0x3FFFCU)
#define COM_MODE_013_RES_BODY_RTT_RESULT_RTT_CFO_SHIFT (2U)
/*! RTT_CFO - RTT Carrier Frequency Offset (CFO) result. */
#define COM_MODE_013_RES_BODY_RTT_RESULT_RTT_CFO(x) (((uint32_t)(((uint32_t)(x)) << COM_MODE_013_RES_BODY_RTT_RESULT_RTT_CFO_SHIFT)) & COM_MODE_013_RES_BODY_RTT_RESULT_RTT_CFO_MASK)

#define COM_MODE_013_RES_BODY_RTT_RESULT_RTT_INT_ADJ_MASK (0xC0000U)
#define COM_MODE_013_RES_BODY_RTT_RESULT_RTT_INT_ADJ_SHIFT (18U)
/*! RTT_INT_ADJ - Integer adjustment reported from the RTT result. */
#define COM_MODE_013_RES_BODY_RTT_RESULT_RTT_INT_ADJ(x) (((uint32_t)(((uint32_t)(x)) << COM_MODE_013_RES_BODY_RTT_RESULT_RTT_INT_ADJ_SHIFT)) & COM_MODE_013_RES_BODY_RTT_RESULT_RTT_INT_ADJ_MASK)

#define COM_MODE_013_RES_BODY_RTT_RESULT_RTT_HAM_DIST_SAT_MASK (0x300000U)
#define COM_MODE_013_RES_BODY_RTT_RESULT_RTT_HAM_DIST_SAT_SHIFT (20U)
/*! RTT_HAM_DIST_SAT - Hamming Distance Saturation from the RTT result. */
#define COM_MODE_013_RES_BODY_RTT_RESULT_RTT_HAM_DIST_SAT(x) (((uint32_t)(((uint32_t)(x)) << COM_MODE_013_RES_BODY_RTT_RESULT_RTT_HAM_DIST_SAT_SHIFT)) & COM_MODE_013_RES_BODY_RTT_RESULT_RTT_HAM_DIST_SAT_MASK)

#define COM_MODE_013_RES_BODY_RTT_RESULT_RTT_P_DELTA_MASK (0xFFC00000U)
#define COM_MODE_013_RES_BODY_RTT_RESULT_RTT_P_DELTA_SHIFT (22U)
/*! RTT_P_DELTA - P-delta value from the RTT result. */
#define COM_MODE_013_RES_BODY_RTT_RESULT_RTT_P_DELTA(x) (((uint32_t)(((uint32_t)(x)) << COM_MODE_013_RES_BODY_RTT_RESULT_RTT_P_DELTA_SHIFT)) & COM_MODE_013_RES_BODY_RTT_RESULT_RTT_P_DELTA_MASK)
/*! @} */

/*! @name CFO_EST - CFO estimate for the step. */
/*! @{ */

#define COM_MODE_013_RES_BODY_CFO_EST_CFO_EST_MASK (0x3FFU)
#define COM_MODE_013_RES_BODY_CFO_EST_CFO_EST_SHIFT (0U)
/*! CFO_EST - Carrier Frequency Offset estimate for the step. Signed 10-bit format. */
#define COM_MODE_013_RES_BODY_CFO_EST_CFO_EST(x) (((uint32_t)(((uint32_t)(x)) << COM_MODE_013_RES_BODY_CFO_EST_CFO_EST_SHIFT)) & COM_MODE_013_RES_BODY_CFO_EST_CFO_EST_MASK)
/*! @} */

/*! @name TIMESTAMP - TPM module timestamp for the step. */
/*! @{ */

#define COM_MODE_013_RES_BODY_TIMESTAMP_TPM_MASK (0xFFFFFFFFU)
#define COM_MODE_013_RES_BODY_TIMESTAMP_TPM_SHIFT (0U)
/*! TPM - Timestamp for the step. */
#define COM_MODE_013_RES_BODY_TIMESTAMP_TPM(x)   (((uint32_t)(((uint32_t)(x)) << COM_MODE_013_RES_BODY_TIMESTAMP_TPM_SHIFT)) & COM_MODE_013_RES_BODY_TIMESTAMP_TPM_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group COM_MODE_013_RES_BODY_Register_Masks */


/*!
 * @}
 */ /* end of group COM_MODE_013_RES_BODY_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- COM_RES_HDR Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup COM_RES_HDR_Peripheral_Access_Layer COM_RES_HDR Peripheral Access Layer
 * @{
 */

/** COM_RES_HDR - Register Layout Typedef */
typedef struct {
  __IO uint8_t STEP_ID;                            /**< STEP_ID for the step., offset: 0x0 */
  __IO uint8_t SIZE_AGC_IDX;                       /**< Result size and AGC index for the step., offset: 0x1 */
  __IO uint16_t PBCD_CTUNE_AA_DET;                 /**< PBCD or CTUNE and AA detection status for the step, offset: 0x2 */
} COM_RES_HDR_Type;

/* ----------------------------------------------------------------------------
   -- COM_RES_HDR Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup COM_RES_HDR_Register_Masks COM_RES_HDR Register Masks
 * @{
 */

/*! @name STEP_ID - STEP_ID for the step. */
/*! @{ */

#define COM_RES_HDR_STEP_ID_STEP_ID_MASK         (0xFFU)
#define COM_RES_HDR_STEP_ID_STEP_ID_SHIFT        (0U)
/*! STEP_ID - STEP_ID for the step. */
#define COM_RES_HDR_STEP_ID_STEP_ID(x)           (((uint8_t)(((uint8_t)(x)) << COM_RES_HDR_STEP_ID_STEP_ID_SHIFT)) & COM_RES_HDR_STEP_ID_STEP_ID_MASK)
/*! @} */

/*! @name SIZE_AGC_IDX - Result size and AGC index for the step. */
/*! @{ */

#define COM_RES_HDR_SIZE_AGC_IDX_RESULT_SIZE_MASK (0xFU)
#define COM_RES_HDR_SIZE_AGC_IDX_RESULT_SIZE_SHIFT (0U)
/*! RESULT_SIZE - Result length for the step. */
#define COM_RES_HDR_SIZE_AGC_IDX_RESULT_SIZE(x)  (((uint8_t)(((uint8_t)(x)) << COM_RES_HDR_SIZE_AGC_IDX_RESULT_SIZE_SHIFT)) & COM_RES_HDR_SIZE_AGC_IDX_RESULT_SIZE_MASK)

#define COM_RES_HDR_SIZE_AGC_IDX_AGC_IDX_MASK    (0xF0U)
#define COM_RES_HDR_SIZE_AGC_IDX_AGC_IDX_SHIFT   (4U)
/*! AGC_IDX - AGC Index reported for the step. */
#define COM_RES_HDR_SIZE_AGC_IDX_AGC_IDX(x)      (((uint8_t)(((uint8_t)(x)) << COM_RES_HDR_SIZE_AGC_IDX_AGC_IDX_SHIFT)) & COM_RES_HDR_SIZE_AGC_IDX_AGC_IDX_MASK)
/*! @} */

/*! @name PBCD_CTUNE_AA_DET - PBCD or CTUNE and AA detection status for the step */
/*! @{ */

#define COM_RES_HDR_PBCD_CTUNE_AA_DET_PBCD_CTUNE_MASK (0x1FFU)
#define COM_RES_HDR_PBCD_CTUNE_AA_DET_PBCD_CTUNE_SHIFT (0U)
/*! PBCD_CTUNE - PBCD or CTUNE for the step. */
#define COM_RES_HDR_PBCD_CTUNE_AA_DET_PBCD_CTUNE(x) (((uint16_t)(((uint16_t)(x)) << COM_RES_HDR_PBCD_CTUNE_AA_DET_PBCD_CTUNE_SHIFT)) & COM_RES_HDR_PBCD_CTUNE_AA_DET_PBCD_CTUNE_MASK)

#define COM_RES_HDR_PBCD_CTUNE_AA_DET_TIME_DRIFT_MASK (0x3000U)
#define COM_RES_HDR_PBCD_CTUNE_AA_DET_TIME_DRIFT_SHIFT (12U)
/*! TIME_DRIFT - TIME DRIFT delta value
 *  0b00..0 us
 *  0b01..+1us
 *  0b11..-1us
 */
#define COM_RES_HDR_PBCD_CTUNE_AA_DET_TIME_DRIFT(x) (((uint16_t)(((uint16_t)(x)) << COM_RES_HDR_PBCD_CTUNE_AA_DET_TIME_DRIFT_SHIFT)) & COM_RES_HDR_PBCD_CTUNE_AA_DET_TIME_DRIFT_MASK)

#define COM_RES_HDR_PBCD_CTUNE_AA_DET_AA_DET_MASK (0x8000U)
#define COM_RES_HDR_PBCD_CTUNE_AA_DET_AA_DET_SHIFT (15U)
/*! AA_DET - AA detection status reported for the step. */
#define COM_RES_HDR_PBCD_CTUNE_AA_DET_AA_DET(x)  (((uint16_t)(((uint16_t)(x)) << COM_RES_HDR_PBCD_CTUNE_AA_DET_AA_DET_SHIFT)) & COM_RES_HDR_PBCD_CTUNE_AA_DET_AA_DET_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group COM_RES_HDR_Register_Masks */


/*!
 * @}
 */ /* end of group COM_RES_HDR_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- IQ_RES_BODY Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup IQ_RES_BODY_Peripheral_Access_Layer IQ_RES_BODY Peripheral Access Layer
 * @{
 */

/** IQ_RES_BODY - Register Layout Typedef */
typedef struct {
  __IO uint32_t PCT_RESULT[5];                     /**< IQ and TQI result for the step., array offset: 0x0, array step: 0x4 */
} IQ_RES_BODY_Type;

/* ----------------------------------------------------------------------------
   -- IQ_RES_BODY Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup IQ_RES_BODY_Register_Masks IQ_RES_BODY Register Masks
 * @{
 */

/*! @name PCT_RESULT - IQ and TQI result for the step. */
/*! @{ */

#define IQ_RES_BODY_PCT_RESULT_TQI_MASK          (0x3U)
#define IQ_RES_BODY_PCT_RESULT_TQI_SHIFT         (0U)
/*! TQI - Tone Quality Indication (TQI) for the individual path.
 *  0b00..Good quality
 *  0b01..Medium quality
 *  0b10..Low quality
 *  0b11..Reserved
 */
#define IQ_RES_BODY_PCT_RESULT_TQI(x)            (((uint32_t)(((uint32_t)(x)) << IQ_RES_BODY_PCT_RESULT_TQI_SHIFT)) & IQ_RES_BODY_PCT_RESULT_TQI_MASK)

#define IQ_RES_BODY_PCT_RESULT_PCT_I_MASK        (0xFFF0U)
#define IQ_RES_BODY_PCT_RESULT_PCT_I_SHIFT       (4U)
/*! PCT_I - In-phase component of the PCT for the individual path. */
#define IQ_RES_BODY_PCT_RESULT_PCT_I(x)          (((uint32_t)(((uint32_t)(x)) << IQ_RES_BODY_PCT_RESULT_PCT_I_SHIFT)) & IQ_RES_BODY_PCT_RESULT_PCT_I_MASK)

#define IQ_RES_BODY_PCT_RESULT_PCT_Q_MASK        (0xFFF00000U)
#define IQ_RES_BODY_PCT_RESULT_PCT_Q_SHIFT       (20U)
/*! PCT_Q - Quadrature component of the PCT for the individual path. */
#define IQ_RES_BODY_PCT_RESULT_PCT_Q(x)          (((uint32_t)(((uint32_t)(x)) << IQ_RES_BODY_PCT_RESULT_PCT_Q_SHIFT)) & IQ_RES_BODY_PCT_RESULT_PCT_Q_MASK)
/*! @} */

/* The count of IQ_RES_BODY_PCT_RESULT */
#define IQ_RES_BODY_PCT_RESULT_COUNT             (5U)


/*!
 * @}
 */ /* end of group IQ_RES_BODY_Register_Masks */


/*!
 * @}
 */ /* end of group IQ_RES_BODY_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- MODE2_CFG_HDR Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MODE2_CFG_HDR_Peripheral_Access_Layer MODE2_CFG_HDR Peripheral Access Layer
 * @{
 */

/** MODE2_CFG_HDR - Register Layout Typedef */
typedef struct {
  __IO uint16_t CHANNEL_NUM;                       /**< Channel number for the step., offset: 0x0 */
  __IO uint16_t STEP_CFG;                          /**< Configuration for the step., offset: 0x2 */
  __IO uint16_t STEP_CFO;                          /**< CFO setting for the step, offset: 0x4 */
  __IO uint16_t HPM_CAL_FACTOR;                    /**< HPM CAL factor to apply for the step., offset: 0x6 */
  __IO uint32_t CTUNE_MANUAL;                      /**< CTUNE manual to inject for the step., offset: 0x8 */
} MODE2_CFG_HDR_Type;

/* ----------------------------------------------------------------------------
   -- MODE2_CFG_HDR Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup MODE2_CFG_HDR_Register_Masks MODE2_CFG_HDR Register Masks
 * @{
 */

/*! @name CHANNEL_NUM - Channel number for the step. */
/*! @{ */

#define MODE2_CFG_HDR_CHANNEL_NUM_CHANNEL_NUM_MASK (0xFFFFU)
#define MODE2_CFG_HDR_CHANNEL_NUM_CHANNEL_NUM_SHIFT (0U)
/*! CHANNEL_NUM - Channel number for the step. */
#define MODE2_CFG_HDR_CHANNEL_NUM_CHANNEL_NUM(x) (((uint16_t)(((uint16_t)(x)) << MODE2_CFG_HDR_CHANNEL_NUM_CHANNEL_NUM_SHIFT)) & MODE2_CFG_HDR_CHANNEL_NUM_CHANNEL_NUM_MASK)
/*! @} */

/*! @name STEP_CFG - Configuration for the step. */
/*! @{ */

#define MODE2_CFG_HDR_STEP_CFG_MODE_MASK         (0x3U)
#define MODE2_CFG_HDR_STEP_CFG_MODE_SHIFT        (0U)
/*! MODE - Mode for the step
 *  0b00..Frequency Compensation Step (Mode 0)
 *  0b01..Pk-Pk step (Mode 1)
 *  0b10..Tn-Tn step (Mode 2)
 *  0b11..Pk-Tn-Tn-Pk step (Mode 3)
 */
#define MODE2_CFG_HDR_STEP_CFG_MODE(x)           (((uint16_t)(((uint16_t)(x)) << MODE2_CFG_HDR_STEP_CFG_MODE_SHIFT)) & MODE2_CFG_HDR_STEP_CFG_MODE_MASK)

#define MODE2_CFG_HDR_STEP_CFG_TONE_EXT_MASK     (0xCU)
#define MODE2_CFG_HDR_STEP_CFG_TONE_EXT_SHIFT    (2U)
/*! TONE_EXT - Choice of tone extension for the initiator portion of the step.
 *  0b00..Tone extension is not present for either role TX.
 *  0b01..Tone extension is present for initiator TX only.
 *  0b10..Tone extension is present for reflector TX only.
 *  0b11..Tone extension is present for both roles TX.
 */
#define MODE2_CFG_HDR_STEP_CFG_TONE_EXT(x)       (((uint16_t)(((uint16_t)(x)) << MODE2_CFG_HDR_STEP_CFG_TONE_EXT_SHIFT)) & MODE2_CFG_HDR_STEP_CFG_TONE_EXT_MASK)

#define MODE2_CFG_HDR_STEP_CFG_ANT_PERMUT_MASK   (0x1F0U)
#define MODE2_CFG_HDR_STEP_CFG_ANT_PERMUT_SHIFT  (4U)
/*! ANT_PERMUT - Antenna permutation pattern for the step. */
#define MODE2_CFG_HDR_STEP_CFG_ANT_PERMUT(x)     (((uint16_t)(((uint16_t)(x)) << MODE2_CFG_HDR_STEP_CFG_ANT_PERMUT_SHIFT)) & MODE2_CFG_HDR_STEP_CFG_ANT_PERMUT_MASK)

#define MODE2_CFG_HDR_STEP_CFG_ANT_CS_SYNC_MASK  (0x600U)
#define MODE2_CFG_HDR_STEP_CFG_ANT_CS_SYNC_SHIFT (9U)
/*! ANT_CS_SYNC - Antenna cs Sync */
#define MODE2_CFG_HDR_STEP_CFG_ANT_CS_SYNC(x)    (((uint16_t)(((uint16_t)(x)) << MODE2_CFG_HDR_STEP_CFG_ANT_CS_SYNC_SHIFT)) & MODE2_CFG_HDR_STEP_CFG_ANT_CS_SYNC_MASK)

#define MODE2_CFG_HDR_STEP_CFG_EP_ONE_WAY_MASK   (0x800U)
#define MODE2_CFG_HDR_STEP_CFG_EP_ONE_WAY_SHIFT  (11U)
/*! EP_ONE_WAY - One way ranging? */
#define MODE2_CFG_HDR_STEP_CFG_EP_ONE_WAY(x)     (((uint16_t)(((uint16_t)(x)) << MODE2_CFG_HDR_STEP_CFG_EP_ONE_WAY_SHIFT)) & MODE2_CFG_HDR_STEP_CFG_EP_ONE_WAY_MASK)

#define MODE2_CFG_HDR_STEP_CFG_T_PM_SEL_MASK     (0x1000U)
#define MODE2_CFG_HDR_STEP_CFG_T_PM_SEL_SHIFT    (12U)
/*! T_PM_SEL - Selection of T_PM choices. */
#define MODE2_CFG_HDR_STEP_CFG_T_PM_SEL(x)       (((uint16_t)(((uint16_t)(x)) << MODE2_CFG_HDR_STEP_CFG_T_PM_SEL_SHIFT)) & MODE2_CFG_HDR_STEP_CFG_T_PM_SEL_MASK)
/*! @} */

/*! @name STEP_CFO - CFO setting for the step */
/*! @{ */

#define MODE2_CFG_HDR_STEP_CFO_STEP_CFO_MASK     (0xFFFFU)
#define MODE2_CFG_HDR_STEP_CFO_STEP_CFO_SHIFT    (0U)
/*! STEP_CFO - CFO setting for the step. */
#define MODE2_CFG_HDR_STEP_CFO_STEP_CFO(x)       (((uint16_t)(((uint16_t)(x)) << MODE2_CFG_HDR_STEP_CFO_STEP_CFO_SHIFT)) & MODE2_CFG_HDR_STEP_CFO_STEP_CFO_MASK)
/*! @} */

/*! @name HPM_CAL_FACTOR - HPM CAL factor to apply for the step. */
/*! @{ */

#define MODE2_CFG_HDR_HPM_CAL_FACTOR_HPM_CAL_FACTOR_MASK (0xFFFU)
#define MODE2_CFG_HDR_HPM_CAL_FACTOR_HPM_CAL_FACTOR_SHIFT (0U)
/*! HPM_CAL_FACTOR - HPM CAL factor to apply for the step */
#define MODE2_CFG_HDR_HPM_CAL_FACTOR_HPM_CAL_FACTOR(x) (((uint16_t)(((uint16_t)(x)) << MODE2_CFG_HDR_HPM_CAL_FACTOR_HPM_CAL_FACTOR_SHIFT)) & MODE2_CFG_HDR_HPM_CAL_FACTOR_HPM_CAL_FACTOR_MASK)
/*! @} */

/*! @name CTUNE_MANUAL - CTUNE manual to inject for the step. */
/*! @{ */

#define MODE2_CFG_HDR_CTUNE_MANUAL_CTUNE_MANUAL_MASK (0x1FFU)
#define MODE2_CFG_HDR_CTUNE_MANUAL_CTUNE_MANUAL_SHIFT (0U)
/*! CTUNE_MANUAL - CTUNE manual to inject for the step. */
#define MODE2_CFG_HDR_CTUNE_MANUAL_CTUNE_MANUAL(x) (((uint32_t)(((uint32_t)(x)) << MODE2_CFG_HDR_CTUNE_MANUAL_CTUNE_MANUAL_SHIFT)) & MODE2_CFG_HDR_CTUNE_MANUAL_CTUNE_MANUAL_MASK)
/*! @} */


/*!
 * @}
 */ /* end of group MODE2_CFG_HDR_Register_Masks */


/*!
 * @}
 */ /* end of group MODE2_CFG_HDR_Peripheral_Access_Layer */


/* ----------------------------------------------------------------------------
   -- PAYLOAD_CFG_BODY Peripheral Access Layer
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PAYLOAD_CFG_BODY_Peripheral_Access_Layer PAYLOAD_CFG_BODY Peripheral Access Layer
 * @{
 */

/** PAYLOAD_CFG_BODY - Register Layout Typedef */
typedef struct {
  __IO uint32_t AA_INIT;                           /**< Access address used for the Initiator transmission phase, offset: 0x0 */
  __IO uint32_t AA_REF;                            /**< Access address used for the reflector transmission phase, offset: 0x4 */
  struct {                                         /* offset: 0x8, array step: 0x8 */
    __IO uint32_t INIT;                              /**< 32bit word of payload for the initiator for the step., array offset: 0x8, array step: 0x8 */
    __IO uint32_t REFL;                              /**< 32bit word of payload for the reflector for the step., array offset: 0xC, array step: 0x8 */
  } PAYLOAD[4];
} PAYLOAD_CFG_BODY_Type;

/* ----------------------------------------------------------------------------
   -- PAYLOAD_CFG_BODY Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup PAYLOAD_CFG_BODY_Register_Masks PAYLOAD_CFG_BODY Register Masks
 * @{
 */

/*! @name AA_INIT - Access address used for the Initiator transmission phase */
/*! @{ */

#define PAYLOAD_CFG_BODY_AA_INIT_AA_INIT_MASK    (0xFFFFFFFFU)
#define PAYLOAD_CFG_BODY_AA_INIT_AA_INIT_SHIFT   (0U)
/*! AA_INIT - Access address sent during Initiator transmission phase (first half step). */
#define PAYLOAD_CFG_BODY_AA_INIT_AA_INIT(x)      (((uint32_t)(((uint32_t)(x)) << PAYLOAD_CFG_BODY_AA_INIT_AA_INIT_SHIFT)) & PAYLOAD_CFG_BODY_AA_INIT_AA_INIT_MASK)
/*! @} */

/*! @name AA_REF - Access address used for the reflector transmission phase */
/*! @{ */

#define PAYLOAD_CFG_BODY_AA_REF_AA_REF_MASK      (0xFFFFFFFFU)
#define PAYLOAD_CFG_BODY_AA_REF_AA_REF_SHIFT     (0U)
/*! AA_REF - Access address sent during Reflector transmission phase (first half step). */
#define PAYLOAD_CFG_BODY_AA_REF_AA_REF(x)        (((uint32_t)(((uint32_t)(x)) << PAYLOAD_CFG_BODY_AA_REF_AA_REF_SHIFT)) & PAYLOAD_CFG_BODY_AA_REF_AA_REF_MASK)
/*! @} */

/*! @name INIT - 32bit word of payload for the initiator for the step. */
/*! @{ */

#define PAYLOAD_CFG_BODY_INIT_PLD_MASK           (0xFFFFFFFFU)
#define PAYLOAD_CFG_BODY_INIT_PLD_SHIFT          (0U)
/*! PLD - One payload word. */
#define PAYLOAD_CFG_BODY_INIT_PLD(x)             (((uint32_t)(((uint32_t)(x)) << PAYLOAD_CFG_BODY_INIT_PLD_SHIFT)) & PAYLOAD_CFG_BODY_INIT_PLD_MASK)
/*! @} */

/* The count of PAYLOAD_CFG_BODY_INIT */
#define PAYLOAD_CFG_BODY_INIT_COUNT              (4U)

/*! @name REFL - 32bit word of payload for the reflector for the step. */
/*! @{ */

#define PAYLOAD_CFG_BODY_REFL_PLD_MASK           (0xFFFFFFFFU)
#define PAYLOAD_CFG_BODY_REFL_PLD_SHIFT          (0U)
/*! PLD - One payload word. */
#define PAYLOAD_CFG_BODY_REFL_PLD(x)             (((uint32_t)(((uint32_t)(x)) << PAYLOAD_CFG_BODY_REFL_PLD_SHIFT)) & PAYLOAD_CFG_BODY_REFL_PLD_MASK)
/*! @} */

/* The count of PAYLOAD_CFG_BODY_REFL */
#define PAYLOAD_CFG_BODY_REFL_COUNT              (4U)


/*!
 * @}
 */ /* end of group PAYLOAD_CFG_BODY_Register_Masks */


/*!
 * @}
 */ /* end of group PAYLOAD_CFG_BODY_Peripheral_Access_Layer */


/*
** End of section using anonymous unions
*/

// #error Not supported compiler type

/*!
 * @}
 */ /* end of group Peripheral_access_layer */

#endif /*  defined(NXP_RADIO_GEN) && (NXP_RADIO_GEN >= 475)  */


#endif /* NXP_XCVR_LCL_STEP_STRUCTS_H */


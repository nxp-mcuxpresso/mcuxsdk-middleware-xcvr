/*
 * Copyright (c) 2016, Freescale Semiconductor, Inc.
 * Copyright 2018-2019,2022 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef NXP_XCVR_GFSK_0510_CONFIG_H
/* clang-format off */
#define NXP_XCVR_GFSK_0510_CONFIG_H
/* clang-format on */

#include "nxp2p4_xcvr.h"
#include "nxp_xcvr_common_config.h" /* make common configs available to the mode config file for pointer struct assembly */

/*!
 * @addtogroup configs Radio Configuration Files
 * @{
 */

/*******************************************************************************
 * Definitions
 *******************************************************************************/

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*! @brief Mode GFSK BT 0P5 H 1P0 1mbps specific configuration */
extern const xcvr_mode_datarate_config_t xcvr_gfsk_bt_0p5_h_1p0_1mbps_config;

/* COMPLETE CONFIG STRUCTURES */
/*! @brief  GFSK BT=0.5, h=1.0 complete 1Mbps specific configuration. */
extern const xcvr_config_t xcvr_gfsk_bt_0p5_h_1p0_1mbps_full_config;

#if defined(__cplusplus)
extern "C" {
#endif

/* @} */

#if defined(__cplusplus)
}
#endif

/*! @}*/

#endif /* NXP_XCVR_GFSK_0510_CONFIG_H */

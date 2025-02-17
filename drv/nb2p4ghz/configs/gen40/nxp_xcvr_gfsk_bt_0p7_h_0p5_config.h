/*
 * Copyright (c) 2016, Freescale Semiconductor, Inc.
 * Copyright 2018-2019,2022 NXP
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef NXP_XCVR_GFSK_0705_CONFIG_H
/* clang-format off */
#define NXP_XCVR_GFSK_0705_CONFIG_H
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

/*! @brief Mode GFSK BT 0P7 H 0P5 250kbps specific configuration */
extern const xcvr_mode_datarate_config_t xcvr_gfsk_bt_0p7_h_0p5_250kbps_config;
/*! @brief Mode GFSK BT 0P7 H 0P5 500kbps specific configuration */
extern const xcvr_mode_datarate_config_t xcvr_gfsk_bt_0p7_h_0p5_500kbps_config;
/*! @brief Mode GFSK BT 0P7 H 0P5 1mbps specific configuration */
extern const xcvr_mode_datarate_config_t xcvr_gfsk_bt_0p7_h_0p5_1mbps_config;

/* COMPLETE CONFIG STRUCTURES */
/*! @brief  GFSK BT=0.7, h=0.5 mode & datarate 1Mbps specific configuration. */
extern const xcvr_config_t xcvr_gfsk_bt_0p7_h_0p5_1mbps_full_config;
/*! @brief  GFSK BT=0.7, h=0.5 mode & datarate 500Kbps specific configuration. */
extern const xcvr_config_t xcvr_gfsk_bt_0p7_h_0p5_500kbps_full_config;
/*! @brief  GFSK BT=0.7, h=0.5 mode & datarate 250Kbps specific configuration. */
extern const xcvr_config_t xcvr_gfsk_bt_0p7_h_0p5_250kbps_full_config;

#if defined(__cplusplus)
extern "C" {
#endif

/* @} */

#if defined(__cplusplus)
}
#endif

/*! @}*/

#endif /* NXP_XCVR_GFSK_05032_CONFIG_H */

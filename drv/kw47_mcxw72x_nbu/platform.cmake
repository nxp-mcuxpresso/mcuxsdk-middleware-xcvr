# Copyright 2025 NXP
# SPDX-License-Identifier: BSD-3-Clause

# Platform-specific files for KW47/MCXW72 platform
set(CONFIG_MCUX_COMPONENT_middleware.wireless.xcvr.kw47_mcxw72 ON)

# Platform-specific configuration for kw47_mcxw72x_nbu
set(PLATFORM_DEFINES
	CPU_KW47B42ZB7AFTA_cm33_core1
	FPGA_TARGET=0
	HDI_BUS=0
	RF_OSC_26MHZ=0
	NXP_RADIO_GEN=470
)

set(PLATFORM_SOURCES
	${CMAKE_CURRENT_LIST_DIR}/../nb2p4ghz/configs/gen47/nxp_xcvr_coding_config.c
	${CMAKE_CURRENT_LIST_DIR}/../nb2p4ghz/configs/gen47/nxp_xcvr_coding_config.h
	${CMAKE_CURRENT_LIST_DIR}/../nb2p4ghz/configs/gen47/nxp_xcvr_common_config.c
	${CMAKE_CURRENT_LIST_DIR}/../nb2p4ghz/configs/gen47/nxp_xcvr_common_config.h
	${CMAKE_CURRENT_LIST_DIR}/../nb2p4ghz/configs/gen47/nxp_xcvr_fsk_h_0p5_config.c
	${CMAKE_CURRENT_LIST_DIR}/../nb2p4ghz/configs/gen47/nxp_xcvr_fsk_h_0p5_config.h
	${CMAKE_CURRENT_LIST_DIR}/../nb2p4ghz/configs/gen47/nxp_xcvr_gfsk_bt_0p3_h_0p5_config.c
	${CMAKE_CURRENT_LIST_DIR}/../nb2p4ghz/configs/gen47/nxp_xcvr_gfsk_bt_0p3_h_0p5_config.h
	${CMAKE_CURRENT_LIST_DIR}/../nb2p4ghz/configs/gen47/nxp_xcvr_gfsk_bt_0p5_h_0p32_config.c
	${CMAKE_CURRENT_LIST_DIR}/../nb2p4ghz/configs/gen47/nxp_xcvr_gfsk_bt_0p5_h_0p32_config.h
	${CMAKE_CURRENT_LIST_DIR}/../nb2p4ghz/configs/gen47/nxp_xcvr_gfsk_bt_0p5_h_0p5_config.c
	${CMAKE_CURRENT_LIST_DIR}/../nb2p4ghz/configs/gen47/nxp_xcvr_gfsk_bt_0p5_h_0p5_config.h
	${CMAKE_CURRENT_LIST_DIR}/../nb2p4ghz/configs/gen47/nxp_xcvr_gfsk_bt_0p5_h_0p7_config.c
	${CMAKE_CURRENT_LIST_DIR}/../nb2p4ghz/configs/gen47/nxp_xcvr_gfsk_bt_0p5_h_0p7_config.h
	${CMAKE_CURRENT_LIST_DIR}/../nb2p4ghz/configs/gen47/nxp_xcvr_gfsk_bt_0p5_h_1p0_config.c
	${CMAKE_CURRENT_LIST_DIR}/../nb2p4ghz/configs/gen47/nxp_xcvr_gfsk_bt_0p5_h_1p0_config.h
	${CMAKE_CURRENT_LIST_DIR}/../nb2p4ghz/configs/gen47/nxp_xcvr_gfsk_bt_0p7_h_0p5_config.c
	${CMAKE_CURRENT_LIST_DIR}/../nb2p4ghz/configs/gen47/nxp_xcvr_gfsk_bt_0p7_h_0p5_config.h
	${CMAKE_CURRENT_LIST_DIR}/../nb2p4ghz/configs/gen47/nxp_xcvr_gfsk_bt_1p0_h_0p5_config.c
	${CMAKE_CURRENT_LIST_DIR}/../nb2p4ghz/configs/gen47/nxp_xcvr_gfsk_bt_1p0_h_0p5_config.h
	${CMAKE_CURRENT_LIST_DIR}/../nb2p4ghz/configs/gen47/nxp_xcvr_gfsk_bt_2p0_h_0p5_config.c
	${CMAKE_CURRENT_LIST_DIR}/../nb2p4ghz/configs/gen47/nxp_xcvr_gfsk_bt_2p0_h_0p5_config.h
	${CMAKE_CURRENT_LIST_DIR}/../nb2p4ghz/configs/gen47/nxp_xcvr_lcl_config.c
	${CMAKE_CURRENT_LIST_DIR}/../nb2p4ghz/configs/gen47/nxp_xcvr_lcl_config.h
	${CMAKE_CURRENT_LIST_DIR}/../nb2p4ghz/configs/gen47/nxp_xcvr_mode_config.c
	${CMAKE_CURRENT_LIST_DIR}/../nb2p4ghz/configs/gen47/nxp_xcvr_mode_config.h
	${CMAKE_CURRENT_LIST_DIR}/../nb2p4ghz/configs/gen47/nxp_xcvr_msk_config.c
	${CMAKE_CURRENT_LIST_DIR}/../nb2p4ghz/configs/gen47/nxp_xcvr_msk_config.h
	${CMAKE_CURRENT_LIST_DIR}/../nb2p4ghz/configs/gen47/nxp_xcvr_oqpsk_802p15p4_config.c
	${CMAKE_CURRENT_LIST_DIR}/../nb2p4ghz/configs/gen47/nxp_xcvr_oqpsk_802p15p4_config.h

)

set(PLATFORM_INCLUDES
	${CMAKE_CURRENT_LIST_DIR}/../nb2p4ghz/configs/gen47/.
	${SDK_DIR}/arch/arm/CMSIS/Core/Include
	${SDK_DIR}/devices/Wireless/KW/KW47B42ZB7
	${SDK_DIR}/devices/Wireless/KW/KW47B42ZB7/drivers
	${SDK_DIR}/devices/Wireless/KW/periph6
)

set(PLATFORM_COMPILE_OPTIONS
	--cpu Cortex-M33.no_dsp
	-e
	--thumb
	--header_context
)

set(PLATFORM_LINK_OPTIONS
	--cpu Cortex-M33.no_dsp
)

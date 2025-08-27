# Copyright 2025 NXP
# SPDX-License-Identifier: BSD-3-Clause

# SoC family definitions
mcux_set_list(KW45_NBU_FAMILY "KW45B41Z52xxxA_NBU KW45B41Z53xxxA_NBU  KW45B41Z82xxxA_NBU  KW45B41Z83xxxA_NBU  K32W1480xxxA_NBU")
mcux_set_list(MCXW71_NBU_FAMILY "MCXW716CxxxA_NBU MCXW716AxxxA_NBU")
mcux_set_list(KW45_FAMILY "KW45B41Z52xxxA KW45B41Z53xxxA  KW45B41Z82xxxA  KW45B41Z83xxxA  K32W1480xxxA")
mcux_set_list(MCXW71_FAMILY "MCXW716CxxxA MCXW716AxxxA")
mcux_set_list(KW45_FAMILY_WITHOUT_K32W1 "KW45B41Z52xxxA KW45B41Z53xxxA  KW45B41Z82xxxA  KW45B41Z83xxxA")
mcux_set_list(KW47_FAMILY "KW47B42Z83xxxA KW47B42Z96xxxA KW47B42Z97xxxA KW47B42ZB2xxxA KW47B42ZB3xxxA KW47B42ZB6xxxA KW47B42ZB7xxxA KW47Z42082xxxA KW47Z42092xxxA KW47Z420B2xxxA KW47Z420B3xxxA")
mcux_set_list(MCXW72_FAMILY "MCXW727CxxxA")
mcux_set_list(KW43_FAMILY "KW43B43ZC7xxxA")
mcux_set_list(KW43_NBU_FAMILY "KW43B43ZC7xxxA_NBU")
mcux_set_list(MCXW23_FAMILY "MCXW236 MCXW235")

if(CONFIG_MCUX_COMPONENT_middleware.wireless.xcvr)
	# ******** KW47 & KW43 APP core only ********
    # add source files and header file - header file are required for IAR project generation
    mcux_add_source(
        SOURCES
            drv/nb2p4ghz/nxp2p4_xcvr.c
            drv/nb2p4ghz/nxp2p4_xcvr.h
            drv/nb2p4ghz/nxp_xcvr_trim.c
            drv/nb2p4ghz/nxp_xcvr_trim.h
            drv/rfmc_ctrl.c
            drv/rfmc_ctrl.h
            drv/nxp_xcvr_lcl_ctrl.c
            drv/nxp_xcvr_lcl_ctrl.h
            drv/nxp_xcvr_ext_ctrl.c
            drv/nxp_xcvr_ext_ctrl.h
            drv/dbg_ram_capture.c
            drv/dbg_ram_capture.h
            drv/dma_capture.c
            drv/dma_capture.h
            drv/mathfp.c
            drv/mathfp.h
		DEVICE_IDS ${KW47_FAMILY} ${MCXW72_FAMILY} ${KW43_FAMILY}
		CORE_IDS "cm33_core0" "cm33"
    )

    # add include path - common includes for both cores, all derivatives
    mcux_add_include(
        INCLUDES
            drv/.
            drv/nb2p4ghz/.
    )

	# ******** KW45 specific - both app and NBU core ********
	# add sources and include path for families kw45_k32w1_mcxw71
	mcux_add_source(
		SOURCES
            drv/nb2p4ghz/nxp2p4_xcvr.c
            drv/nb2p4ghz/nxp2p4_xcvr.h
            drv/nb2p4ghz/nxp_xcvr_trim.c
            drv/nb2p4ghz/nxp_xcvr_trim.h
            drv/rfmc_ctrl.c
            drv/rfmc_ctrl.h
            drv/nxp_xcvr_lcl_ctrl.c
            drv/nxp_xcvr_lcl_ctrl.h
            drv/nxp_xcvr_ext_ctrl.c
            drv/nxp_xcvr_ext_ctrl.h
            drv/dbg_ram_capture.c
            drv/dbg_ram_capture.h
            drv/dma_capture.c
            drv/dma_capture.h
            drv/mathfp.c
            drv/mathfp.h
			drv/nb2p4ghz/configs/gen45/*.c
			drv/nb2p4ghz/configs/gen45/*.h
		DEVICE_IDS ${KW45_FAMILY} ${KW45_NBU_FAMILY} ${MCXW71_NBU_FAMILY} ${MCXW71_FAMILY}

	)
	mcux_add_include(
		INCLUDES
			drv/nb2p4ghz/configs/gen45/.
		DEVICE_IDS ${KW45_FAMILY} ${MCXW71_FAMILY} ${KW45_NBU_FAMILY} ${MCXW71_NBU_FAMILY}
   )

	# ******** KW47 specific ********
	# add sources and include path for families kw47_mcxw72
	mcux_add_source(
		SOURCES
			drv/nb2p4ghz/configs/gen47/*.c
			drv/nb2p4ghz/configs/gen47/*.h
			drv/nxp_xcvr_lcl_step_mgr.c
			drv/nxp_xcvr_lcl_step_mgr.h
			drv/nxp_xcvr_lcl_step_structs.h
		DEVICE_IDS ${KW47_FAMILY} ${MCXW72_FAMILY}
		CORE_IDS "cm33_core0"
	)
	
	mcux_add_include(
		INCLUDES
			drv/nb2p4ghz/configs/gen47/.
		DEVICE_IDS ${KW47_FAMILY} ${MCXW72_FAMILY}
	)
	
	# Add headers for library used on core 1
	mcux_add_source(
		SOURCES
			drv/nb2p4ghz/configs/gen47/*.h
			drv/nxp_xcvr_lcl_step_mgr.h
			drv/nxp_xcvr_lcl_step_structs.h
		DEVICE_IDS ${KW47_FAMILY} ${MCXW72_FAMILY}
		CORE_IDS "cm33_core1"
	)
	# Add library for core 1
	mcux_add_library(
		LIBS lib/xcvr_kw47_mcxw72x_nbu.a
		TOOLCHAINS kds armgcc mcux iar
		DEVICE_IDS ${KW47_FAMILY} ${MCXW72_FAMILY}
		CORE_IDS "cm33_core1"
	)

	# ******** KW43 specific ********
	# Full source file build for core 0
	mcux_add_source(
		SOURCES
			# TODO : Add the full config file list
			#drv/nb2p4ghz/configs/gen47_5/*.c
			#drv/nb2p4ghz/configs/gen47_5/*.h
			drv/nb2p4ghz/configs/gen47_5/nxp_xcvr_common_config.c
			drv/nb2p4ghz/configs/gen47_5/nxp_xcvr_common_config.h
			drv/nb2p4ghz/configs/gen47_5/nxp_xcvr_lcl_config.c
			drv/nb2p4ghz/configs/gen47_5/nxp_xcvr_lcl_config.h
			drv/nb2p4ghz/configs/gen47_5/nxp_xcvr_mode_config.c
			drv/nb2p4ghz/configs/gen47_5/nxp_xcvr_mode_config.h
			drv/nb2p4ghz/configs/gen47_5/nxp_xcvr_msk_config.c
			drv/nb2p4ghz/configs/gen47_5/nxp_xcvr_msk_config.h
			drv/nb2p4ghz/configs/gen47_5/nxp_xcvr_coding_config.c
			drv/nb2p4ghz/configs/gen47_5/nxp_xcvr_coding_config.h
			drv/nb2p4ghz/configs/gen47_5/nxp_xcvr_gfsk_bt_0p5_h_0p5_config.c
			drv/nb2p4ghz/configs/gen47_5/nxp_xcvr_gfsk_bt_0p5_h_0p5_config.h
			drv/nb2p4ghz/configs/gen47_5/nxp_xcvr_gfsk_bt_0p5_h_0p7_config.c
			drv/nb2p4ghz/configs/gen47_5/nxp_xcvr_gfsk_bt_0p5_h_0p7_config.h
			drv/nb2p4ghz/configs/gen47_5/nxp_xcvr_gfsk_bt_0p5_h_0p32_config.c
			drv/nb2p4ghz/configs/gen47_5/nxp_xcvr_gfsk_bt_0p5_h_0p32_config.h
			drv/nb2p4ghz/configs/gen47_5/nxp_xcvr_gfsk_bt_0p5_h_1p0_config.c
			drv/nb2p4ghz/configs/gen47_5/nxp_xcvr_gfsk_bt_0p5_h_1p0_config.h
			drv/nb2p4ghz/configs/gen47_5/nxp_xcvr_gfsk_bt_2p0_h_0p5_config.c
			drv/nb2p4ghz/configs/gen47_5/nxp_xcvr_gfsk_bt_2p0_h_0p5_config.h
			drv/nb2p4ghz/configs/gen47_5/nxp_xcvr_oqpsk_802p15p4_config.c
			drv/nb2p4ghz/configs/gen47_5/nxp_xcvr_oqpsk_802p15p4_config.h
			drv/nxp_xcvr_lcl_step_mgr.c
			drv/nxp_xcvr_lcl_step_mgr.h
			drv/nxp_xcvr_lcl_step_structs.h
		DEVICE_IDS ${KW43_FAMILY}
		CORE_IDS "cm33" "cm33_core"
	)
	mcux_add_include(
		INCLUDES
			drv/nb2p4ghz/configs/gen47_5/.
		DEVICE_IDS ${KW43_FAMILY} ${KW43_NBU_FAMILY}
	)
	
	# Add headers for library used on core 1
	mcux_add_source(
		SOURCES
            drv/nb2p4ghz/nxp2p4_xcvr.h
            drv/nb2p4ghz/nxp_xcvr_trim.h
            drv/rfmc_ctrl.h
            drv/nxp_xcvr_lcl_ctrl.h
            drv/nxp_xcvr_ext_ctrl.h
            drv/dbg_ram_capture.h
            drv/dma_capture.h
            drv/mathfp.h
			drv/nb2p4ghz/configs/gen47_5/*.h
			drv/nxp_xcvr_lcl_step_mgr.h
			drv/nxp_xcvr_lcl_step_structs.h
		DEVICE_IDS ${KW43_NBU_FAMILY}
		CORE_IDS "cm33_core1" "cm33"
	)
	# Add library for core 1
	mcux_add_library(
		LIBS lib/xcvr_kw43_mcxw70_nbu.a
		TOOLCHAINS kds armgcc mcux iar
		DEVICE_IDS ${KW43_NBU_FAMILY}
		CORE_IDS "cm33_core1" "cm33"
	)

endif()


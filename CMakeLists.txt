# Copyright 2024 NXP
# SPDX-License-Identifier: BSD-3-Clause

if(CONFIG_MCUX_COMPONENT_middleware.wireless.xcvr)

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
    )

    # add include path
    mcux_add_include(
        INCLUDES
            drv/.
            drv/nb2p4ghz/.
    )

    if(CONFIG_MCUX_COMPONENT_middleware.wireless.xcvr.kw45_k32w1_mcxw71)
        # add sources and include path for families kw45_k32w1_mcxw71
        mcux_add_source(
            SOURCES
                drv/nb2p4ghz/configs/gen45/*.c
                drv/nb2p4ghz/configs/gen45/*.h
        )
        mcux_add_include(
            INCLUDES
                drv/nb2p4ghz/configs/gen45/.
        )
    endif()

    if(CONFIG_MCUX_COMPONENT_middleware.wireless.xcvr.kw47_mcxw72)
        # add sources and include path for families kw47_mcxw72
        mcux_add_source(
            SOURCES
                drv/nb2p4ghz/configs/gen47/*.c
                drv/nb2p4ghz/configs/gen47/*.h
                drv/nxp_xcvr_lcl_step_mgr.c
                drv/nxp_xcvr_lcl_step_mgr.h
                drv/nxp_xcvr_lcl_step_structs.h
        )
        mcux_add_include(
            INCLUDES
                drv/nb2p4ghz/configs/gen47/.
        )
    endif()

    if(CONFIG_MCUX_COMPONENT_middleware.wireless.xcvr.gen475)
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
        )
        mcux_add_include(
            INCLUDES
                drv/nb2p4ghz/configs/gen47_5/.
        )
    endif()

endif()


# Copyright 2025 NXP
# SPDX-License-Identifier: BSD-3-Clause

cmake_minimum_required(VERSION 3.16)

# Set the toolchain file for IAR
set(CMAKE_TOOLCHAIN_FILE "${CMAKE_CURRENT_SOURCE_DIR}/iar.cmake" CACHE FILEPATH "Toolchain file")

project(XCVR_library C)

set(SDK_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../../../..")

set(CONFIG_MCUX_COMPONENT_middleware.wireless.xcvr ON)

# Platform selection option
set(PLATFORM_TARGET "kw47_mcxw72x_nbu" CACHE STRING "Target platform")
set_property(CACHE PLATFORM_TARGET PROPERTY STRINGS "kw47_mcxw72x_nbu" "kw43_mcxw70_nbu")

# Validate platform selection
if(NOT EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/${PLATFORM_TARGET}")
	message(FATAL_ERROR "Platform directory ${PLATFORM_TARGET} does not exist")
endif()

# Include platform-specific configuration if it exists
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/${PLATFORM_TARGET}/platform.cmake")
	include("${CMAKE_CURRENT_SOURCE_DIR}/${PLATFORM_TARGET}/platform.cmake")
endif()

# Common source files (platform independent)
set(COMMON_SOURCES
	nb2p4ghz/nxp2p4_xcvr.c
	nb2p4ghz/nxp2p4_xcvr.h
	nb2p4ghz/nxp_xcvr_trim.c
	nb2p4ghz/nxp_xcvr_trim.h
	rfmc_ctrl.c
	rfmc_ctrl.h
	nxp_xcvr_lcl_ctrl.c
	nxp_xcvr_lcl_ctrl.h
	nxp_xcvr_ext_ctrl.c
	nxp_xcvr_ext_ctrl.h
	dbg_ram_capture.c
	dbg_ram_capture.h
	dma_capture.c
	dma_capture.h
	mathfp.c
	mathfp.h
	nxp_xcvr_lcl_step_mgr.c
	nxp_xcvr_lcl_step_mgr.h
	nxp_xcvr_lcl_step_structs.h
)

# Create the library
add_library(XCVR_library STATIC
	${COMMON_SOURCES}
	${PLATFORM_SOURCES}
)

# Set include directories
target_include_directories(XCVR_library
	PUBLIC
		${CMAKE_CURRENT_SOURCE_DIR}
		${CMAKE_CURRENT_SOURCE_DIR}/${PLATFORM_TARGET}
		${PLATFORM_INCLUDES}
		${CMAKE_CURRENT_SOURCE_DIR}/nb2p4ghz
		${SDK_DIR}/drivers/common
)

# Apply platform-specific compiler definitions if defined
if(DEFINED PLATFORM_DEFINES)
	target_compile_definitions(XCVR_library PRIVATE ${PLATFORM_DEFINES})
endif()

# Apply platform-specific compiler options if defined
if(DEFINED PLATFORM_COMPILE_OPTIONS)
	target_compile_options(XCVR_library PRIVATE ${PLATFORM_COMPILE_OPTIONS})
endif()

# Set library properties
set_target_properties(XCVR_library PROPERTIES
	OUTPUT_NAME "xcvr_${PLATFORM_TARGET}"
	ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
)

# Print configuration information
message(STATUS "Building for platform: ${PLATFORM_TARGET}")
if(DEFINED PLATFORM_DEFINES)
	message(STATUS "Platform defines: ${PLATFORM_DEFINES}")
endif()

add_custom_command(TARGET XCVR_library
	POST_BUILD
	COMMAND cmake -E echo "Copying xcvr_${PLATFORM_TARGET}.a to ${SDK_DIR}/middleware/wireless/XCVR/lib"
	COMMAND cmake -E copy ${CMAKE_BINARY_DIR}/lib/xcvr_${PLATFORM_TARGET}.a ${SDK_DIR}/middleware/wireless/XCVR/lib
	VERBATIM
)

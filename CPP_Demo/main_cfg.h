#pragma once

// main_cfg.h
// CPP_Demo

/* Copyright(c) Vector Informatik GmbH.All rights reserved.
   Licensed under the MIT license.See LICENSE file in the project root for details. */

// Application configuration:
// XCP configuration is in xcp_cfg.h (Protocol Layer) and xcptl_cfg.h (Transport Layer)

#define APP_NAME                "CPP_Demo"
#define APP_VERSION_MAJOR       6
#define APP_VERSION_MINOR       0
#define APP_CPP_Demo


#define ON 1
#define OFF 0


// Debug prints
#define OPTION_ENABLE_DBG_PRINTS        ON
#define OPTION_DEBUG_LEVEL              2 
#define OPTION_UDP_DEBUG_LEVEL          0  


// Enable demo how to measure dynamic instances
#define OPTION_ENABLE_DYNAMIC_DEMO        ON


// A2L generation
#define OPTION_ENABLE_A2L_GEN            ON             // Enable A2L generation
#if OPTION_ENABLE_A2L_GEN
  #define OPTION_ENABLE_A2L_SYMBOL_LINKS ON             // Enable generation of symbol links (required for CANape integrated linker map update)
  #define OPTION_A2L_NAME                "CPP_Demo"     // A2L name 
  #define OPTION_A2L_FILE_NAME           "CPP_Demo.a2l" // A2L filename 
  #define OPTION_A2L_PROJECT_NAME        "CPP_Demo"     // A2L project name
#endif


// Set clock resolution (for clock function in platform.c)
#define CLOCK_USE_APP_TIME_US
//#define CLOCK_USE_UTC_TIME_NS


// Ethernet Transport Layer
#define OPTION_ENABLE_ETH_TRANSPORT     ON 
#define OPTION_USE_TCP                  OFF 
#define OPTION_MTU                      1500            // Ethernet MTU
#define OPTION_SERVER_PORT              5555            // Default UDP port
#define OPTION_SERVER_ADDR              {127,0,0,1}       // IP addr to bind, 0.0.0.0 = ANY


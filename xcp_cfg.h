/*----------------------------------------------------------------------------
| File:
|   XCP_CFG.H
|   V1.0 23.9.2020
|
| Project:
|   Konfiguration file for XCP basic driver
|   Linux XCP on UDP demo (Tested on RaspberryPi4)
 ----------------------------------------------------------------------------*/

#if defined ( __XCP_CFG_H__ )
#else
#define __XCP_CFG_H__


// General includes
#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/time.h>
#include <time.h>
#include <pthread.h> // link with -lpthread

/*----------------------------------------------------------------------------*/
/* Platform specific definitions */

  /* 8-Bit  */
typedef unsigned char  vuint8;
typedef signed char    vsint8;

/* 16-Bit  */
typedef unsigned short vuint16;
typedef signed short   vsint16;

/* 32-Bit  */
typedef unsigned long  vuint32;
typedef signed long    vsint32;

/* Byte order */
//#define XCP_CPUTYPE_BIGENDIAN  /* Motorola */
#define XCP_CPUTYPE_LITTLEENDIAN /* Intel */

/* Memory qualifiers */
#define MEMORY_CONST const
#define MEMORY_ROM const


/*----------------------------------------------------------------------------*/
/* XCP Driver Callbacks as macros */

// Convert a XCP (BYTE addrExt, DWORD addr from A2L) address to a C pointer to unsigned byte
// extern BYTEPTR ApplXcpGetPointer(vuint8 addr_ext, vuint32 addr)
#define ApplXcpGetPointer(e,a) ((BYTEPTR)((a)))

// Get and commit buffer space for a DTO message
extern unsigned char* udpServerGetPacketBuffer(unsigned int size, void** par);
extern void udpServerCommitPacketBuffer(void* par);
#define ApplXcpGetDtoBuffer udpServerGetPacketBuffer
#define ApplXcpCommitDtoBuffer udpServerCommitPacketBuffer


/*----------------------------------------------------------------------------*/
/* Test instrumentation */

/* Turn on screen logging, assertions and parameter checks */

#define XCP_ENABLE_TESTMODE
#ifdef XCP_ENABLE_TESTMODE
  #define ApplXcpPrint printf
  #define XCP_ASSERT(x) if (!(x)) ApplXcpPrint("Assertion failed\n");
  #define XCP_ENABLE_PARAMETER_CHECK
#endif


/*----------------------------------------------------------------------------*/
/* XCP protocol parameters */

#define XCP_UDP_MTU (1500-20-8)  // IPv4 1500 ETH - 28 IP - 8 UDP

/* XCP message length */
#define kXcpMaxCTO     250      /* Maximum CTO and CRM Message Lenght */
#define kXcpMaxDTO     (XCP_UDP_MTU-4)      /* Maximum DTO Message Lenght UDP_MTU - Transport Layer Header */

#define XCP_ENABLE_CALIBRATION
#define XCP_DISABLE_WRITE_PROTECTION
#define XCP_DISABLE_READ_PROTECTION
#define XCP_ENABLE_GET_SESSION_STATUS_API
#define XCP_DISABLE_GET_XCP_DATA_POINTER
#define XCP_DISABLE_MEM_MAPPING

/* Standard commands */
#define XCP_ENABLE_COMM_MODE_INFO
#define XCP_DISABLE_MODIFY_BITS
#define XCP_DISABLE_USER_COMMAND
#define XCP_ENABLE_SHORT_DOWNLOAD
#define XCP_ENABLE_SHORT_UPLOAD
#define XCP_ENABLE_BLOCK_UPLOAD
#define XCP_ENABLE_BLOCK_DOWNLOAD


/* Synchronous Data Acquisition (DAQ) */

#define kXcpDaqMemSize 60000u  // Memory space reserved for DAQ tables

#define XCP_SEND_BUFFER


/* DAQ timestamp */
#define kXcpDaqTimestampSize 4
#define kXcpDaqTimestampUnit DAQ_TIMESTAMP_UNIT_1NS
#define kXcpDaqTimestampTicksPerUnit 1  
typedef vuint32 XcpDaqTimestampType;
extern XcpDaqTimestampType ApplXcpTimer(void);
extern int ApplXcpTimerInit(void);
#define ApplXcpGetTimestamp() (XcpDaqTimestampType)ApplXcpTimer()


#include "xcp_def.h" // Set remaining default


#endif


//---------------------------------------------------------------------
//   PROG : 
//   DATE : 2013.12
//   COMP : sh-rfid
//   FILE : mydatatype.h
//   DESP : all file list
//---------------------------------------------------------------------


#ifndef  __MYDATATYPE_h__
#define  __MYDATATYPE_h__

/*
*********************************************************************************************************
*                                              DATA TYPES
*                                         (Compiler Specific)
*********************************************************************************************************
*/

#define uchar unsigned char
#define uint  unsigned int
#define ulong unsigned long

#define TRUE 1
//#define NULL 0

typedef unsigned char  BOOLEAN;
typedef unsigned char  INT8U;                    /* Unsigned  8 bit quantity                           */
typedef signed   char  INT8S;                    /* Signed    8 bit quantity                           */
typedef unsigned int   INT16U;                   /* Unsigned 16 bit quantity                           */
typedef signed   int   INT16S;                   /* Signed   16 bit quantity                           */
typedef unsigned long  INT32U;                   /* Unsigned 32 bit quantity                           */
typedef signed   long  INT32S;                   /* Signed   32 bit quantity                           */
typedef float          FP32;                     /* Single precision floating point                    */
typedef double         FP64;                     /* Double precision floating point                    */
	                  

#ifdef   	MCU_VAR
#define 	EXT
#else 
#define 	EXT   extern 
#endif         


#endif
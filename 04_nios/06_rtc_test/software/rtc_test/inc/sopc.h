/*
 * =====================================================================================
 *
 *       Filename:  sopc.h
 *
 *    Description:  
 *
 *        Version:  1.0.0
 *        Created:  2016-8-6 10:09:46
 *       Revision:  
 *       Compiler:  Nios II Eclipse
 *
 *         Author:  ����(AVIC)
 *          Email:  avic633@gmail.com
 *            URL:  http://kingst.cnblogs.com
 *
 * =====================================================================================
 */

#ifndef SOPC_H_
#define SOPC_H_

/*-----------------------------------------------------------------------------
 *  Include
 *-----------------------------------------------------------------------------*/
#include "system.h"

/*-----------------------------------------------------------------------------
 *  Define
 *-----------------------------------------------------------------------------*/
#define _RTC

/*-----------------------------------------------------------------------------
 *  Struct  
 *-----------------------------------------------------------------------------*/
typedef struct
{
	unsigned long int DATA;
	unsigned long int DIRECTION;
	unsigned long int INTERRUPT_MASK;
	unsigned long int EDGE_CAPTURE;
}PIO_STR;

/*-----------------------------------------------------------------------------
 *  Peripheral declaration
 *-----------------------------------------------------------------------------*/
#ifdef _RTC
#define RTC_SCLK          ((PIO_STR *) (RTC_SCLK_BASE | 1<<31))
#define RTC_DATA          ((PIO_STR *) (RTC_DATA_BASE | 1<<31))
#define RTC_RST           ((PIO_STR *) (RTC_NRST_BASE | 1<<31))
#endif /* _RTC */

#endif /*SOPC_H_*/

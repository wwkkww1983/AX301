/*
 * =====================================================================================
 *
 *       Filename:  sopc.h
 *
 *    Description:  
 *
 *        Version:  1.0.0
 *        Created:  2016.4.16
 *       Revision:  none
 *       Compiler:  Nios II 12.1 Eclipse
 *
 *         Author:  ���� (AVIC)
 *			Email:  avic633@gmail.com  
 *			   QQ:  984597569
 *			  URL:  http://kingst.cnblogs.com
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
#define _LED

/*-----------------------------------------------------------------------------
 *  Peripheral registers structures  
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
#ifdef _LED
#define LED          ((PIO_STR *) (PIO_LED_BASE| 1<<31))
#endif /*_LED*/

#endif /*SOPC_H_*/


/*
 * =====================================================================================
 *
 *       Filename:  main.c
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

/*-----------------------------------------------------------------------------
 *  Include
 *-----------------------------------------------------------------------------*/
#include <stdio.h>
#include <sys/unistd.h>
#include <io.h>
#include <string.h>

#include "system.h"
#include "altera_avalon_pio_regs.h"
#include "altera_avalon_timer_regs.h"
#include "alt_types.h"
#include "sys/alt_irq.h"
#include "../inc/sopc.h"

/*-----------------------------------------------------------------------------
 *  Variable
 *-----------------------------------------------------------------------------*/
static void timer_init(void);    //��ʼ���ж�
static void ISR_timer1(void *context, alt_u32 id);
static void ISR_timer2(void *context, alt_u32 id);

int i = 0,j = 0,flag;
alt_u32 timer_prd[4] = {5000000, 10000000, 50000000, 100000000};//��ʱ��������


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
int main(void)
{
	//��ʼ��Timer
	//timer_init();

	//���Timer1�жϱ�־�Ĵ���
	IOWR_ALTERA_AVALON_TIMER_STATUS(TIMER1_BASE, 0x00);
	//����Timer1����
	IOWR_ALTERA_AVALON_TIMER_PERIODL(TIMER1_BASE,80000000);
	IOWR_ALTERA_AVALON_TIMER_PERIODH(TIMER1_BASE, 80000000 >> 16);
	//����Timer1�ж�
	IOWR_ALTERA_AVALON_TIMER_CONTROL(TIMER1_BASE, 0x07);
	//ע��Timer1�ж�
	alt_ic_isr_register(TIMER1_IRQ_INTERRUPT_CONTROLLER_ID,TIMER1_IRQ, ISR_timer1,(void *)TIMER1_BASE,0x0);

	//���Timer2�жϱ�־�Ĵ���
	IOWR_ALTERA_AVALON_TIMER_STATUS(TIMER2_BASE, 0x00);
	//����Timer2����
	IOWR_ALTERA_AVALON_TIMER_PERIODL(TIMER2_BASE,400000000);
	IOWR_ALTERA_AVALON_TIMER_PERIODH(TIMER2_BASE, 400000000 >> 16);
	//����Timer2�ж�
	IOWR_ALTERA_AVALON_TIMER_CONTROL(TIMER2_BASE, 0x07);
	//ע��Timer2�ж�
	alt_ic_isr_register(TIMER2_IRQ_INTERRUPT_CONTROLLER_ID,TIMER2_IRQ, ISR_timer2,(void *)TIMER2_BASE,0x0);

	while(1);

	return 0;
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  ISR_timer
 *  Description:  
 * =====================================================================================
 */
static void ISR_timer1(void *context, alt_u32 id)
{  
	//������ˮ����˸��һ���ĸ�LED
	LED->DATA = 1<<i;

	i++;

	if(i == 4)
		i = 0;    

	//���Timer�жϱ�־�Ĵ���
	IOWR_ALTERA_AVALON_TIMER_STATUS(TIMER1_BASE, 0x00);
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  ISR_timer2
 *  Description:  ͨ����ʱ��2���ı䶨ʱ��1�����ڣ��ı����Ҫ����������ʱ��
 * =====================================================================================
 */
static void ISR_timer2(void *context, alt_u32 id)
{
	//�ı䶨ʱ��1������
	IOWR_ALTERA_AVALON_TIMER_PERIODL(TIMER1_BASE, timer_prd[j]);
	IOWR_ALTERA_AVALON_TIMER_PERIODH(TIMER1_BASE, timer_prd[j] >> 16);  

	//����������ʱ��
	IOWR_ALTERA_AVALON_TIMER_CONTROL(TIMER1_BASE, 0x07); 

	//��˸Ƶ���ȸߺ��Ȼ���ֱ��
	if(j == 0)
		flag = 0;
	if(j == 3)
		flag = 1;

	if(flag == 0){
		j++;
	}
	else{
		j--;
	}

	//����жϱ�־λ
	IOWR_ALTERA_AVALON_TIMER_STATUS(TIMER2_BASE, 0);  
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  timer_init
 *  Description:  
 * =====================================================================================
 */
void timer_init(void)    //��ʼ���ж�
{
	//���Timer1�жϱ�־�Ĵ���
	IOWR_ALTERA_AVALON_TIMER_STATUS(TIMER1_BASE, 0x00);
	//����Timer1����
	IOWR_ALTERA_AVALON_TIMER_PERIODL(TIMER1_BASE,80000000);
	IOWR_ALTERA_AVALON_TIMER_PERIODH(TIMER1_BASE, 80000000 >> 16);
	//����Timer1�ж�
	IOWR_ALTERA_AVALON_TIMER_CONTROL(TIMER1_BASE, 0x07);     
	//ע��Timer1�ж�
	alt_ic_isr_register(TIMER1_IRQ_INTERRUPT_CONTROLLER_ID,TIMER1_IRQ, ISR_timer1,(void *)TIMER1_BASE,0x0);

	//���Timer2�жϱ�־�Ĵ���
	IOWR_ALTERA_AVALON_TIMER_STATUS(TIMER2_BASE, 0x00);
	//����Timer2����
	IOWR_ALTERA_AVALON_TIMER_PERIODL(TIMER2_BASE,400000000);
	IOWR_ALTERA_AVALON_TIMER_PERIODH(TIMER2_BASE, 400000000 >> 16);
	//����Timer2�ж�
	IOWR_ALTERA_AVALON_TIMER_CONTROL(TIMER2_BASE, 0x07);
	//ע��Timer2�ж�
	alt_ic_isr_register(TIMER2_IRQ_INTERRUPT_CONTROLLER_ID,TIMER2_IRQ, ISR_timer2,(void *)TIMER2_BASE,0x0);
}

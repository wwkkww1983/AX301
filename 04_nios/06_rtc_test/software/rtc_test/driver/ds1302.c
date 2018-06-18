/*
 * =====================================================================================
 *
 *       Filename:  ds1302.c
 *
 *    Description:  
 *
 *        Version:  1.0.0
 *        Created:  2016.4.16
 *       Revision:  none
 *       Compiler:  Nios II 12.1 Eclipse
 *         Author:  ���� (AVIC)
 *			Email:  avic633@gmail.com  
 *			  URL:  http://kingst.cnblogs.com
 *			  
 * =====================================================================================
 */

#include "../inc/ds1302.h"

static void delay(unsigned int dly);
static void write_1byte_to_ds1302(unsigned char da);
static unsigned char read_1byte_from_ds1302(void);
static void write_data_to_ds1302(unsigned char addr, unsigned char da);
static unsigned char read_data_from_ds1302(unsigned char addr); 
void set_time(unsigned char *ti);
void get_time(char *ti);

DS1302_STR ds1302={
	.set_time = set_time,
	.get_time = get_time
};

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  delay
 *  Description:   
 * =====================================================================================
 */ 
void delay(unsigned int dly) 
{   
	for(;dly>0;dly--); 
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  write_1byte_to_ds1302
 *  Description:  ��ds1302д��1 byte���� 
 * =====================================================================================
 */ 
void write_1byte_to_ds1302(unsigned char da) 
{ 
	unsigned int i;

	RTC_DATA_OUT;

	for(i=8; i>0; i--){ 
		if((da&0x01)!= 0) 
			RTC_DATA->DATA = 1; 
		else 
			RTC_DATA->DATA = 0; 

		delay(10); 
		RTC_SCLK->DATA = 1; 
		delay(20); 
		RTC_SCLK->DATA = 0;
		delay(10);

		da >>= 1; //�൱�ڻ���е� RRC 
	} 
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  read_1byte_from_ds1302
 *  Description:  ��ds1302��ȡ1 byte����
 * =====================================================================================
 */ 
unsigned char read_1byte_from_ds1302(void) 
{ 
	unsigned char i; 
	unsigned char da = 0; 

	RTC_DATA_IN;

	for(i=8; i>0; i--){ 
		delay(10); 
		da >>= 1; //�൱�ڻ���е� RRC 
		if(RTC_DATA->DATA !=0 )
			da += 0x80;

		RTC_SCLK->DATA = 1; 
		delay(20); 
		RTC_SCLK->DATA = 0; 
		delay(10); 
	}

	RTC_DATA_OUT;

	return(da); 
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  write_data_to_ds1302
 *  Description:  ��ds1302д������ 
 * =====================================================================================
 */ 
void write_data_to_ds1302(unsigned char addr, unsigned char da) 
{ 
	RTC_DATA_OUT;
	RTC_RST->DATA = 0;//��λ���͵�ƽ��Ч
	RTC_SCLK->DATA = 0;
	delay(40); 

	RTC_RST->DATA = 1;

	write_1byte_to_ds1302(addr); // ��ַ������ 
	write_1byte_to_ds1302(da); // д1Byte����

	RTC_SCLK->DATA = 1;
	RTC_RST->DATA = 0;

	delay(40); 
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  read_data_from_ds1302
 *  Description:  ��ds1302��ȡ���� 
 * =====================================================================================
 */
unsigned char read_data_from_ds1302(unsigned char addr) 
{ 
	unsigned char da;

	RTC_RST->DATA = 0;
	RTC_SCLK->DATA = 0;

	delay(40);

	RTC_RST->DATA = 1;

	write_1byte_to_ds1302(addr);
	da = read_1byte_from_ds1302();

	RTC_SCLK->DATA = 1;

	RTC_RST->DATA = 0;

	delay(40);

	return(da); 
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  set_time
 *  Description:  ����ʱ��  
 * =====================================================================================
 */
void set_time(unsigned char *ti) 
{ 
	unsigned char i; 
	unsigned char addr = 0x80; 

	write_data_to_ds1302(0x8e,0x00); // ��������,WP=0,д����

	for(i =7;i>0;i--){ 
		write_data_to_ds1302(addr,*ti); // �� �� ʱ �� �� ���� ��

		ti++; 
		addr +=2; 
	} 

	write_data_to_ds1302(0x8e,0x80); // ��������,WP=1,д����
}
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  get_time
 *  Description:  ��ȡʱ�� ,��ȡ��ʱ��ΪBCD�룬��Ҫת����ʮ����
 * =====================================================================================
 */
void get_time(char *ti) 
{ 
	unsigned char i; 
	unsigned char addr = 0x81; 
	char time;

	for (i=0;i<7;i++){ 
		time=read_data_from_ds1302(addr);//��ȡ��ʱ��ΪBCD��
		ti[i] = time/16*10+time%16;//��ʽΪ: �� �� ʱ �� �� ���� ��
		addr += 2; 
	}
}  
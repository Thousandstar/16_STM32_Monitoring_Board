/*�ļ�����LM393_Opto.h
  �����ˣ����ʤ
  ���ܣ�LM393����ת�ټƵ���������LM393_Opto.c��ͷ�ļ���
  �����ļ��� sys.h
  */
#include "sys.h"

//sws added 4.26
#include "timer.h"
#include "led.h" 
/* ���ʤ�޸�2014_4_4 */
//#define SensorIO0   {GPIOA->CRL&=0XFFFFFFFB;GPIOA->CRL|=8<<0;}	 //����ģʽ
#define SensorIO0   PAin(11)	   //������11����˿� 


u8 	LM393_Opto_Init(void);
u8 	SensorIO0_Scan(void);
u16 	SensorIO0_test(void);



#ifndef __TIMER_H
#define __TIMER_H
#include "sys.h"
//Mini STM32������
//��ʱ�� ��������			 
//����ԭ��@ALIENTEK
//2010/6/1

//ͨ���ı�TIM3->CCR2��ֵ���ı�ռ�ձȣ��Ӷ�����LED0������
//sws added 2014-4-16
//#define	JUMP0  PAin(9)



#define LED0_PWM_VAL TIM3->CCR2 

void TIM3_IRQHandler(void);

void Timerx_Init(u32 arr,u32 psc);
void PWM_Init(u16 arr,u16 psc);
#endif
























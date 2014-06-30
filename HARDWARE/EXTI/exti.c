#include "exti.h"
#include "led.h"
#include "key.h"
#include "delay.h"
#include "usart.h"

//sws addded 5-19
#include "LM393_Opto.h"
u16 i=0;
//Mini STM32������
//�ⲿ�ж� ��������			 
//����ԭ��@ALIENTEK
//2010/5/30  

//�ⲿ�ж�0�������
void EXTI0_IRQHandler(void)
{
	delay_ms(10);//����
	EXTI->PR=1<<0; 
	printf("��ȥ10���յ���");
	printf("%ld",i);
	printf("���ź�");
	printf("\n\r");
	printf("ת�٣�%d",i*60/10);
 	printf("rpm");
	printf("\n\r");
	i=0;

	 //���LINE0�ϵ��жϱ�־λ  
}

//�ⲿ�ж�15~10�������
void EXTI15_10_IRQHandler(void)
{			
	delay_ms(10);    //����			 
/*	if(KEY0==0)      //����0
	{
		LED0=!LED0;
	}else if(KEY1==0)//����1
	{
		LED1=!LED1;
	}
	
*/  
	i++;
	printf("i++");
	EXTI->PR=1<<13;     //���LINE13�ϵ��жϱ�־λ  
	EXTI->PR=1<<15;     //���LINE15�ϵ��жϱ�־λ  
}
//�ⲿ�жϳ�ʼ������
//��ʼ��PA0,PA13,PA15Ϊ�ж�����.
void EXTIX_Init(void)
{
	RCC->APB2ENR|=1<<2;     //ʹ��PORTAʱ��
	RCC->APB2ENR|=1<<0;     //��������ʱ��		  
	AFIO->MAPR&=0XF8FFFFFF; //���MAPR��[26:24]
	AFIO->MAPR|=0X04000000; //�ر�JTAG	    

//	GPIOA->CRL&=0XFFFFFFF0;//PA0���ó�����	  
//44	GPIOA->CRL|=0X00000008;   
	GPIOA->CRH&=0X0F0FFFFF;//PA13,15���ó�����	  
	GPIOA->CRH|=0X80800000; 				   
	GPIOA->ODR|=1<<13;	   //PA13����,PA0Ĭ������
	GPIOA->ODR|=1<<15;	   //PA15����

//	Ex_NVIC_Config(GPIO_A,0,RTIR); //�����ش���
	Ex_NVIC_Config(GPIO_B,0,RTIR); //�����ش���
	Ex_NVIC_Config(GPIO_A,13,RTIR);//�����ش���
	Ex_NVIC_Config(GPIO_A,15,FTIR);//�½��ش���

	MY_NVIC_Init(2,2,EXTI0_IRQChannel,2);    //��ռ2�������ȼ�2����2
	MY_NVIC_Init(2,1,EXTI15_10_IRQChannel,2);//��ռ2�������ȼ�1����2	   
}












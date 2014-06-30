#include <stm32f10x_lib.h>
#include "sys.h"
#include "usart.h"		
#include "delay.h"	
#include "led.h" 
#include "key.h"
#include "exti.h"
#include "wdg.h"
#include "timer.h"
	   
#include "rtc.h"
#include "wkup.h"
#include "adc.h"
#include "dma.h"
#include "24cxx.h"
#include "flash.h"
#include "touch.h"
#include "24l01.h"
#include "mmc_sd.h"
#include "remote.h"
#include "ds18b20.h"
#include "adc.h"
#include "exti.h"

#include "LM393_Opto.h"
//Mini STM32�����巶������22
//����ң�� ʵ��
//����ԭ��@ALIENTEK
//2010.6.17	
				

/*
   "*********************   test.c    **********************\n\r"
   "|        MINISTM32���������Ӳ�����ϵͳ��֤����        |\n\r"
   "|          ����USART �첽ͨ��Э�鼰STM32�̼��⹹��      |\n\r"
   "|               ��������������Ϣ��ȫʵ����              |\n\r"
   "|                       Ӳ��������                      |\n\r"
   "|                       2014��4��                       |\n\r"
   "*-------------------------------------------------------*\n\r";
*/			
int main(void)
{	
	short tem;
	  
	u16 i=0;

	u16 vol=0;

	u8 flag1=0;  

	u8 sensor0=0;

	u8 PB=PB0;
	
    float voltage;
	
	
					    
  	Stm32_Clock_Init(9);//ϵͳʱ������
	delay_init(72);		//��ʱ��ʼ��
	uart_init(72,9600); //����1��ʼ��

	printf("   HELLO.STM32!!!11");	
 //	LED_Init();
	printf("   HELLO.STM32!!!22");
	if(DS18B20_Init()==1)
	{
		printf("error!!");

	}

//	Adc_Init();
//	Timerx_Init(50000,7199);
//	EXTIX_Init();

	while(1)
	{
		
		delay_ms(200);	
		tem=DS18B20_Get_Temp();
			if(tem<0)
				{
					tem=-tem;
					printf("-");	
				}						 
					printf("�¶ȣ�temp:%d",tem/10);
					printf(".%d",tem%10);
					printf("\n\r");

	}

//u8 flag2=1;
 /*
  	while (1)
  	{	
		tem=DS18B20_Get_Temp();
		sensor0	= SensorIO0_Scan();

//���ʤ�޸�2014_4_4
		if(sensor0==1)
		{
			flag1=1;
//			printf("sensor0==1");
		}else if((flag1==1)&&(sensor0==0))
		{
			flag1=0;
			
//			printf("(flag1==1)&&(sensor0==0)");
//			printf("������0������һ���½��أ������źű��:");
			i++;
//			printf("%ld",i);

//			printf("\n\r");

		}

//		if(PB^PB0)	
delay_ms(200);	
			{
				printf("��ȥ5���յ���");
				printf("%ld",i);
			    printf("���ź�");
			 	printf("\n\r");
				printf("ת�٣�%d",i*60/5);
 			    printf("rpm");
			 	printf("\n\r");
				vol=Get_Adc(ADC_CH0);
				voltage=(float)vol*(3.3/4096);
				i=0;
				if(tem<0)
				{
					tem=-tem;
					printf("-");	
				}						 
					printf("�¶ȣ�temp:%d",tem/10);
					printf(".%d",tem%10);
					printf("\n\r");
					printf("��ѹ��vol:%f",voltage);
					printf("\n\r");
//			PB=PB0;
			}

	}

	
		 */
	   
}


				 






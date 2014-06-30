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
//Mini STM32开发板范例代码22
//红外遥控 实验
//正点原子@ALIENTEK
//2010.6.17	
				

/*
   "*********************   test.c    **********************\n\r"
   "|        MINISTM32开发板带外硬件监控系统验证程序        |\n\r"
   "|          基于USART 异步通信协议及STM32固件库构建      |\n\r"
   "|               哈工程网络与信息安全实验室              |\n\r"
   "|                       硬件开发组                      |\n\r"
   "|                       2014年4月                       |\n\r"
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
	
	
					    
  	Stm32_Clock_Init(9);//系统时钟设置
	delay_init(72);		//延时初始化
	uart_init(72,9600); //串口1初始化

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
					printf("温度：temp:%d",tem/10);
					printf(".%d",tem%10);
					printf("\n\r");

	}

//u8 flag2=1;
 /*
  	while (1)
  	{	
		tem=DS18B20_Get_Temp();
		sensor0	= SensorIO0_Scan();

//孙帷胜修改2014_4_4
		if(sensor0==1)
		{
			flag1=1;
//			printf("sensor0==1");
		}else if((flag1==1)&&(sensor0==0))
		{
			flag1=0;
			
//			printf("(flag1==1)&&(sensor0==0)");
//			printf("传感器0传回了一个下降沿，周期信号编号:");
			i++;
//			printf("%ld",i);

//			printf("\n\r");

		}

//		if(PB^PB0)	
delay_ms(200);	
			{
				printf("过去5秒收到了");
				printf("%ld",i);
			    printf("个信号");
			 	printf("\n\r");
				printf("转速：%d",i*60/5);
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
					printf("温度：temp:%d",tem/10);
					printf(".%d",tem%10);
					printf("\n\r");
					printf("电压：vol:%f",voltage);
					printf("\n\r");
//			PB=PB0;
			}

	}

	
		 */
	   
}


				 






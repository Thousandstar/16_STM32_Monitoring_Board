#include "exti.h"
#include "led.h"
#include "key.h"
#include "delay.h"
#include "usart.h"

//sws addded 5-19
#include "LM393_Opto.h"
u16 i=0;
//Mini STM32开发板
//外部中断 驱动代码			 
//正点原子@ALIENTEK
//2010/5/30  

//外部中断0服务程序
void EXTI0_IRQHandler(void)
{
	delay_ms(10);//消抖
	EXTI->PR=1<<0; 
	printf("过去10秒收到了");
	printf("%ld",i);
	printf("个信号");
	printf("\n\r");
	printf("转速：%d",i*60/10);
 	printf("rpm");
	printf("\n\r");
	i=0;

	 //清除LINE0上的中断标志位  
}

//外部中断15~10服务程序
void EXTI15_10_IRQHandler(void)
{			
	delay_ms(10);    //消抖			 
/*	if(KEY0==0)      //按键0
	{
		LED0=!LED0;
	}else if(KEY1==0)//按键1
	{
		LED1=!LED1;
	}
	
*/  
	i++;
	printf("i++");
	EXTI->PR=1<<13;     //清除LINE13上的中断标志位  
	EXTI->PR=1<<15;     //清除LINE15上的中断标志位  
}
//外部中断初始化程序
//初始化PA0,PA13,PA15为中断输入.
void EXTIX_Init(void)
{
	RCC->APB2ENR|=1<<2;     //使能PORTA时钟
	RCC->APB2ENR|=1<<0;     //开启辅助时钟		  
	AFIO->MAPR&=0XF8FFFFFF; //清除MAPR的[26:24]
	AFIO->MAPR|=0X04000000; //关闭JTAG	    

//	GPIOA->CRL&=0XFFFFFFF0;//PA0设置成输入	  
//44	GPIOA->CRL|=0X00000008;   
	GPIOA->CRH&=0X0F0FFFFF;//PA13,15设置成输入	  
	GPIOA->CRH|=0X80800000; 				   
	GPIOA->ODR|=1<<13;	   //PA13上拉,PA0默认下拉
	GPIOA->ODR|=1<<15;	   //PA15上拉

//	Ex_NVIC_Config(GPIO_A,0,RTIR); //上升沿触发
	Ex_NVIC_Config(GPIO_B,0,RTIR); //上升沿触发
	Ex_NVIC_Config(GPIO_A,13,RTIR);//上升沿触发
	Ex_NVIC_Config(GPIO_A,15,FTIR);//下降沿触发

	MY_NVIC_Init(2,2,EXTI0_IRQChannel,2);    //抢占2，子优先级2，组2
	MY_NVIC_Init(2,1,EXTI15_10_IRQChannel,2);//抢占2，子优先级1，组2	   
}













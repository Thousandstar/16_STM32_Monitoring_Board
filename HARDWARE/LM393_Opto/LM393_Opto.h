/*文件名：LM393_Opto.h
  负责人：孙帷胜
  功能：LM393光耦转速计的驱动程序LM393_Opto.c的头文件。
  依赖文件： sys.h
  */
#include "sys.h"

//sws added 4.26
#include "timer.h"
#include "led.h" 
/* 孙帷胜修改2014_4_4 */
//#define SensorIO0   {GPIOA->CRL&=0XFFFFFFFB;GPIOA->CRL|=8<<0;}	 //输入模式
#define SensorIO0   PAin(11)	   //传感器11输入端口 


u8 	LM393_Opto_Init(void);
u8 	SensorIO0_Scan(void);
u16 	SensorIO0_test(void);



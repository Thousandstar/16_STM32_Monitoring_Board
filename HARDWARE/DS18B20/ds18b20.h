#ifndef __DS18B20_H
#define __DS18B20_H 
#include "sys.h"   
//Mini STM32开发板
//DS18B20 驱动函数 
//正点原子@ALIENTEK
//2010/6/17	

//IO方向设置
#define DS18B20_IO_IN()  {GPIOB->CRH&=0XFFFFF0FF;GPIOB->CRH|=0X00000800;}
#define DS18B20_IO_OUT() {GPIOB->CRH&=0XFFFFF0FF;GPIOB->CRH|=0X00000300;}
////IO操作函数											   
#define	DS18B20_DQ_OUT PBout(10) //数据端口	PB10 
#define	DS18B20_DQ_IN  PBin(10)  //数据端口	PB10 

   	
u8 DS18B20_Init(void);//初始化DS18B20
short DS18B20_Get_Temp(void);//获取温度
void DS18B20_Start(void);//开始温度转换
void DS18B20_Write_Byte(u8 dat);//写入一个字节
u8 DS18B20_Read_Byte(void);//读出一个字节
u8 DS18B20_Read_Bit(void);//读出一个位
u8 DS18B20_Check(void);//检测是否存在DS18B20
void DS18B20_Rst(void);//复位DS18B20    
#endif
















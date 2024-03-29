#ifndef _MMC_SD_H_
#define _MMC_SD_H_		 	 
#include <stm32f10x_lib.h> 
//Mini STM32开发板
//SD卡 驱动 
//正点原子@ALIENTEK
//2010/6/13	

//SD传输数据结束后是否释放总线宏定义  
#define NO_RELEASE      0
#define RELEASE         1
		   
// SD卡类型定义  
#define SD_TYPE_MMC     0
#define SD_TYPE_V1      1
#define SD_TYPE_V2      2
#define SD_TYPE_V2HC    4	    	  

// SD卡指令表  	   
#define CMD0    0       //卡复位
#define CMD9    9       //命令9 ，读CSD数据
#define CMD10   10      //命令10，读CID数据
#define CMD12   12      //命令12，停止数据传输
#define CMD16   16      //命令16，设置SectorSize 应返回0x00
#define CMD17   17      //命令17，读sector
#define CMD18   18      //命令18，读Multi sector
#define ACMD23  23      //命令23，设置多sector写入前预先擦除N个block
#define CMD24   24      //命令24，写sector
#define CMD25   25      //命令25，写Multi sector
#define ACMD41  41      //命令41，应返回0x00
#define CMD55   55      //命令55，应返回0x01
#define CMD58   58      //命令58，读OCR信息
#define CMD59   59      //命令59，使能/禁止CRC，应返回0x00
					 
//这部分应根据具体的连线来修改!
//Mini STM32使用的是PA3作为SD卡的CS脚.
#define	SD_CS  PAout(3) //SD卡片选引脚					    	  

extern u8  SD_Type;//SD卡的类型
//函数申明区 
u8 SD_WaitReady(void);                          //等待SD卡就绪
u8 SD_SendCommand(u8 cmd, u32 arg, u8 crc);     //SD卡发送一个命令
u8 SD_SendCommand_NoDeassert(u8 cmd, u32 arg, u8 crc);
u8 SD_Init(void);                               //SD卡初始化
u8 SD_Idle_Sta(void);                           //设置SD卡到挂起模式

u8 SD_ReceiveData(u8 *data, u16 len, u8 release);//SD卡读数据
u8 SD_GetCID(u8 *cid_data);                     //读SD卡CID
u8 SD_GetCSD(u8 *csd_data);                     //读SD卡CSD
u32 SD_GetCapacity(void);                       //取SD卡容量

u8 SD_ReadSingleBlock(u32 sector, u8 *buffer);  //读一个sector
u8 SD_WriteSingleBlock(u32 sector, const u8 *buffer); 		//写一个sector
u8 SD_ReadMultiBlock(u32 sector, u8 *buffer, u8 count); 	//读多个sector
u8 SD_WriteMultiBlock(u32 sector, const u8 *data, u8 count);//写多个sector
u8 SD_Read_Bytes(unsigned long address,unsigned char *buf,unsigned int offset,unsigned int bytes);//读取一byte
#endif





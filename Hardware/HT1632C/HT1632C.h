/**
  ******************************************************************************
  * @file    HT1632C.h
  * @author  KylinDC(inlovingdays@gmail.com)
  * @version V1.0
  * @date    14-May-2016
  * @brief	 HT1632C.c头文件
  ******************************************************************************
  * @description
  *
  * 宏定义指令表
  * 宏定义引脚操作
  *
  ******************************************************************************
  */

#ifndef	_HT1632C_H_
#define	_HT1632C_H_

#include "gpio.h"
#include "sys.h"

/*--指令表--*/
#define SYS_DIS             0x00			//关闭系统震荡
#define SYS_EN              0x01			//打开系统震荡
#define LED_OFF             0x02			//关闭LED显示
#define LED_ON              0x03			//打开LED显示
#define BLINK_OFF           0x08			//关闭闪烁
#define	BLINK_ON            0X09		   	//打开闪烁
#define	SLAVE_MODE          0X10		   	//从模式
#define	RC_MASTER_MODE      0X18	   		//内部RC时钟
#define	EXT_CLK_MASTER_MODE	0X1C   			//外部时钟
#define COM_OPTION          0X20		   	//8COM，NMOS模式
#define PWM_DUTY            0XAD			//PWM亮度控制(0xA0~0xAF)
#define	CMD                 1				//1代表发送命令，0为数据
#define	DAT                 0

/*--引脚操作定义--*/
#define CS_high		CS2=CS1=1
#define CS1_high 	CS1=1
#define CS2_high	CS2=1
#define CS_low		CS2=CS1=0
#define CS1_low 	CS1=0
#define CS2_low 	CS2=0
#define WR_high		WR=1
#define WR_low		WR=0
#define DATA_high	DATA=1
#define DATA_low	DATA=0

void HT1632C_Writer(unsigned char Data, unsigned char cnt, unsigned char type);
void HT1632C_Writer_CMD(unsigned char cmd);
void HT1632C_Writer_DATA(unsigned char Addr, unsigned char Data);
void HT1632C_Writer_AllDATA(unsigned char Addr, unsigned char *p, unsigned char cnt);
void HT1632C_clr(void);
void HT1632C_Init(void);
#endif

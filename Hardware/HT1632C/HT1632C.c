/**
  ******************************************************************************
  * @file    HT1632C.c
  * @author  KylinDC(inlovingdays@gmail.com)
  * @version V1.0
  * @date    14-May-2016
  * @brief	 向HT1632C写入数据点亮相应的LED灯
  ******************************************************************************
  * @description
  *
  * CS    高电平禁止
  *   	  低电平写入
  * WR    上升沿DATA写入数据
  * RD    下降沿DATA读出数据
  *
  ******************************************************************************
  */

#include "HT1632C.h"

/**
  * @brief  写入指令或数据
  * @param  None
  * @retval None
  */
void HT1632C_Writer(unsigned char Data, unsigned char cnt, unsigned char type)
{
	unsigned char i;
	if (type == CMD)	//判断数据是否为指令
	{
		for (i = 0; i < cnt; i++)
		{
			WR_low;
			if (Data & 0x80)
				DATA_high;
			else
				DATA_low;
			Data <<= 1;
			WR_high;
		}
	}
	else
	{
		for (i = 0; i < cnt; i++)
		{
			WR_low;
			if (Data & 0x01)
				DATA_high;
			else
				DATA_low;
			Data >>= 1;
			WR_high;
		}
	}
}

/**
  * @brief  写入指令
  * @param  None
  * @retval None
  */
void HT1632C_Writer_CMD(unsigned char cmd)
{
	CS_low;
	HT1632C_Writer(0x80, 3, CMD);
	HT1632C_Writer(cmd, 9, CMD);
	CS_high;
}

/**
  * @brief  写入单个数据
  * @param  None
  * @retval None
  */
void HT1632C_Writer_DATA(unsigned char Addr, unsigned char Data)
{
	if (Addr < 0x80)
	{
		CS1_low;
		HT1632C_Writer(0xa0, 3, CMD);
		HT1632C_Writer(Addr << 1, 7, CMD);
		HT1632C_Writer(Data, 8, DAT);
		CS1_high;
	}
	else
	{
		CS2_low;
		HT1632C_Writer(0xa0, 3, CMD);
		HT1632C_Writer(Addr << 1, 7, CMD);
		HT1632C_Writer(Data, 8, DAT);
		CS2_high;
	}
}

/**
  * @brief  批量写入数据
  * @param  None
  * @retval None
  */
void HT1632C_Writer_AllDATA(unsigned char Addr, unsigned char *p, unsigned char cnt)
{
	if (Addr < 0x80)
	{
		unsigned char i;
		CS1_low;
		HT1632C_Writer(0xa0, 3, CMD);
		HT1632C_Writer(Addr << 1, 7, CMD);
		for (i = 0; i < cnt; i++)
		{
			HT1632C_Writer(*p, 8, DAT);
			p++;
		}
		CS1_high;
	}
	else
	{
		unsigned char i;
		CS2_low;
		HT1632C_Writer(0xa0, 3, CMD);
		HT1632C_Writer(Addr << 1, 7, CMD);
		for (i = 0; i < cnt; i++)
		{
			HT1632C_Writer(*p, 8, DAT);
			p++;
		}
		CS2_high;
	}
}

/**
  * @brief  全灭所有LED灯
  * @param  None
  * @retval None
  */
void HT1632C_clr(void)
{
	unsigned char i;
	CS_low;
	HT1632C_Writer(0xa0, 3, CMD);
	HT1632C_Writer(0x00, 7, CMD);
	for (i = 0; i < 32; i++)
		HT1632C_Writer(0x00, 8, DAT);
	CS_high;
}

/**
  * @brief  初始化HT1632C芯片
  * @param  None
  * @retval None
  */
void HT1632C_Init(void)
{
	CS_high;
	WR_high;
	DATA_high;
	HT1632C_Writer_CMD(SYS_DIS);
	HT1632C_Writer_CMD(COM_OPTION);
	HT1632C_Writer_CMD(RC_MASTER_MODE);
	HT1632C_Writer_CMD(SYS_EN);
	HT1632C_Writer_CMD(PWM_DUTY);
	HT1632C_Writer_CMD(BLINK_OFF);
	HT1632C_Writer_CMD(LED_ON);
	HT1632C_clr();
}

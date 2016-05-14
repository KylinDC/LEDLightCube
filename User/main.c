/**
  ******************************************************************************
  * @file    mian.c
  * @author  KylinDC(inlovingdays@gmail.com)
  * @version V1.0
  * @date    14-May-2016
  * @brief   将串口接收的数据处理后传给LED驱动芯片
  ******************************************************************************
  * @description
  *
  * 初始化外设芯片、I/O口、串口及中断
  * 将串口传递的数据存储到temp[]数组
  * 将temp[]数组分割为temp1[]及temp2[]两个数组
  * 分别向CS1及CS2写入数据
  *
  ******************************************************************************
  */

#include "stm32f10x.h"
#include "gpio.h"
#include "usart1.h"
#include "HT1632C.h"
#include "sys.h"


unsigned char temp[65];     //定义数组接收来自串口的数据
unsigned char a = 0;      //接收串口数据计数

/**
  * @brief  将数组temp[]写入HT1632C芯片，点亮相应的LED灯
  * @param  数组temp1[]、temp2[]储存分割的temp[]
  * @retval None
  */
void Enlight()
{
	unsigned char temp1[32];  //定义数组储存向CS1写入的数据
	unsigned char temp2[32];  //定义数组储存向CS2写入的数据
	unsigned char i;
	unsigned char t;
//  HT1632C_clr();
	for (i = 0; i < 32 ; i++) //除去头数据后，将temp[]分为两个数组
		temp1[i] = temp[i + 1];
	for (t = 0; t < 32 ; t++)
		temp2[t] = temp[t + 33];
	HT1632C_Writer_AllDATA(0x00, temp1, 32);  //向CS1写入数据
	HT1632C_Writer_AllDATA(0x80, temp2, 32);  //向CS2写入数据
	a = 0;
}

/**
  * @brief  中断接收串口数据
  * @param  None
  * @retval None
  */
void USART1_IRQHandler(void)
{
	if (USART_GetITStatus(USART1, USART_IT_RXNE))
	{
		temp[a] = USART_ReceiveData(USART1);  //接收来自串口的数据
		a++;
		if (a >= 65)              //如果数组temp[]存满
			Enlight();
	}
}

/**
  * @brief  初始化I/O口、串口、中断、HT1632C芯片
  * @param  None
  * @retval None
  */
int main(void)
{
	My_GPIO_Init();
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);   //设置中断优先级为2
	My_USART1_Init();
	HT1632C_Init();
	HT1632C_clr();
	while (1);
}

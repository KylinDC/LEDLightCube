/**
  ******************************************************************************
  * @file    usart1.c
  * @author  KylinDC(inlovingdays@gmail.com)
  * @version V1.0
  * @date    14-May-2016
  * @brief	 初始化串口及中断
  ******************************************************************************
  */

#include "usart1.h"
#include "stm32f10x.h"

/**
  * @brief  初始化串口及中断
  * @param  None
  * @retval None
  */
void My_USART1_Init(void)
{
	/*--定义I/O口、串口、中断--*/
	GPIO_InitTypeDef GPIO_InitStrue;
	USART_InitTypeDef USART_InitStrue;
	NVIC_InitTypeDef NVIC_InitStrue;

	/*--I/O口初始化--*/
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);	//使能I/O口时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);	//使能串口时钟

	GPIO_InitStrue.GPIO_Mode = GPIO_Mode_AF_PP;				//设置为复用推挽输出
	GPIO_InitStrue.GPIO_Pin = GPIO_Pin_9;
	GPIO_InitStrue.GPIO_Speed = GPIO_Speed_10MHz;
	GPIO_Init(GPIOA, &GPIO_InitStrue);

	GPIO_InitStrue.GPIO_Mode = GPIO_Mode_IN_FLOATING;		//设置为浮空输入
	GPIO_InitStrue.GPIO_Pin = GPIO_Pin_10;
	GPIO_InitStrue.GPIO_Speed = GPIO_Speed_10MHz;
	GPIO_Init(GPIOA, &GPIO_InitStrue);

	/*--串口初始化--*/
	USART_InitStrue.USART_BaudRate = 115200;				//设置串口波特率
	USART_InitStrue.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStrue.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	USART_InitStrue.USART_Parity = USART_Parity_No;			//设置奇偶校验位为无
	USART_InitStrue.USART_StopBits = USART_StopBits_1;		//设置停止位为1
	USART_InitStrue.USART_WordLength = USART_WordLength_8b;	//设置字长为8位

	USART_Init(USART1, &USART_InitStrue);
	USART_Cmd(USART1, ENABLE);
	USART_ITConfig(USART1, USART_IT_RXNE, ENABLE); 			//打开接受中断

	/*--中断初始化--*/
	NVIC_InitStrue.NVIC_IRQChannel = USART1_IRQn;
	NVIC_InitStrue.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStrue.NVIC_IRQChannelPreemptionPriority = 1;	//设置响应优先级为1
	NVIC_InitStrue.NVIC_IRQChannelSubPriority = 1;
	NVIC_Init(&NVIC_InitStrue);
}

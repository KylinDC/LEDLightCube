#include "led.h"
#include "stm32f10x.h"
#include "delay.h"

void LED_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB, ENABLE); //GPIOA|B
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	GPIO_SetBits(GPIOA, GPIO_Pin_5);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	GPIO_SetBits(GPIOA, GPIO_Pin_6);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	GPIO_SetBits(GPIOA, GPIO_Pin_7);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	GPIO_SetBits(GPIOB, GPIO_Pin_0);
}

void My_USART1_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStrue;
	USART_InitTypeDef USART_InitStrue;
	NVIC_InitTypeDef NVIC_InitStrue;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);

	GPIO_InitStrue.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStrue.GPIO_Pin = GPIO_Pin_9;
	GPIO_InitStrue.GPIO_Speed = GPIO_Speed_10MHz;
	GPIO_Init(GPIOA, &GPIO_InitStrue);

	GPIO_InitStrue.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_InitStrue.GPIO_Pin = GPIO_Pin_10;
	GPIO_InitStrue.GPIO_Speed = GPIO_Speed_10MHz;
	GPIO_Init(GPIOA, &GPIO_InitStrue);

	USART_InitStrue.USART_BaudRate = 115200;
	USART_InitStrue.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStrue.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	USART_InitStrue.USART_Parity = USART_Parity_No;
	USART_InitStrue.USART_StopBits = USART_StopBits_1;
	USART_InitStrue.USART_WordLength = USART_WordLength_8b;

	USART_Init(USART1, &USART_InitStrue);

	USART_Cmd(USART1, ENABLE);

	USART_ITConfig(USART1, USART_IT_RXNE, ENABLE); //打开接受中断

	NVIC_InitStrue.NVIC_IRQChannel = USART1_IRQn;
	NVIC_InitStrue.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStrue.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitStrue.NVIC_IRQChannelSubPriority = 1;
	NVIC_Init(&NVIC_InitStrue);

}

/**
  ******************************************************************************
  * @file    gpio.c
  * @author  KylinDC(inlovingdays@gmail.com)
  * @version V1.0
  * @date    14-May-2016
  * @brief	 初始化I/O口
  ******************************************************************************
  */

#include "gpio.h"
#include "stm32f10x.h"

/**
  * @brief  初始化I/O口
  * @param  None
  * @retval None
  */
void My_GPIO_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB, ENABLE);	//使能GPIOA|B时钟
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;	//设置为推挽输出
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	//设置I/O口速度为50MHz

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

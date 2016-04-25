#include "button.h"
#include "stm32f10x.h"
#include "delay.h"

void BUTTON_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA || RCC_APB2Periph_GPIOB, ENABLE);
	GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable, ENABLE);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
}

u8 BUTTON_Scan(u8 mode)
{
	static u8 button_up = 1;
	if (mode)
		button_up = 1;
	if (button_up && (BUTTON0 == 0 || BUTTON1 == 0))
	{
		delay_ms(10);
		button_up = 1;
		if (BUTTON0 == 0)
			return BUTTON0_PRES;
		else if (BUTTON1 == 0)
			return BUTTON1_PRES;
	}
	else if (BUTTON0 == 1 && BUTTON1 == 1)
		button_up = 1;
	return 0;
}













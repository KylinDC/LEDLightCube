/**
  ******************************************************************************
  * @file    Project/STM32F10x_StdPeriph_Template/main.c
  * @author  MCD Application Team
  * @version V3.5.0
  * @date    08-April-2011
  * @brief   Main program body
  ******************************************************************************
  * @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2011 STMicroelectronics</center></h2>
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"
#include "led.h"
#include "delay.h"
#include "sys.h"
#include "usart.h"
#include "stm32f10x.h"

/**
  * @brief  Main program.
  * @param  None
  * @retval None
  */

int main(void)
{
    delay_init();
    LED_Init();
    while (1)
    {
        LED0 = 1;
        LED1 = 0;
        delay_ms(300);

        LED0 = 0;
        LED1 = 1;
        delay_ms(300);
    }
}


/**
int main(void)
{
  delay_init();
  LED_Init();
  while (1)
  {
    GPIO_SetBits(GPIOA, GPIO_Pin_7);
    GPIO_SetBits(GPIOB, GPIO_Pin_0);
    delay_ms(5000);
    GPIO_ResetBits(GPIOA, GPIO_Pin_7);
    GPIO_ResetBits(GPIOB, GPIO_Pin_0);
    delay_ms(5000);
  }
}
*/

/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/

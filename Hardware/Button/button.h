#ifndef __BUTTON_H
#define __BUTTON_H
#include "sys.h"

#define BUTTON0 GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_15)
#define BUTTON1 GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_3)

#define BUTTON0_PRES 1
#define BUTTON1_PRES 2

void BUTTON_Init(void);
u8 BUTTON_Scan(u8 mode);

#endif

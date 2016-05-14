/**
  ******************************************************************************
  * @file    gpio.h
  * @author  KylinDC(inlovingdays@gmail.com)
  * @version V1.0
  * @date    14-May-2016
  * @brief	 gpio.h头文件
  ******************************************************************************
  */

#ifndef _GPIO_H_
#define _GPIO_H_
#include "sys.h"

//宏定义I/O口
#define CS1 PAout(5)
#define CS2 PAout(6)
#define WR PAout(7)
#define DATA PBout(0)

void My_GPIO_Init(void);

#endif

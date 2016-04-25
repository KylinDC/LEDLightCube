#ifndef __LED_H
#define __LED_H
#include "sys.h"

#define CS1 PAout(5)
#define CS2 PAout(6)
#define WR PAout(7)
#define DATA PBout(0)

void LED_Init(void);

#endif

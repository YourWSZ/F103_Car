#ifndef __BEEP_H
#define __BEEP_H
#include "stm32f1xx_hal.h"
#define beep_PIN GPIO_PIN_13
#define beep_PORT GPIOC
//PC13连上了一颗LED，通过LED闪烁来判断延时长短


void beep_ON(void);
void beep_OFF(void);

#endif
/************************ (C) COPYRIGHT Wishengine *****END OF FILE****/

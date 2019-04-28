#include <main.h>
#include "beep.h"
#include "pwm.h"
#include "tim.h"

void beep_ON()
{
	HAL_GPIO_WritePin(beep_PORT,beep_PIN,GPIO_PIN_SET);
}

void beep_OFF()
{
	HAL_GPIO_WritePin(beep_PORT,beep_PIN,GPIO_PIN_RESET);
}
/************************ (C) COPYRIGHT Wishengine *****END OF FILE****/


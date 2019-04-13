#ifndef __PWM_H
#define __PWM_H
#include "stm32f1xx_hal.h"
#define AIN1_PIN GPIO_PIN_15
#define AIN1_PORT GPIOB
#define AIN2_PIN GPIO_PIN_14
#define AIN2_PORT GPIOB
#define BIN1_PIN GPIO_PIN_13
#define BIN1_PORT GPIOB
#define BIN2_PIN GPIO_PIN_12
#define BIN2_PORT GPIOB

#define AIN1_SET() HAL_GPIO_WritePin(AIN1_PORT,AIN1_PIN,GPIO_PIN_SET)
#define AIN2_SET() HAL_GPIO_WritePin(AIN2_PORT,AIN2_PIN,GPIO_PIN_SET)
#define BIN1_SET() HAL_GPIO_WritePin(BIN1_PORT,BIN1_PIN,GPIO_PIN_SET)
#define BIN2_SET() HAL_GPIO_WritePin(BIN2_PORT,BIN2_PIN,GPIO_PIN_SET)

#define AIN1_RESET() HAL_GPIO_WritePin(AIN1_PORT,AIN1_PIN,GPIO_PIN_RESET)
#define AIN2_RESET() HAL_GPIO_WritePin(AIN2_PORT,AIN2_PIN,GPIO_PIN_RESET)
#define BIN1_RESET() HAL_GPIO_WritePin(BIN1_PORT,BIN1_PIN,GPIO_PIN_RESET)
#define BIN2_RESET() HAL_GPIO_WritePin(BIN2_PORT,BIN2_PIN,GPIO_PIN_RESET)




void PWM_Init(void);
void PWM_SetDuty(TIM_HandleTypeDef *tim,uint32_t tim_channel,float duty);
#endif
/************************ (C) COPYRIGHT Wishengine *****END OF FILE****/

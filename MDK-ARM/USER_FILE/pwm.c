#include <main.h>
#include "pwm.h"
#include "tim.h"


void PWM_Init()   //PWM初始化
{

	HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_2);
}

void PWM_SetDuty(TIM_HandleTypeDef *tim,uint32_t tim_channel,float duty)  //PWM占空比设定函数   duty最大为1000
	{
	    switch(tim_channel)
			{
				case TIM_CHANNEL_1: tim->Instance->CCR1 = duty - 1;break;                     
				case TIM_CHANNEL_2: tim->Instance->CCR2 = duty - 1;break;                               
				case TIM_CHANNEL_3: tim->Instance->CCR3 = duty - 1;break;                                                   
				case TIM_CHANNEL_4: tim->Instance->CCR4 = duty - 1;break;					 
			}
	}


/************************************小车驱动引脚设定***************************************
	PWMA -> PA8 (TIM1_CH1)
	PWMB -> PA9 (TIM1_CH2)
	AIN1 -> PB15
	AIN2 -> PB14
	BIN1 -> PB13
	BIN2 -> PB12
	
*******************************************************************************************/
void Set_Pwm(int motor_a,int motor_b) //PWM设定函数
{
	    float duty; //PWM大小，最大1000，最小1
    	
/*---------------->电机A正转*<----------------*/		
		if(motor_a>0)			
		{
			duty=motor_a;
			PWM_SetDuty(&htim1,TIM_CHANNEL_1,duty);
			AIN1_SET();
			AIN2_RESET();
		}
/*---------------->电机A反转*<----------------*/ 			
		else	          		
		{
			duty=-motor_a;
			PWM_SetDuty(&htim1,TIM_CHANNEL_1,duty);
			AIN2_SET();
			AIN1_RESET();
		}
		
		
/*---------------->电机B正转*<----------------*/		
		if(motor_b>0)	
		{
			duty=motor_b;
			PWM_SetDuty(&htim1,TIM_CHANNEL_2,duty);
			BIN1_SET();
			BIN2_RESET();
		}
		
/*---------------->电机B反转*<----------------*/			
		else	            	
		{
			duty=-motor_b;
			PWM_SetDuty(&htim1,TIM_CHANNEL_2,duty);
			BIN2_SET();
			BIN1_RESET();
		}   
		

}


void stop()//停车函数
{
	PWM_SetDuty(&htim1,TIM_CHANNEL_1,0);
	PWM_SetDuty(&htim1,TIM_CHANNEL_2,0);
}
/************************ (C) COPYRIGHT Wishengine *****END OF FILE****/

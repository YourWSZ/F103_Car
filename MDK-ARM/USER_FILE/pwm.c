#include <main.h>
#include "pwm.h"
#include "tim.h"


void PWM_Init()   //PWM��ʼ��
{

	HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&htim1,TIM_CHANNEL_2);
}

void PWM_SetDuty(TIM_HandleTypeDef *tim,uint32_t tim_channel,float duty)  //PWMռ�ձ��趨����   duty���Ϊ1000
	{
	    switch(tim_channel)
			{
				case TIM_CHANNEL_1: tim->Instance->CCR1 = duty - 1;break;                     
				case TIM_CHANNEL_2: tim->Instance->CCR2 = duty - 1;break;                               
				case TIM_CHANNEL_3: tim->Instance->CCR3 = duty - 1;break;                                                   
				case TIM_CHANNEL_4: tim->Instance->CCR4 = duty - 1;break;					 
			}
	}


/************************************С�����������趨***************************************
	PWMA -> PA8 (TIM1_CH1)
	PWMB -> PA9 (TIM1_CH2)
	AIN1 -> PB15
	AIN2 -> PB14
	BIN1 -> PB13
	BIN2 -> PB12
	
*******************************************************************************************/
void Set_Pwm(int motor_a,int motor_b) //PWM�趨����
{
	    float duty; //PWM��С�����1000����С1
    	
/*---------------->���A��ת*<----------------*/		
		if(motor_a>0)			
		{
			duty=motor_a;
			PWM_SetDuty(&htim1,TIM_CHANNEL_1,duty);
			AIN1_SET();
			AIN2_RESET();
		}
/*---------------->���A��ת*<----------------*/ 			
		else	          		
		{
			duty=-motor_a;
			PWM_SetDuty(&htim1,TIM_CHANNEL_1,duty);
			AIN2_SET();
			AIN1_RESET();
		}
		
		
/*---------------->���B��ת*<----------------*/		
		if(motor_b>0)	
		{
			duty=motor_b;
			PWM_SetDuty(&htim1,TIM_CHANNEL_2,duty);
			BIN1_SET();
			BIN2_RESET();
		}
		
/*---------------->���B��ת*<----------------*/			
		else	            	
		{
			duty=-motor_b;
			PWM_SetDuty(&htim1,TIM_CHANNEL_2,duty);
			BIN2_SET();
			BIN1_RESET();
		}   
		

}


void stop()//ͣ������
{
	PWM_SetDuty(&htim1,TIM_CHANNEL_1,0);
	PWM_SetDuty(&htim1,TIM_CHANNEL_2,0);
}
/************************ (C) COPYRIGHT Wishengine *****END OF FILE****/

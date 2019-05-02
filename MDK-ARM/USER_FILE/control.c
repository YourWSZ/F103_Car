#include <main.h>
#include "control.h"

int status; //红外传感器状态

float Velocity_KP=10,Velocity_KI=10;	                        //速度控制PID参数
float Position_KP=40,Position_KI=0,Position_KD=40;              //位置控制PID参数



int Incremental_PI (int Encoder,int Target)
{ 	
	 static int Bias,Pwm,Last_bias;
	 Bias=Encoder-Target;                //计算偏差
	 Pwm+=Velocity_KP*(Bias-Last_bias)+Velocity_KI*Bias;   //增量式PI控制器
	 if(Pwm>720)Pwm=720;
	 if(Pwm<-720)Pwm=-720;
	 Last_bias=Bias;	                   //保存上一次偏差 
	 return Pwm;                         //增量输出
}



int Position_PID (int Encoder,int Target)
{ 	
	 static float Bias,Pwm,Integral_bias,Last_Bias;
	 Bias=Encoder-Target;                                  //计算偏差
	 Integral_bias+=Bias;	                                 //求出偏差的积分
	 if(Integral_bias>100000)Integral_bias=10000;
	 if(Integral_bias<-100000)Integral_bias=-10000;
	 Pwm=Position_KP*Bias+Position_KI/100*Integral_bias+Position_KD*(Bias-Last_Bias);       //位置式PID控制器
	 Last_Bias=Bias;                                       //保存上一次偏差 
	 return Pwm;                                           //增量输出
}

//获取红外传感器状态
void Read_Status()
{
	status=HAL_GPIO_ReadPin(TCRT1_PORT,TCRT1_PIN)<<3 | HAL_GPIO_ReadPin(TCRT2_PORT,TCRT2_PIN)<<2 | HAL_GPIO_ReadPin(TCRT3_PORT,TCRT3_PIN)<<1 | HAL_GPIO_ReadPin(TCRT4_PORT,TCRT4_PIN)<<0;
}

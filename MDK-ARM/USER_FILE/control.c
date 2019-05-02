#include <main.h>
#include "control.h"

int status; //���⴫����״̬

float Velocity_KP=10,Velocity_KI=10;	                        //�ٶȿ���PID����
float Position_KP=40,Position_KI=0,Position_KD=40;              //λ�ÿ���PID����



int Incremental_PI (int Encoder,int Target)
{ 	
	 static int Bias,Pwm,Last_bias;
	 Bias=Encoder-Target;                //����ƫ��
	 Pwm+=Velocity_KP*(Bias-Last_bias)+Velocity_KI*Bias;   //����ʽPI������
	 if(Pwm>720)Pwm=720;
	 if(Pwm<-720)Pwm=-720;
	 Last_bias=Bias;	                   //������һ��ƫ�� 
	 return Pwm;                         //�������
}



int Position_PID (int Encoder,int Target)
{ 	
	 static float Bias,Pwm,Integral_bias,Last_Bias;
	 Bias=Encoder-Target;                                  //����ƫ��
	 Integral_bias+=Bias;	                                 //���ƫ��Ļ���
	 if(Integral_bias>100000)Integral_bias=10000;
	 if(Integral_bias<-100000)Integral_bias=-10000;
	 Pwm=Position_KP*Bias+Position_KI/100*Integral_bias+Position_KD*(Bias-Last_Bias);       //λ��ʽPID������
	 Last_Bias=Bias;                                       //������һ��ƫ�� 
	 return Pwm;                                           //�������
}

//��ȡ���⴫����״̬
void Read_Status()
{
	status=HAL_GPIO_ReadPin(TCRT1_PORT,TCRT1_PIN)<<3 | HAL_GPIO_ReadPin(TCRT2_PORT,TCRT2_PIN)<<2 | HAL_GPIO_ReadPin(TCRT3_PORT,TCRT3_PIN)<<1 | HAL_GPIO_ReadPin(TCRT4_PORT,TCRT4_PIN)<<0;
}

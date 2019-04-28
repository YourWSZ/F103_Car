#ifndef __CONTROL_H
#define __CONTROL_H

//float Velocity_KP=10,Velocity_KI=10;	                        //�ٶȿ���PID����
//float Position_KP=40,Position_KI=0,Position_KD=40;              //λ�ÿ���PID����
/*

���⴫�����������ã�
           - - - - - - - 
		  |  P  P  P  P  |  ��ͷ    
		  |  A  A  A  A  |
		  |  3  4  5  6  |
		  |              |
		 
		                    ��β 

*/
#define TCRT1_PIN GPIO_PIN_3 
#define TCRT2_PIN GPIO_PIN_4
#define TCRT3_PIN GPIO_PIN_5
#define TCRT4_PIN GPIO_PIN_6

#define TCRT1_PORT GPIOA
#define TCRT2_PORT GPIOA
#define TCRT3_PORT GPIOA
#define TCRT4_PORT GPIOA


int Incremental_PI (int Encoder,int Target);
int Position_PID (int Encoder,int Target);


#endif
/************************ (C) COPYRIGHT Wishengine *****END OF FILE****/

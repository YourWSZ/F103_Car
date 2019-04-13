
#include "us100.h"
#include "usart.h"
char usart1_RxBuffer[2];
char usart1_TxBuffer[1];

void read_distance()
{
	usart1_TxBuffer[0]=0x50; //≤‚æ‡÷∏¡Ó
	HAL_UART_Transmit(&huart1,(uint8_t *)usart1_TxBuffer,1,10);//∑¢ÀÕ≤‚æ‡÷∏¡Ó
}

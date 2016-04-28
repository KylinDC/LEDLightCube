#include "stm32f10x.h"
#include "led.h"
#include "HT1632C.h"
#include "delay.h"
#include "sys.h"

unsigned char temp[65];
//{
//	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 
//	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 
//	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 
//	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 
//	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 
//	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 
//	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 
//	0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0xFF,
//};
unsigned char temp1[32];
unsigned char temp2[32];
unsigned char i;
unsigned char t;
unsigned char a =0;
//u8 c=0;


void Enlight(void)
{
	
//	u8 b=0;
	HT1632C_clr();
	for (i = 0; i < 32 ; i++)
		temp1[i] = temp[i+1];
	for (t = 0; t < 32 ; t++)
		temp2[t] = temp[t +33];
	HT1632C_Writer_AllDATA(0x00, temp1, 32);
	HT1632C_Writer_AllDATA(0x80, temp2, 32);

//	for (b=0;b<65;b++)
//	{
//		temp[b]=0x00;
//	}
	a=0;
}

void USART1_IRQHandler(void)
{
//	unsigned char rec[65];
	if (USART_GetITStatus(USART1, USART_IT_RXNE))
	{
		temp[a] = USART_ReceiveData(USART1);
//		USART_SendData(USART1, temp[a]);
//		temp[a]=rec[c];
//		c++;
		a++;
		if(a>=65)
			Enlight();	
//		USART_SendData(USART1, a);		
	}
}

int main(void)
{
	LED_Init();
	delay_init();
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	My_USART1_Init();
	HT1632C_Init();
	HT1632C_clr();
//	HT1632C_Writer_DATA(0x00, A);
//	HT1632C_Writer_DATA(0x80, A);
	while (1);
}

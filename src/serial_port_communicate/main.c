#include <REGX52.H>
#include <uart.h>
#include <time.h>

unsigned char sec;


void main()
{
	uart_init();
	
	while(1)
	{
		// Ex1: 
//		uart_send_byte(sec);
//		sec++;
//		delay(1000);
	}
	
}


void uart_routine(void) interrupt 4
{
	
	
	if (TI)				//检测串口1发送中断
	{
		TI = 0;			//清除串口1发送中断请求位
	}
	if (RI)				//检测串口1接收中断
	{	
		// light the led1 with Byte Registers P2 FROM REGX52.h
		// P2=0xFE;//1111 1110
		// 读取 SBUF 数据
		P2=SBUF;
		uart_send_byte(SBUF);
		RI = 0;			//清除串口1接收中断请求位
	}
}

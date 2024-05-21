#include <REGX52.H>

/*
	* @brief  串口初始化
	* @param
	* @return 
	SCON 串口控制寄存器: 
	SCON = 0100 0000 = 0x40
		SM0/FE=0, SM1=1;  工作模式1
		SM2=0
		REN=1;  // 允许/禁止接收
		TB8=0
		RB8=0
		TI=0   // 发送中断请求标志位, 发送完成 TI=1
		RI=0   // 发送中断请求标志位, 接收完成 RI=1
		
	PCON 电源控制寄存器
	
*/

void uart_init(void) //4800bps@12.000MHz
{
	// 串口寄存器配置
	SCON=0x50;      //SCON 初始化
	PCON |= 0x80;		//使能波特率倍速位SMOD
	
	// 定时器寄存器配置
	// TMOD 模式寄存器： timer1 为 8bit 自动重装载模式
	//TMOD=0x01; // 0010 0000 
	TMOD = TMOD & 0xF0; // TMOD 低四位清零 ，高四位保持不变
	TMOD = TMOD |0x20;  // TMOD 高四位置 0010， 低四位保持不变， timer1 为 8bit 自动重装载模式
	
	// 根据波特率配置 初始值
	// 8bit=256 - F3=243 = 13, 表示每次计数13 会溢出一次
	// 定时器的时钟频率是 12M /12T =1M, 每次计数是 1/1M = 1us
	// 因此，定时器1 溢出的周期是 13*1us, 定时器1溢出率 =1/ 13us = 0.07692 MHz 
	// 波特率= 定时器1溢出率 0.07692 MHz/16 = 0.00480769 MHz = 4807.69 Hz
	TL1 = 0xF3;			//设置定时初始值
	TH1 = 0xF3;			//设置定时重载值
	
	ET1=0 ; //disable timer1 interupt， 在计数有溢出就可以生产波特率
	TR1 = 1;			//定时器1开始计时
	
	EA=1;
	ES = 1;				//使能串口1中断
}

/*
	* @brief  串口发送一个字节数据
	* @param
	* @return 
*/
void uart_send_byte(unsigned char byte)
{
	// 把数据写入 SBUF， 一旦写入就会发送出去
	SBUF=byte;
	//发送中断请求标志位, 发送后TI=1, 需要软件进行复位 TI=0
	while(TI==0);
	TI=0;
}







/*
	* @brief  串口接收一个字节数据
	* @param
	* @return 
*/
void uart_receive_byte(unsigned char byte)
{
	// 把数据写入 SBUF， 一旦写入就会发送出去
	SBUF=byte;
	//发送中断请求标志位, 发送后TI=1, 需要软件进行复位 TI=0
	while(TI==0);
	TI=0;
}
#include <REGX52.H>
/*
  * @brief  interrupter0 
	* @param
	* @return 
	STC 89C52RC 单片机时钟频率（晶振频率）=12M =12 *10^6
	
	外部中断 
	INT0 -> P32
	INT0 -> P33
	
	IT0=1; // INT0 控制位，enable INT0 runing
	
	//中断允许控制寄存器 (IE: interupt Enable)
	IE0=0; // 中断标志位
	EX0=1; // enable external interrupter interupt
	EA =1; //open global interupt switch
	
	//中断优先级寄存器 (IP: interupt Prority)
	PX0=1; // high prority for INT0
	
*/

void int0_init(void)
{
	IT0=1; // INT0 控制位，enable INT0 runing
	
	//中断允许控制寄存器 (IE: interupt Enable)
	IE0=0; // 中断标志位
	EX0=1; // enable external interrupter interupt
	EA =1; //open global interupt switch
	
	//中断优先级寄存器 (IP: interupt Prority)
	PX0=1; // high prority for INT0
}


/*
	* @brief  int0 run interrupt function when 每次 P32为低电平的时候
	* @param
	* @return 
*/

// interrupt function
//void Int0_Routine(void) interrupt 0
//{
//	num ++;
//}

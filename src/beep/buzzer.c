#include <REGX52.H>
#include <time.h>
#include <INTRINS.H>

//蜂鸣器端口
// sbit buzzer = P2^5;




/*
  * @brief  延时函数 500us
	* @param
	* @return 
*/
void Delay500us(void)	//@12.000MHz
{
	unsigned char data i;
	// 延时一个机器周期 1us
	_nop_();
	i = 247;
	while (--i);
}


/*
  * @brief  蜂鸣器发生时长 ms
	* @param
	* @return 
*/
//void buzzer_time(unsigned int ms)
//{		
//		unsigned int i;
//		// bezzer 反转 2*ms , 每次 响 ms*2*delay
//		for(i=0;i<ms*2;i++)
//		{
//			// 反转一次，反转2次为一个周期
//			buzzer = !buzzer;
//			//delay(1);   //  需要2 ms, f= 1/2ms = 500hz
//			Delay500us(); // 需要1 ms, f= 1/1ms = 1000hz
//		}
//}



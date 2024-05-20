#include <REGX52.H>
/*
  * @brief  timer0 初始化，1毫秒@12.000MHz
	* @param
	* @return 
*/

void timer0_init(void) 
{	/*
	TMOD 模式寄存器：set timer0 as mode 1(16 bit)
	16 bit timer: max num 2**16-1 = 65535
	单片机时钟频率（晶振频率）=12M =12 *10^6
	12T模式： timer 的频率= 系统时钟/12 =1M
	每个 1us 计数加1，总共定时时间 65535 us, 超过是溢出产生中断
	*/
	//TMOD=0x01; // 0000 0001
	TMOD = TMOD & 0xF0; // TMOD 低四位清零，高四位保持不变
	TMOD = TMOD |0x01;  // TMOD 低四位置1， 高四位保持不变
	TR0=1; // timer0 start runing
	TF0=0; //清除TF0标志
	
	//每个 1ms 中断：	初始值设置为 64535 -> 65565 = 1000 us =1 ms
	//每个 100us 中断：	初始值设置为 65435 -> 65565 = 100 us =1 ms
	TH0=65435/256;
	TL0=65435%256+1;
	
	ET0=1; //enable timer0 interupt
	EA=1;  //open global interupt switch
	PT0=0;  // lowe
}


/*
// interrupt function template: reverse the led by each 1s
void Timer0_Rountine(void) interrupt 1
{	
	static unsigned int T0_count=0;
	
	// timer0 溢出后重新初始化
	TH0=65435/256;    
	TL0=65435%256+1; 
	T0_count ++;
	if (T0_count>=1000)
	{
		T0_count =0;
		P2_0 =~ P2_0;
	}
	
}

*/
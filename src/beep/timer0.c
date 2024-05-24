#include <REGX52.H>
/*
  * @brief  timer0 初始化，1毫秒@12.000MHz
	* @param
	* @return 
	
	STC 89C52RC 单片机时钟频率（晶振频率）=12M =12 *10^6
	12T模式： timer 的频率= 系统时钟/12 =1M
	
	TMOD 模式寄存器：
	//TMOD=0x01; // 0000 0001 set timer0 as mode 1(16 bit)
	
	16 bit timer: 最大计数 max num 2**16-1 = 65535,
	每个 1us 计数加1，总共定时时间 65535 us, 超过是溢出产生中断，执行对应中断口的 中断函数
	
	TCON: Timer/Counter 0 and 1 control
	16 bit timer: TL0(8 bits) + TH0(8 bits)
	TL0’s 8 bits 溢出向 TH0 进位，TH0's 8 bits 溢出置位 TCON 中的溢出标志位 TF0
	
	TF0 :  TCON 中的溢出标志位
	TR0: TCON 寄存器中的控制位
	
	中断允许控制寄存器 (IE: interupt Enable)
	ET0=1; //enable timer0 interupt
	EA=1;  //open global interupt switch
	
	中断优先级寄存器 (IP: interupt Prority)
	PT0=0;  // low prority for timer0
	
*/

void timer0_init(void) 
{		
	TMOD = TMOD & 0xF0; // TMOD 低四位清零，高四位保持不变
	TMOD = TMOD |0x01;  // TMOD 低四位置1， 高四位保持不变
	
	TR0=1; // timer0 start runing
	TF0=0; // 清除TF0标志
	
	//每隔 1ms 中断：	初始值设置为 64535 -> 65565 = 1000 us =1 ms
	TH0=64535/256;  // timer 高电位
	TL0=64535%256+1;
	
	ET0=1; //enable timer0 interupt
	EA=1;  //open global interupt switch
	PT0=0;  // low prority
}


/*
// interrupt function template on interrupt 1: reverse the led by each 1s

void Timer0_Rountine(void) interrupt 1
{	
	static unsigned int T0_count=0;
	
	// timer0 溢出后重新初始化
	TH0=64535/256;    //0xFC
	TL0=64535%256+1; //0x18
	T0_count ++;
	if (T0_count>=1000)
	{
		T0_count =0;
		P2_0 =~ P2_0;
	}
	
}

*/
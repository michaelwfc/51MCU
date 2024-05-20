#include <REGX52.H>
#include <int0.h>
#include <timer0.h>

unsigned int ir_time; // ir 计时
unsigned char ir_state; // state 0,1,2:  state=0 空闲, state=1 搜寻起始信号, 
unsigned char ir_data[4]; // store the data
unsigned char ir_position_data; 
unsigned char ir_data_flag;
unsigned char ir_repeat_flag;
unsigned char ir_address; // ir address
unsigned char ir_command; // ir command



void ir_init(void)
{
	timer0_init();
	int0_init();
}

/*
	* @brief  //外部中断0中断函数，下降沿触发执行,  when 每次 P32为低电平的时候
	* @param
	* @return 
*/
void Int0_Routine(void) interrupt 0
{	
	//num ++;
	P2=0;
	// ir 波形 第1次 使得P32为低电平的时候，表示开始进入 start/repeat 阶段
	if(ir_state==0)
	{
		// test whether enter into ir_state by int0 from ir
		
		
		timer0_set_counter(0);
		timer0_run(1);
		ir_state=1;
	}
	// ir 波形 第2次 使得P32为低电平的时候，表示开始进入 data 阶段
	if(ir_state==1)
	{
		// 获取 两次低电平之间的时间间隔
		ir_time =  timer0_get_counter();
		timer0_set_counter(0);
		
		// 如果是 start信号 的 时间间隔
		if(ir_time>13500-500 && ir_time<13500+500)
		{
			ir_state =2;
		}
		else if (ir_time > 11250-500 && ir_time < 11250+500)
		{
			ir_repeat_flag=1;
			timer0_run(0);
			ir_state=0;
		}
		else
		{
			ir_state=1;
		}
		
	}
}
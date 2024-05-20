#include <REGX52.H>
#include <LCD1602.h>
#include <int0.h>
#include <timer0.h>
#include <time.h>
#include <ir.h>


unsigned char num;
unsigned int duration;

void main()
{
	LCD_Init();
	LCD_ShowString(1,1,"Time");
	
	// Ex1: test int0 
	//int0_init();
	
//	//Ex2: test running time
//	timer0_init();
//	timer0_set_counter(0); // set the counter =0
//	timer0_run(1);         // stat the timer0
//	delay(10);
//	duration = timer0_get_counter(); // get the counter us
	
	// Ex3: 
	ir_init();
	
	
	
	while(1)
	{
		LCD_ShowNum(2,1,num,3);
		//LCD_ShowNum(2,1,duration,5);
	
	}
}


//void Int0_Routine(void) interrupt 0
//{
//	//num ++;
//	P2=0;
//}


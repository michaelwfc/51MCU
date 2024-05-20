#include <REGX52.H>
#include <timer0.h>
#include <key.h>
#include <INTRINS.H>
#include "LCD1602.h"

// Ex1: interrupt function which use key to control the direction of lighting leds
unsigned char key_num,led_mode,delay_ms=500;

void main()
{	
	P2=0xFE;//1111 1110， light the led1 with Byte Registers P2 FROM REGX52.h
	timer0_init();

	while(1)
	{
		key_num = get_key_num();
		if(key_num)
		{
				// test the led
//			
//			if(key_num==1)P2_0=~P2_0;
//			if(key_num==2)P2_1=~P2_1;
//			if(key_num==3)P2_2=~P2_2;
//			if(key_num==4)P2_3=~P2_3;
			
				// key_num 1 to control the direction
				if(key_num==1)
				{
						led_mode++;
						led_mode = led_mode%2;
				}
				// key_num to speed
				if(key_num==2)
				{
					delay_ms -= 100;
					if(delay_ms <=0)
					{
						//reset delay_ms
						delay_ms =100;
					}
				}
				if(key_num==3)
				{
					delay_ms += 100;
				}
				
				
				// reset key
				if(key_num==4)
				{
					delay_ms =500;
				}
		}
	
	}
}


void Timer0_Rountine(void) interrupt 1
{	
	static unsigned int T0_count=0;
	
	// timer0 溢出后重新初始化
	TH0=64535/256;    //0xFC
	TL0=64535%256+1; //0x18
	T0_count ++;
	if (T0_count>=delay_ms)
	{
		T0_count =0;
		// P2_0 =~ P2_0;
		
		// if led_mode=0, move right, led_mode=1,move left
		if(led_mode==0)
		{
			// 循环移位
				P2 = _crol_(P2,1);
		}
		if(led_mode==1)
		{
			P2=_cror_(P2,1);
		}
	}
}

// Ex2: interrupt function which use key to control the direction of lighting leds
//unsigned char sec=55,minute=59,hour=23;

//void main()
//{	
//	LCD_Init();
//	timer0_init();
//	
//	LCD_ShowString(1,1,"Michael's Clock:");

//	while(1)
//	{
//			LCD_ShowNum(2,1,hour,2);
//			LCD_ShowString(2,3,":");
//			LCD_ShowNum(2,4,minute,2);
//			LCD_ShowString(2,6,":");
//			LCD_ShowNum(2,7,sec,2);
//	}
//}


// Ex2: interrupt function template to show the clock
//void Timer0_Rountine(void) interrupt 1
//{	
//	static unsigned int T0_count=0;
//	
//	// timer0 溢出后重新初始化
//	TH0=64535/256;    //0xFC
//	TL0=64535%256+1; //0x18
//	T0_count ++;
//	if (T0_count>=1000)
//	{
//		T0_count =0;
//		sec++;
//		if(sec>=60)
//		{
//			minute++;
//			sec=0;
//		}
//		if(minute>=60)
//		{
//			hour++;
//			minute=0;
//		}
//		if(hour>=24)
//		{
//			hour=0;
//		}
//	}
//	
//}

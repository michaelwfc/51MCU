#include <REGX52.H>
#include <timer0.h>
#include <key.h>
#include <nixie.h>

// EX2: use key to control the light of led
sbit LED=P2^0;
sbit MOTOR=P1^0;

unsigned char compare,speed,key_num;
void main()
{
	timer0_init();

	while(1)
	{
		key_num = get_key_num();
		if (key_num==1)
		{
			speed++;
			speed%=4;
			if(speed==0){compare=0;}
			if(speed==1){compare=50;}
			if(speed==2){compare=75;}
			if(speed==3){compare=100;}
		}
		nixie(1,speed);
	}
}

void Timer0_Rountine(void) interrupt 1
{	
	static unsigned int count=0;
	
	// timer0 溢出后重新初始化
	TH0=65435/256;    
	TL0=65435%256+1; 
	count ++;
	count %=100;
	if (count<compare)
	{
		LED =0;
		MOTOR=1;
	}
	else
	{
		LED=1;
		MOTOR=0;
	}

}


// EX1: breath led
//void delay_(unsigned int ms)
//{
//	while(ms--);
//}


//void main()
//{
//	
////P2_0=0;
//	unsigned char Time,i ;
//	
//	while(1)
//	{	
//		// make the  time longer, the led become lighter
//		for(Time=0;Time<100;Time++)
//		{		
//			for (i=0;i<20;i++)
//			{
//				LED=0; //light the led
//				delay_(Time);
//				LED=1;
//				delay_(100-Time);
//			}
//		}
//		
//		// make the  time shorter, the led become less light
//		for(Time=100;Time>0;Time--)
//		{		
//			for (i=0;i<20;i++)
//			{
//				LED=0; //light the led
//				delay_(Time);
//				LED=1;
//				delay_(100-Time);
//			}
//		}
//		
//	}
//			
//}
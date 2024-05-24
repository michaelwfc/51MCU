#include <REGX52.H>
#include <time.h>
#include <key.h>
#include <nixie.h>
#include <buzzer.h>
#include <timer0.h>

sbit buzzer = P2^5;

// Ex1: key to beep
//unsigned char key_num;

//void main()
//{	
//	nixie(1,0);
//	while(1)
//	{
//		key_num = get_key_num();
//		if(key_num)
//		{
//			buzzer_time(100);
//			nixie(1,key_num);
//		}	
//	}
//}

// EX2

//索引与频率对照表
unsigned int FreqTable[]={

	63628,63731,63835,63928,64021,64103,64185,64260,64331,64400,64463,64528,
	64580,64633,64684,64732,64777,64820,64860,64898,64934,64968,65000,65030,
	65058,65085,65110,65134,65157,65178,65198,65217,65235,65252,65268,65283,
};



unsigned char freq_select;

void main()
{	
	// freq_select=1;
	// 每隔 1ms计时器溢出后，触发冲断函数
	timer0_init();
	while(1)
	{
		freq_select++;
		delay(500);
	}
	
}


void Timer0_Rountine(void) interrupt 1
{	
	
	// timer0 溢出后重新初始化
	TH0=FreqTable[freq_select]/256;   
	TL0=FreqTable[freq_select]%256+1;
	// 每个 1ms 会反转一次，周期为 2ms, 频率 为500hz
	buzzer = !buzzer;
}

#include <REGX52.H>
void delay(unsigned int ms);


void main()
{

	//P2 Bit Registers
	//P2_0=0;
	
	// unsigned char: 8 bit same with Byte Register P2
	unsigned char led_num=0; 
	signed int move_bit=0;
	
	// light the D1 with Byte Registers P2 FROM REGX52.h
	//1111 1110  set 1st led low voltage, and other high voltage
	
	P2=0xFE; 
	
	while(1)
	{
		
// ex1 :press button to light the led and loose to shutdown
//		if (P3_1==0)// press button to lower valtage
//		{
//			P2_0=0;// light 1st led
//		}
//		else
//		{
//			P2_0=1 ;// shotdown 1st led
//		}

// ex2 :light the led by 500ms
//		P2_0=0;
//		delay(500);
//		P2_0=1;
//		delay(500);
		
		// ex3: press the button, and reverse the state of led
//		if(P3_1==0)
//		{
//			delay(20); // because of some latency from press phisical button
//			while(P3_1==0)
//			{
//			};
//			delay(20);
//			// when not press the button, reverse the binary state of led
//			P2_0 = ~P2_0;	
//		}
//		

// ex3: press botton to show led by binary add
//		if(P3_1==0)
//		{
//				delay(20);
//				while(P3_1==0);
//				delay(20);
//				// P2 deault value: 1111 1111
//				led_num ++;
//				//P2=~P2;
//				P2 =~led_num;
//		}

// ex4: move forward and back one led by press button 1 and 2
		if(P3_1==0||P3_0==0)
		{
			if 	(P3_1==0)
			{
				move_bit++;
			}
			else{
				move_bit--;}
			delay(20);
			while(P3_1==0 || P3_0==0);
			delay(20);
			// P2 deault value: 1111 1111
			if (move_bit>7)
			{
				move_bit=0;
			}
			else if(move_bit<0)
			{
				move_bit=7;
			}

			P2 = 0x01<< move_bit;
			P2 =~P2;
		}	
	}
}

	
void delay(unsigned int ms)
{
	unsigned char i, j;
	while(ms)
	{
		i = 2;
		j = 239;
		do
		{
			while (--j);
		} while (--i);
			ms--;
		}

}
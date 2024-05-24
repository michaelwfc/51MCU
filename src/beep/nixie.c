#include <REGX52.H>
#include <time.h>

unsigned char NixieTable[]= {
	0x3F, // diplay 0 : a,b,c,d,e,f  1111 1100 -> 0011 1111 -> 0x3F 
	0x06,// diplay 1 : b,c  0110 0000 -> 0000 0110 -> 0x06 
	0x5B,
	0x4F,
	0x66,
	0x6D,
	0x7D, // diplay 6 : a,c, d,e, f,g 1011 1110 -> 0111 1101 -> 0x7D
	0x07,	0x7F, 0x6F,
	// A,B
	// 0x77,0x7c,0x39,0x5E,0x79,0x71, 0x00
};


void nixie(unsigned char location, num)
{
	switch(location)
	{	
		// from left to right
		// location 1 is led 8 = Y7
		case 1: P2_4=1;P2_3=1;P2_2=1;break;  
		// location 2 is led 7 = Y6
		case 2: P2_4=1;P2_3=1;P2_2=0;break;  
		// location 3 is led 6 = Y5
		case 3: P2_4=1;P2_3=0;P2_2=1;break;  
		// location 4 is led 5 = Y4
		case 4: P2_4=1;P2_3=0;P2_2=0;break;
		
		case 5: P2_4=0;P2_3=1;P2_2=1;break;
		case 6: P2_4=0;P2_3=1;P2_2=0;break;
		case 7: P2_4=0;P2_3=0;P2_2=1;break;
		case 8: P2_4=0;P2_3=0;P2_2=0;break;
	}
	P0 = NixieTable[num];

//	delay(1);
//	P0 = 0x00; // reset the led
}
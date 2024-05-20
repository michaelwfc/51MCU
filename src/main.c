#include <REGX52.H>

void main()
{	
	// USE 74HC138 with the 3 binary digits to control the display led location
	// 011 = 3 -> led 3
	P24=1;
	P23=0;
	P22=0;
	// diplay 6 on led 3 : a,c, d,e, f,g 1011 1110 -> 0111 1101 -> 0x7D
	P0=0x7D;
	while(1);
	
	
	
}
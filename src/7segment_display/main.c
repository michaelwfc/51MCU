#include <REGX52.H>
#include <nixie.h>


void main()
{	
	// ex1: display 6 on led #3
	// USE 74HC138 with the 3 binary digits to control the display led location
	// 011 = 3 -> Y3 -> led #4
	// P2_4=0; P2_3=1; P2_2=0;
	//nixie(4);
	// diplay 6 on led 3 : a,c, d,e, f,g 1011 1110 -> 0111 1101 -> 0x7D
	//P0=0x7D;
	
	// ex2: 
	// nixie(5,7);
	
	// ex3: dynimic display
	
	 
	while(1)
	{
		nixie(1,2);
		nixie(3,4);
		nixie(5,6);
	}
	
	
	
}



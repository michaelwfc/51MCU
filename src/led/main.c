#include <REGX52.h>
#include <INTRINS.H>

void Delay1ms()		//@12.000MHz
{
	unsigned char i, j;

	i = 2;
	j = 239;
	do
	{
		while (--j);
	} while (--i);
}


void Delay500ms()		//@12.000MHz
{
	unsigned char i, j, k;

	_nop_();
	i = 4;
	j = 205;
	k = 187;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
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

void main()
{	
	// light the led1 with Byte Registers P2 FROM REGX52.h
	P2=0xFE;//1111 1110
	// light by skip one
	P2= 0xAA; //1010 1010 
	while(1)
	{	
		unsigned int m = 1000;
		// light the D1
		P2=0xFE;
		delay(m); //Delay500ms();
		
		// close the D1 
		P2=0xFD;
		delay(m); //Delay500ms();
		
		P2=0xFB;
		delay(m);
		
		P2=0xF7;
		delay(m);
		
		P2=0xEF;
		delay(m);
		
		P2=0xDF;
		delay(m);
		
		P2=0xBF;
		delay(m);
		
		P2=0x7F;
		delay(m);
	}
	
}
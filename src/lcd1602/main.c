#include <REGX52.H>
#include "LCD1602.h"
#include <time.h>

int result=0;

void main()
{	
  	LCD_Init();
//	LCD_ShowChar(1,1,'A');
//	LCD_ShowString(1,3,"hello");
//	LCD_ShowNum(1,9,123,3);
//	LCD_ShowSignedNum(1,13,-67,2);
//	LCD_ShowHexNum(2,1,0xB2,2);
//	LCD_ShowBinNum(2,4,0xAC,8);
	while(1)
	{
		LCD_ShowNum(1,1,result,3);
		delay(1000);
		result ++;
			
	}
}
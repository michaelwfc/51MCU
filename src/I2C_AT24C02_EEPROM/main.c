#include <REGX52.H>
#include <time.h>
#include <key.h>
#include <LCD1602.h>
#include <AT24C02.h>


unsigned char key_num;
unsigned int num;

void main()
{

	LCD_Init();
	
	// Test: 
	//LCD_ShowString(1,1,"I2C");
//	unsigned char Data;
//	AT24C02_write_byte(1,66);
//	delay(10);
//	
//	Data = AT24C02_read_byte(1);
//	LCD_ShowNum(2,1,Data,3);
	
	LCD_ShowNum(1,1,num,5);
	while(1)
	{
		key_num= get_key_num();
		if(key_num==1)
		{
			num++;
			LCD_ShowNum(1,1,num,5);
		}
		if(key_num==2)
		{
			num--;
			LCD_ShowNum(1,1,num,5);
		}
		if(key_num==3)
		{
			AT24C02_write_byte(0,num%256);
			delay(5);
			AT24C02_write_byte(1,num/256);
			delay(5);
			LCD_ShowString(2,1,"Write OK");
			delay(1000);
			LCD_ShowString(2,1,"        ");
		}
		if(key_num==4)
		{
			num = AT24C02_read_byte(0);
			num |= AT24C02_read_byte(1)<<8;
			LCD_ShowNum(1,1,num,5);
			LCD_ShowString(2,1,"Read OK");
			delay(1000);
			LCD_ShowString(2,1,"       ");
		}
		
	}
}
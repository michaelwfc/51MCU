#include <REGX52.H>
#include <time.h>

/**
  * @brief 按下独立按键获取 key_num
  * @param
  * @return 范围 0~4， 无按键时返回0
  **/
unsigned char get_key_num(void)
{
	unsigned char key_num = 0;
	if(P3_1==0){delay(20);while(P3_1==0);delay(20);key_num=1;}
	if(P3_0==0){delay(20);while(P3_0==0);delay(20);key_num=2;}
	if(P3_2==0){delay(20);while(P3_2==0);delay(20);key_num=3;}
	if(P3_3==0){delay(20);while(P3_3==0);delay(20);key_num=4;}
	
	return key_num;
	
}
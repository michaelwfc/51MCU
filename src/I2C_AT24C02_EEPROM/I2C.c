#include <REGX52.H>

/*
SCL,SDA 默认情况是高电平（空闲状态）
*/
sbit I2C_SCL=P2^1;
sbit I2C_SDA=P2^0;


/**
  * @brief  START 位： SCL 高电平时， SDA 进入下降沿（高电平换到低电平）
  * @param  无
  * @retval 无
  */
void i2c_start()
{
	I2C_SDA=1;
	I2C_SCL=1;
	I2C_SDA=0; // I2C_SDA 进入下降沿
	I2C_SCL=0;
}


/**
  * @brief  STOP 位：SCL 高电平时， SDA 进入上升沿
  * @param  无
  * @retval 无
  */
void i2c_stop()
{
	I2C_SDA=0;
	I2C_SCL=1; // 符合空闲状态的高电平
	// I2C_SDA 立马拉高， 因为单片机的时钟频率（1MHz）,周期为1us,大于起始条件建立时间 0.25ns
	I2C_SDA=1; // I2C_SDA 进入上升沿

}


/**
  * @brief  send byte
  * @param  无
  * @retval 无
  */
void i2c_send_byte(unsigned char byte)
{
	unsigned char i;
	for(i=0;i<8;i++)
	{
		// I2C_SDA=bye&0x80; // byte 最高位给 I2C_SDA
		I2C_SDA=byte&(0x80>>i); // 0x80 右移 i位，取第i位 给 I2C_SDA
		I2C_SCL=1; // 符合空闲状态的高电平
		// I2C_SCL 立马拉低， 因为单片机的时钟频率（1MHz）,周期为1us,大于 时钟高电平宽度 0.4 mus
		I2C_SCL=0; 
	}
}


/**
  * @brief  receive byte
  * @param  无
  * @retval 无
  */
unsigned char i2c_receive_byte(void)
{
	unsigned char i, byte=0x00;
	// I2C_SDA 置位高电平空闲状态
	I2C_SDA=1;
	
	for(i=0;i<8;i++)
	{
		// 先释放 I2C_SDA
		I2C_SCL=1;
		// 如果 I2C_SDA=1， byte 获取第i位=1， 如果I2C_SDA=0，则获取默认值0
		if(I2C_SDA){byte|=(0x80>>i);}
		// I2C_SCL 立马拉低
		I2C_SCL=0;
	}
	return byte;
}


/**
  * @brief  i2c_send_ack
	* @param  ack_bit 应答位，0为应答，1为非应答
  * @retval 无
  */
void i2c_send_ack(unsigned char ack_bit)
{
	I2C_SDA=ack_bit; 
	I2C_SCL=1; 
	I2C_SCL=0; 
}


/**
  * @brief  i2c_receive_ack
  * @param  无
  * @retval 无
  */
unsigned char i2c_receive_ack(void)
{		
	unsigned char ack_bit;
	// 先释放 I2C_SDA
	I2C_SDA=1; 
	I2C_SCL=1; 
	// 如果 I2C_SDA=1，ack_bit=1, 如果 I2C_SDA=0，ack_bit=0 
	// if(I2C_SDA){ack_bit=1;}
	ack_bit=I2C_SDA; 
	I2C_SCL=0; 
	return ack_bit;

}


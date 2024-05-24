#include <REGX52.H>
#include <I2C.h>

#define AT24C02_ADDRESS   0xA0

void AT24C02_write_byte(unsigned char word_address,Data)
{
	//unsigned char ack;
	
	i2c_start();                       // 开始条件
	i2c_send_byte(AT24C02_ADDRESS);    // 发送 slave adress
	i2c_receive_ack();           // 接收应答位
	i2c_send_byte(word_address);       // 发送 word_address
	i2c_receive_ack();                 // 接收应答位
	//if(ack==0) P2=0;
	
	i2c_send_byte(Data);
	i2c_receive_ack();
	i2c_stop();	
}

unsigned char AT24C02_read_byte(unsigned char word_address)
{
	unsigned char Data;
	
	i2c_start();                       // 开始条件
	i2c_send_byte(AT24C02_ADDRESS);    // 发送 slave adress
	i2c_receive_ack();                 // 接收应答位
	i2c_send_byte(word_address);       // 发送 word_address
	i2c_receive_ack();                 // 接收应答位
	
	i2c_start();                       // 开始条件
	i2c_send_byte(AT24C02_ADDRESS|0x01); // 发送读地址
	i2c_receive_ack();
	Data = i2c_receive_byte();
	i2c_send_ack(1);
	i2c_stop();	
	
	return Data;
	
}
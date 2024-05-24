#ifndef __I2C_H__
#define __I2C_H__

void i2c_start();
void i2c_stop();
void i2c_send_byte(unsigned char byte);
unsigned char i2c_receive_byte(void);
void i2c_send_ack(unsigned char ack_bit);
unsigned char i2c_receive_ack(void);
#endif
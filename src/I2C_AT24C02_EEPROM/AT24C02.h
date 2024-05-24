#ifndef __AT24C02_H__
#define __AT24C02_H__

void AT24C02_write_byte(unsigned char word_address,Data);
unsigned char AT24C02_read_byte(unsigned char word_address);

#endif
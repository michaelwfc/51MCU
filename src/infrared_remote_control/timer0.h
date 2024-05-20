#ifndef __TIMER0_H__
#define __TIMER0_H__

void timer0_init(void);
void timer0_set_counter(unsigned int value);
unsigned int timer0_get_counter(void);
void timer0_run(unsigned char flag);

#endif


/*
 * led.h
 *
 * Created: 10/9/2023 3:49:47 PM
 *  Author: HD STORE
 */ 


void LED_init(char port , char bin);

void LED_ON(unsigned char port ,unsigned char bin);

void LED_OFF(unsigned char port , unsigned char bin);

void LED_TOOGLE(unsigned char port , unsigned char bin);

char LED_READSTATUS(char port, char bin );

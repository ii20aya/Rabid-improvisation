/*
 * led.c
 *
 * Created: 10/9/2023 3:49:34 PM
 *  Author: HD STORE
 */ 
#include "DIO.h" 
#include <avr/io.h>
#include "led.h"
void LED_init(char port , char bin){

	
	
	DIO_SET_BINDIR(port, bin , 1);
	

}
/////////////////////////////////////////

void LED_ON(unsigned char port ,unsigned char bin){
DIO_WRITE(port , bin ,1);	
}
//////////////////////////////////////////////////

void LED_OFF(unsigned char port , unsigned char bin){
	
		
		
		DIO_WRITE(port, bin , 0);
		
			}
	//////////////////////////////////
	
void LED_TOOGLE(unsigned char port , unsigned char bin) {
	
		DIO_toggle(port, bin );
		
		}
	//////////////////////////////////////
	
char LED_READSTATUS(char port, char bin ){
return DIO_READ(port,bin);	

}		
	

	
/*
 * _7segbcd.c
 *
 * Created: 10/18/2023 1:59:14 PM
 *  Author: HD STORE
 */ 
#define lownibble
#include "DIO.h"
#include "macro.h"
seven_segbcd_inti(char port , char low_or_high){
	#if define lownibble
	
	DIO_SET_BINDIR(port,0,1);
	DIO_SET_BINDIR(port,1,1);
	DIO_SET_BINDIR(port,2,1);
	DIO_SET_BINDIR(port,3,1);
	#else
	DIO_SET_BINDIR(port,4,1);
	DIO_SET_BINDIR(port,5,1);
	DIO_SET_BINDIR(port,6,1);
	DIO_SET_BINDIR(port,7,1);
	#endif
}
seven_segbcd_write(char port, char val){
	
}

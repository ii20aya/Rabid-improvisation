/*
 * keypad.c
 *
 * Created: 12/11/2023 4:37:03 PM
 *  Author: HD STORE
 */ 
#include "keypad.h"
void keypad_inti(void){
	//to access rows<<outputs
	DIO_SET_BINDIR('D',0,1);
	DIO_SET_BINDIR('D',1,1);
	DIO_SET_BINDIR('D',2,1);
	DIO_SET_BINDIR('D',3,1);
	//to access cols<< inputs
	DIO_SET_BINDIR('D',4,0);
	DIO_SET_BINDIR('D',5,0);
	DIO_SET_BINDIR('D',6,0);
	DIO_SET_BINDIR('D',7,0);
	DIO_CONNECT_PULLUP('D',4,1);
	DIO_CONNECT_PULLUP('D',5,1);
    DIO_CONNECT_PULLUP('D',6,1);
	DIO_CONNECT_PULLUP('D',7,1);
}

 int keypad_check_press (void){
	// hardware <<
	//char arr[4][4]={{'1','2','3','/'},{'4','5','6','*'},{'7','8','9','-'},{'o','0','=','+'}};
char arr[4][4]={{'7','8','9','/'},{'4','5','6','*'},{'1','2','3','-'},{'A','0','=','+'}};

	char row , col ,x	;
	char return_value=NOTPRESSED; //0xff <<macrooo
	for(row=0;row<4;row++)
{
	DIO_WRITE('D',0,1);
	DIO_WRITE('D',1,1);
	DIO_WRITE('D',2,1);
	DIO_WRITE('D',3,1);
	DIO_WRITE('D',row,0);

      for(col=4;col<8;col++){
	     x=DIO_READ('D',(col)); //4 , 5 , 6 , 7
	     if(x==0){
		           return_value=arr[row][col-4];
		             break; //out just from small loop
	}
}
if(x==0){
	break; //out from large loop
}
}
return return_value;
	}
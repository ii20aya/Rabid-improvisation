/*
 * DIO.c
 *
 * Created: 10/7/2023 6:52:12 PM
 *  Author: HD STORE
 */ 
#include "macro.h"
//#define DDRA  *(unsigned char*)(0x3A)
//#define PORTA *(volatile unsigned char*)(0x3B)
#include <avr/io.h>
void DIO_SET_BINDIR(char port, char bit , char dir){ // direction mean bin is input or output //0 1
	
	switch(port){
		case 'A':
		case 'a':
		if(dir==1) //output
		{SET_BIT(DDRA,bit);}
		else
		{CLEAR_BIT(DDRA,bit);}
		break;
		
		
		case 'B':
		case 'b':
		if(dir==1) //output
		{SET_BIT(DDRB,bit);}
		else
		{CLEAR_BIT(DDRB,bit);}
		break;
		
		
		case 'C':
		case 'c':
		if(dir==1) //output
		{SET_BIT(DDRC,bit);}
		else
		{CLEAR_BIT(DDRC,bit);}
		break;
		
		case 'D':
		case 'd':
		if(dir==1) //output
		{SET_BIT(DDRD,bit);}
		else
		{CLEAR_BIT(DDRD,bit);}
		break;
		
		default:
		break;
	}
}	
	
	
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	
	void DIO_WRITE(char port, char bit , char val){ //??? ??? ????? ????? ???? ???? ???? ?? pin ???? ?????? ????
		switch(port){
			case 'A':
			case 'a':
			if(val==1) //output
			{SET_BIT(PORTA,bit);}
			else
			{CLEAR_BIT(PORTA,bit);}
			break;
			
			
			case 'B':
			case 'b':
			if(val==1) //output
			{SET_BIT(PORTB,bit);}
			else
			{CLEAR_BIT(PORTB,bit);}
			break;
			
			
			case 'C':
			case 'c':
			if(val==1) //output
			{SET_BIT(PORTC,bit);}
			else
			{CLEAR_BIT(PORTC,bit);}
			break;
			
			
			case 'D':
			case 'd':
			if(val==1) //output
			{SET_BIT(PORTD,bit);}
			else
			{CLEAR_BIT(PORTD,bit);}
			break;
			
			default:
			break;
		}
}


////////////////////////////////////////////////////////////////////////////
void DIO_toggle(char port , char pin){
	switch(port){
		case 'A':
		case'a':
		TOGGLE_BIT(PORTA,pin);
		break;
		 case 'B':
		 case'b':
		 TOGGLE_BIT(PORTB,pin);
		 break;
		 case 'C':
		 case'c':
		 TOGGLE_BIT(PORTC,pin);
		 break;
		 case 'D':
		 case 'd':
		 TOGGLE_BIT(PORTD,pin);
		 break;
		 default:
		 break;
		 
	}
}
//////////////////////////////////////////////////////////////////////////////////

unsigned char DIO_READ(char port , char pin){
	unsigned char res=0;
	switch(port){
		case 'A':
		case 'a':
		res=READ_BIT(PINA , pin);
		break;
		
		case 'B':
		case 'b':
		res=READ_BIT(PINB , pin);
		break;
		
		case 'C':
		case 'c':
		res=READ_BIT(PINC , pin);
		break;
		
		case 'D':
		case 'd':
		res=READ_BIT(PIND , pin);
		break;
		default:
		break;
		
	}
	
	return res;
	
}
///////////////////////////////////////////////////////////////////////////////////////////////////
 void DIO_setportdir(char port , char dir){ //access all ddr regestir
	 switch(port){
		 case'A':
		 case 'a':
		 DDRA=dir;
		 break;
		 
		 case'B':
		 case 'b':
		 DDRB=dir;
		 break;
		 
		 case'C':
		 case 'c':
		 DDRC=dir;
		 break;
		 
		 case'D':
		 case 'd':
		 DDRD=dir;
		 break;
		 
	 }		 
 }
 ////////////////////////////////////////////////////////////
 
 void DIO_writeport(unsigned char port ,unsigned char val){ //access all port regestir
 switch(port){
	 case'A':
	 case 'a':
	 PORTA=val;
	 break;
	 
	 case'B':
	 case 'b':
	 PORTB=val;
	 break;
	 
	 case'C':
	 case 'c':
	 PORTC=val;
	 break;
	 
	 case'D':
	 case 'd':
	 PORTD=val;
	 break;
	 
 }
 }
 //////////////////////////////////////////////////////////////
 char DIO_READPORT(char port){
	 unsigned char return_val=0;
	 switch(port){
		 case 'A':
		 case 'a':
		 return_val=PINA;
		 break;
		 
		 
		 case 'B':
		 case 'b':
		 return_val=PINB;
		 break;
		 
		 case 'C':
		 case 'c':
		 return_val=PINC;
		 break;
		 
		 case 'D':
		 case 'd':
		 return_val=PIND;
		 break;
	 }
	 return return_val;
	 
 }
 /////////////////////////////////////////////////////////////
 void DIO_toggleport(char port){
	 switch(port){
	 case 'A':
	 case 'a':
	 PORTA^=0xff ;   //255 // 8 ?????
	 break; 
	 
	 case 'B':
	 case 'b':
	 PORTB^=0xff ;   //255 // 8 ????? ====  portb=~portb
	 break;
	 
	 case 'C':
	 case 'c':
	 PORTC^=0xff ;   //255 // 8 ?????
	 break;
	 
	 case 'D':
	 case 'd':
	 PORTD^=0xff ;   //255 // 8 ?????
	 break;
	 }
	 
	 		 
 }
 ///////////////////////////////////////////////
 void DIO_CONNECT_PULLUP(char port, char bin , char connect_val){
	 switch(port){
		  case 'A':
	 case 'a':
	 if(connect_val==1)
	 {SET_BIT(PORTA,bin);}
	 else
	{ CLEAR_BIT(PORTA, bin );}
	 break; 
	 
	 case 'B':
	 case 'b': 
	if(connect_val==1)
	{ SET_BIT(PORTB,bin);}
	 else
	{  CLEAR_BIT(PORTB, bin );}
	 break;
	 
	 case 'C':
	 case 'c':
	if(connect_val==1)
	{ SET_BIT(PORTC,bin);}
	 else
	 { CLEAR_BIT(PORTC, bin );}
	 break;
	 
	 case 'D':
	 case 'd':
	if(connect_val==1)
	{SET_BIT(PORTD,bin);}
	 else
	 { CLEAR_BIT(PORTD, bin );}
	 break;
	 }
		 
 }
 /////////////////////////////////////////////////
  void DIO_write_lownibble(char port, char val){
	  DIO_WRITE(port,0,READ_BIT(val,0)); //read first bit in val
	  DIO_WRITE(port,1,READ_BIT(val,1));
	  DIO_WRITE(port,2,READ_BIT(val,2));
	  DIO_WRITE(port,3,READ_BIT(val,3));
	  
	  
  }
  //////////////////////////////////
   void DIO_write_highnibble(char port, char val)
   {
	   val<<=4;
	   switch(port){
		   case 'a':
		   case 'A':
		   PORTA&=0x0f;
		   PORTA|=val;
		   break;
		   case 'b':
		   case 'B':
		   PORTB&=0x0f;
		   PORTB|=val; 
		   break;
		   case 'c':
		   case 'C':
		   PORTC&=0x0f;
		   PORTC|=val;
		   break;
		   case 'd':
		   case 'D':
		   PORTD&=0x0f;
		   PORTD|=val;
		   break;}
	    //DIO_WRITE(port,4,READ_BIT(val,0));
	    //DIO_WRITE(port,5,READ_BIT(val,1));
	    //DIO_WRITE(port,6,READ_BIT(val,2));
	    //DIO_WRITE(port,7,READ_BIT(val,3));}
	    
	   
   }
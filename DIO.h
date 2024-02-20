/*
 * DIO.h
 *
 * Created: 10/7/2023 6:51:35 PM
 *  Author: HD STORE
 */ 


void DIO_SET_BINDIR(char port, char bit , char dir); //prototype to set 0 or 1 in ddr regstir to determine wheather is input or output

void DIO_WRITE(char port, char bit , char val); //acess in port regestir if output<<set ,, if input<<clear

void DIO_toggle(char port , char pin); //toggle specific pin in port regestir

unsigned char DIO_READ(char port , char pin); //read from pin regestir

void DIO_setportdir(char port , char dir) ;// access all ddr

void DIO_writeport(char port , char val); //accesss all port

 char DIO_READPORT(char port); //read all regestir port
 
 void DIO_toggleport(char port) ;// toggle all regestir port
 
 void DIO_CONNECT_PULLUP(char port, char bin , char connect_val); // validaion of internal pull up in MC
 
  void DIO_write_lownibble(char port,char  val);
  
   void DIO_write_highnibble(char port, char val);
  
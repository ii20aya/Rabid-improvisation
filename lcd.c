/*
 * lcd.c
 *
 * Created: 11/26/2023 9:33:57 PM
 *  Author: HD STORE
 */ 


//#include "DIO.h"
#define F_CPU 8000000UL
#include <util/delay.h>
#include "lcd.h"
#include <stdio.h>
#include <float.h>

void LCD_send_data(char data){
	
	//in case 4-bit mode
	DIO_write_highnibble('A',data>>4);
	DIO_WRITE('b',1,1); 
	enablee();
	DIO_write_highnibble('A',data);
	DIO_WRITE('b',1,1);
	enablee();
	//#endif
	_delay_ms(1);
	
}
 void enablee(void){ //send falling edge //static becuse only calling by these function i write insidde it and can not calling from main function
	DIO_WRITE('b',0,1);
	_delay_ms(2); //wait from 2 to 5 second
	DIO_WRITE('b',0,0);
	_delay_ms(2);
}

void LCD_send_command(char cmd){
	//#if defined e_bit_mode
	/*DIO_writeport('a',cmd);
	DIO_WRITE('b',1,0);
	enablee();*/
	
	//#elif defined f_bit_mode
	//in case 4-bit mode
	DIO_write_highnibble('A',cmd>>4);
	DIO_WRITE('b',1,0);
	enablee();
	DIO_write_highnibble('A',cmd);
	DIO_WRITE('b',1,0);
	enablee();
	//#endif
	_delay_ms(1);
	
}

void LCD_clear_screen(void){
	LCD_send_command(0x01);
	_delay_ms(10);
}

void LCD_return_home(void){
	LCD_send_command(0x02);
	_delay_ms(10);
}

void LCD_cursore_display_on(void){
LCD_send_command(0x0c);
_delay_ms(10);	
}
void LCD_entery_mode(void){
	LCD_send_command(0x06);
	_delay_ms(10);
}

void LCD_inti(void)
{
	_delay_ms(200);
	/*
	//#if defined e_bit_mode
	//in case 8-bit mode
	DIO_SET_BINDIR('a',0,1); //set pin of data output
	DIO_SET_BINDIR('a',1,1);
	DIO_SET_BINDIR('a',2,1);
	DIO_SET_BINDIR('a',3,1);
	DIO_SET_BINDIR('a',4,1);
	DIO_SET_BINDIR('a',5,1);
	DIO_SET_BINDIR('a',6,1);
	DIO_SET_BINDIR('a',7,1);
	DIO_SET_BINDIR('B',0,1);
	DIO_SET_BINDIR('B',2,1);
	DIO_SET_BINDIR('B',1,1);
	DIO_WRITE('B',2,0);
	LCD_send_command(0x38);
	_delay_ms(1);
	LCD_cursore_display_on(); //display cursor on
	_delay_ms(1);
	LCD_clear_screen();
	_delay_ms(10);
	LCD_entery_mode();//set function /<<entry mode
	_delay_ms(1);
	*/
	
	//#elif defined f_bit_mode
	// in case 4-bit mode
	DIO_SET_BINDIR('a',4,1);
	DIO_SET_BINDIR('a',5,1);
	DIO_SET_BINDIR('a',6,1);
	DIO_SET_BINDIR('a',7,1);
	DIO_SET_BINDIR('B',0,1);
	DIO_SET_BINDIR('B',2,1);
	DIO_SET_BINDIR('B',1,1);
	DIO_WRITE('B',2,0);
	LCD_return_home();
	_delay_ms(10);
	//LCD_send_command(0x38);// 8bit mode 
	//this line to make compiler understand that i work in 4-bit mode not 8-bit mode
	LCD_send_command(0x28);
	_delay_ms(1);
	LCD_cursore_display_on(); //display cursor on
	_delay_ms(1);
	LCD_clear_screen();
	_delay_ms(10);
	LCD_entery_mode();//set function /<<entry mode
	_delay_ms(1);
	//#endif
}
void LCD_send_string(char* data){
	while((*data)!='\0'){// access letter by letter
		LCD_send_data(*data);
		data++;
	}
	
	
}


void LCD_move_cursore(char row , char col){
	char x;
	if(row<1 || row>2 || col<1 || col>16){
		x=0x80;
	}
	else if(row==1){
		x=0x80+col-1; 
	}
	else if(row==2){
		x=0xc0+col-1;
	}
	
	LCD_send_command(x);
	_delay_ms(1);
}



void LCD_color_font(uint16_t color) {
    
   LCD_send_command(0x62);//ommand to set font color
    LCD_send_data(color >> 8); // High byte of color
   LCD_send_data(color); // Low byte of color
}


 int i=0;  
void lcd_sendFloat(int num) {
	 char buffer[15]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	sprintf(buffer, "%d", num);  // Convert float to string 
	 for ( i = 0; buffer[i] != '\0'; i++) { //???? ???? ????????? ??? ????  ??????
		 LCD_send_data(buffer[i]);
		 _delay_ms(500);  // Adjust delay as needed
		
	 }
}


void lcd_decimalToBinary(int decimalNumber) {
	long binaryNumber = 0, remainder, base = 1;

	while (decimalNumber > 0) {
		remainder = decimalNumber % 2;
		binaryNumber = binaryNumber + remainder * base;
		decimalNumber = decimalNumber / 2;
		base = base * 10;  // This should be base = base * 2;
	}

char buffer[15] = {0};
sprintf(buffer, "%ld", binaryNumber);  // Convert long to string
for (int i = 0; buffer[i] != '\0'; i++) {
	LCD_send_data(buffer[i]);
	_delay_ms(500);  // Adjust delay as needed
}
}



/*
Theme currentTheme = THEME_RED; // Assuming default theme is THEME_RED

// Function to set the LCD background theme
void LCD_theme (Theme theme) {
	currentTheme = theme;
	// Code to change the LCD background theme based on the selected theme
	// ...
}

*/


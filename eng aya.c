#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include <stdbool.h>
#include "macro.h"
#include "DIO.h"
#include "lcd.h"
#include "led.h"
#include "timer.h"
#include "keypad.h"
#include "7seg.h"
#define cc //common cathod for 7 segment
#include <avr/interrupt.h>//to use bilt in functions in interrupt
#include <stdio.h>
#include <math.h>
#include <float.h>
#define NOTPRESSED 0xff
volatile int flag1=0;
int main(void)
{
	//int flag1=0;
seven_seg_inti('c');
LCD_inti();
keypad_inti();
LED_init('A',0);
LED_init('A',1);
timer_CTC_init_interrupt();
int i ,  row, count , count2, arr[]={1 , 2 , 5 , 8 , 9 , 6 , 4 , 3 , 7}, send_num  ,flag2=0;
unsigned char seven=1;
unsigned col;
int arrr[]={1,8,9,3,7,2,5,6,4};

LCD_send_command(64);
LCD_send_data(0x1F);// to draw squar
LCD_send_data(0x11);
LCD_send_data(0x11);
LCD_send_data(0x11);
LCD_send_data(0x11);
LCD_send_data(0x11);
LCD_send_data(0x1F);
LCD_send_data(0x00);

LCD_send_data(0x0E);
LCD_send_data(0x1F);
LCD_send_data(0x13);
LCD_send_data(0x06);
LCD_send_data(0x0C);
LCD_send_data(0x0C);
LCD_send_data(0x00);
LCD_send_data(0x08);

LCD_move_cursore(1,5);
LCD_send_string("START . . . ");
_delay_ms(1000);
LCD_clear_screen();
seven_seg_write_commka('c',seven); //initially score is one

while(1){
	char x=NOTPRESSED;
LCD_move_cursore(1,6);
LCD_send_string("Ready ");
LCD_send_data(1); //send custom "?"
_delay_ms(800);
LCD_clear_screen();

	
count=0;
row=1;
col=1;
count2=0;
for(i=0 ; i <=8 ; i++){ // to send numbers to lcd
LCD_move_cursore(row, col);
LCD_send_data(arrr[i]+48);
_delay_ms(300);
if(count==4){
	row=2 ; 
	col=-2;
}
count++;
col+=3;

}//end for loop

_delay_ms(1300);

col=1; row=1; send_num=1;
for(i=0 ; i<10; i+=2){ // odd up . even down i=0
	
	
if((col%2)==0){ //even up
	LCD_move_cursore(2,col);
	LCD_send_data(0);//send custom squar
	do{
		if(flag1>=100)
		{
			flag2=1;
		}
		x=keypad_check_press();
		_delay_ms(200);
		
	}while(x==NOTPRESSED && flag2==0 );
	
	if(x==NOTPRESSED) //time of timer endded without any press from user
	{
		LCD_move_cursore(2,col);
		LCD_send_data(arr[i]+48);
		seven--;
		seven_seg_write_commka('c',(seven)); // score which appear on seven segment will be minced
	}
	else if (x==(arr[i]+48))
	{
		LCD_move_cursore(2,col);
		LCD_send_data(arr[i]+48);
		LED_ON('a',1);
		seven++;
		seven_seg_write_commka('c',(seven)); // score which appear on seven segment will be increase cause the answer of user is true
		_delay_ms(1000);
		LED_OFF('a',1);
	}
	else if(x!=arr[i]) // answer of user is wrong inside time of timer
	{
		LCD_move_cursore(2,col);
		LCD_send_string("x");
		_delay_ms(700);
		LCD_move_cursore(2,col);
		LCD_send_data(arr[i]+48);
		LED_ON('a',0);
		seven--;
		seven_seg_write_commka('c',(seven)); // score which appear on seven segment will be minced
		_delay_ms(1000);
		LED_OFF('a',0);
	}
	} //end of first condition 
		
if(col%2!=0){ //odd down
	LCD_move_cursore(1 ,col);
	LCD_send_data(0);//send custom squar
	do{
		if(flag1>=100)
		{
			flag2=1;
		}
		x=keypad_check_press();
		_delay_ms(200);
		
	}while(x==NOTPRESSED && flag2==0 );
	
	if(x==NOTPRESSED) //time of timer endded without any press from user
	{
		LCD_move_cursore(1,col);
		LCD_send_data(arr[i]+48);
	seven--;
		seven_seg_write_commka('c',(seven)); // score which appear on seven segment will be minced
	
	}
	else if (x==(arr[i]+48))
	{
		LCD_move_cursore(1,col);
		LCD_send_data(arr[i]+48);
		LED_ON('a',1);
		seven++;
		seven_seg_write_commka('c',(seven)); // score which appear on seven segment will be increase cause the answer of user is true
		_delay_ms(1000);
		LED_OFF('a',1);
	}
	else if (x!=arr[i]) // answer of user is wrong inside time of timer
	{
		LCD_move_cursore(1,col);
		LCD_send_string("x");
		_delay_ms(500);
		LCD_move_cursore(1,col);
		LCD_send_data(arr[i]+48);
	LED_ON('a',0);
	seven--;
	seven_seg_write_commka('c',(seven)); // score which appear on seven segment will be minced
	_delay_ms(1000);
	LED_OFF('a',0);
	}
} //end of second condition
col+=3;
x=0;
flag1=0; flag2=0;
} //end of loop <<odd up . even down




///////////////////////////////////////////////////////////////////////////////////////////////////
col=1; row=1; send_num=1;
for(i=1 ; i<8; i+=2){ // even up . odd down 


if((col%2)==0){ //even up
LCD_move_cursore(1,col);
LCD_send_data(0);//send custom squar
do{
	if(flag1>=100)
	{
		flag2=1;
	}
	x=keypad_check_press();
	_delay_ms(200);
	
}while(x==NOTPRESSED && flag2==0 );

if(x==NOTPRESSED) //time of timer endded without any press from user
{
	LCD_move_cursore(1,col);
	LCD_send_data(arr[i]+48);
	seven--;
	seven_seg_write_commka('c',(seven)); // score which appear on seven segment will be minced
}
else if (x==(arr[i]+48))
{
	LCD_move_cursore(1,col);
	LCD_send_data(arr[i]+48);
	LED_ON('a',1);
	seven++;
	seven_seg_write_commka('c',(seven)); // score which appear on seven segment will be increase cause the answer of user is true
	_delay_ms(1000);
	LED_OFF('a',1);
}
else if (x!=arr[i]) // answer of user is wrong inside time of timer
{
	LCD_move_cursore(1,col);
	LCD_send_string("x");
	_delay_ms(700);
	LCD_move_cursore(1,col);
	LCD_send_data(arr[i]+48);
	LED_ON('a',0);
	seven--;
	seven_seg_write_commka('c',(seven)); // score which appear on seven segment will be minced
	_delay_ms(1000);
	LED_OFF('a',0);
}
	} //end of first condition 
		
if(col%2!=0){ //odd down
	LCD_move_cursore(2 ,col);
	LCD_send_data(0);//send custom squar
	do{
		if(flag1>=100)
		{
			flag2=1;
		}
		x=keypad_check_press();
		_delay_ms(200);
		
	}while(x==NOTPRESSED && flag2==0 );
	
	if(x==NOTPRESSED) //time of timer endded without any press from user
	{
		LCD_move_cursore(2,col);
		LCD_send_data(arr[i]+48);
	seven--;
		seven_seg_write_commka('c',(seven)); // score which appear on seven segment will be minced
	
	}
	else if (x==(arr[i]+48))
	{
		LCD_move_cursore(2,col);
		LCD_send_data(arr[i]+48);
		LED_ON('a',1);
		seven++;
		seven_seg_write_commka('c',(seven)); // score which appear on seven segment will be increase cause the answer of user is true
		_delay_ms(1000);
		LED_OFF('a',1);
	}
	else if (x!=arr[i]) // answer of user is wrong inside time of timer
	{
		LCD_move_cursore(2,col);
		LCD_send_string("x");
		_delay_ms(500);
		LCD_move_cursore(2,col);
		LCD_send_data(arr[i]+48);
	LED_ON('a',0);
	seven--;
	seven_seg_write_commka('c',(seven)); // score which appear on seven segment will be minced
	_delay_ms(1000);
	LED_OFF('a',0);
	}
} //end of second condition
col+=3;
x=0;
flag1=0; flag2=0;
} //end of loop <<odd up . even down


LCD_clear_screen();
LCD_move_cursore(1,1);
LCD_send_string("Your Score is :");
_delay_ms(500);
send_num=((seven+48)/9)*10;
LCD_move_cursore(2,5);
lcd_sendFloat(send_num);
LCD_send_string(" %");
_delay_ms(800);
LCD_clear_screen();
}//end of big while
}
 

ISR(TIMER0_COMP_vect)
{
	flag1++;
}

	


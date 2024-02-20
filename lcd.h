/*
 * lcd.h
 *
 * Created: 11/26/2023 9:34:11 PM
 *  Author: HD STORE
 */ 

#include "DIO.h"
#include "macro.h"
/*
typedef enum {
	THEME_RED,
	THEME_GREEN,
	THEME_BLUE
	// Add more themes as per your requirement
} Theme;
*/
#include <stdio.h>
#include <float.h>
void LCD_send_data(char data);
void enablee(void);
void LCD_send_command(char cmd);
void LCD_clear_screen(void);
void LCD_return_home(void);
void LCD_inti(void);
void LCD_send_string(char* ptr);
void LCD_move_cursore(char row , char col);
void LCD_cursore_display_on(void);
void LCD_entery_mode(void);
//void LCD_theme (Theme theme);
#define RED 0xF800
#define GREEN 0x07E0
#define BLUE 0x001F
void LCD_color_font(uint16_t color);
void lcd_sendFloat(int num);
void lcd_decimalToBinary(int decimalNumber) ;
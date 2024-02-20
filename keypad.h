/*
 * keypad.h
 *
 * Created: 12/11/2023 4:37:20 PM
 *  Author: HD STORE
 */ 
#include "DIO.h"
#define NOTPRESSED 0xff
void keypad_inti(void);
 int keypad_check_press (void);
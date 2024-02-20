/*
 * _7seg.h
 *
 * Created: 10/13/2023 11:20:07 AM
 *  Author: HD STORE
 */ 
#include "DIO.h"
#include "macro.h"
#define cc
void seven_seg_inti(char port);

void seven_seg_write_commka(char port , char val);

void seven_seg_bcd_inti(char port );

void seven_segbcd_write(char port, char val);
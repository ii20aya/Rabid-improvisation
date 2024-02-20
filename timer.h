/*
 * timer.h
 *
 * Created: 2/12/2024 1:32:39 PM
 *  Author: HD STORE
 */ 


void timer_CTC_init_interrupt(void);
void timer_wave_nonPWM(void);
void timer_wave_fastPWM(void);
void timer_wave_phasecorrectPWM(void);
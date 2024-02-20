/*
 * timer.c
 *
 * Created: 2/12/2024 1:32:21 PM
 *  Author: HD STORE
 */ 
/*
 * timer.c
 *
 * Created: 9/25/2019 7:22:07 PM
 *  Author: Mohamed Zaghlol
 */ 
 
#include "macro.h"
#include <avr/io.h>
#define F_CPU 8000000UL
#include <avr/interrupt.h>
#include "timer.h"
#define TIMER_PRESCALER 1024 // Timer0 prescaler set to 1024
#define DESIRED_PERIOD 100 // Desired interrupt period in seconds
uint16_t compare_value = (F_CPU / (TIMER_PRESCALER * DESIRED_PERIOD)) - 1;
void timer_CTC_init_interrupt(void)
{
	/* select CTC mode*/
	SET_BIT(TCCR0,WGM01);
	/* load a value in OCR0 */
	OCR0=compare_value;
	/* select timer clock */ //prescalr is 1024
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS02);
	/* enable interrupt*/
	sei(); //active i bit
	SET_BIT(TIMSK,OCIE0); //active enable bit to allow to send request of interrupt
}


void timer_wave_nonPWM(void)
{
	/* set OC0 as output pin */
	SET_BIT(DDRB,3);
	/* select CTC mode*/
	SET_BIT(TCCR0,WGM01);
	/* load a value in OCR0 */
	OCR0=64;
	/* select timer clock */
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS02);
	/* toggle OC0 on compare match*/
	SET_BIT(TCCR0,COM00);
}

void timer_wave_fastPWM(void)
{
	/* set OC0 as output pin */
	SET_BIT(DDRB,3);
	/* select fast PWM mode*/
	SET_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);
	/* load a value in OCR0 */
	OCR0=64;
	/* select timer clock */
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS02);
	/* Set OC0 on compare match, clear OC0 at BOTTOM,(inverting mode)*/
	SET_BIT(TCCR0,COM00);
	SET_BIT(TCCR0,COM01);
}


void timer_wave_phasecorrectPWM(void)
{
	/* set OC0 as output pin */
	SET_BIT(DDRB,3);
	/* select phase correct PWM mode*/
	SET_BIT(TCCR0,WGM00);
	/* load a value in OCR0 */
	OCR0=64;
	/* select timer clock */
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS02);
	/* Set OC0 on compare match when up-counting. Clear OC0 on compare match when down counting.*/
	SET_BIT(TCCR0,COM00);
	SET_BIT(TCCR0,COM01);
}


#include "ShiftPWM.h"

void ShiftPWM_Init()
{
	TCCR1A = 0x00;
	TCCR1B = 0x00;

	// Timer CTC - Mode 4, Prescaler - clk/1
	TCCR1B |= (1<<WGM12) | (1<<CS10);

	OCR1A = PWMFREQ;

	// Enable Interrupt
	TIMSK1 |= (1<<OCIE1A);
}

void ShiftPWM_HandleInterrupt()
{
}

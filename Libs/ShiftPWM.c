#include "ShiftPWM.h"

uint8_t row = 0x01;
//uint8_t sample[] = {63,55,47,39,31,23,7,1};
uint8_t sample[] = {15,13,11,9,7,5,3,1};

void ShiftPWM_Init()
{
	counter = 0;

	Shift595_Init();

	//cli();

	TCCR1A = 0;
	TCCR1B = 0;


	// Timer CTC - Mode 4, Prescaler - clk/1
	TCCR1B |= ((1<<WGM12) | (1<<CS10));

	OCR1A = PWMFREQ;

	// Enable Interrupt
	TIMSK1 |= (1<<OCIE1A);

	sei();
}

void ShiftPWM_HandleInterrupt()
{
	Shift595_SendByte(row, 0);

	for(uint8_t idx = 0; idx < 8; idx++)
	{
		if(sample[idx] <= counter)
		{
			Shift595_SendBit(1);
		}
		else
		{
			Shift595_SendBit(0);
		}
	}

	for(uint8_t idx = 0; idx < 8; idx++)
	{
		if(sample[idx] <= counter)
		{
			Shift595_SendBit(1);
		}
		else
		{
			Shift595_SendBit(0);
		}
	}

	for(uint8_t idx = 0; idx < 8; idx++)
	{
		if(sample[idx] <= counter)
		{
			Shift595_SendBit(1);
		}
		else
		{
			Shift595_SendBit(0);
		}
	}

	//Shift595_SendByte(0x00,1);
	//Shift595_SendByte(0x00,1);

	Shift595_Latch();

	row *= 2;
	if(row == 0)
		row = 0x01;

	if(counter++ >= BRIGHTNESS)
	{
		counter = 0;
	}
}

ISR(TIMER1_COMPA_vect)
{
	ShiftPWM_HandleInterrupt();
}

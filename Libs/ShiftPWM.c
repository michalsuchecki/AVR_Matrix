#include "ShiftPWM.h"

uint8_t rows[] = {0x01, 0x02, 0x04,0x08, 0x10, 0x20, 0x40, 0x80};

void ShiftPWM_Init()
{
	counter = 0;

	Shift595_Init();

	TCCR1A = 0;
	TCCR1B = 0;

	// Timer CTC - Mode 4, Prescaler - clk/1
	TCCR1B |= ((1<<WGM12) | (1<<CS10));

	OCR1A = PWMFREQ;

	// Enable Interrupt
	TIMSK1 |= (1<<OCIE1A);

	sei();
}

void ShiftPWM_ClearAll()
{
	for(uint8_t i; i< 64; i++)
	{
		LEDBuffer[i].r = 0;
		LEDBuffer[i].g = 0;
		LEDBuffer[i].b = 0;
	}
}

void ShiftPWM_HandleInterrupt()
{
	uint8_t idx, offset = 0;

	for(uint8_t row = 0; row < 8; row++)
	{
		Shift595_SendByte(rows[row], 0);

		// Green
		for(idx = 0; idx < 8; idx++)
		{
			if(LEDBuffer[offset + idx].g <= counter)
			{
				Shift595_SendBit(1);
			}
			else
			{
				Shift595_SendBit(0);
			}
		}
		// Red
		for(idx = 0; idx < 8; idx++)
		{
			if(LEDBuffer[offset + idx].r <= counter)
			{
				Shift595_SendBit(1);
			}
			else
			{
				Shift595_SendBit(0);
			}
		}
		// Blue
		for(idx = 0; idx < 8; idx++)
		{
			if(LEDBuffer[offset + idx].b <= counter)
			{
				Shift595_SendBit(1);
			}
			else
			{
				Shift595_SendBit(0);
			}
		}
		Shift595_Latch();

		offset += 8;
	}

	// TODO: Remove code, edit PCB - add Enable Wire
	//Clear
	Shift595_SendByte(0x00, 0);
	Shift595_SendByte(0xFF, 0);
	Shift595_SendByte(0xFF, 0);
	Shift595_SendByte(0xFF, 0);
	Shift595_Latch();

	if(counter++ >= BRIGHTNESS)
	{
		counter = 0;
	}
}

ISR(TIMER1_COMPA_vect)
{
	ShiftPWM_HandleInterrupt();
}

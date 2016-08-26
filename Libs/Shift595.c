/*
 * Shift595.cpp
 *
 *  Created on: 22 sie 2016
 *      Author: Haru
 */

#include "Shift595.h"

void Shift595_Init()
{
	DDRB = (1 << CLOCK) | (1 << DATA) | (1 << LATCH);
	PORTB = 0x00;
}


void Shift595_SendByte(uint8_t data, uint8_t Inverted)
{
	uint8_t temp = data;

	if(Inverted) temp = ~temp;

	for(uint8_t x = 0; x < 8; x++)
	{
		if(temp & 0x80)
		{
			PIN_HIGH(SHIFTPORT, DATA);
		}
		else
		{
			PIN_LOW(SHIFTPORT, DATA);
		}

		PIN_LOW(SHIFTPORT, CLOCK);
		PIN_HIGH(SHIFTPORT, CLOCK);

		temp <<= 1;
	}
}

void Shift595_SendData(uint8_t *data, uint8_t lenght, uint8_t Inverted)
{
	uint8_t index = 0;
	while(index < lenght )
	{
		Shift595_SendByte(*(data+index), Inverted);
		index++;
	}

}

void Shift595_Latch()
{
	PIN_LOW(SHIFTPORT, LATCH);
	PIN_HIGH(SHIFTPORT, LATCH);
}

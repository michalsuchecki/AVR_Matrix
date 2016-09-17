/*
 * main.c
 *
 *  Created on: 22 sie 2016
 *      Author: Haru
 */

#include "common.h"
#include "Libs/ShiftPWM.h"

int main(void)
{

	DDRB = 0xFF;
	PORTB = 0x00;

	ShiftPWM_Init();

	uint8_t step = 256/64;
	for(uint8_t i = 0; i < 64; i++)
	{
		HSVtoRGB(&LEDBuffer[i],step*i,255,255);
	}

	while(1)
	{
		// still working ?
		_delay_ms(200);
		PORTB ^= (1<<PB5);
	}
}

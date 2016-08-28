/*
 * main.c
 *
 *  Created on: 22 sie 2016
 *      Author: Haru
 */

#include "common.h"
#include "Libs/ShiftPWM.h"

// FRAME	[_ROW_, GREEN, RED, BLUE]
uint8_t frame[4] = { 0x00, 0x00, 0x00, 0xff};

int main(void)
{
	_delay_ms(500);

	ShiftPWM_Init();

	while(1)
	{

	}
}

ISR(TIMER1_COMPA_vect)
{
	ShiftPWM_HandleInterrupt();
}




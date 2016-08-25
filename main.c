/*
 * main.c
 *
 *  Created on: 22 sie 2016
 *      Author: Haru
 */

#include "common.h"
#include "Libs/Shift595.h"

// PIN 13 - POMARANCZOWY

volatile uint8_t val = 0x00;

int main(void)
{
	_delay_ms(500);

	Shift595_Init();
	Shift595_SendByte(0x55, 0);
	Shift595_Latch();

	while(1)
	{
		Shift595_SendByte(val, 0);
		Shift595_Latch();
		_delay_ms(50);
		val++;
	}
}




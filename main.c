/*
 * main.c
 *
 *  Created on: 22 sie 2016
 *      Author: Haru
 */

#include "common.h"
#include "Libs/Shift595.h"

// PIN 13 - POMARANCZOWY

// FRAME	[_ROW_, GREEN, RED, BLUE]
uint8_t frame[4] = { 0x00, 0x00, 0x00, 0xff};

volatile uint8_t val = 0x00;

int main(void)
{
	_delay_ms(500);

	Shift595_Init();
	//Shift595_SendData(frame,3,0);

	//Clear Data
	Shift595_SendByte(0x00,0);
	Shift595_SendByte(0x00,0);
	Shift595_SendByte(0x00,0);
	Shift595_SendByte(0x00,0);

	Shift595_SendByte(0x00,0);	// ROW
	Shift595_SendByte(0x00,1);	// G
	Shift595_SendByte(0x00,1);	// R
	Shift595_SendByte(0xff,1);	// B

	//Shift595_SendData(frame,4,1);
	Shift595_Latch();


	while(1)
	{
		//Shift595_SendData(frame,3,0);
		//Shift595_Latch();
		/*Shift595_SendByte(val, 0);
		Shift595_Latch();
		_delay_ms(50);
		val++;*/
	}
}




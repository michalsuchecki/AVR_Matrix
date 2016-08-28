#ifndef LIBS_SHIFT595_H_
#define LIBS_SHIFT595_H_

#include "../common.h"

#define LATCH PB2	// D10
#define DATA PB1	// D9
#define CLOCK PB0	// D8

#define SHIFTPORT PORTB
#define SHIFTDIR DDRB

#define REGISTERS 4

/*
1 - VCC
2 - GND
3 - CLK
4 - DATA
5 - LATCH
*/

void Shift595_Init();
void Shift595_SendBit(uint8_t bit);
void Shift595_SendByte(uint8_t data, uint8_t Inverted);
void Shift595_SendData(uint8_t *data, uint8_t lenght, uint8_t Inverted);
void Shift595_Latch();

#endif

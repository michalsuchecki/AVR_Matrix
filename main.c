/*
 * main.c
 *
 *  Created on: 22 sie 2016
 *      Author: Haru
 */

#include <avr/io.h>
#include <avr/delay.h>

// PIN 13 - POMARANCZOWY
#define LED  PB5
#define PORT PORTB

#define PIN_HIGH(pin) PORTB |= (1 << pin)
#define PIN_LOW(pin) PORTB &= ~(1 << pin)
#define CHECK_BIT(data, bit) ((data) & (1 << (bit)))

int main(void)
{
	DDRB = 0xFF;
	PORT = 0x00;
	while(1)
	{
		PIN_LOW(LED);
		_delay_ms(500);
		PIN_HIGH(LED);
		_delay_ms(500);
	}
}




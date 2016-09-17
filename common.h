#ifndef COMMON_H_
#define COMMON_H_

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include <stdlib.h>

#define TRUE 1
#define FALSE 0

#define PIN_HIGH(PORT,PIN) (PORT |= (1 << PIN))
#define PIN_LOW(PORT,PIN) (PORT &= ~(1 << PIN))
#define CHECK_BIT(data, bit) ((data) & (1 << (bit)))

// LED's Settings
#define BRIGHTNESS 16 // Max brightness
#define LEDFREQ 75	// PWM Frequency (Hz)

typedef struct SColor{
	uint8_t r;
	uint8_t g;
	uint8_t b;
} Color;

void HSVtoRGB( Color *color, uint8_t h, uint8_t s, uint8_t v);

#endif

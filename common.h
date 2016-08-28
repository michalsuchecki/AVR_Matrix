#ifndef COMMON_H_
#define COMMON_H_

#define F_CPU 16000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include <stdlib.h>

#define TRUE 1
#define FALSE 0

#define PIN_HIGH(PORT,PIN) (PORT |= (1 << PIN))
#define PIN_LOW(PORT,PIN) (PORT &= ~(1 << PIN))
#define CHECK_BIT(data, bit) ((data) & (1 << (bit)))

#endif

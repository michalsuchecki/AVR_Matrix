#ifndef LIBS_SHIFTPWM_H_
#define LIBS_SHIFTPWM_H_

#include "../common.h"
#include "Shift595.h"


#define PWMFREQ	((F_CPU/(LEDFREQ * (BRIGHTNESS+1)))-1)

#define LEDCOUNT 64

Color LEDBuffer[LEDCOUNT];

volatile uint8_t counter;

void ShiftPWM_Init();
void ShiftPWM_HandleInterrupt();

#endif

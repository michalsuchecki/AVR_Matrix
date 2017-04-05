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
void ShiftPWM_SetColor(Color *c);
void ShiftPWM_SetAll(uint8_t value);
void ShiftPWM_ClearAll();

#endif

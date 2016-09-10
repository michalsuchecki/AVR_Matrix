#ifndef LIBS_SHIFTPWM_H_
#define LIBS_SHIFTPWM_H_

#include "../common.h"
#include "Shift595.h"

#define BRIGHTNESS 16 // Max brightness
#define LEDFREQ 75	// PWM Frequency (Hz)
#define PWMFREQ	((F_CPU/(LEDFREQ * (BRIGHTNESS+1)))-1)

volatile uint8_t counter;

void ShiftPWM_Init();
void ShiftPWM_HandleInterrupt();

#endif

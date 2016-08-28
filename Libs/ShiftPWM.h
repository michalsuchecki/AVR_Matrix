#ifndef LIBS_SHIFTPWM_H_
#define LIBS_SHIFTPWM_H_

#include "../common.h"
#include "Shift595.h"

#define BRIGHTNESS 63
#define LEDFREQ    70
#define PWMFREQ	   ((F_CPU/(LEDFREQ * (BRIGHTNESS+1)))-1)


void ShiftPWM_Init();
void ShiftPWM_HandleInterrupt();

#endif

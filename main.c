#include "common.h"
#include "Libs/ShiftPWM.h"

int main(void)
{

	DDRB = 0xFF;
	PORTB = 0x00;

	ShiftPWM_Init();

	uint8_t step = 256/64;
	uint8_t offset = 0;

	while(1)
	{
		// still working ?
		//_delay_ms(200);
		//PORTB ^= (1<<PB5);

		/*
		Color c;

		for(uint8_t i = 0; i < 255; i++)
		{
			HSVtoRGB(&c,i,255,255);
			ShiftPWM_SetColor(&c);
			_delay_ms(10);

		}


		_delay_ms(1000);
		*/

		for(uint8_t i = 0; i < 64; i++)
		{
			HSVtoRGB(&LEDBuffer[i],offset + step*i,255,255);
			//_delay_ms();

		}
		offset+=2;
		_delay_ms(1);
		//ShiftPWM_ClearAll();

	}
}

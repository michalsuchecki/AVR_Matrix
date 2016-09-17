#include "common.h"

/*
 * ~by Mirekk36 (Atnel)
 * link: http://mirekk36.blogspot.com/2015/06/ws2812-magic-led-przestrzen-barw-hsv.html
 *
 * Skalowanie wartoœci <span class="posthilit">HSV</span>:
 * H:      0-255, 0=Red, 42=Yellow, 85=Green, 128=Aqua, 171=Blue, 214=Magenta
 * S:      0-255, 0=tylko bia³a barwa, 255=pe³ne kolory
 * V:      0-255, 0=brak œwiat³a, 255=maksymalna jasnoœæ
 *
 *
 */
void HSVtoRGB( Color *color, uint8_t h, uint8_t s, uint8_t v)
{
	uint16_t region, remainder, p, q, t;

	if (s == 0)
	{
		color->r = color->g = color->b = v;
	}
	else
	{
		region = h*6 / 256;
		remainder = (h*6)%256;

		p = (v * (255 - s)) / 256;
		q = (v * (255 - (s * remainder)/256)) / 256;
		t = (v * (255 - (s * (255 - remainder))/256)) / 256;

		switch (region)
		{
		case 0:
			color->r = v;
			color->g = t;
			color->b = p;
            break;
		case 1:
			color->r = q;
			color->g = v;
			color->b = p;
            break;
		case 2:
			color->r = p;
            color->g = v;
            color->b = t;
            break;
		case 3:
			color->r = p;
            color->g = q;
            color->b = v;
            break;
        case 4:
        	color->r = t;
            color->g = p;
            color->b = v;
            break;
        case 5:
        	color->r = v;
        	color->g = p;
        	color->b = q;
            break;
		}
    }

	// Clamp
	color->r = color->r / BRIGHTNESS;
	color->g = color->g / BRIGHTNESS;
	color->b = color->b / BRIGHTNESS;

}





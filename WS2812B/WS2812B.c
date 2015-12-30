/*
 *
 * This example is configured for a Atmega32 at 16MHz
 */ 

#include <util/delay.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include "light_ws2812.h"

#define LED_COUNT 8

struct cRGB led[LED_COUNT];

struct cRGB colors[8];

void init_colors(){
	colors[0].r=150; colors[0].g=150; colors[0].b=150;
	colors[1].r=255; colors[1].g=000; colors[1].b=000;//red
	colors[2].r=255; colors[2].g=100; colors[2].b=000;//orange
	colors[3].r=100; colors[3].g=255; colors[3].b=000;//yellow
	colors[4].r=000; colors[4].g=255; colors[4].b=000;//green
	colors[5].r=000; colors[5].g=100; colors[5].b=255;//light blue
	colors[6].r=000; colors[6].g=000; colors[6].b=255;//blue
	colors[7].r=100; colors[7].g=000; colors[7].b=255;//violet
}

int8_t sign(uint8_t a, uint8_t b) {
	if(a < b) return -1;
	if(a > b) return 1;
	return 0;
}

int main(void)
{
	init_colors();
	
	uint8_t i;
	
	for(i = 0; i < LED_COUNT; i++) {
		led[i].r = 0;
		led[i].g = 0;
		led[i].b = 0;
	}
	
	uint8_t c_index = 0;
	
	while(1)
	{
		if(led[0].r == colors[c_index].r && led[0].g == colors[c_index].g && led[0].b == colors[c_index].b) {
			
			// shift values
			for(i = LED_COUNT - 1; i > 0; i--) {
				led[i].r = led[i - 1].r;
				led[i].g = led[i - 1].g;
				led[i].b = led[i - 1].b;
			}
			
			// take next color
			c_index = (c_index + 1) % LED_COUNT;
		}
		else {
			led[0].r += sign(colors[c_index].r, led[0].r);
			led[0].g += sign(colors[c_index].g, led[0].g);
			led[0].b += sign(colors[c_index].b, led[0].b);
		}

		ws2812_setleds(led, LED_COUNT);
		_delay_ms(10);
	}
	
	return 0;
}

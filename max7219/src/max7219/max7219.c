/*
 * max7219.c
 *
 * Created: 15.11.2013 21:43:25
 *  Author: snakeye
 */ 

#include <avr/io.h>

#include "max7219.h"

#define MAX7219_PORT PORTC
#define DIN PC1
#define CLK PC3
#define LOAD PC4

#define DIN_1 MAX7219_PORT |= (1 << DIN)
#define DIN_0 MAX7219_PORT &= ~(1 << DIN)
#define CLK_1 MAX7219_PORT |= (1 << CLK)
#define CLK_0 MAX7219_PORT &= ~(1 << CLK)
#define LOAD_1 MAX7219_PORT |= (1 << LOAD)
#define LOAD_0 MAX7219_PORT &= ~(1 << LOAD)

void max7219_send(unsigned char data)
{
	static unsigned char i;
	asm("nop");
	for(i = 0; i < 8; i++) 
	{
		CLK_0;
		asm("nop");
		if(data & 0x80)
		{
			DIN_1;
		}
		else 
		{
			DIN_0;	
		}
		data = data << 1;
		CLK_1;
	}
}

void max7219_write(unsigned char reg, unsigned char data)
{
	LOAD_1;
	max7219_send(reg);
	max7219_send(data);
	LOAD_0;	
	asm("nop");
	LOAD_1;
}

void max7219_init()
{
	DDRC |= (1<<DIN) | (1<<CLK) | (1<<LOAD);	

	max7219_write(MAX7219_REG_DECODE, 0);
	max7219_write(MAX7219_REG_SCAN, 7);
	max7219_write(MAX7219_REG_BRIGHTNESS, 0x0f);
	max7219_write(MAX7219_REG_TEST, 0);
	max7219_write(MAX7219_REG_SHUTDOWN, 1);
}


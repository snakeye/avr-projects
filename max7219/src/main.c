/*
 * max7219_avr.c
 *
 * Created: 15.11.2013 21:41:35
 *  Author: snakeye
 */ 

#define F_CPU 1000000L

#include <avr/io.h>
#include <util/delay.h>

#include "max7219/max7219.h"

int main(void)
{
	max7219_init();
	
	max7219_write(1, 0b00011110);
	max7219_write(2, 0b00100001);
	max7219_write(3, 0b11010010);
	max7219_write(4, 0b11000000);
	max7219_write(5, 0b11010010);
	max7219_write(6, 0b11001100);
	max7219_write(7, 0b00100001);
	max7219_write(8, 0b00011110);

    while(1)
    {
    }
}
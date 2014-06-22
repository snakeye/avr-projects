/*
 * HD44780 I2C Test application
 *
 * Created: 21.06.2014 18:51:03
 *  Author: Andrey
 */ 
#include <avr/io.h>

#include "lib/i2c.h"
#include "lib/hd44780-i2c.h"

int main(void)
{
	i2c_init();
	
	display_init();
	
    while(1)
    {
        //TODO:: Please write your application code 
    }
}
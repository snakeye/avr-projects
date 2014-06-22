/*
 * hd44870_i2c.c
 *
 * Created: 21.06.2014 18:52:19
 *  Author: Andrey
 */ 
#include "i2c.h"

#include "hd44780-i2c.h"

void display_init()
{
	i2c_start(0x4E, 0x00, TW_WRITE);
	
	i2c_write(0x30);
	i2c_write(0x30);
	i2c_write(0x30);
	
	i2c_write(0x20);
	i2c_write(0x20);
	i2c_write(0xF0);
	
	i2c_write(0x00);
	i2c_write(0xF0);
	
	i2c_write(0x00);
	i2c_write(0x10);
	
	i2c_write(0x00);
	i2c_write(0x60);
	
	i2c_stop();	
}

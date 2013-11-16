/*
 * max7219.h
 *
 * Created: 15.11.2013 21:43:05
 *  Author: snakeye
 */ 

#ifndef MAX7219_H_
#define MAX7219_H_

#define MAX7219_REG_DECODE 0x09
#define MAX7219_REG_BRIGHTNESS 0x0A
#define MAX7219_REG_SCAN 0x0B
#define MAX7219_REG_SHUTDOWN 0x0C
#define MAX7219_REG_TEST 0x0F

void max7219_init();
void max7219_write(unsigned char reg, unsigned char data);

#endif /* MAX7219_H_ */
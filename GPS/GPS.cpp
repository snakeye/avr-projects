/*
 * GPS.cpp
 *
 * Created: 25.12.2015 15:51:42
 *  Author: snakeye
 */ 
#include <avr/io.h>
#include "timeout.h"
#include "5110/5110.h"
#include "uart/uart.h"
#include "nmea/nmea.h"

UART uart;
LCD_5110 lcd;
NMEA nmea;

ISR(USART_RX_vect) {
	unsigned char incom = UDR0;    //RECEIVE THE BYTE ON RX
	
	nmea.fusedata(incom);	
}

int main(void)
{	
	cli();
	
	_delay_ms(100);
		
	// define the 5 LCD Data pins: SCE, RST, DC, DATA, CLK
	lcd.lcd_init(&PORTC, PB0, &PORTC, PB1, &PORTC, PB2, &PORTC, PB3, &PORTC, PB4);
		
	lcd.lcd_clear();
	lcd.lcd_str("GPS test");
	
	uart.Init(0, 9600, true);

	lcd.lcd_clear();
	lcd.lcd_goto_xy(0, 0);
	lcd.lcd_str("Ready");

    unsigned char cnt = 0;
	
    while(1)
    {
		// current time
		lcd.lcd_goto_xy(0, 1);
		lcd.lcd_string_format("%02d:%02d:%02d", nmea.getHour(), nmea.getMinute(), nmea.getSecond());
			
		if(nmea.isdataready()) {
			// latitude
			lcd.lcd_goto_xy(0, 2);
			lcd.lcd_string_format("Lat: %f", nmea.getLatitude());
			
			// longitude
			lcd.lcd_goto_xy(0, 3);
			lcd.lcd_string_format("Lon: %f", nmea.getLongitude());
		}
		else {
			// latitude
			lcd.lcd_goto_xy(0, 2);
			lcd.lcd_str(nmea.tmp_words[0]);
			
			// longitude
			lcd.lcd_goto_xy(0, 3);
			lcd.lcd_str(nmea.tmp_words[3]);
		}
		
		// dot
		lcd.lcd_goto_xy(5, 0);
		lcd.lcd_chr((cnt % 2) ? '.': ' ');
		
		cnt += 1;
		_delay_ms(250);
    }
}
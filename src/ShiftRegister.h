#ifndef _SHIFT_REGISTER_H_
#define _SHIFT_REGISTER_H_

#include <avr/io.h>

#define HIGH 1
#define LOW  0

#define SHIFT_REGISTER_LSB			7
#define SHIFT_REGISTER_MSB			0
#define SHIFT_REGISTER_MSB_POSITION 0x07

/* Pinovi za upravljanje shift registrom 74HCT595 */

// STCP	Pin 12	Storage Register Clock Input
#define LATCH_DDR	DDRB
#define LATCH_PORT	PORTB

// SHCP	Pin 11 Shift Register Clock Input
#define CLK_PORT	PORTD
#define CLK_DDR		DDRD

// OE	Pin 13	Output enable input (Aktivan na LOW)
#define ENABLE_PORT PORTD
#define ENABLE_DDR	DDRD

// DS	Pin 14	Serial Data Input
#define DATA_DDR	DDRB
#define DATA_PORT	PORTB


class ShiftRegister
{
	private:
		 uint8_t dataPin;
		 uint8_t enablePin;
		 uint8_t clockPin;
		 uint8_t latchPin;
		 uint8_t storageRegister;
	
	public:
		ShiftRegister(uint8_t dataPin = 0, uint8_t enablePin = 7, uint8_t clockPin = 4, uint8_t latchPin = 4);
		void shiftOut(void);
		void writePin(uint8_t pin, uint8_t level);
};

#endif

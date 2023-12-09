#include "MAX7219.h"

// Defines microcontroller pins connected to MAX7219
MaxMatrix::MaxMatrix(uint8_t _din, uint8_t _cs, uint8_t _clk) 
{
	din = _din;
	cs = _cs;
	clk = _clk;
}

// Prepares assigned pins for communication and sets up MAX7219 chip for operation to control LED matrix.
void MaxMatrix::init()
{
	pinMode(din, OUTPUT);
	pinMode(clk, OUTPUT);
	pinMode(cs, OUTPUT); 
	digitalWrite(clk, HIGH); // clk signal is active low
	
	configCtrlReg(max7219_reg_decodeMode, 0x00); // No decode for digits 7-0
	configCtrlReg(max7219_reg_intensity, 0x02); // 0x00 - 0x0F
	configCtrlReg(max7219_reg_scanLimit, 0x07); // display all digits
	configCtrlReg(max7219_reg_shutdown, 0x01); // normal operation
	configCtrlReg(max7219_reg_displayTest, 0x00); // normal operation
	clear(); // Turn all LEDs off
}

// Changes LED brightness by using an internal PWM modulator.
// Accepts a range of intensity values from 0 to 15.
void MaxMatrix::configIntensity(uint8_t intensity)
{
	configCtrlReg(max7219_reg_intensity, intensity);
}

// Clears the frame buffer which turns all LEDs off.
void MaxMatrix::clear()
{
	for (int i=0; i<8; i++){
		frame_buffer[i] = 0;
		digitalWrite(cs, LOW); // wake up the slave
		shiftOut(din, clk, MSBFIRST, i+1); // register address is sent first (0x01 - 0x08)
		shiftOut(din, clk, MSBFIRST, frame_buffer[i]); // data is sent second
		digitalWrite(cs, HIGH); // finish communication
	}
}

void MaxMatrix::configCtrlReg(uint8_t reg_address, uint8_t data)
{
	digitalWrite(cs, LOW);
	shiftOut(din, clk, MSBFIRST, reg_address);
	shiftOut(din, clk, MSBFIRST, data);
	digitalWrite(cs, HIGH);
}

void MaxMatrix::switchLED(uint8_t column, uint8_t row, uint8_t data)
{
    bitWrite(frame_buffer[column], row, data); // sets or clears a bit in register
	digitalWrite(cs, LOW);
	shiftOut(din, clk, MSBFIRST, column+1);
	shiftOut(din, clk, MSBFIRST, frame_buffer[column]);
	digitalWrite(cs, HIGH);
}
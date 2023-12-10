# MAX7219_library
Library for control of an 8x8 LED matrix driven by MAX7219 display driver. Tested on Arduino Uno, Arduino Nano and STM32 NUCLEO-F446RE development boards. This library was written with the intention to be used for a microcontroller based gaming console.

![image](MAX7219_LED_matrix.jpg)
*MAX7219 display driver chip with an 8x8 LED matrix*

## Features
- Easy driver configuration with dedicated functions, normal operation can be initialized with a single function.
- Arduino library features **software** implemented SPI protocol which allows unconstrained selection of CS, CLK and DATA pins.
- STM32 library features **hardware** implemented SPI protocol which does not allow arbitrary selection of CLK and DATA pins.
- Each LED is controlled individually.

## Functions
- void init();
- void clear();
- void sendData(uint8_t reg_address, uint8_t data);
- void switchLED(uint8_t column, uint8_t row, uint8_t data);

## Installation
### Arduino
**Arduino IDE**
1. Download and extract the library ZIP file.
2. Place the MAX7219_Arduino folder in the Arduino libraries folder (example: C:\Users\Darius\Documents\Arduino\libraries).
3. Launch Arduino IDE and open the example sketch for testing (File > Examples > MAX7219_Arduino > fill_screen).

**Platform IO**

### STM32
**STM32CubeIDE**
1. Download and extract the library ZIP file.
2. Launch STM32CubeIDE and create a workspace where you like.
3. Place the MAX7219_STM32 folder in the created workspace directory.
4. Import
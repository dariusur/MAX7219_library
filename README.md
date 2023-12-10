# MAX7219_library
Library for control of an 8x8 LED matrix driven by MAX7219 display driver. Tested on Arduino Uno, Arduino Nano and STM32 NUCLEO-F446RE development boards. This library was written with the intention to be used for a microcontroller based gaming console.

<img align="center" src="https://github.com/dariusur/MAX7219_library/blob/main/images/MAX7219_LED_matrix.jpg">
*Fig. 1. MAX7219 display driver chip with an 8x8 LED matrix*

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
TODO

### STM32
To use MAX7219 display driver with STM32 microcontroller you will also need a logic level converter. The logic high level for the driver should be at least 3.5 V which is not low enough to be reliably controlled by the STM32.
**STM32CubeIDE**
1. Download and extract the library ZIP file.
2. Launch STM32CubeIDE and create a workspace where you like.
3. Place the MAX7219_STM32 folder in the created workspace directory.
4. In STM32CubeIDE close the Information center window and go to File > Import > General > Existing Projects into Workspace.
5. Select the imported folder as the root directory.
6. (Optional) View the MAX7219.h and MAX7219.cpp files in Core > Inc and Core > Src folders respectively, as well as the main.cpp file.
7. Compile and upload the code.

This library was tested using the STM32 NUCLEO-F446RE development board. In the case of another board or some unexpected errors due to different software version here is what to do:
1. In STM32CubeIDE create a new project and go through the usual setup of the development board.
2. In the .ioc file set up the SPI protocol the way that its shown in Fig. 2.
![image](images/MAX7219_LED_matrix.jpg)
*Fig. 2. SPI configuration*
3. Place the MAX7219.h and MAX7219.cpp files in Core > Inc and Core > Src folders respectively.
4. In the main.c file add lines of code as shown in Fig. 3.
`printf("asdasd");`
5. Compile and upload code.

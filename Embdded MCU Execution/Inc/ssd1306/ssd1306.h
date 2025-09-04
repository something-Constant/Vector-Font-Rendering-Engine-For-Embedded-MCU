/*
MIT License

Copyright (c) 2025 Mohamad Hoseyn Meymandi

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#ifndef _SSD1306_H
#define _SSD1306_H

#include <stdint.h>
#include "stm32f1xx_hal.h"
#define I2Ch hi2c1

extern I2C_HandleTypeDef I2Ch;

#define LcdAddres 0x78 // Write mode

#define WIDTH 128
#define HEIGHT 64

#define BufferSize ((WIDTH * HEIGHT) >> 3)
extern uint8_t Buffer[BufferSize];

#define setpixel(x, y, buffer) BufferSetPixel(x, y, 1, buffer)

#define line_1 0
#define line_2 4

// Charge Pump Regulator **important
/*
    SSD1306 is a single-chip CMOS OLED/PLED driver with controller for organic /
   polymer light emitting diode dot-matrix graphic display system. It consists
   of 128 segments and 64 commons. This IC is designed for Common Cathode type
   OLED panel. (Can't turn on the LEDs with 5v or 3.3v) For the detailed
   characteristics of the driver IC,

    The internal regulator circuit in SSD1306 accompanying only 2 external
   capacitors can generate a 7.5V voltage supply, VCC, from a low voltage supply
   input, VBAT. The VCC is the voltage supply to the OLED driver block. This is
   a switching capacitor regulator circuit, designed for handheld applications.
    This regulator can be turned on/off by software command setting.

    For turning the leds on must Enable charge pump during display on.
    The Charge Pump must be
    enabled by the following command:
    0X8D ; Charge Pump Setting
    0X14 ; Enable Charge Pump
    0XAF; Display ON
*/
#define Charge_Pump_Reg 0X8D
#define Charge_Pump_Enable 0X14
#define Charge_Pump_Disable 0X10

// ssd1306 Controll address
#define Command_Reg 0x00
#define Data_Reg 0x40

// Fundamental Commands
/*
    set contrast:

    Double uint8_t command to select 1 out of 256
    contrast steps. Contrast increases as the value
    increases. (RESET = 0X7F )

    First Contrast_Reg Then Contrast_Value
*/
#define Contrast_Reg 0x81
#define Contrast_Value 0xAA

/*
    Set Display ON/OFF:
    Display_ON:Display ON in normal mode
    Display_OFF:Display OFF (sleep mode) (RESET)
*/
#define Display_ON 0xAF
#define Display_OFF 0xAE

/*
    Set Normal/Inverse Display:

    Normal_Display: Normal display(RESET) 0 in RAM: OFF in display panel, 1 in
   RAM: ON in display panel Inverse_Display: Inverse display 0 in RAM: ON in
   display panel, 1 in RAM: OFF in display panel
*/
#define Normal_Display 0xA6
#define Inverse_Display 0xA7

/*
    Entire Display ON:

    Entire_Display_ON : Entire display ON Output ignores RAM content
    Entir_Display_OFF : Resume to RAM content display(RESET) Output follows RAM
   content
*/
#define Entire_Display_ON 0xA5
#define Entir_Display_OFF 0xA4

// Scrolling Commands
//@attention Its not Complete
#define Deactivate_Scroll 0x2E
#define Activate_Scroll 0x2F

// Addressing Setting Command:

/*
    Set Addressing mode
    This is a double Byte command
    First Set_Memory_Address Then Set_Memory_Horizental_Mode
*/
#define Memory_Address_Reg 0X20
#define Set_Memory_Horizental_Mode 0X00
#define Set_Memory_Vertical_Mode 0X01

/*
    Set Column Address:
    This is a Three Byte command
    First Column Address Reg Then Column start address(7 bit) Then  Column end
   address(7 bit)
*/
#define Column_Address_Reg 0X21
#define Column_start_address 0X00
#define Column_end_address 0X7F

/*
    Set Page Address:
    This is a Three Byte command
    First Page Address Reg Then Page start address(3 bit) Then  Page end
   address(3 bit)
*/
#define Page_Address_Reg 0X22
#define Page_start_address 0X00
#define Page_end_address 0X07

// Hardware Configuration (Panel resolution & layout related):

/*
Set Display Start Line:

    Set display RAM display start line register from
    0-63 using 0X40 ~ 0X7F.
    Display start line register is reset to 000000b
    during RESET.
*/
#define Set_Display_Start_Line 0X40

/*
Set Display Offset:
    Set vertical shift by COM from 0d~63d
    The value is reset to 00h after RESET

    This is a double Byte command
    First Display_Offset_Reg Then Set_Memory_Horizental_Mode
*/
#define Display_Offset_Reg 0xD3
#define Display_Offset_Value 0x00

// Timing & Driving Scheme Setting

/*
    Set Display Clock Divide Ratio/Oscillator Frequency

    A[7:4] : Set the Oscillator Frequency, FOSC.
    Oscillator Frequency increases with
    the value of A[7:4] and vice versa.
    RESET is 1000b
    Range:0000b~1111b
    Frequency increases as setting value
    increases

    Display_Oscillator_Frequency_Value: 4 bit → bit4 ~ bit7
    First three bit are Zero (For Clock divider ratio)
*/
#define Display_Oscillator_Frequency_Reg 0XD5
#define Display_Oscillator_Frequency_Value 0X80

/*
    Set COM Pins Hardware Configuration
    for 128x64 the reset value is ok
    for 128x32 the "Sequential COM pin configuration" must be 0

*/
#define Display_COM_Pins_Hardware_Config_Reg 0XDA
#define Display_COM_Pins_Hardware_Config_Value 0X02

void SendLcd(uint8_t Register, uint8_t Data);
void SetXY(uint8_t x, uint8_t y);
void ClearLcd(uint8_t x, uint8_t y);
void LCD_init(void);
void SetPixel(uint8_t x, uint8_t y, uint8_t Status);
void BufferSetPixel(uint8_t XA, uint8_t YA, uint8_t Status, uint8_t *buffer);
void Bitmap(uint8_t x, uint8_t y, uint8_t *Data, uint16_t wight, uint16_t hight);
void FillBuffer(uint8_t XOffset, uint8_t YOffset, uint8_t *Data, uint8_t Width, uint8_t Height, uint8_t *buffer);
void SendBuffer(uint8_t *buffer);
void ClearBuffer(uint8_t *buffer);
void DrawLine(uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1, uint8_t *buffer);

#endif

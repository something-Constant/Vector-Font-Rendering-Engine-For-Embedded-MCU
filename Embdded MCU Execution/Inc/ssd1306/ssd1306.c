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

#include "ssd1306.h"

byte Buffer[BufferSize] = {};

void SendLcd(byte Register, byte Data) {
    byte I2CBuffer[2] = {Register, Data};

    HAL_I2C_Master_Transmit(&I2Ch, LcdAddres, I2CBuffer, 2, 20);
}

void SetXY(byte x, byte y) {
    SendLcd(Command_Reg, Column_Address_Reg);
    SendLcd(Command_Reg, x);
    SendLcd(Command_Reg, Column_end_address);

    SendLcd(Command_Reg, Page_Address_Reg);
    SendLcd(Command_Reg, y);
    SendLcd(Command_Reg, Page_end_address);
}

void ClearLcd(byte x, byte y) {
    int Aria = (((x + 1) * (y + 1)) << 3);

    SetXY(x, y);

    for (int i = 0; i < Aria; i++) {
        SendLcd(Data_Reg, 0);
    }
}

void SetPixel(byte x, byte y, byte Status) {
    SetXY(x, (y / 8));

    if (Status)
        SendLcd(Data_Reg, (1 << (y % 8)));

    else
        SendLcd(Data_Reg, ~(1 << (y % 8)));
}

void LCD_init(void) {
    __NOP();
    __NOP();
    __NOP();
    __NOP();
    __NOP();
    __NOP();
    SendLcd(Command_Reg, Contrast_Reg);
    SendLcd(Command_Reg, Contrast_Value);

    SendLcd(Command_Reg, Memory_Address_Reg);
    SendLcd(Command_Reg, Set_Memory_Horizental_Mode);

    SendLcd(Command_Reg, Normal_Display);

    SendLcd(Command_Reg, Display_Offset_Reg);
    SendLcd(Command_Reg, Display_Offset_Value);

    SendLcd(Command_Reg, Display_Oscillator_Frequency_Reg);
    SendLcd(Command_Reg, Display_Oscillator_Frequency_Value);

#ifdef LCD_128x32
    SendLcd(Command_Reg, Display_COM_Pins_Hardware_Config_Reg);
    SendLcd(Command_Reg, Display_COM_Pins_Hardware_Config_Value);
#endif

    SendLcd(Command_Reg, 0XA1); // FLEEP 180 DEG

    SendLcd(Command_Reg, Entir_Display_OFF);

    SetXY(Column_start_address, Page_start_address);

    SendLcd(Command_Reg, Charge_Pump_Reg);
    SendLcd(Command_Reg, Charge_Pump_Enable);

    SendLcd(Command_Reg, Display_ON);
}

void BufferSetPixel(byte XA, byte YA, byte Status, byte *buffer) {
    int Index = (((XA * 8) + ((YA >> 3) * 128 * 8)) >> 3);

    if (Status)
        buffer[Index] |= (0x01 << (YA % 8));

    else
        buffer[Index] &= ~(0x01 << (YA % 8));
}

void Bitmap(byte x, byte y, byte *Data, int wight, int hight) {
    char k = 0;

    if (hight % 8) {
        k = (hight / 8) + 1;
    }
    else
        k = (hight / 8);

    for (int i = 0; i < k; i++) {
        SetXY(x, i + y);

        for (int x = 0; x < wight; x++) {
            SendLcd(Data_Reg, *Data);
            Data++;
        }
    }
}

void FillBuffer(byte XOffset, byte YOffset, byte *Data, byte Width, byte Height, byte *buffer) {
    byte ORGX = XOffset;
    byte Row  = (Width / 8);
    word Index;

    for (byte Y = 0; Y < Height; Y++) {
        for (byte X = 0; X < Row; X++) {
            for (byte Bit = 0; Bit < 8; Bit++) {
                Index = (XOffset + (YOffset * 128)) >> 3;

                if (*Data & (0x80 >> Bit))
                    buffer[Index] |= (0x80 >> (XOffset % 8));
                else
                    buffer[Index] &= ~(0x80 >> (XOffset % 8));

                XOffset++;
            }
            Data++;
        }
        YOffset++;
        XOffset = ORGX;
    }
}

void SendBuffer(byte *buffer) {
    SetXY(0, 0);
    for (int x = 0; x < BufferSize; x++) {
        SendLcd(Data_Reg, *buffer++);
    }
}

void ClearBuffer(byte *buffer) {
    for (int x = 0; x < BufferSize; x++) {
        *buffer = 0;
        buffer++;
    }
}

void DrawLine(uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1, byte *buffer) {
    int16_t adx = (((x1 >= x0) ? x1 - x0 : x0 - x1) + 1) << 1;
    int16_t ady = (((y1 >= y0) ? y1 - y0 : y0 - y1) + 1) << 1;

    int8_t sx   = (x0 < x1) ? 1 : -1;
    int8_t sy   = (y0 < y1) ? 1 : -1;

    int16_t eps;

    if (adx > ady) {
        eps = (ady - adx) >> 1;

        for (int16_t x = x0, y = y0; sx < 0 ? x >= x1 : x <= x1; x += sx) {
            setpixel(x, y, buffer);

            eps += ady;
            if (eps << 1 >= adx) {
                y += sy;
                eps -= adx;
            }
        }
    }
    else {
        eps = (adx - ady) >> 1;
        for (int16_t x = x0, y = y0; sy < 0 ? y >= y1 : y <= y1; y += sy) {
            setpixel(x, y, buffer);

            eps += adx;
            if (eps << 1 >= ady) {
                x += sx;
                eps -= ady;
            }
        }
    }
}

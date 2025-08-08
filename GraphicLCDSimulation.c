#include "LCD_Semo.h"
#include <fcntl.h>
#include <io.h>
#include <locale.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

#include "Bezier_Font.h"
#include "LineFont.h"

int main() {
    _setmode(_fileno(stdout), 0x20000);

    for (int i = 0; i < BufferSize; i++) {
        Buffer[i] = 0;
    }

    GLCD_DrawChar("HELLO 123!", 10, 20, 1, 1);
    // draw_text_bezier("HELLO 123!", 10, 20, 2);

    Print(Buffer);

    return 0;
}

#include "LCD_Semo.h"
#include "10x10_FontRender.h"
#include "LineFont_5x5x.h"

char frame[50] = "frame";

int main() {
    _setmode(_fileno(stdout), 0x20000);

    for (int i = 0; i < BufferSize; i++)
        Buffer[i] = 0;

    // draw_text_5x5("ABCDEFZ", 0, 0, 2, 1);
    // draw_text_5x5("GHIJKLY", 0, 15, 2, 1);
    // draw_text_5x5("MNOPQR", 0, 30, 2, 1);
    // draw_text_5x5("FTUVWX", 0, 45, 2, 1);

    draw_text("ABCDEFZ", 0, 0, 1, 1);
    draw_text("GHIJKLY", 0, 15, 1, 1);
    draw_text("MNOPQR", 0, 30, 1, 1);
    draw_text("FTUVWX", 0, 45, 1, 1);
    draw_text("01234", 0, 60, 1, 1);
    draw_text("56789_", 0, 75, 1, 1);
    draw_text("?!:;,.*", 0, 90, 1, 1);
    draw_text("+-/=\%()", 0, 105, 1, 1);

    Print(Buffer);

    return 0;
}

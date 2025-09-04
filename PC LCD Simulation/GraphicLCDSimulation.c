#include "LCD_CMD_Simulation.h"
// #include "10x10_FontRender.h"
#include "./Font_5x7/font_render_engine.h"


uint8_t deph = 1, scale = 1;
char frame[50] = "frame";



int main() {
    _setmode(_fileno(stdout), 0x20000);

    for (int i = 0; i < BufferSize; i++)
        Buffer[i] = 0;





    draw_text("ABCDEFGHIJKLMNO", 0, 0, scale, deph);
    draw_text("PQRSTUVWXYZabcd", 0, (8*scale), scale, deph);
    draw_text("efghijklmnopqrs", 0, (16*scale), scale, deph);
    draw_text("tuvwxyz01234567", 0, (24*scale), scale, deph);
    draw_text("89/[]_^()?!:~,*", 0, (32*scale), scale, deph);
    draw_text("&%=+-<>\\", 0, (40*scale), scale, deph);
	GLCD_DrawChar(24, 67, 40, 1, 1);
	GLCD_DrawChar(25, 75, 40, 1, 1);
	GLCD_DrawChar(26, 83, 40, 1, 1);
	GLCD_DrawChar(27, 91, 40, 1, 1);

    Print(Buffer);

    return 0;
}

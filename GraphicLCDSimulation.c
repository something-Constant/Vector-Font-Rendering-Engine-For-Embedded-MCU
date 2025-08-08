#include <fcntl.h>
#include <io.h>
#include <locale.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include "Quadratic Bézier segment Font.h"
#include "LCD_Semo.h"


int main() {
    _setmode(_fileno(stdout), 0x20000);

    for (int i = 0; i < BufferSize; i++) {
        Buffer[i] = 0;
    }

    // GLCD_DrawChar('A', 5, 5, 2, 3);

    // GLCD_DrawChar('H', 10, 0, 2);
    // GLCD_DrawChar('E', 22, 0, 2);
    // GLCD_DrawChar('L', 34, 0, 2);
    // GLCD_DrawChar('L', 46, 0, 2);
    // GLCD_DrawChar('O', 58, 0, 2);
    // draw_text("HELLO?S", 0, 0, 1);
    
    /*

    // Bezier First_Bezier = {.x0 = 10,
    //                        .y0 = 90,
    //                        .x1 = 50,
    //                        .y1 = 10,
    //                        .x2 = 90,
    //                        .y2 = 60,
    //                        .Step = 0.01,
    //                        .t = 0.0,
    //                        .x = 0,
    //                        .y = 0};

    // for (int i = 0; i <= 80; i++) {
    //     // First_Bezier.x = bezier_quad_int(First_Bezier.x0, First_Bezier.x1, First_Bezier.x2, i,
    //     // 80); First_Bezier.y = bezier_quad_int(First_Bezier.y0, First_Bezier.y1,
    //     First_Bezier.y2,
    //     // i, 80);

    //     // SetPixel(First_Bezier.x, First_Bezier.y, 1, Buffer);

    //     DrawLine(lerpFix(First_Bezier.x0, First_Bezier.x1, i, 80),
    //              lerpFix(First_Bezier.y0, First_Bezier.y1, i, 80),
    //              lerpFix(First_Bezier.x1, First_Bezier.x2, i, 80),
    //              lerpFix(First_Bezier.y1, First_Bezier.y2, i, 80));
    // }

    // char car = 'B', scale = 1, x = 0, y = 0, deph = 0;
    // // get_glyph(car)->segments[0].x1;
    // // wprintf(L"(%d,%d,%d,%d)", get_glyph(car)->segments[0].x1, get_glyph(car)->segments[0].y1,
    // //         get_glyph(car)->segments[0].x2, get_glyph(car)->segments[0].y2);
    // if (get_glyph(car)) {


    //     // for (int i = 0; i < get_glyph(car)->segment_count; i++) {
    //     //     DrawLine((get_glyph(car)->segments[i].x1 + deph) * scale + x,
    //     //              (get_glyph(car)->segments[i].y1) * scale + y,
    //     //              (get_glyph(car)->segments[i].x2 + deph) * scale + x,
    //     //              (get_glyph(car)->segments[i].y2) * scale + y);
    //     // }
    //     for (char s = 0; s <= 2; s++) {

    //         if (s == 1)
    //             car = 'A';
    //         else if (!s)
    //             car = 'B';
    //         else
    //             car = 67;
    //         for (char j = 0; j <= deph; j++) {

    //             for (int i = 0; i < get_glyph(car)->segment_count; i++) {

    //                 DrawLine((get_glyph(car)->segments[i].x1 * scale) + x,
    //                          (get_glyph(car)->segments[i].y1 * scale) + y,
    //                          (get_glyph(car)->segments[i].x2 * scale) + x,
    //                          (get_glyph(car)->segments[i].y2 * scale) + y);

    //                 get_glyph(car)->segments[i + 1].x1 +=
    //                     (get_glyph(car)->width * (s + 1) * scale + 5);
    //                 get_glyph(car)->segments[i + 1].x2 +=
    //                     (get_glyph(car)->width * (s + 1) * scale + 5);
    //             }

    //             // for (int i = 0; i < get_glyph(car)->segment_count; i++) {
    //             //     DrawLine((get_glyph(car)->segments[i].x1 * scale) + x +
    //             //     j+(get_glyph(car)->width*s),
    //             //              (get_glyph(car)->segments[i].y1 * scale) + y,
    //             //              (get_glyph(car)->segments[i].x2 * scale) + x +
    //             //              j+(get_glyph(car)->width*s), (get_glyph(car)->segments[i].y2 *
    //             //              scale) + y);
    //             // }
    //         }
    //     }

    //     // scale = 2, x = 10, y = 10, deph = 3;

    //     // for (char j = 0; j <= deph; j++) {
    //     //     for (int i = 0; i < get_glyph(car)->segment_count; i++) {
    //     //         DrawLine((get_glyph(car)->segments[i].x1) * scale + x + j,
    //     //                  (get_glyph(car)->segments[i].y1) * scale + y,
    //     //                  (get_glyph(car)->segments[i].x2) * scale + x + j,
    //     //                  (get_glyph(car)->segments[i].y2) * scale + y);
    //     //     }
    //     // }

    //     //     for (int i = 0; i < get_glyph(car)->segment_count; i++) {
    //     //             DrawLine((get_glyph(car)->segments[i].x1) * scale + x,
    //     //                      (get_glyph(car)->segments[i].y1) * scale + y + 1,
    //     //                      (get_glyph(car)->segments[i].x2) * scale + x,
    //     //                      (get_glyph(car)->segments[i].y2) * scale + y + 1);
    //     //         }

    //     //     for (int i = 0; i < get_glyph(car)->segment_count; i++) {
    //     //             DrawLine((get_glyph(car)->segments[i].x1) * scale + x,
    //     //                      (get_glyph(car)->segments[i].y1) * scale + y -1,
    //     //                      (get_glyph(car)->segments[i].x2) * scale + x,
    //     //                      (get_glyph(car)->segments[i].y2) * scale + y -1);
    //     //         }
    // }

        // {53, 0, 31, 0},
        // {31, 0, 74, 0},
        // {74, 0, 44, 0},
        // {44, 0, 61, 0},
        // {61, 0, 106, 0},
        // {106, 0, 89, 0},
        // {89, 0, 79, 0},
        // {79, 0, 27, 0},
        // {27, 0, 16, 0},
        // {16, 0, 0, 0},
        // {0, 0, 42, 0},
        // for (First_Bezier.t = 0.0; First_Bezier.t <= 1.001; First_Bezier.t +=
       First_Bezier.Step)
       {
        // Beziercurve(&First_Bezier);

        // First_Bezier.x =
        //     lerp(lerp(First_Bezier.x0, First_Bezier.x1, First_Bezier.t),
        //          lerp(First_Bezier.x1, First_Bezier.x2, First_Bezier.t), First_Bezier.t);

        // First_Bezier.y =
        //     lerp(lerp(First_Bezier.y0, First_Bezier.y1, First_Bezier.t),
        //          lerp(First_Bezier.y1, First_Bezier.y2, First_Bezier.t), First_Bezier.t);
        // bezier_quad_int(First_Bezier.x0,First_Bezier.x1,First_Bezier.x2, t, 10)

        // SetPixel(First_Bezier.x, First_Bezier.y, 1, Buffer);

        // DrawLine(lerp(First_Bezier.x0, First_Bezier.x1, First_Bezier.t),
        //          lerp(First_Bezier.y0, First_Bezier.y1, First_Bezier.t),
        //          lerp(First_Bezier.x1, First_Bezier.x2, First_Bezier.t),
        //          lerp(First_Bezier.y1, First_Bezier.y2, First_Bezier.t));

        // DrawLine(lerp(First_Bezier.x0, First_Bezier.x1, First_Bezier.t),
        //          lerp(First_Bezier.y0, First_Bezier.y1, First_Bezier.t),
        //          lerp(First_Bezier.x1, First_Bezier.x2, First_Bezier.t),
        //          lerp(First_Bezier.y1, First_Bezier.y2, First_Bezier.t), Frame);

        // SDL_FRect pixel = {.x = (First_Bezier.x * PIXEL_SCALE) - offset,
        //                    .y = (First_Bezier.y * PIXEL_SCALE) - offset,
        //                    .w = (PIXEL_SCALE),
        //                    .h = (PIXEL_SCALE)};
        // SDL_RenderFillRect(Frame->render, &pixel);

        // SDL_SetRenderDrawColor(Frame->render, rand() % 256, rand() % 256, rand() % 256, 255);
        // }

        // SetPixel(127, 63, 1, Buffer);
        // DrawLine(50, 50, 100, 63);

        // DrawLine(127, 63, 0, 0);
        // DrawLine(100, 0, 0, 10);
        // DrawLine(127, 0, 50, 50);

        // DrawLine_DDA(127, 63, 0, 6);
        // DrawLine_DDA(100, 0, 0, 10);
        // DrawLine_DDA(127, 0, 50, 50);

        // int scale = 3;

        // DrawLine(2 * scale, 1 * scale, 1 * scale, 2 * scale);
        // DrawLine(2 * scale, 1 * scale, 3 * scale, 2 * scale);

        // DrawLine(2 * scale, 1 * scale, 1 * scale, 2 * scale);
        // DrawLine(2 * scale, 1 * scale, 3 * scale, 2 * scale);

        // DrawLine(1 * scale, 2 * scale, 1 * scale, 4 * scale);
        // DrawLine(3 * scale, 2 * scale, 3 * scale, 4 * scale);

        // DrawLine(1 * scale, 3 * scale, 3 * scale, 3 * scale);
        // DrawLine(1 * scale, 2 * scale, 3 * scale, 2 * scale);

        // int x = 10;
        // int y = 10;

        // x *= scale;
        // y *= scale;

        // Define the lines that make up the "A" character
        // DrawLine(x - (2 * scale), y, x + (2 * scale), y);                             //
       Bottom line

        // DrawLine(x + (2 * scale), y, x, y - (5 * scale)); // Left diagonal
        // DrawLine(x - (2 * scale), y, x, y - (5 * scale)); // Right diagonal
        // DrawLine(x - (1 * scale), y - (2 * scale), x + (1 * scale),
        //          y - (2 * scale)); // Middle line

        // DrawLine(12, 10, 7, 19);
        // DrawLine(12, 10, 17, 19);
        // DrawLine(9, 15, 15, 15);

        // DrawLine(10, 0, 10, 10);
        // DrawLine(0, 0, 15, 0);

        // DrawLine_Bresenhams(0, 0, 10, 60);
        // DrawLine_Bresenhams(100, 0, 10, 30);
        // DrawLine_Bresenhams(127, 0, 50, 50);

        // FillBuffer(0, 0, Mario, 128, 64, Buffer);
        // FillBuffer(20,30, Squer, 8, 8, Buffer);
    */

    Print(Buffer);

    return 0;
}

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

#ifndef _FONT_RENDER_ENGINE_H
#define _FONT_RENDER_ENGINE_H

#include "5x7_Font.h"

void Fontdrawline(uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1, uint8_t *buffer) {
    if ((x0 < WIDTH && x1 < WIDTH) && (y0 < HEIGHT && y1 < HEIGHT)) {
        int16_t adx = (((x1 >= x0) ? x1 - x0 : x0 - x1) + 1) << 1;
        int16_t ady = (((y1 >= y0) ? y1 - y0 : y0 - y1) + 1) << 1;

        int8_t sx   = (x0 < x1) ? 1 : -1;
        int8_t sy   = (y0 < y1) ? 1 : -1;

        int16_t eps;

        if (adx > ady) {
            eps = (ady - adx) >> 1;

            for (int16_t x = x0, y = y0; sx < 0 ? x >= x1 : x <= x1; x += sx) {
                setpixel(x, y, Buffer);

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
                setpixel(x, y, Buffer);

                eps += adx;
                if (eps << 1 >= ady) {
                    x += sx;
                    eps -= ady;
                }
            }
        }
    }
}

Glyph_Line *get_glyph_Line(uint8_t c) {
    for (uint8_t i = 0; i < sizeof(font_table) / sizeof(Glyph_Line); i++)
        if (font_table[i].c == c)
            return &font_table[i];

    return NULL; // Character not supported
}

void draw_text(char *str, int16_t x, int16_t y, uint8_t scale, uint8_t deph) {
    while (*str) {
        Glyph_Line *g = get_glyph_Line(*str++);
        if (! g)
            return;

        for (uint8_t j = 0; j < deph; j++) {
            for (uint8_t i = 0; i < g->segment_count; i++) {
                Fontdrawline((x + j + ((g->segments[i].x1 * scale))),
                             (y + ((g->segments[i].y1 * scale))),
                             (x + j + ((g->segments[i].x2 * scale))),
                             (y + ((g->segments[i].y2 * scale))), Buffer);
            }
        }
        x += Font_Width * scale + space; // Advance cursor
    }
}

void GLCD_DrawChar(char c, uint8_t x, uint8_t y, uint8_t scale, uint8_t deph) {
    Glyph_Line *g = get_glyph_Line(c);
    if (! g)
        return;
    for (uint8_t j = 0; j < deph; j++) {
        for (uint8_t i = 0; i < g->segment_count; i++) {
            Fontdrawline((x + j + ((g->segments[i].x1 * scale))),
                         (y + ((g->segments[i].y1 * scale))),
                         (x + j + ((g->segments[i].x2 * scale))),
                         (y + ((g->segments[i].y2 * scale))), Buffer);
        }
    }
}

#endif
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "./Font_5x7/5x7_Font.h"

#define WINDOW_WIDTH 1800
#define WINDOW_HEIGHT 800
#define WINDOW_TITLE "Graphic LCD Simulation"

#define SDL_Flags SDL_INIT_VIDEO
#define PIXEL_SCALE 1
#define offset 0

uint8_t deph = 1,  scale = 15;

typedef struct {
    SDL_Window *window;
    SDL_Renderer *render;
    SDL_Event event;
    SDL_FRect *pixel;
    bool RunningStatus;
} Window;

typedef struct {
    int min;
    int max;
    int Step;
    int t;
} Lerp;

typedef struct {
    int x0;
    int y0;
    int x1;
    int y1;
    int x2;
    int y2;
    int step;
    int t;

    int x;
    int y;

} Bezier;

/*
// floating point math

int lerp(int min, int max, float t) {
    int x;
    x = (max - min) * t + min;
    return x;
}

void Beziercurve(Bezier *Main) {
    Main->x = pow((1 - Main->t), 2.0f) * Main->x0 + 2 * (1 - Main->t) * Main->t * Main->x1 +
              pow(Main->t, 2) * Main->x2;

    Main->y = pow((1 - Main->t), 2.0f) * Main->y0 + 2 * (1 - Main->t) * Main->t * Main->y1 +
              pow(Main->t, 2) * Main->y2;
}
/*/

void Fontdrawline(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, Window *Frame) {
    if ((x0 < WINDOW_WIDTH && x1 < WINDOW_WIDTH) && (y0 < WINDOW_HEIGHT && y1 < WINDOW_HEIGHT)) {
        int16_t adx = (((x1 >= x0) ? x1 - x0 : x0 - x1) + 1) << 1;
        int16_t ady = (((y1 >= y0) ? y1 - y0 : y0 - y1) + 1) << 1;

        int8_t sx   = (x0 < x1) ? 1 : -1;
        int8_t sy   = (y0 < y1) ? 1 : -1;

        int16_t eps;

        if (adx > ady) {
            eps = (ady - adx) >> 1;

            for (int16_t x = x0, y = y0; sx < 0 ? x >= x1 : x <= x1; x += sx) {
                SDL_FRect pixel = {.x = (x * PIXEL_SCALE),
                                   .y = (y * PIXEL_SCALE),
                                   .w = (PIXEL_SCALE),
                                   .h = (PIXEL_SCALE)};
                SDL_RenderFillRect(Frame->render, &pixel);

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
                SDL_FRect pixel = {.x = (x * PIXEL_SCALE),
                                   .y = (y * PIXEL_SCALE),
                                   .w = (PIXEL_SCALE),
                                   .h = (PIXEL_SCALE)};
                SDL_RenderFillRect(Frame->render, &pixel);

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

void draw_text(char *str, int16_t x, int16_t y, uint8_t scale, uint8_t deph, Window *Frame) {
    while (*str) {
        Glyph_Line *g = get_glyph_Line(*str++);
        if (! g)
            return;

        for (uint8_t j = 0; j < deph; j++) {
            for (uint8_t i = 0; i < g->segment_count; i++) {
                Fontdrawline((x + j + ((g->segments[i].x1 * scale))),
                             (y + ((g->segments[i].y1 * scale))),
                             (x + j + ((g->segments[i].x2 * scale))),
                             (y + ((g->segments[i].y2 * scale))), Frame);
            }
        }
        x += Font_Width * scale + space; // Advance cursor
    }
}

void GLCD_DrawChar(char c, uint8_t x, uint8_t y, uint8_t scale, uint8_t deph, Window *Frame) {
    Glyph_Line *g = get_glyph_Line(c);
    if (! g)
        return;
    for (uint8_t j = 0; j < deph; j++) {
        for (uint8_t i = 0; i < g->segment_count; i++) {
            Fontdrawline((x + j + ((g->segments[i].x1 * scale))),
                         (y + ((g->segments[i].y1 * scale))),
                         (x + j + ((g->segments[i].x2 * scale))),
                         (y + ((g->segments[i].y2 * scale))), Frame);
        }
    }
}

int lerpFix(int min, int max, int t, int step) {
    if (! min && ! t)
        return 0;
    else
        return ((((max - min) * t + (step >> 1)) / step) + min);
}

int bezier_quad_int(int p0, int p1, int p2, int t, int n) {
    int nt = n - t;
    int n2 = (n * n);

    return ((nt * nt) * p0 + 2 * nt * t * p1 + t * t * p2 + (n2 >> 1)) / n2;
}

void DrawLine(int x0, int y0, int x1, int y1, Window *Frame) {
    int16_t adx = (((x1 >= x0) ? x1 - x0 : x0 - x1) + 1) << 1;
    int16_t ady = (((y1 >= y0) ? y1 - y0 : y0 - y1) + 1) << 1;

    int8_t sx   = (x0 < x1) ? 1 : -1;
    int8_t sy   = (y0 < y1) ? 1 : -1;

    int16_t eps;

    if (adx > ady) {
        eps = (ady - adx) >> 1;

        for (int16_t x = x0, y = y0; sx < 0 ? x >= x1 : x <= x1; x += sx) {
            SDL_FRect pixel = {.x = (x * PIXEL_SCALE) - offset,
                               .y = (y * PIXEL_SCALE) - offset,
                               .w = (PIXEL_SCALE),
                               .h = (PIXEL_SCALE)};
            SDL_RenderFillRect(Frame->render, &pixel);

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
            SDL_FRect pixel = {.x = (x * PIXEL_SCALE) - offset,
                               .y = (y * PIXEL_SCALE) - offset,
                               .w = (PIXEL_SCALE),
                               .h = (PIXEL_SCALE)};
            SDL_RenderFillRect(Frame->render, &pixel);

            eps += adx;
            if (eps << 1 >= ady) {
                x += sx;
                eps -= ady;
            }
        }
    }
}

bool SDL_Window_Init(Window *Frame) {
    if (! SDL_Init(SDL_Flags)) {
        fprintf(stderr, "Init Error: %s\n", SDL_GetError());
        return 0;
    }

    Frame->window = SDL_CreateWindow(WINDOW_TITLE, WINDOW_WIDTH, WINDOW_HEIGHT, 0);
    if (! Frame->window) {
        fprintf(stderr, "SDL Create Window Error: %s\n", SDL_GetError());
        return 0;
    }

    Frame->render = SDL_CreateRenderer(Frame->window, NULL);
    if (! Frame->render) {
        fprintf(stderr, "SDL Create Renderer Error: %s\n", SDL_GetError());
        return 0;
    }

    return 1;
}

void SDL_Window_Free(Window *Frame) {
    if (Frame->window)
        SDL_DestroyWindow(Frame->window);

    if (Frame->render)
        SDL_DestroyRenderer(Frame->render);

    Frame->render = NULL;
    Frame->window = NULL;
    SDL_Quit();
}

void SDL_Window_Event(Window *Frame) {
    while (SDL_PollEvent(&Frame->event)) {
        switch (Frame->event.type) {
            case SDL_EVENT_QUIT :
                Frame->RunningStatus = 0;
                break;
            default :
                break;
        }
    }
}

void Print(Bezier *main, Window *Frame) {
    for (main->t = 0; main->t <= main->step; main->t++) {
        main->x         = bezier_quad_int(main->x0, main->x1, main->x2, main->t, main->step);
        main->y         = bezier_quad_int(main->y0, main->y1, main->y2, main->t, main->step);

        SDL_FRect pixel = {.x = (main->x * PIXEL_SCALE) - offset,
                           .y = (main->y * PIXEL_SCALE) - offset,
                           .w = (PIXEL_SCALE),
                           .h = (PIXEL_SCALE)};
        SDL_RenderFillRect(Frame->render, &pixel);
    }
}

void SDL_Window_Render(Window *Frame) {
    int flag            = 0;

    Bezier First_Bezier = {.x0   = 5,
                           .y0   = 400,
                           .x1   = 300,
                           .y1   = 60,
                           .x2   = 300,
                           .y2   = 350,
                           .step = 20,
                           .t    = 0,
                           .x    = 0,
                           .y    = 0};

    while (Frame->RunningStatus) {
        while (SDL_PollEvent(&Frame->event)) {
            if (Frame->event.type == SDL_EVENT_QUIT)
                Frame->RunningStatus = 0;
        }
        SDL_SetRenderDrawColor(Frame->render, 0, 0, 0, 255);
        SDL_RenderClear(Frame->render);
        SDL_SetRenderDrawColor(Frame->render, 255, 255, 255, 255);

        draw_text("ABCDEFGHIJKLMNO", 0, 0, scale, deph, Frame);
        draw_text("PQRSTUVWXYZabcd", 0, ((scale) * 8), scale, deph, Frame);
        draw_text("efghijklmnopqrs", 0, ((scale) * 16), scale, deph, Frame);
        draw_text("tuvwxyz01234567", 0, ((scale) * 24), scale, deph, Frame);
        draw_text("89/[]_^()?!:~,*", 0, ((scale) * 32), scale, deph, Frame);
        draw_text("&%=+- < >\\", 0, ((scale) * 40), scale, deph, Frame);
        
        // GLCD_DrawChar(' ', 67, ((scale) * 40), scale, deph, Frame);
        // GLCD_DrawChar(25, 75, ((scale) * 40), scale, deph, Frame);
        // GLCD_DrawChar(26, 83, ((scale) * 40), scale, deph, Frame);
        // GLCD_DrawChar(27, 91, ((scale) * 40), scale, 1, Frame);

        /*
        //////////Bezier curve
            for (int i = 0; i <= First_Bezier.step; i++) {
                First_Bezier.x = bezier_quad_int(First_Bezier.x0, First_Bezier.x1, First_Bezier.x2, i,
                                                 First_Bezier.step);
                First_Bezier.y = bezier_quad_int(First_Bezier.y0, First_Bezier.y1, First_Bezier.y2, i,
                                                 First_Bezier.step);

                DrawLine(lerpFix(First_Bezier.x0, First_Bezier.x1, i, First_Bezier.step),
                         lerpFix(First_Bezier.y0, First_Bezier.y1, i, First_Bezier.step),
                         lerpFix(First_Bezier.x1, First_Bezier.x2, i, First_Bezier.step),
                         lerpFix(First_Bezier.y1, First_Bezier.y2, i, First_Bezier.step), Frame);

                SDL_FRect pixel = {.x = (First_Bezier.x * PIXEL_SCALE) - offset,
                                   .y = (First_Bezier.y * PIXEL_SCALE) - offset,
                                   .w = (PIXEL_SCALE),
                                   .h = (PIXEL_SCALE)};
                SDL_RenderFillRect(Frame->render, &pixel);

                SDL_SetRenderDrawColor(Frame->render, rand() % 256, rand() % 256, rand() % 256, 255);
            }

            */

        SDL_RenderPresent(Frame->render);
        SDL_Delay(50);
    }
}

int main(int argc, char *argv[]) {
    bool Exit_status   = 1;

    Window Main        = {NULL};
    Main.RunningStatus = 1;

    if (SDL_Window_Init(&Main)) {
        Exit_status = 0;
        SDL_Window_Render(&Main);
    }

    SDL_Window_Free(&Main);
    return Exit_status;
}

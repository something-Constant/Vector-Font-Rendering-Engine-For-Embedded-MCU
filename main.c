#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define WINDOW_WIDTH 1000
#define WINDOW_HEIGHT 1000
#define WINDOW_TITLE "Graphic LCD Simulation"

#define SDL_Flags SDL_INIT_VIDEO
#define PIXEL_SCALE 10 // Scale factor for better visibility
#define offset 0
// #define Step 0.05

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
    float Step;
    float t;
    int out;
    int flag;

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

int lerpFix(int min, int max, int t, int step) {
    if (!min && !t)
        return 0;
    else
        return ((((max - min) * t + (step >> 1)) / step) + min);
}

int bezier_quad_int(int p0, int p1, int p2, int t, int n) {
    int nt = n - t;
    int n2 = (n * n);

    return ((nt * nt) * p0 + 2 * nt * t * p1 + t * t * p2 + (n2 >> 1)) / n2;
}

// int bezier_quad_int(int p0, int p1, int p2, int n, int s) {
//     int sn = (s - n);
//     return ((sn * sn * p0 + 2 * sn * n * p1 + n * n * p2) + (s * s) / 2) / (s * s);
// }

void DrawLine(int x0, int y0, int x1, int y1, Window *Frame) {

    int16_t adx = (((x1 >= x0) ? x1 - x0 : x0 - x1) + 1) << 1;
    int16_t ady = (((y1 >= y0) ? y1 - y0 : y0 - y1) + 1) << 1;

    int8_t sx = (x0 < x1) ? 1 : -1;
    int8_t sy = (y0 < y1) ? 1 : -1;

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

void MoveThLine(Lerp *Main) {

    Main->out = lerp(Main->min, Main->max, Main->t);

    // DrawLine(, 10, lerp(Main->min, Main->max, Main->t), 20, Frame);
    // DrawLine(lerp(Main->min, Main->max, Main->t) + 1, 10, lerp(Main->min, Main->max, Main->t) +
    // 1
    //          20, Frame);

    // printf("X = %d, point = %f\n", lerp(32, 224, point), point);

    if (!Main->flag) {
        if (Main->t >= 1)
            Main->flag = 1;
        else
            Main->t += Main->Step;
    }

    if (Main->flag) {
        if (Main->t <= 0.001f)
            Main->flag = 0;
        else
            Main->t -= Main->Step;
    }
}

bool SDL_Window_Init(Window *Frame) {
    if (!SDL_Init(SDL_Flags)) {
        fprintf(stderr, "Init Error: %s\n", SDL_GetError());
        return 0;
    }

    Frame->window = SDL_CreateWindow(WINDOW_TITLE, WINDOW_WIDTH, WINDOW_HEIGHT, 0);
    if (!Frame->window) {
        fprintf(stderr, "SDL Create Window Error: %s\n", SDL_GetError());
        return 0;
    }

    Frame->render = SDL_CreateRenderer(Frame->window, NULL);
    if (!Frame->render) {
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
            case SDL_EVENT_QUIT:
                Frame->RunningStatus = 0;
                break;
            default:
                break;
        }
    }
}

void Print(Bezier *main, Window *Frame) {

    for (main->t = 0; main->t <= main->step; main->t++) {
        main->x = bezier_quad_int(main->x0, main->x1, main->x2, main->t, main->step);
        main->y = bezier_quad_int(main->y0, main->y1, main->y2, main->t, main->step);

        SDL_FRect pixel = {.x = (main->x * PIXEL_SCALE) - offset,
                           .y = (main->y * PIXEL_SCALE) - offset,
                           .w = (PIXEL_SCALE),
                           .h = (PIXEL_SCALE)};
        SDL_RenderFillRect(Frame->render, &pixel);
    }
}

void SDL_Window_Render(Window *Frame) {

    int flag = 0, step;

    Lerp line1;

    line1.min = 32;
    line1.max = 224;
    line1.Step = 0.1;
    line1.flag = 0;
    line1.out = 0;
    line1.t = 0;

    Lerp line2;

    line2.min = 32;
    line2.max = 224;
    line2.Step = 0.05;
    line2.flag = 0;
    line2.out = 0;
    line2.t = 0;

    // Bezier First_Bezier = {.x0 = 100,
    //                        .y0 = 100,
    //                        .x1 = 150,
    //                        .y1 = 100,
    //                        .x2 = 200,
    //                        .y2 = 200,
    //                        .Step = 0.001,
    //                        .t = 0.0,
    //                        .x = 0,
    //                        .y = 0};

    Bezier First_Bezier = {.x0 = 10,
                           .y0 = 90,
                           .x1 = 50,
                           .y1 = 10,
                           .x2 = 90,
                           .y2 = 60,
                           .step = 0.01,
                           .t = 0.0,
                           .x = 0,
                           .y = 0};

    while (Frame->RunningStatus) {
        while (SDL_PollEvent(&Frame->event)) {
            if (Frame->event.type == SDL_EVENT_QUIT)
                Frame->RunningStatus = 0;
        }
        SDL_SetRenderDrawColor(Frame->render, 0, 0, 0, 255);
        SDL_RenderClear(Frame->render);
        SDL_SetRenderDrawColor(Frame->render, 255, 255, 255, 255);
        if (!flag) {

            // static const BezierSegment S_segs[] = {{{10, 2, 8, 0, 2, 0},
            //                                         {2, 0, 0, 2, 0, 4},
            //                                         {0, 4, 2, 6, 8, 6},
            //                                         {8, 6, 10, 8, 10, 10},
            //                                         {10, 10, 8, 12, 2, 12}}};

            Bezier a = {.x0 = 10, .y0 = 2, .x1 = 8, .y1 = 0, .x2 = 2, .y2 = 0};
            a.step = 20;
            // Print(&a, Frame);

            for (a.t = 0; a.t <= a.step; a.t++) {
                a.x = bezier_quad_int(a.x0, a.x1, a.x2, a.t, a.step);
                a.y = bezier_quad_int(a.y0, a.y1, a.y2, a.t, a.step);

                SDL_FRect pixel = {.x = (a.x * PIXEL_SCALE) - offset,
                                   .y = (a.y * PIXEL_SCALE) - offset,
                                   .w = (PIXEL_SCALE),
                                   .h = (PIXEL_SCALE)};
                SDL_RenderFillRect(Frame->render, &pixel);
            }

            a.x0 = 2;
            a.y0 = 0;
            a.x1 = 0;
            a.y1 = 2;
            a.x2 = 0;
            a.y2 = 4;

            for (a.t = 0; a.t <= a.step; a.t++) {
                a.x = bezier_quad_int(a.x0, a.x1, a.x2, a.t, a.step);
                a.y = bezier_quad_int(a.y0, a.y1, a.y2, a.t, a.step);

                SDL_FRect pixel = {.x = (a.x * PIXEL_SCALE) - offset,
                                   .y = (a.y * PIXEL_SCALE) - offset,
                                   .w = (PIXEL_SCALE),
                                   .h = (PIXEL_SCALE)};
                SDL_RenderFillRect(Frame->render, &pixel);
            }

            a.x0 = 0;
            a.y0 = 4;
            a.x1 = 2;
            a.y1 = 6;
            a.x2 = 8;
            a.y2 = 6;

            for (a.t = 0; a.t <= a.step; a.t++) {
                a.x = bezier_quad_int(a.x0, a.x1, a.x2, a.t, a.step);
                a.y = bezier_quad_int(a.y0, a.y1, a.y2, a.t, a.step);

                SDL_FRect pixel = {.x = (a.x * PIXEL_SCALE) - offset,
                                   .y = (a.y * PIXEL_SCALE) - offset,
                                   .w = (PIXEL_SCALE),
                                   .h = (PIXEL_SCALE)};
                SDL_RenderFillRect(Frame->render, &pixel);
            }
            a.x0 = 8;
            a.y0 = 6;
            a.x1 = 10;
            a.y1 = 8;
            a.x2 = 10;
            a.y2 = 10;
            for (a.t = 0; a.t <= a.step; a.t++) {
                a.x = bezier_quad_int(a.x0, a.x1, a.x2, a.t, a.step);
                a.y = bezier_quad_int(a.y0, a.y1, a.y2, a.t, a.step);

                SDL_FRect pixel = {.x = (a.x * PIXEL_SCALE) - offset,
                                   .y = (a.y * PIXEL_SCALE) - offset,
                                   .w = (PIXEL_SCALE),
                                   .h = (PIXEL_SCALE)};
                SDL_RenderFillRect(Frame->render, &pixel);
            }
            a.x0 = 10;
            a.y0 = 10;
            a.x1 = 8;
            a.y1 = 12;
            a.x2 = 1;
            a.y2 = 10;
            for (a.t = 0; a.t <= a.step; a.t++) {
                a.x = bezier_quad_int(a.x0, a.x1, a.x2, a.t, a.step);
                a.y = bezier_quad_int(a.y0, a.y1, a.y2, a.t, a.step);

                SDL_FRect pixel = {.x = (a.x * PIXEL_SCALE) - offset,
                                   .y = (a.y * PIXEL_SCALE) - offset,
                                   .w = (PIXEL_SCALE),
                                   .h = (PIXEL_SCALE)};
                SDL_RenderFillRect(Frame->render, &pixel);
            }

            // DrawLine(0,0, 10,0, Frame);
            // DrawLine(10,0, 0,10, Frame);
            // DrawLine(0,10, 10,10, Frame);

            // DrawLine(10, 2, 8, 0, Frame);
            // DrawLine(8, 0, 2, 0, Frame);
            // DrawLine(2, 0, 0, 2, Frame);
            // DrawLine(0, 2, 0, 8, Frame);
            // DrawLine(0, 8, 2, 10, Frame);
            // DrawLine(2, 10, 8, 10, Frame);
            // DrawLine(8, 10, 10, 8, Frame);

            // for (int i = 0; i <= step; i++) {
            //     First_Bezier.x =
            //         bezier_quad_int(First_Bezier.x0, First_Bezier.x1, First_Bezier.x2, i,
            //         step);
            //     First_Bezier.y =
            //         bezier_quad_int(First_Bezier.y0, First_Bezier.y1, First_Bezier.y2, i,
            //         step);

            //     // DrawLine(lerpFix(First_Bezier.x0, First_Bezier.x1, i, step),
            //     //          lerpFix(First_Bezier.y0, First_Bezier.y1, i, step),
            //     //          lerpFix(First_Bezier.x1, First_Bezier.x2, i, step),
            //     //          lerpFix(First_Bezier.y1, First_Bezier.y2, i, step), Frame);

            //     // First_Bezier.x =
            //     //     lerpFix(lerpFix(First_Bezier.x0, First_Bezier.x1, i, step),
            //     //             lerpFix(First_Bezier.x1, First_Bezier.x2, i, step), i, step);

            //     // First_Bezier.y =
            //     //     lerpFix(lerpFix(First_Bezier.y0, First_Bezier.y1, i, step),
            //     //             lerpFix(First_Bezier.y1, First_Bezier.y2, i, step), i, step);

            //     printf("(%d, %d)\n", First_Bezier.x, First_Bezier.y);

            //     SDL_FRect pixel = {.x = (First_Bezier.x * PIXEL_SCALE) - offset,
            //                        .y = (First_Bezier.y * PIXEL_SCALE) - offset,
            //                        .w = (PIXEL_SCALE),
            //                        .h = (PIXEL_SCALE)};
            //     SDL_RenderFillRect(Frame->render, &pixel);

            //     SDL_SetRenderDrawColor(Frame->render, rand() % 256, rand() % 256, rand() %
            //     256,
            //                            255);
            // }

            // DrawLine(106, 31, 99, 54, Frame);
            // DrawLine(90, 81, 77, 112, Frame);
            // DrawLine(64, 146, 106, 31, Frame);

            // for (First_Bezier.t = 0.0; First_Bezier.t <= 1.001; First_Bezier.t +=
            // First_Bezier.Step)
            // {
            //     // Beziercurve(&First_Bezier);

            //     First_Bezier.x =
            //         lerp(lerp(First_Bezier.x0, First_Bezier.x1, First_Bezier.t),
            //              lerp(First_Bezier.x1, First_Bezier.x2, First_Bezier.t),
            //              First_Bezier.t);

            //     First_Bezier.y =
            //         lerp(lerp(First_Bezier.y0, First_Bezier.y1, First_Bezier.t),
            //              lerp(First_Bezier.y1, First_Bezier.y2, First_Bezier.t),
            //              First_Bezier.t);

            //     // DrawLine(lerp(First_Bezier.x0, First_Bezier.x1, First_Bezier.t),
            //     //          lerp(First_Bezier.y0, First_Bezier.y1, First_Bezier.t),
            //     //          lerp(First_Bezier.x1, First_Bezier.x2, First_Bezier.t),
            //     //          lerp(First_Bezier.y1, First_Bezier.y2, First_Bezier.t), Frame);

            //     SDL_FRect pixel = {.x = (First_Bezier.x * PIXEL_SCALE) - offset,
            //                        .y = (First_Bezier.y * PIXEL_SCALE) - offset,
            //                        .w = (PIXEL_SCALE),
            //                        .h = (PIXEL_SCALE)};
            //     SDL_RenderFillRect(Frame->render, &pixel);

            //     // SDL_SetRenderDrawColor(Frame->render, rand() % 256, rand() % 256, rand() %
            //     256, 255);
            // }

            // DrawLine(First_Bezier.x0, First_Bezier.y0, First_Bezier.x1, First_Bezier.y1,
            // Frame); DrawLine(First_Bezier.x1, First_Bezier.y1, First_Bezier.x2,
            // First_Bezier.y2, Frame);

            // for (First_Bezier.t = 0.0; First_Bezier.t <= 1.0; First_Bezier.t +=
            // First_Bezier.Step) {
            //     Beziercurve(&First_Bezier);

            //     DrawLine(lerp(First_Bezier.x0, First_Bezier.x1, First_Bezier.t),
            //              lerp(First_Bezier.y0, First_Bezier.y1, First_Bezier.t),
            //              lerp(First_Bezier.x1, First_Bezier.x2, First_Bezier.t),
            //              lerp(First_Bezier.y1, First_Bezier.y2, First_Bezier.t), Frame);

            //     SDL_FRect pixel = {.x = (First_Bezier.x * PIXEL_SCALE) - offset,
            //                        .y = (First_Bezier.y * PIXEL_SCALE) - offset,
            //                        .w = (PIXEL_SCALE),
            //                        .h = (PIXEL_SCALE)};
            //     SDL_RenderFillRect(Frame->render, &pixel);

            //     SDL_SetRenderDrawColor(Frame->render, rand() % 256, rand() % 256, rand() %
            //     256, 255);
            // }

            // DrawLine(12, 10, 7, 19, Frame);
            // DrawLine(12, 10, 17, 19, Frame);

            // DrawLine(32, 15, 224, 15, Frame);
            // DrawLine(line1.out, 10, line1.out, 20, Frame);
            // DrawLine(line1.out + 1, 10, line1.out + 1, 20, Frame);
            // MoveThLine(&line1);

            // DrawLine(32, 30, 224, 30, Frame);
            // DrawLine(line2.out, 25, line2.out, 35, Frame);
            // DrawLine(line2.out + 1, 25, line2.out + 1, 35, Frame);
            // MoveThLine(&line2);

            SDL_RenderPresent(Frame->render);
            SDL_Delay(50); // ~60 FPS
            flag = 1;
        }
    }
}

int main(int argc, char *argv[]) {
    bool Exit_status = 1;

    Window Main = {NULL};
    Main.RunningStatus = 1;

    if (SDL_Window_Init(&Main)) {
        Exit_status = 0;
        SDL_Window_Render(&Main);
    }

    SDL_Window_Free(&Main);
    return Exit_status;
}


#define SetPixel(x, y) NULL

typedef struct {
    int8_t min;
    int8_t max;
    int8_t step;
    int8_t t;
} Lerp;

typedef struct {
    int8_t x0;
    int8_t y0;
    int8_t x1;
    int8_t y1;
    int8_t x2;
    int8_t y2;

    int8_t t;
    int8_t step;

    int8_t x;
    int8_t y;

} Bezier;

typedef struct {
    int8_t x0;
    int8_t y0;
    int8_t x1;
    int8_t y1;
} Line;

int16_t Lerp_Fix(Lerp *main) {
    if (!main->t && !main->min)
        return 0;
    else
        return ((((main->max - main->min) * main->t + (main->step >> 1)) / main->step) + main->min);
}

void Bezierquad_curve(Bezier *main) {
    int16_t nt = (main->step - main->t);
    int16_t n2 = (main->step * main->step);

    main->x = (((nt * nt) * main->x0) + (2 * nt * main->t * main->x1) +
               (main->t * main->t * main->x2) + (n2 >> 1)) /
              n2;
    main->y = (((nt * nt) * main->y0) + (2 * nt * main->t * main->y1) +
               (main->t * main->t * main->y2) + (n2 >> 1)) /
              n2;
}

void DrawLine(Line *main) {

    int16_t adx = (((main->x1 >= main->x0) ? main->x1 - main->x0 : main->x0 - main->x1) + 1) << 1;
    int16_t ady = (((main->y1 >= main->y0) ? main->y1 - main->y0 : main->y0 - main->y1) + 1) << 1;

    int8_t sx = (main->x0 < main->x1) ? 1 : -1;
    int8_t sy = (main->y0 < main->y1) ? 1 : -1;

    int16_t eps;

    if (adx > ady) {

        eps = (ady - adx) >> 1;

        for (int16_t x = main->x0, y = main->y0; sx < 0 ? x >= main->x1 : x <= main->x1; x += sx) {

            SetPixel(x, y);

            eps += ady;
            if (eps << 1 >= adx) {
                y += sy;
                eps -= adx;
            }
        }
    }
    else {
        eps = (adx - ady) >> 1;
        for (int16_t x = main->x0, y = main->y0; sy < 0 ? y >= main->y1 : y <= main->y1; y += sy) {

            SetPixel(x, y);

            eps += adx;
            if (eps << 1 >= ady) {
                x += sx;
                eps -= ady;
            }
        }
    }
}
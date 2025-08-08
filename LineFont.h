#include <stdint.h>

// Line segment structure (8-bit signed for compactness)
typedef struct {
    int8_t x1, y1, x2, y2;
} LineSegment;

// Glyph metadata
typedef struct {
    char c;                // Character
    uint8_t width;         // Glyph width
    uint8_t height;        // Glyph height
    uint8_t segment_count; // Number of line segments
    LineSegment *segments;
} Glyph_Line;

// -------------------------------
// Individual Letter Definitions
// ------------------------------

// ======================
// LETTERS (A-Z)
// ======================
static LineSegment A_seg[] = {{0, 10, 5, 0}, {5, 0, 10, 10}, {2, 5, 8, 5}};
static LineSegment B_seg[] = {{0, 0, 0, 10},  {0, 0, 7, 0},   {0, 5, 7, 5},  {0, 10, 7, 10},
                              {7, 0, 10, 2},  {10, 2, 10, 4}, {10, 4, 7, 5}, {7, 5, 10, 6},
                              {10, 6, 10, 8}, {10, 8, 7, 10}};
static LineSegment C_seg[] = {{10, 2, 8, 0}, {8, 0, 2, 0},   {2, 0, 0, 2},  {0, 2, 0, 8},
                              {0, 8, 2, 10}, {2, 10, 8, 10}, {8, 10, 10, 8}};
static LineSegment D_seg[] = {{0, 0, 0, 10},  {0, 0, 6, 0},   {6, 0, 10, 3},
                              {10, 3, 10, 7}, {10, 7, 6, 10}, {6, 10, 0, 10}};
static LineSegment E_seg[] = {{0, 0, 0, 10}, {0, 0, 10, 0}, {0, 5, 7, 5}, {0, 10, 10, 10}};
static LineSegment F_seg[] = {{0, 0, 0, 10}, {0, 0, 10, 0}, {0, 5, 7, 5}};
static LineSegment G_seg[] = {{10, 2, 8, 0},  {8, 0, 2, 0},   {2, 0, 0, 2},
                              {0, 2, 0, 8},   {0, 8, 2, 10},  {2, 10, 8, 10},
                              {8, 10, 10, 8}, {10, 8, 10, 5}, {10, 5, 6, 5}};
static LineSegment H_seg[] = {{0, 0, 0, 10}, {10, 0, 10, 10}, {0, 5, 10, 5}};
static LineSegment I_seg[] = {{3, 0, 7, 0}, {5, 0, 5, 10}, {3, 10, 7, 10}};
static LineSegment J_seg[] = {{7, 0, 7, 8}, {7, 8, 5, 10}, {5, 10, 2, 10}, {2, 10, 0, 8}};
static LineSegment K_seg[] = {{0, 0, 0, 10}, {0, 5, 10, 0}, {0, 5, 10, 10}};
static LineSegment L_seg[] = {{0, 0, 0, 10}, {0, 10, 10, 10}};
static LineSegment M_seg[] = {{0, 10, 0, 0}, {0, 0, 5, 5}, {5, 5, 10, 0}, {10, 0, 10, 10}};
static LineSegment N_seg[] = {{0, 10, 0, 0}, {0, 0, 10, 10}, {10, 10, 10, 0}};
static LineSegment O_seg[] = {{0, 2, 2, 0},   {2, 0, 8, 0},   {8, 0, 10, 2}, {10, 2, 10, 8},
                              {10, 8, 8, 10}, {8, 10, 2, 10}, {2, 10, 0, 8}, {0, 8, 0, 2}};

// Fixed P: simpler, balanced bowl (top only), stem full height
static LineSegment P_seg[] = {
    {0, 0, 0, 10}, {0, 0, 7, 0}, {7, 0, 10, 3}, {10, 3, 7, 5}, {7, 5, 0, 5}};

// Fixed Q remains as before (with tail)
static LineSegment Q_seg[] = {{0, 2, 2, 0},   {2, 0, 8, 0},   {8, 0, 10, 2},
                              {10, 2, 10, 8}, {10, 8, 8, 10}, {8, 10, 2, 10},
                              {2, 10, 0, 8},  {0, 8, 0, 2},   {6, 6, 10, 10}};

// Fixed R: same as P with a diagonal leg
static LineSegment R_seg[] = {{0, 0, 0, 10}, {0, 0, 7, 0}, {7, 0, 10, 3},
                              {10, 3, 7, 5}, {7, 5, 0, 5}, {0, 5, 8, 10}};

static LineSegment S_seg[] = {{10, 2, 8, 0},  {8, 0, 2, 0},   {2, 0, 0, 2},  {0, 2, 0, 4},
                              {0, 4, 2, 5},   {2, 5, 8, 5},   {8, 5, 10, 6}, {10, 6, 10, 8},
                              {10, 8, 8, 10}, {8, 10, 2, 10}, {2, 10, 0, 8}};
static LineSegment T_seg[] = {{0, 0, 10, 0}, {5, 0, 5, 10}};
static LineSegment U_seg[] = {
    {0, 0, 0, 8}, {0, 8, 2, 10}, {2, 10, 8, 10}, {8, 10, 10, 8}, {10, 8, 10, 0}};
static LineSegment V_seg[] = {{0, 0, 5, 10}, {5, 10, 10, 0}};
static LineSegment W_seg[] = {{0, 0, 2, 10}, {2, 10, 5, 5}, {5, 5, 8, 10}, {8, 10, 10, 0}};
static LineSegment X_seg[] = {{0, 0, 10, 10}, {0, 10, 10, 0}};
static LineSegment Y_seg[] = {{0, 0, 5, 5}, {10, 0, 5, 5}, {5, 5, 5, 10}};
static LineSegment Z_seg[] = {{0, 0, 10, 0}, {10, 0, 0, 10}, {0, 10, 10, 10}};

// ======================
// DIGITS (0-9)
// ======================

// Fixed 0: a little narrower than letter O (margin 1..9)
static LineSegment _0_seg[] = {{1, 2, 3, 0},  {3, 0, 7, 0},   {7, 0, 9, 2},  {9, 2, 9, 8},
                               {9, 8, 7, 10}, {7, 10, 3, 10}, {3, 10, 1, 8}, {1, 8, 1, 2}};

// Fixed 1: clear vertical stroke + top hook + bottom foot
static LineSegment _1_seg[] = {{6, 0, 6, 10}, {3, 3, 6, 0}, {2, 10, 10, 10}};

static LineSegment _2_seg[] = {{0, 2, 2, 0},   {2, 0, 8, 0},   {8, 0, 10, 2},
                               {10, 2, 10, 4}, {10, 4, 0, 10}, {0, 10, 10, 10}};

// Slightly simplified 3 (keeps readable shape)
static LineSegment _3_seg[] = {{0, 2, 2, 0},   {2, 0, 8, 0},  {8, 0, 10, 2},  {10, 2, 10, 4},
                               {10, 4, 8, 5},  {8, 5, 10, 6}, {10, 6, 10, 8}, {10, 8, 8, 10},
                               {8, 10, 2, 10}, {2, 10, 0, 8}};

// Fixed 4: vertical right leg at x=8 for clarity
static LineSegment _4_seg[] = {{8, 0, 0, 6}, {0, 6, 10, 6}, {8, 0, 8, 10}};

static LineSegment _5_seg[] = {{10, 0, 0, 0},  {0, 0, 0, 5},   {0, 5, 8, 5},   {8, 5, 10, 6},
                               {10, 6, 10, 8}, {10, 8, 8, 10}, {8, 10, 2, 10}, {2, 10, 0, 8}};
static LineSegment _6_seg[] = {{10, 2, 8, 0}, {8, 0, 2, 0},   {2, 0, 0, 2},   {0, 2, 0, 8},
                               {0, 8, 2, 10}, {2, 10, 8, 10}, {8, 10, 10, 8}, {10, 8, 10, 6},
                               {10, 6, 8, 5}, {8, 5, 2, 5}};
static LineSegment _7_seg[] = {{0, 0, 10, 0}, {10, 0, 2, 10}};

// _8: kept symmetrical double-loop, still readable
static LineSegment _8_seg[] = {{0, 2, 2, 0},  {2, 0, 8, 0},   {8, 0, 10, 2},  {10, 2, 10, 4},
                               {10, 4, 8, 5}, {8, 5, 2, 5},   {1, 5, 0, 4},   {0, 4, 0, 2},
                               {0, 8, 2, 10}, {2, 10, 8, 10}, {8, 10, 10, 8}, {10, 8, 10, 6},
                               {10, 6, 8, 5}, {8, 5, 2, 5},   {1, 5, 0, 6},   {0, 6, 0, 8}};

static LineSegment _9_seg[] = {
    // Top loop
    {2, 0, 8, 0},  {8, 0, 10, 2}, {2, 10, 8, 10}, {10, 8, 8, 10}, {10, 3, 10, 7},
    {2, 10, 0, 8}, {2, 5, 8, 5},  {0, 3, 0, 4},   {0, 2, 2, 0}

    // Stem

};

// ======================
// SYMBOLS (! ? . , : ;)
// ======================

// Fixed ! with short top cap, main stroke and dot
static LineSegment _excl[] = {
    {4, 9, 6, 9},
    {4, 8, 6, 8}, // Main vertical (with cap)
    {5, 6, 5, 0},
    {4, 0, 4, 3}, // Square dot
    {6, 0, 6, 3}  // Square dot

};

/* ? */ static LineSegment _quest[] = {{0, 2, 2, 0},   {2, 0, 8, 0}, {8, 0, 10, 2}, // Top curve
                                       {9, 3, 7, 5},   {7, 5, 7, 7},                // Hook

                                       {6, 10, 8, 10}, {6, 9, 8, 9}};

static LineSegment _period[] = {{5, 9, 5, 10}};
static LineSegment _comma[] = {{4, 8, 4, 9}, {4, 9, 3, 10}};
static LineSegment _colon[] = {{5, 2, 5, 3}, {5, 7, 5, 8}};
static LineSegment _semicolon[] = {{5, 2, 5, 3}, {5, 7, 5, 9}, {5, 9, 4, 10}};

// ======================
// FONT LOOKUP TABLE
// ======================

static Glyph_Line font_table[] = {
    // Letters A-Z
    {'A', 10, 10, 3, A_seg},
    {'B', 10, 10, 10, B_seg},
    {'C', 10, 10, 7, C_seg},
    {'D', 10, 10, 6, D_seg},
    {'E', 10, 10, 4, E_seg},
    {'F', 10, 10, 3, F_seg},
    {'G', 10, 10, 9, G_seg},
    {'H', 10, 10, 3, H_seg},
    {'I', 10, 10, 3, I_seg},
    {'J', 10, 10, 4, J_seg},
    {'K', 10, 10, 3, K_seg},
    {'L', 10, 10, 2, L_seg},
    {'M', 10, 10, 4, M_seg},
    {'N', 10, 10, 3, N_seg},
    {'O', 10, 10, 8, O_seg},
    {'P', 10, 10, 5, P_seg},
    {'Q', 10, 10, 9, Q_seg},
    {'R', 10, 10, 6, R_seg},
    {'S', 10, 10, 11, S_seg},
    {'T', 10, 10, 2, T_seg},
    {'U', 10, 10, 5, U_seg},
    {'V', 10, 10, 2, V_seg},
    {'W', 10, 10, 4, W_seg},
    {'X', 10, 10, 2, X_seg},
    {'Y', 10, 10, 3, Y_seg},
    {'Z', 10, 10, 3, Z_seg},

    // Digits 0-9
    {'0', 10, 10, 8, _0_seg},
    {'1', 10, 10, 3, _1_seg},
    {'2', 10, 10, 6, _2_seg},
    {'3', 10, 10, 10, _3_seg},
    {'4', 10, 10, 3, _4_seg},
    {'5', 10, 10, 8, _5_seg},
    {'6', 10, 10, 10, _6_seg},
    {'7', 10, 10, 2, _7_seg},
    {'8', 10, 10, 16, _8_seg},
    {'9', 10, 10, 9, _9_seg},

    // Symbols
    {'!', 6, 10, 5, _excl},
    {'?', 10, 10, 7, _quest},
    {'.', 2, 10, 1, _period},
    {',', 4, 10, 2, _comma},
    {':', 2, 10, 2, _colon},
    {';', 4, 10, 3, _semicolon}};

// // Get glyph data for a character
// Glyph *get_glyph(char c) {
//     if (c >= 'A' && c <= 'Z')
//         return &font_az[c - 'A'];

//     else if ((c - 32) >= 'A' && (c - 32) <= 'Z')
//         return &font_az[(c - 32) - 'A'];

//     return NULL; // Character not supported
// }

Glyph_Line *get_glyph_Line(char c) {
    for (uint8_t i = 0; i < sizeof(font_table) / sizeof(Glyph_Line); i++) {
        if (font_table[i].c == c)
            return &font_table[i];
    }
    return NULL; // Character not supported
}

void draw_text(char *str, int16_t x, int16_t y, uint8_t scale) {
    while (*str) {
        Glyph_Line *g = get_glyph_Line(*str++);
        if (!g)
            return;

        for (uint8_t i = 0; i < g->segment_count; i++) {
            DrawLine((x + g->segments[i].x1 * scale), (y + g->segments[i].y1 * scale),
                     (x + g->segments[i].x2 * scale), (y + g->segments[i].y2 * scale));
        }
        x += g->width * scale + 5; // Advance cursor
    }
}

void GLCD_DrawChar(char c, uint8_t x, uint8_t y, uint8_t scale, uint8_t deph) {
    Glyph_Line *g = get_glyph_Line(c);
    if (!g)
        return;
    for (uint8_t j = 0; j < deph; j++) {
        for (uint8_t i = 0; i < g->segment_count; i++) {

            DrawLine((x + j + (g->segments[i].x1 * scale)), (y + (g->segments[i].y1 * scale)),
                     (x + j + (g->segments[i].x2 * scale)), (y + (g->segments[i].y2 * scale)));
        }
    }
}
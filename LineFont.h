#pragma once
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
} Glyph;

// -------------------------------
// Individual Letter Definitions
// -------------------------------

// A
static LineSegment A_segments[] = {{5, 0, 0, 10}, {5, 0, 10, 10}, {3, 5, 7, 5}};

// B
static LineSegment B_segments[] = {{0, 0, 0, 10}, {0, 10, 6, 10}, {6, 10, 8, 8}, {8, 8, 8, 6},
                                   {8, 6, 6, 5},  {6, 5, 0, 5},   {6, 5, 8, 4},  {8, 4, 8, 2},
                                   {8, 2, 6, 0},  {6, 0, 0, 0}};

// C
static LineSegment C_segments[] = {{10, 2, 8, 0}, {8, 0, 2, 0},   {2, 0, 0, 2},  {0, 2, 0, 8},
                                   {0, 8, 2, 10}, {2, 10, 8, 10}, {8, 10, 10, 8}};

// D
static LineSegment D_segments[] = {{0, 0, 0, 10},  {0, 10, 6, 10}, {6, 10, 10, 6},
                                   {10, 6, 10, 4}, {10, 4, 6, 0},  {6, 0, 0, 0}};

// E
static LineSegment E_segments[] = {{0, 0, 0, 10}, {0, 10, 10, 10}, {0, 5, 8, 5}, {0, 0, 10, 0}};

// F
static LineSegment F_segments[] = {{0, 0, 0, 10}, {0, 10, 10, 10}, {0, 5, 6, 5}};

// G
static LineSegment G_segments[] = {{10, 2, 8, 0},  {8, 0, 2, 0},   {2, 0, 0, 2},
                                   {0, 2, 0, 8},   {0, 8, 2, 10},  {2, 10, 8, 10},
                                   {8, 10, 10, 8}, {10, 8, 10, 4}, {10, 4, 6, 4}};

// H
static LineSegment H_segments[] = {{0, 0, 0, 10}, {10, 0, 10, 10}, {0, 5, 10, 5}};

// I
static LineSegment I_segments[] = {{0, 0, 10, 0}, {5, 0, 5, 10}, {0, 10, 10, 10}};

// J
static LineSegment J_segments[] = {{5, 0, 5, 8}, {5, 8, 3, 10}, {3, 10, 0, 10}};

// K
static LineSegment K_segments[] = {{0, 0, 0, 10}, {0, 5, 10, 0}, {0, 5, 10, 10}};

// L
static LineSegment L_segments[] = {{0, 0, 0, 10}, {0, 10, 10, 10}};

// M
static LineSegment M_segments[] = {{0, 10, 0, 0}, {0, 0, 5, 5}, {5, 5, 10, 0}, {10, 0, 10, 10}};

// N
static LineSegment N_segments[] = {{0, 10, 0, 0}, {0, 0, 10, 10}, {10, 10, 10, 0}};

// O
static LineSegment O_segments[] = {{0, 2, 2, 0},   {2, 0, 8, 0},   {8, 0, 10, 2}, {10, 2, 10, 8},
                                   {10, 8, 8, 10}, {8, 10, 2, 10}, {2, 10, 0, 8}, {0, 8, 0, 2}};

// P
static LineSegment P_segments[] = {{0, 0, 0, 10}, {0, 10, 6, 10}, {6, 10, 8, 8},
                                   {8, 8, 8, 6},  {8, 6, 6, 5},   {6, 5, 0, 5}};

// Q
static LineSegment Q_segments[] = {{0, 2, 2, 0},   {2, 0, 8, 0},   {8, 0, 10, 2},
                                   {10, 2, 10, 8}, {10, 8, 8, 10}, {8, 10, 2, 10},
                                   {2, 10, 0, 8},  {0, 8, 0, 2},   {6, 6, 10, 10}};

// R
static LineSegment R_segments[] = {{0, 0, 0, 10}, {0, 10, 6, 10}, {6, 10, 8, 8}, {8, 8, 8, 6},
                                   {8, 6, 6, 5},  {6, 5, 0, 5},   {6, 5, 10, 0}};

// S
static LineSegment S_segments[] = {{10, 2, 8, 0},  {8, 0, 2, 0},   {2, 0, 0, 2},  {0, 2, 0, 4},
                                   {0, 4, 2, 5},   {2, 5, 8, 5},   {8, 5, 10, 6}, {10, 6, 10, 8},
                                   {10, 8, 8, 10}, {8, 10, 2, 10}, {2, 10, 0, 8}};

// T
static LineSegment T_segments[] = {{0, 0, 10, 0}, {5, 0, 5, 10}};

// U
static LineSegment U_segments[] = {
    {0, 0, 0, 8}, {0, 8, 2, 10}, {2, 10, 8, 10}, {8, 10, 10, 8}, {10, 8, 10, 0}};

// V
static LineSegment V_segments[] = {{0, 0, 5, 10}, {5, 10, 10, 0}};

// W
static LineSegment W_segments[] = {{0, 0, 0, 10}, {0, 10, 5, 5}, {5, 5, 10, 10}, {10, 10, 10, 0}};

// X
static LineSegment X_segments[] = {{0, 0, 10, 10}, {0, 10, 10, 0}};

// Y
static LineSegment Y_segments[] = {{0, 0, 5, 5}, {10, 0, 5, 5}, {5, 5, 5, 10}};

// Z
static LineSegment Z_segments[] = {{0, 0, 10, 0}, {10, 0, 0, 10}, {0, 10, 10, 10}};

// 0
static LineSegment digit_0_segments[] = {{0, 2, 2, 0},   {2, 0, 8, 0},   {8, 0, 10, 2},
                                         {10, 2, 10, 8}, {10, 8, 8, 10}, {8, 10, 2, 10},
                                         {2, 10, 0, 8},  {0, 8, 0, 2}};

// 1
static LineSegment digit_1_segments[] = {{5, 0, 5, 10}, {3, 2, 5, 0}, {5, 10, 3, 8}};

// 2
static LineSegment digit_2_segments[] = {{0, 2, 2, 0},   {2, 0, 8, 0},   {8, 0, 10, 2},
                                         {10, 2, 10, 4}, {10, 4, 0, 10}, {0, 10, 10, 10}};

// 3
static LineSegment digit_3_segments[] = {
    {0, 2, 2, 0}, {2, 0, 8, 0}, {8, 0, 10, 2}, {10, 2, 10, 4}, {10, 4, 8, 5}, {8, 5, 2, 5},
    {2, 5, 0, 6}, {0, 6, 0, 8}, {0, 8, 2, 10}, {2, 10, 8, 10}, {8, 10, 10, 8}};

// 4
static LineSegment digit_4_segments[] = {{8, 0, 0, 6}, {0, 6, 10, 6}, {6, 0, 6, 10}};

// 5
static LineSegment digit_5_segments[] = {{10, 0, 0, 0},  {0, 0, 0, 5},   {0, 5, 8, 5},
                                         {8, 5, 10, 6},  {10, 6, 10, 8}, {10, 8, 8, 10},
                                         {8, 10, 2, 10}, {2, 10, 0, 8}};

// 6
static LineSegment digit_6_segments[] = {
    {10, 2, 8, 0},  {8, 0, 2, 0},   {2, 0, 0, 2},   {0, 2, 0, 8},  {0, 8, 2, 10},
    {2, 10, 8, 10}, {8, 10, 10, 8}, {10, 8, 10, 6}, {10, 6, 8, 5}, {8, 5, 2, 5}};

// 7
static LineSegment digit_7_segments[] = {{0, 0, 10, 0}, {10, 0, 2, 10}};

// 8
static LineSegment digit_8_segments[] = {
    {0, 2, 2, 0},  {2, 0, 8, 0}, {8, 0, 10, 2}, {10, 2, 10, 4}, {10, 4, 8, 5},  {8, 5, 2, 5},
    {2, 5, 0, 6},  {0, 6, 0, 8}, {0, 8, 2, 10}, {2, 10, 8, 10}, {8, 10, 10, 8}, {10, 8, 10, 6},
    {10, 6, 8, 5}, {8, 5, 2, 5}, {2, 5, 0, 4},  {0, 4, 0, 2}};

// 9
static LineSegment digit_9_segments[] = {{10, 6, 8, 8}, {8, 8, 2, 8},  {2, 8, 0, 6},
                                         {0, 6, 0, 2},  {0, 2, 2, 0},  {2, 0, 8, 0},
                                         {8, 0, 10, 2}, {10, 2, 10, 6}};

// -------------------------------
// Special Symbols (!, ?, etc.)
// -------------------------------

// !
static LineSegment symbol_exclamation_segments[] = {{4, 0, 5, 7},  {5, 0, 5, 7},  {6, 0, 5, 7},
                                                    {4, 9, 4, 10}, {5, 9, 5, 10}, {6, 9, 6, 10}};

// ?
static LineSegment symbol_question_segments[] = {{0, 2, 2, 0},   {2, 0, 8, 0},  {8, 0, 10, 2},
                                                 {10, 2, 10, 4}, {10, 4, 6, 6}, {6, 6, 6, 7},
                                                 {5, 9, 5, 10},  {6, 9, 6, 10}, {7, 9, 7, 10}};

// .
static LineSegment symbol_period_segments[] = {{5, 9, 5, 10}, {6, 9, 6, 10}, {7, 9, 7, 10}};

// ,
static LineSegment symbol_comma_segments[] = {{5, 9, 5, 10}, {5, 10, 4, 11}};

// :
static LineSegment symbol_colon_segments[] = {{5, 2, 5, 3}, {5, 7, 5, 8}};

// -------------------------------
// Font Lookup Table
// -------------------------------
static Glyph font_digits_symbols[] = {
    {'A', 10, 10, sizeof(A_segments) / sizeof(LineSegment), A_segments},
    {'B', 10, 10, sizeof(B_segments) / sizeof(LineSegment), B_segments},
    {'C', 10, 10, sizeof(C_segments) / sizeof(LineSegment), C_segments},
    {'D', 10, 10, sizeof(D_segments) / sizeof(LineSegment), D_segments},
    {'E', 10, 10, sizeof(E_segments) / sizeof(LineSegment), E_segments},
    {'F', 10, 10, sizeof(F_segments) / sizeof(LineSegment), F_segments},
    {'G', 10, 10, sizeof(G_segments) / sizeof(LineSegment), G_segments},
    {'H', 10, 10, sizeof(H_segments) / sizeof(LineSegment), H_segments},
    {'I', 10, 10, sizeof(I_segments) / sizeof(LineSegment), I_segments},
    {'J', 10, 10, sizeof(J_segments) / sizeof(LineSegment), J_segments},
    {'K', 10, 10, sizeof(K_segments) / sizeof(LineSegment), K_segments},
    {'L', 10, 10, sizeof(L_segments) / sizeof(LineSegment), L_segments},
    {'M', 10, 10, sizeof(M_segments) / sizeof(LineSegment), M_segments},
    {'N', 10, 10, sizeof(N_segments) / sizeof(LineSegment), N_segments},
    {'O', 10, 10, sizeof(O_segments) / sizeof(LineSegment), O_segments},
    {'P', 10, 10, sizeof(P_segments) / sizeof(LineSegment), P_segments},
    {'Q', 10, 10, sizeof(Q_segments) / sizeof(LineSegment), Q_segments},
    {'R', 10, 10, sizeof(R_segments) / sizeof(LineSegment), R_segments},
    {'S', 10, 10, sizeof(S_segments) / sizeof(LineSegment), S_segments},
    {'T', 10, 10, sizeof(T_segments) / sizeof(LineSegment), T_segments},
    {'U', 10, 10, sizeof(U_segments) / sizeof(LineSegment), U_segments},
    {'V', 10, 10, sizeof(V_segments) / sizeof(LineSegment), V_segments},
    {'W', 10, 10, sizeof(W_segments) / sizeof(LineSegment), W_segments},
    {'X', 10, 10, sizeof(X_segments) / sizeof(LineSegment), X_segments},
    {'Y', 10, 10, sizeof(Y_segments) / sizeof(LineSegment), Y_segments},
    {'Z', 10, 10, sizeof(Z_segments) / sizeof(LineSegment), Z_segments},
    {'0', 10, 10, sizeof(digit_0_segments) / sizeof(LineSegment), digit_0_segments},
    {'1', 10, 10, sizeof(digit_1_segments) / sizeof(LineSegment), digit_1_segments},
    {'2', 10, 10, sizeof(digit_2_segments) / sizeof(LineSegment), digit_2_segments},
    {'3', 10, 10, sizeof(digit_3_segments) / sizeof(LineSegment), digit_3_segments},
    {'4', 10, 10, sizeof(digit_4_segments) / sizeof(LineSegment), digit_4_segments},
    {'5', 10, 10, sizeof(digit_5_segments) / sizeof(LineSegment), digit_5_segments},
    {'6', 10, 10, sizeof(digit_6_segments) / sizeof(LineSegment), digit_6_segments},
    {'7', 10, 10, sizeof(digit_7_segments) / sizeof(LineSegment), digit_7_segments},
    {'8', 10, 10, sizeof(digit_8_segments) / sizeof(LineSegment), digit_8_segments},

    {'9', 10, 10, sizeof(digit_9_segments) / sizeof(LineSegment), digit_9_segments},
    {'!', 4, 10, sizeof(symbol_exclamation_segments) / sizeof(LineSegment),
     symbol_exclamation_segments},
    {'?', 10, 10, sizeof(symbol_question_segments) / sizeof(LineSegment), symbol_question_segments},
    {'.', 2, 10, sizeof(symbol_period_segments) / sizeof(LineSegment), symbol_period_segments},
    {',', 4, 11, sizeof(symbol_comma_segments) / sizeof(LineSegment), symbol_comma_segments},
    {':', 2, 10, sizeof(symbol_colon_segments) / sizeof(LineSegment), symbol_colon_segments}};

// // Get glyph data for a character
// Glyph *get_glyph(char c) {
//     if (c >= 'A' && c <= 'Z')
//         return &font_az[c - 'A'];

//     else if ((c - 32) >= 'A' && (c - 32) <= 'Z')
//         return &font_az[(c - 32) - 'A'];

//     return NULL; // Character not supported
// }

Glyph *get_glyph(char c) {
    for (uint8_t i = 0; i < sizeof(font_digits_symbols) / sizeof(Glyph); i++) {
        if (font_digits_symbols[i].c == c)
            return &font_digits_symbols[i];
    }
    return NULL; // Character not supported
}

void draw_text(char *str, int16_t x, int16_t y, uint8_t scale) {
    while (*str) {
        Glyph *g = get_glyph(*str++);
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
    Glyph *g = get_glyph(c);
    if (!g)
        return;
    for (uint8_t j = 0; j < deph; j++) {
        for (uint8_t i = 0; i < g->segment_count; i++) {

            DrawLine((x + j + (g->segments[i].x1 * scale)), (y + j + (g->segments[i].y1 * scale)),
                     (x + j + (g->segments[i].x2 * scale)), (y + j + (g->segments[i].y2 * scale)));
        }
    }
}
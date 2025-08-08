#include <stdint.h>

// Quadratic Bézier segment (6 bytes)
typedef struct {
    int8_t x0, y0; // Start point
    int8_t x1, y1; // Control point
    int8_t x2, y2; // End point
} BezierSegment;

// Glyph_Bez metadata (4 bytes + curve data)
typedef struct {
    char c;            // ASCII character
    uint8_t seg_count; // Number of segments
    uint8_t width;     // Glyph_Bez width (units)
    BezierSegment *segs;
} Glyph_Bez;

// -------------------------------
// Uppercase Letters (A-Z)
// -------------------------------
static BezierSegment A_segs[] = {{0, 10, 2, 5, 5, 0}, {5, 0, 8, 5, 10, 10}, {2, 5, 5, 5, 8, 5}};
static BezierSegment B_segs[] = {
    {0, 0, 6, 0, 8, 2}, {8, 2, 10, 4, 8, 6}, {8, 6, 6, 8, 0, 8}, {0, 0, 0, 4, 0, 8}};
static BezierSegment C_segs[] = {
    {10, 2, 8, 0, 2, 0}, {2, 0, 0, 2, 0, 8}, {0, 8, 2, 10, 8, 10}, {8, 10, 10, 8, 10, 6}};
static BezierSegment D_segs[] = {{0, 0, 6, 0, 10, 4}, {10, 4, 10, 6, 6, 10}, {6, 10, 0, 10, 0, 5}};
static BezierSegment E_segs[] = {
    {10, 0, 0, 0, 0, 0}, {0, 0, 0, 5, 8, 5}, {0, 5, 0, 10, 10, 10}, {0, 0, 0, 0, 0, 10}};
static BezierSegment F_segs[] = {{0, 0, 0, 0, 0, 10}, {0, 0, 0, 0, 10, 0}, {0, 5, 0, 5, 6, 5}};
static BezierSegment G_segs[] = {{10, 2, 8, 0, 2, 0},
                                 {2, 0, 0, 2, 0, 8},
                                 {0, 8, 2, 10, 8, 10},
                                 {8, 10, 10, 8, 10, 4},
                                 {10, 4, 6, 4, 6, 4}};
static BezierSegment H_segs[] = {{0, 0, 0, 0, 0, 10}, {10, 0, 10, 0, 10, 10}, {0, 5, 0, 5, 10, 5}};
static BezierSegment I_segs[] = {{0, 0, 5, 0, 10, 0}, {5, 0, 5, 0, 5, 10}, {0, 10, 5, 10, 10, 10}};
static BezierSegment J_segs[] = {{5, 0, 5, 0, 5, 8}, {5, 8, 3, 10, 0, 10}};
static BezierSegment K_segs[] = {{0, 0, 0, 0, 0, 10}, {0, 5, 0, 5, 10, 0}, {0, 5, 0, 5, 10, 10}};
static BezierSegment L_segs[] = {{0, 0, 0, 0, 0, 10}, {0, 10, 0, 10, 10, 10}};
static BezierSegment M_segs[] = {{0, 10, 0, 5, 5, 0}, {5, 0, 10, 5, 10, 10}};
static BezierSegment N_segs[] = {{0, 10, 0, 0, 10, 10}, {10, 10, 10, 0, 10, 0}};
static BezierSegment O_segs[] = {
    {0, 2, 2, 0, 8, 0}, {8, 0, 10, 2, 10, 8}, {10, 8, 8, 10, 2, 10}, {2, 10, 0, 8, 0, 2}};
static BezierSegment P_segs[] = {
    {0, 0, 0, 0, 0, 10}, {0, 0, 6, 0, 8, 2}, {8, 2, 8, 6, 6, 8}, {6, 8, 0, 8, 0, 5}};
static BezierSegment Q_segs[] = {{0, 2, 2, 0, 8, 0},
                                 {8, 0, 10, 2, 10, 8},
                                 {10, 8, 8, 10, 2, 10},
                                 {2, 10, 0, 8, 0, 2},
                                 {6, 6, 8, 8, 10, 10}};
static BezierSegment R_segs[] = {{0, 0, 0, 0, 0, 10},
                                 {0, 0, 6, 0, 8, 2},
                                 {8, 2, 8, 6, 6, 8},
                                 {6, 8, 0, 8, 0, 5},
                                 {6, 8, 8, 10, 10, 10}};
static BezierSegment S_segs[] = {{10, 2, 8, 0, 2, 0},
                                 {2, 0, 0, 2, 0, 4},
                                 {0, 4, 2, 6, 8, 6},
                                 {8, 6, 10, 8, 10, 10},
                                 {10, 10, 8, 12, 2, 12}};
static BezierSegment T_segs[] = {{0, 0, 5, 0, 10, 0}, {5, 0, 5, 0, 5, 10}};
static BezierSegment U_segs[] = {{0, 0, 0, 8, 2, 10}, {2, 10, 8, 10, 10, 8}, {10, 8, 10, 0, 10, 0}};
static BezierSegment V_segs[] = {0, 0, 5, 10, 10, 0};
static BezierSegment W_segs[] = {{0, 0, 2, 10, 5, 5}, {5, 5, 8, 10, 10, 0}};
static BezierSegment X_segs[] = {{0, 0, 5, 5, 10, 10}, {10, 0, 5, 5, 0, 10}};
static BezierSegment Y_segs[] = {{0, 0, 5, 5, 10, 0}, {5, 5, 5, 5, 5, 10}};
static BezierSegment Z_segs[] = {
    {0, 0, 10, 0, 10, 0}, {10, 0, 0, 10, 0, 10}, {0, 10, 10, 10, 10, 10}};

// Digits (0-9)
static BezierSegment _0_segs[] = {
    {5, 0, 10, 0, 10, 5}, {10, 5, 10, 10, 5, 10}, {5, 10, 0, 10, 0, 5}, {0, 5, 0, 0, 5, 0}};
static BezierSegment _1_segs[] = {{5, 0, 5, 0, 5, 10}, {3, 2, 4, 1, 5, 0}, {5, 10, 4, 9, 3, 8}};
static BezierSegment _2_segs[] = {
    {0, 2, 2, 0, 8, 0}, {8, 0, 10, 2, 10, 4}, {10, 4, 0, 10, 0, 10}, {0, 10, 10, 10, 10, 10}};
static BezierSegment _3_segs[] = {{0, 2, 2, 0, 8, 0},     {8, 0, 10, 2, 10, 4},
                                  {10, 4, 8, 6, 2, 6},    {2, 6, 8, 6, 10, 8},
                                  {10, 8, 10, 10, 8, 12}, {8, 12, 2, 12, 0, 10}};
static BezierSegment _4_segs[] = {{8, 0, 0, 6, 0, 6}, {0, 6, 10, 6, 10, 6}, {6, 0, 6, 0, 6, 10}};
static BezierSegment _5_segs[] = {{10, 0, 0, 0, 0, 0},
                                  {0, 0, 0, 5, 8, 5},
                                  {8, 5, 10, 6, 10, 8},
                                  {10, 8, 8, 10, 2, 10},
                                  {2, 10, 0, 8, 0, 8}};
static BezierSegment _6_segs[] = {{10, 2, 8, 0, 2, 0},
                                  {2, 0, 0, 2, 0, 8},
                                  {0, 8, 2, 10, 8, 10},
                                  {8, 10, 10, 8, 10, 6},
                                  {10, 6, 8, 4, 2, 4}};
static BezierSegment _7_segs[] = {{0, 0, 10, 0, 10, 0}, {10, 0, 2, 10, 2, 10}};
static BezierSegment _8_segs[] = {
    {0, 2, 2, 0, 8, 0},    {8, 0, 10, 2, 10, 4},   {10, 4, 8, 6, 2, 6}, {2, 6, 0, 8, 0, 10},
    {0, 10, 2, 12, 8, 12}, {8, 12, 10, 10, 10, 8}, {10, 8, 8, 6, 2, 6}};
static BezierSegment _9_segs[] = {
    {10, 6, 8, 8, 2, 8}, {2, 8, 0, 6, 0, 2}, {0, 2, 2, 0, 8, 0}, {8, 0, 10, 2, 10, 6}};

// Symbols
static BezierSegment _excl_segs[] = {{5, 0, 5, 5, 5, 8}, {5, 9, 5, 10, 5, 10}};
static BezierSegment _quest_segs[] = {
    {0, 2, 5, 0, 10, 2}, {10, 2, 8, 4, 6, 5}, {6, 8, 6, 9, 6, 10}};
static BezierSegment _period_segs[] = {5, 9, 5, 10, 5, 10};
static BezierSegment _comma_segs[] = {5, 9, 5, 10, 4, 11};
static BezierSegment _colon_segs[] = {{5, 2, 5, 3, 5, 3}, {5, 7, 5, 8, 5, 8}};
static BezierSegment _semicolon_segs[] = {{5, 2, 5, 3, 5, 3}, {5, 7, 5, 9, 4, 10}};
static BezierSegment _plus_segs[] = {{5, 0, 5, 5, 5, 10}, {0, 5, 5, 5, 10, 5}};
static BezierSegment _minus_segs[] = {0, 5, 5, 5, 10, 5};
static BezierSegment _equal_segs[] = {{0, 3, 5, 3, 10, 3}, {0, 7, 5, 7, 10, 7}};
static BezierSegment _at_segs[] = {{10, 5, 5, 0, 0, 5},
                                   {0, 5, 0, 8, 2, 10},
                                   {2, 10, 8, 10, 10, 8},
                                   {10, 8, 10, 3, 6, 3},
                                   {6, 3, 6, 6, 8, 6}};
static BezierSegment _hash_segs[] = {
    {2, 0, 2, 0, 2, 10}, {8, 0, 8, 0, 8, 10}, {0, 3, 10, 3, 10, 3}, {0, 7, 10, 7, 10, 7}};
static BezierSegment _dollar_segs[] = {
    {5, 0, 5, 2, 5, 8}, {5, 8, 5, 10, 5, 10}, {2, 2, 8, 2, 8, 2}, {2, 8, 8, 8, 8, 8}};
static BezierSegment _percent_segs[] = {
    {0, 0, 10, 10, 10, 10}, {2, 2, 3, 2, 3, 2}, {7, 8, 8, 8, 8, 8}};
static BezierSegment _ampersand_segs[] = {
    {10, 0, 5, 5, 0, 10}, {0, 5, 5, 5, 10, 0}, {5, 5, 10, 10, 10, 10}};
static BezierSegment _asterisk_segs[] = {
    {5, 0, 5, 5, 5, 10}, {0, 3, 10, 7, 10, 7}, {10, 3, 0, 7, 0, 7}};
static BezierSegment _lparen_segs[] = {6, 0, 3, 3, 0, 10};
static BezierSegment _rparen_segs[] = {0, 0, 3, 7, 6, 10};
static BezierSegment _lbracket_segs[] = {
    {6, 0, 2, 0, 2, 0}, {2, 0, 2, 10, 2, 10}, {2, 10, 6, 10, 6, 10}};
static BezierSegment _rbracket_segs[] = {
    {0, 0, 4, 0, 4, 0}, {4, 0, 4, 10, 4, 10}, {4, 10, 0, 10, 0, 10}};
static BezierSegment _lbrace_segs[] = {{6, 0, 3, 0, 0, 5}, {0, 5, 3, 10, 6, 10}};
static BezierSegment _rbrace_segs[] = {{0, 0, 3, 0, 6, 5}, {6, 5, 3, 10, 0, 10}};
static BezierSegment _lt_segs[] = {10, 0, 0, 5, 10, 10};
static BezierSegment _gt_segs[] = {0, 0, 10, 5, 0, 10};
static BezierSegment _slash_segs[] = {10, 0, 0, 10, 0, 10};

// -------------------------------
// Font Lookup Table
// -------------------------------
static Glyph_Bez bezier_font[] = {
    // Letters A-Z
    {'A', 3, 10, A_segs},
    {'B', 4, 10, B_segs},
    {'C', 4, 10, C_segs},
    {'D', 3, 10, D_segs},
    {'E', 4, 10, E_segs},
    {'F', 3, 10, F_segs},
    {'G', 5, 10, G_segs},
    {'H', 3, 10, H_segs},
    {'I', 3, 10, I_segs},
    {'J', 2, 10, J_segs},
    {'K', 3, 10, K_segs},
    {'L', 2, 10, L_segs},
    {'M', 2, 10, M_segs},
    {'N', 2, 10, N_segs},
    {'O', 4, 10, O_segs},
    {'P', 4, 10, P_segs},
    {'Q', 5, 10, Q_segs},
    {'R', 5, 10, R_segs},
    {'S', 5, 10, S_segs},
    {'T', 2, 10, T_segs},
    {'U', 3, 10, U_segs},
    {'V', 1, 10, V_segs},
    {'W', 2, 10, W_segs},
    {'X', 2, 10, X_segs},
    {'Y', 2, 10, Y_segs},
    {'Z', 3, 10, Z_segs},

    // Digits 0-9
    {'0', 4, 10, _0_segs},
    {'1', 3, 10, _1_segs},
    {'2', 4, 10, _2_segs},
    {'3', 6, 10, _3_segs},
    {'4', 3, 10, _4_segs},
    {'5', 5, 10, _5_segs},
    {'6', 5, 10, _6_segs},
    {'7', 2, 10, _7_segs},
    {'8', 7, 10, _8_segs},
    {'9', 4, 10, _9_segs},

    // Symbols
    {'!', 2, 10, _excl_segs},
    {'?', 3, 10, _quest_segs},
    {'.', 1, 10, _period_segs},
    {',', 1, 11, _comma_segs},
    {':', 2, 10, _colon_segs},
    {';', 2, 10, _semicolon_segs},
    {'+', 2, 10, _plus_segs},
    {'-', 1, 10, _minus_segs},
    {'=', 2, 10, _equal_segs},
    {'@', 5, 10, _at_segs},
    {'#', 4, 10, _hash_segs},
    {'$', 4, 10, _dollar_segs},
    {'%', 3, 10, _percent_segs},
    {'&', 3, 10, _ampersand_segs},
    {'*', 3, 10, _asterisk_segs},
    {'(', 1, 10, _lparen_segs},
    {')', 1, 10, _rparen_segs},
    {'[', 3, 10, _lbracket_segs},
    {']', 3, 10, _rbracket_segs},
    {'{', 2, 10, _lbrace_segs},
    {'}', 2, 10, _rbrace_segs},
    {'<', 1, 10, _lt_segs},
    {'>', 1, 10, _gt_segs},
    {'/', 1, 10, _slash_segs}};

// Get glyph_BezGlyph_Bez by ASCII code

Glyph_Bez *get_glyph_BezGlyph(char c) {
    for (uint8_t i = 0; i < sizeof(bezier_font) / sizeof(Glyph_Bez); i++) {
        if (bezier_font[i].c == c)
            return &bezier_font[i];
    }
    return NULL;
}

// Draw text string
void draw_text_bezier(char *str, int16_t x, int16_t y, uint8_t scale) {
    while (*str) {
        Glyph_Bez *g = get_glyph_BezGlyph(*str++);
        if (!g)
            return;

        Bezier line = {.step = 30};

        for (uint8_t i = 0; i < g->seg_count; i++) {

            line.x0 = (x + g->segs[i].x0 * scale);
            line.x1 = (x + g->segs[i].x1 * scale);
            line.x2 = (x + g->segs[i].x2 * scale);

            line.y0 = (y + g->segs[i].y0 * scale);
            line.y1 = (y + g->segs[i].y1 * scale);
            line.y2 = (y + g->segs[i].y2 * scale);

            bezier(&line);

            // bezier_quad_int((x + seg.x0 * scale), y + seg.y0 * scale, x + seg.x1 * scale,
            //                 y + seg.y1 * scale, x + seg.x2 * scale, y + seg.y2 * scale);
        }
        x += g->width * scale + 2; // Advance cursor
    }
}

// Example: Draw "HELLO 123!" at (10,20) with 2x scale
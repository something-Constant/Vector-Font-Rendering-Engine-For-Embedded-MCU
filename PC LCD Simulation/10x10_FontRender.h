#include <stdint.h>

#define space 4

typedef struct {
    const int8_t x1, y1, x2, y2;
} LineSegment;

typedef struct {
    uint8_t c;             // Character
    uint8_t width;         // Glyph width
    uint8_t height;        // Glyph height
    uint8_t segment_count; // Number of line segments
    LineSegment *segments;

} Glyph_Line;

// ======================
// LETTER (A-Z)
// ======================
static LineSegment A_seg[] = {
    {4, 0, 0, 9},
    {4, 0, 9, 9},
    {3, 4, 6, 4}
};
static LineSegment B_seg[] = {
    {0, 0, 0, 9},
    {0, 0, 6, 0},
    {0, 4, 6, 4},
    {0, 9, 6, 9},
    {6, 0, 9, 2},
    {9, 2, 9, 4},
    {9, 4, 6, 4},
    {6, 4, 9, 5},
    {9, 5, 9, 7},
    {9, 7, 6, 9}
};
static LineSegment C_seg[] = {
    {9, 2, 7, 0},
    {7, 0, 2, 0},
    {2, 0, 0, 2},
    {0, 2, 0, 7},
    {0, 7, 2, 9},
    {2, 9, 7, 9},
    {7, 9, 9, 7}
};
static LineSegment D_seg[] = {
    {0, 0, 0, 9},
    {0, 0, 5, 0},
    {5, 0, 9, 3},
    {9, 3, 9, 6},
    {9, 6, 5, 9},
    {5, 9, 0, 9}
};
static LineSegment E_seg[] = {
    {0, 0, 0, 9},
    {0, 0, 9, 0},
    {0, 4, 6, 4},
    {0, 9, 9, 9}
};
static LineSegment F_seg[] = {
    {0, 0, 0, 9},
    {0, 0, 9, 0},
    {0, 4, 6, 4}
};
static LineSegment G_seg[] = {
    {9, 2, 7, 0},
    {7, 0, 2, 0},
    {2, 0, 0, 2},
    {0, 2, 0, 7},
    {0, 7, 2, 9},
    {2, 9, 7, 9},
    {7, 9, 9, 7},
    {9, 7, 9, 4},
    {9, 4, 5, 4}
};
static LineSegment H_seg[] = {
    {0, 0, 0, 9},
    {9, 0, 9, 9},
    {0, 4, 9, 4}
};
static LineSegment I_seg[] = {
    {3, 0, 6, 0},
    {4, 0, 4, 9},
    {3, 9, 6, 9}
};
static LineSegment J_seg[] = {
    {6, 0, 6, 7},
    {6, 7, 4, 9},
    {4, 9, 2, 9},
    {2, 9, 0, 7}
};
static LineSegment K_seg[] = {
    {0, 0, 0, 9},
    {0, 4, 9, 0},
    {0, 4, 9, 9}
};
static LineSegment L_seg[] = {
    {0, 0, 0, 9},
    {0, 9, 9, 9}
};
static LineSegment M_seg[] = {
    {0, 9, 0, 0},
    {0, 0, 4, 4},
    {4, 4, 9, 0},
    {9, 0, 9, 9}
};
static LineSegment N_seg[] = {
    {0, 9, 0, 0},
    {0, 0, 9, 9},
    {9, 9, 9, 0}
};
static LineSegment O_seg[] = {
    {0, 2, 2, 0},
    {2, 0, 7, 0},
    {7, 0, 9, 2},
    {9, 2, 9, 7},
    {9, 7, 7, 9},
    {7, 9, 2, 9},
    {2, 9, 0, 7},
    {0, 7, 0, 2}
};

static LineSegment P_seg[] = {
    {0, 0, 0, 9},
    {0, 0, 6, 0},
    {6, 0, 9, 3},
    {9, 3, 6, 4},
    {6, 4, 0, 4}
};

static LineSegment Q_seg[] = {
    {0, 2, 2, 0},
    {2, 0, 7, 0},
    {7, 0, 9, 2},
    {9, 2, 9, 7},
    {9, 7, 7, 9},
    {7, 9, 2, 9},
    {2, 9, 0, 7},
    {0, 7, 0, 2},
    {5, 5, 9, 9}
};

static LineSegment R_seg[] = {
    {0, 0, 0, 9},
    {0, 0, 6, 0},
    {6, 0, 9, 3},
    {9, 3, 6, 4},
    {6, 4, 0, 4},
    {0, 4, 7, 9}
};
static LineSegment S_seg[] = {
    {9, 2, 7, 0},
    {7, 0, 2, 0},
    {2, 0, 0, 2},
    {0, 2, 0, 4},
    {0, 4, 2, 4},
    {2, 4, 7, 4},
    {7, 4, 9, 5},
    {9, 5, 9, 7},
    {9, 7, 7, 9},
    {7, 9, 2, 9},
    {2, 9, 0, 7}
};
static LineSegment T_seg[] = {
    {0, 0, 9, 0},
    {4, 0, 4, 9}
};

static LineSegment U_seg[] = {
    {0, 0, 0, 7},
    {0, 7, 2, 9},
    {2, 9, 7, 9},
    {7, 9, 9, 7},
    {9, 7, 9, 0}
};

static LineSegment V_seg[] = {
    {0, 0, 4, 9},
    {4, 9, 9, 0}
};
static LineSegment W_seg[] = {
    {0, 0, 2, 9},
    {2, 9, 4, 4},
    {4, 4, 7, 9},
    {7, 9, 9, 0}
};
static LineSegment X_seg[] = {
    {0, 0, 9, 9},
    {0, 9, 9, 0}
};
static LineSegment Y_seg[] = {
    {0, 0, 4, 4},
    {9, 0, 4, 4},
    {4, 4, 4, 9}
};
static LineSegment Z_seg[] = {
    {0, 0, 9, 0},
    {9, 0, 0, 9},
    {0, 9, 9, 9}
};

// ======================
// DIGITS (0-9)
// ======================
static LineSegment _0_seg[] = {
    {1, 2, 3, 0},
    {3, 0, 6, 0},
    {6, 0, 8, 2},
    {8, 2, 8, 7},
    {8, 7, 6, 9},
    {6, 9, 3, 9},
    {3, 9, 1, 7},
    {1, 7, 1, 2}
};

static LineSegment _1_seg[] = {
    {5, 0, 5, 9},
    {3, 3, 5, 0},
    {2, 9, 9, 9}
};

static LineSegment _2_seg[] = {
    {0, 2, 2, 0},
    {2, 0, 7, 0},
    {7, 0, 9, 2},
    {9, 2, 9, 4},
    {9, 4, 0, 9},
    {0, 9, 9, 9}
};

static LineSegment _3_seg[] = {
    {0, 2, 2, 0},
    {2, 0, 7, 0},
    {7, 0, 9, 2},
    {9, 2, 9, 4},
    {9, 4, 7, 4},
    {7, 4, 9, 5},
    {9, 5, 9, 7},
    {9, 7, 7, 9},
    {7, 9, 2, 9},
    {2, 9, 0, 7}
};

static LineSegment _4_seg[] = {
    {7, 0, 0, 5},
    {0, 5, 9, 5},
    {7, 0, 7, 9}
};

static LineSegment _5_seg[] = {
    {9, 0, 0, 0},
    {0, 0, 0, 4},
    {0, 4, 7, 4},
    {7, 4, 9, 5},
    {9, 5, 9, 7},
    {9, 7, 7, 9},
    {7, 9, 2, 9},
    {2, 9, 0, 7}
};
static LineSegment _6_seg[] = {
    {9, 2, 7, 0},
    {7, 0, 2, 0},
    {2, 0, 0, 2},
    {0, 2, 0, 7},
    {0, 7, 2, 9},
    {2, 9, 7, 9},
    {7, 9, 9, 7},
    {9, 7, 9, 5},
    {9, 5, 7, 4},
    {7, 4, 2, 4}
};
static LineSegment _7_seg[] = {
    {0, 0, 9, 0},
    {9, 0, 2, 9}
};

static LineSegment _8_seg[] = {
    {0, 2, 2, 0},
    {2, 0, 7, 0},
    {7, 0, 9, 2},
    {9, 2, 9, 4},
    {9, 4, 7, 4},
    {7, 4, 2, 4},
    {1, 4, 0, 4},
    {0, 4, 0, 2},
    {0, 7, 2, 9},
    {2, 9, 7, 9},
    {7, 9, 9, 7},
    {9, 7, 9, 5},
    {9, 5, 7, 4},
    {7, 4, 2, 4},
    {1, 4, 0, 5},
    {0, 5, 0, 7}
};

static LineSegment _9_seg[] = {

    {2, 0, 7, 0},
    {7, 0, 9, 2},
    {2, 9, 7, 9},
    {9, 7, 7, 9},
    {9, 3, 9, 6},
    {2, 9, 0, 7},
    {2, 4, 7, 4},
    {0, 3, 0, 4},
    {0, 2, 2, 0}
};

// ======================
// SYMBOLS (! ? . , : ;)
// ======================

static LineSegment _excl[] = {
    {4, 8, 5, 8},
    {4, 7, 5, 7},
    {4, 5, 4, 0},
    {4, 0, 4, 3},
    {5, 0, 5, 3}
};

static LineSegment _quest[] = {
    {0, 2, 2, 0},
    {2, 0, 7, 0},
    {7, 0, 9, 2},
    {8, 3, 6, 4},
    {6, 4, 6, 6},
    {5, 9, 7, 9},
    {5, 8, 7, 8}
};

static LineSegment _period[] = {
    {3, 6, 6, 6},
    {3, 7, 6, 7}
};
static LineSegment _comma[] = {
    {4, 7, 4, 8},
    {4, 8, 3, 9}
};
static LineSegment _colon[] = {
    {4, 2, 4, 3},
    {4, 6, 4, 7}
};
static LineSegment _semicolon[] = {
    {4, 2, 4, 3},
    {4, 6, 4, 8},
    {4, 8, 4, 9}
};

static LineSegment _percent[] = {
    {0, 9, 2, 9},
    {0, 7, 2, 7},
    {7, 2, 9, 2},
    {7, 0, 9, 0},
    {0, 0, 9, 9}
};

static LineSegment _minus[] = {
    {0, 5, 9, 5}
};

static LineSegment _equal[] = {
    {0, 3, 9, 3},
    {0, 6, 9, 6}
};

static LineSegment _slash[] = {
    {0, 0, 9, 9}
};

static LineSegment _underscore[] = {
    {0, 9, 9, 9}
};

static LineSegment _lparen[] = {
    {6, 0, 4, 2},
    {4, 2, 4, 7},
    {4, 7, 6, 9}
};

static LineSegment _rparen[] = {
    {3, 0, 5, 2},
    {5, 2, 5, 7},
    {5, 7, 3, 9}
};

static LineSegment _asterisk[] = {
    {0, 5, 9, 5},
    {4, 0, 4, 9},
    {0, 0, 9, 9},
    {0, 9, 9, 0}
};

static LineSegment _plus[] = {
    {5, 0, 5, 9},
    {0, 5, 9, 5}
};

// ======================
// FONT LOOKUP TABLE
// ======================

static Glyph_Line font_table[] = {
    // Letters A-Z
    {'A', 10, 10, 3,  A_seg      },
    {'B', 10, 10, 10, B_seg      },
    {'C', 10, 10, 7,  C_seg      },
    {'D', 10, 10, 6,  D_seg      },
    {'E', 10, 10, 4,  E_seg      },
    {'F', 10, 10, 3,  F_seg      },
    {'G', 10, 10, 9,  G_seg      },
    {'H', 10, 10, 3,  H_seg      },
    {'I', 10, 10, 3,  I_seg      },
    {'J', 10, 10, 4,  J_seg      },
    {'K', 10, 10, 3,  K_seg      },
    {'L', 10, 10, 2,  L_seg      },
    {'M', 10, 10, 4,  M_seg      },
    {'N', 10, 10, 3,  N_seg      },
    {'O', 10, 10, 8,  O_seg      },
    {'P', 10, 10, 5,  P_seg      },
    {'Q', 10, 10, 9,  Q_seg      },
    {'R', 10, 10, 6,  R_seg      },
    {'S', 10, 10, 11, S_seg      },
    {'T', 10, 10, 2,  T_seg      },
    {'U', 10, 10, 5,  U_seg      },
    {'V', 10, 10, 2,  V_seg      },
    {'W', 10, 10, 4,  W_seg      },
    {'X', 10, 10, 2,  X_seg      },
    {'Y', 10, 10, 3,  Y_seg      },
    {'Z', 10, 10, 3,  Z_seg      },

    // Digits 0-9
    {'0', 10, 10, 8,  _0_seg     },
    {'1', 10, 10, 3,  _1_seg     },
    {'2', 10, 10, 6,  _2_seg     },
    {'3', 10, 10, 10, _3_seg     },
    {'4', 10, 10, 3,  _4_seg     },
    {'5', 10, 10, 8,  _5_seg     },
    {'6', 10, 10, 10, _6_seg     },
    {'7', 10, 10, 2,  _7_seg     },
    {'8', 10, 10, 16, _8_seg     },
    {'9', 10, 10, 9,  _9_seg     },

    // Symbols
    {'!', 10, 10, 5,  _excl      },
    {'?', 10, 10, 7,  _quest     },
    {'.', 10, 10, 2,  _period    },
    {',', 10, 10, 2,  _comma     },
    {':', 10, 10, 2,  _colon     },
    {';', 10, 10, 3,  _semicolon },
    {'%', 10, 10, 5,  _percent   },
    {'-', 10, 10, 1,  _minus     },
    {'=', 10, 10, 2,  _equal     },
    {'/', 10, 10, 1,  _slash     },
    {'_', 10, 10, 1,  _underscore},
    {'(', 10, 10, 3,  _lparen    },
    {')', 10, 10, 3,  _rparen    },
    {'*', 10, 10, 4,  _asterisk  },
    {'+', 10, 10, 2,  _plus      }
};

Glyph_Line *get_glyph_Line(uint8_t c) {
    if (c == '_')
        return &font_table[46];

    for (uint8_t i = 0; i < sizeof(font_table) / sizeof(Glyph_Line); i++)
        if (font_table[i].c == c || font_table[i].c == (c - 32))
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
                DrawLine((x + j + (g->segments[i].x1 * scale)), (y + (g->segments[i].y1 * scale)),
                         (x + j + (g->segments[i].x2 * scale)), (y + (g->segments[i].y2 * scale)));
            }
        }
        x += g->width * scale + space; // Advance cursor
    }
}

void GLCD_DrawChar(char c, uint8_t x, uint8_t y, uint8_t scale, uint8_t deph) {
    Glyph_Line *g = get_glyph_Line(c);
    if (! g)
        return;
    for (uint8_t j = 0; j < deph; j++) {
        for (uint8_t i = 0; i < g->segment_count; i++) {
            DrawLine((x + j + (g->segments[i].x1 * scale)), (y + (g->segments[i].y1 * scale)),
                     (x + j + (g->segments[i].x2 * scale)), (y + (g->segments[i].y2 * scale)));
        }
    }
}

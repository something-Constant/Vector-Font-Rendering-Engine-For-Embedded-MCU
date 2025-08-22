#include <stdint.h>

#define space 4
#define Font_Width 5
#define Font_Height 7

// Add LCD buffer here
extern char Buffer[];
// Add LCD setpixel Function here
#define setpixel(x, y, buffer) BufferSetPixel(x, y, 1, buffer)

typedef struct {
    const int8_t x1, y1, x2, y2;
} LineSegment;

typedef struct {
    uint8_t c;             // Character
    uint8_t segment_count; // Number of line segments
    LineSegment *segments;

} Glyph_Line;

// ======================
// LETTER (A-Z)
// ======================
LineSegment A_seg[] = {
    {0, 6, 0, 2},
    {4, 2, 4, 6},
    {4, 2, 2, 0},
    {0, 2, 2, 0},
    {4, 3, 0, 3}
};
LineSegment B_seg[] = {
    {0, 0, 0, 6},
    {0, 0, 3, 0},
    {0, 3, 3, 3},
    {0, 6, 3, 6},
    {3, 0, 4, 1},
    {4, 1, 4, 2},
    {4, 2, 3, 3},
    {3, 3, 4, 4},
    {4, 4, 4, 5},
    {4, 5, 3, 6}
};
LineSegment C_seg[] = {
    {1, 0, 3, 0},
    {0, 1, 0, 5},
    {1, 6, 3, 6},
    {3, 6, 4, 5},
    {3, 0, 4, 1},
    {1, 0, 0, 1},
    {0, 5, 1, 6}
};
LineSegment D_seg[] = {
    {0, 0, 0, 6},
    {0, 0, 3, 0},
    {0, 6, 3, 6},
    {4, 1, 4, 5},
    {4, 5, 3, 6},
    {3, 0, 4, 1}
};
LineSegment E_seg[] = {
    {0, 0, 0, 9},
    {0, 0, 9, 0},
    {0, 4, 6, 4},
    {0, 9, 9, 9}
};
LineSegment F_seg[] = {
    {0, 0, 0, 9},
    {0, 0, 9, 0},
    {0, 4, 6, 4}
};
LineSegment G_seg[] = {
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
LineSegment H_seg[] = {
    {0, 0, 0, 9},
    {9, 0, 9, 9},
    {0, 4, 9, 4}
};
LineSegment I_seg[] = {
    {3, 0, 6, 0},
    {4, 0, 4, 9},
    {3, 9, 6, 9}
};
LineSegment J_seg[] = {
    {6, 0, 6, 7},
    {6, 7, 4, 9},
    {4, 9, 2, 9},
    {2, 9, 0, 7}
};
LineSegment K_seg[] = {
    {0, 0, 0, 9},
    {0, 4, 9, 0},
    {0, 4, 9, 9}
};
LineSegment L_seg[] = {
    {0, 0, 0, 9},
    {0, 9, 9, 9}
};
LineSegment M_seg[] = {
    {0, 9, 0, 0},
    {0, 0, 4, 4},
    {4, 4, 9, 0},
    {9, 0, 9, 9}
};
LineSegment N_seg[] = {
    {0, 9, 0, 0},
    {0, 0, 9, 9},
    {9, 9, 9, 0}
};
LineSegment O_seg[] = {
    {0, 2, 2, 0},
    {2, 0, 7, 0},
    {7, 0, 9, 2},
    {9, 2, 9, 7},
    {9, 7, 7, 9},
    {7, 9, 2, 9},
    {2, 9, 0, 7},
    {0, 7, 0, 2}
};

LineSegment P_seg[] = {
    {0, 0, 0, 9},
    {0, 0, 6, 0},
    {6, 0, 9, 3},
    {9, 3, 6, 4},
    {6, 4, 0, 4}
};

LineSegment Q_seg[] = {
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

LineSegment R_seg[] = {
    {0, 0, 0, 9},
    {0, 0, 6, 0},
    {6, 0, 9, 3},
    {9, 3, 6, 4},
    {6, 4, 0, 4},
    {0, 4, 7, 9}
};
LineSegment S_seg[] = {
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
LineSegment T_seg[] = {
    {0, 0, 9, 0},
    {4, 0, 4, 9}
};

LineSegment U_seg[] = {
    {0, 0, 0, 7},
    {0, 7, 2, 9},
    {2, 9, 7, 9},
    {7, 9, 9, 7},
    {9, 7, 9, 0}
};

LineSegment V_seg[] = {
    {0, 0, 4, 9},
    {4, 9, 9, 0}
};
LineSegment W_seg[] = {
    {0, 0, 2, 9},
    {2, 9, 4, 4},
    {4, 4, 7, 9},
    {7, 9, 9, 0}
};
LineSegment X_seg[] = {
    {0, 0, 9, 9},
    {0, 9, 9, 0}
};
LineSegment Y_seg[] = {
    {0, 0, 4, 4},
    {9, 0, 4, 4},
    {4, 4, 4, 9}
};
LineSegment Z_seg[] = {
    {0, 0, 9, 0},
    {9, 0, 0, 9},
    {0, 9, 9, 9}
};

// ======================
// DIGITS (0-9)
// ======================
LineSegment _0_seg[] = {
    {1, 2, 3, 0},
    {3, 0, 6, 0},
    {6, 0, 8, 2},
    {8, 2, 8, 7},
    {8, 7, 6, 9},
    {6, 9, 3, 9},
    {3, 9, 1, 7},
    {1, 7, 1, 2}
};

LineSegment _1_seg[] = {
    {5, 0, 5, 9},
    {3, 3, 5, 0},
    {2, 9, 9, 9}
};

LineSegment _2_seg[] = {
    {0, 2, 2, 0},
    {2, 0, 7, 0},
    {7, 0, 9, 2},
    {9, 2, 9, 4},
    {9, 4, 0, 9},
    {0, 9, 9, 9}
};

LineSegment _3_seg[] = {
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

LineSegment _4_seg[] = {
    {7, 0, 0, 5},
    {0, 5, 9, 5},
    {7, 0, 7, 9}
};

LineSegment _5_seg[] = {
    {9, 0, 0, 0},
    {0, 0, 0, 4},
    {0, 4, 7, 4},
    {7, 4, 9, 5},
    {9, 5, 9, 7},
    {9, 7, 7, 9},
    {7, 9, 2, 9},
    {2, 9, 0, 7}
};
LineSegment _6_seg[] = {
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
LineSegment _7_seg[] = {
    {0, 0, 9, 0},
    {9, 0, 2, 9}
};

LineSegment _8_seg[] = {
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

LineSegment _9_seg[] = {

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

LineSegment _excl[] = {
    {4, 8, 5, 8},
    {4, 7, 5, 7},
    {4, 5, 4, 0},
    {4, 0, 4, 3},
    {5, 0, 5, 3}
};

LineSegment _quest[] = {
    {0, 2, 2, 0},
    {2, 0, 7, 0},
    {7, 0, 9, 2},
    {8, 3, 6, 4},
    {6, 4, 6, 6},
    {5, 9, 7, 9},
    {5, 8, 7, 8}
};

LineSegment _period[] = {
    {3, 6, 6, 6},
    {3, 7, 6, 7}
};
LineSegment _comma[] = {
    {4, 7, 4, 8},
    {4, 8, 3, 9}
};
LineSegment _colon[] = {
    {4, 2, 4, 3},
    {4, 6, 4, 7}
};
LineSegment _semicolon[] = {
    {4, 2, 4, 3},
    {4, 6, 4, 8},
    {4, 8, 4, 9}
};

LineSegment _percent[] = {
    {0, 9, 2, 9},
    {0, 7, 2, 7},
    {7, 2, 9, 2},
    {7, 0, 9, 0},
    {0, 0, 9, 9}
};

LineSegment _minus[] = {
    {0, 5, 9, 5}
};

LineSegment _equal[] = {
    {0, 3, 9, 3},
    {0, 6, 9, 6}
};

LineSegment _slash[] = {
    {0, 0, 9, 9}
};

LineSegment _underscore[] = {
    {0, 9, 9, 9}
};

LineSegment _lparen[] = {
    {6, 0, 4, 2},
    {4, 2, 4, 7},
    {4, 7, 6, 9}
};

LineSegment _rparen[] = {
    {3, 0, 5, 2},
    {5, 2, 5, 7},
    {5, 7, 3, 9}
};

LineSegment _asterisk[] = {
    {0, 5, 9, 5},
    {4, 0, 4, 9},
    {0, 0, 9, 9},
    {0, 9, 9, 0}
};

LineSegment _plus[] = {
    {5, 0, 5, 9},
    {0, 5, 9, 5}
};

// ======================
// FONT LOOKUP TABLE
// ======================
Glyph_Line font_table[] = {
    // Letters A-Z
    {'A', sizeof(A_seg),       A_seg      },
    {'B', sizeof(B_seg),       B_seg      },
    {'C', sizeof(C_seg),       C_seg      },
    {'D', sizeof(D_seg),       D_seg      },
    {'E', sizeof(E_seg),       E_seg      },
    {'F', sizeof(F_seg),       F_seg      },
    {'G', sizeof(G_seg),       G_seg      },
    {'H', sizeof(H_seg),       H_seg      },
    {'I', sizeof(I_seg),       I_seg      },
    {'J', sizeof(J_seg),       J_seg      },
    {'K', sizeof(K_seg),       K_seg      },
    {'L', sizeof(L_seg),       L_seg      },
    {'M', sizeof(M_seg),       M_seg      },
    {'N', sizeof(N_seg),       N_seg      },
    {'O', sizeof(O_seg),       O_seg      },
    {'P', sizeof(P_seg),       P_seg      },
    {'Q', sizeof(Q_seg),       Q_seg      },
    {'R', sizeof(R_seg),       R_seg      },
    {'S', sizeof(S_seg),       S_seg      },
    {'T', sizeof(T_seg),       T_seg      },
    {'U', sizeof(U_seg),       U_seg      },
    {'V', sizeof(V_seg),       V_seg      },
    {'W', sizeof(W_seg),       W_seg      },
    {'X', sizeof(X_seg),       X_seg      },
    {'Y', sizeof(Y_seg),       Y_seg      },
    {'Z', sizeof(Z_seg),       Z_seg      },

    // Digits 0-9
    {'0', sizeof(_0_seg),      _0_seg     },
    {'1', sizeof(_1_seg),      _1_seg     },
    {'2', sizeof(_2_seg),      _2_seg     },
    {'3', sizeof(_3_seg),      _3_seg     },
    {'4', sizeof(_4_seg),      _4_seg     },
    {'5', sizeof(_5_seg),      _5_seg     },
    {'6', sizeof(_6_seg),      _6_seg     },
    {'7', sizeof(_7_seg),      _7_seg     },
    {'8', sizeof(_8_seg),      _8_seg     },
    {'9', sizeof(_9_seg),      _9_seg     },

    // Symbols
    {'!', sizeof(_excl),       _excl      },
    {'?', sizeof(_quest),      _quest     },
    {'.', sizeof(_period),     _period    },
    {',', sizeof(_comma),      _comma     },
    {':', sizeof(_colon),      _colon     },
    {';', sizeof(_semicolon),  _semicolon },
    {'%', sizeof(_percent),    _percent   },
    {'-', sizeof(_minus),      _minus     },
    {'=', sizeof(_equal),      _equal     },
    {'/', sizeof(_slash),      _slash     },
    {'_', sizeof(_underscore), _underscore},
    {'(', sizeof(_lparen),     _lparen    },
    {')', sizeof(_rparen),     _rparen    },
    {'*', sizeof(_asterisk),   _asterisk  },
    {'+', sizeof(_plus),       _plus      }
};

// void drawline(uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1, uint8_t *buffer);
// Glyph_Line *get_glyph_Line(uint8_t c);
// void draw_text(char *str, int16_t x, int16_t y, uint8_t scale, uint8_t deph);
// void GLCD_DrawChar(char c, uint8_t x, uint8_t y, uint8_t scale, uint8_t deph);

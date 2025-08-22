#include <stdint.h>

#define space 2
#define Font_Width 5
#define Font_Height 7
#define linepoint 4

// Add LCD buffer here
extern char Buffer[];
// Add LCD setpixel Function here
#define setpixel(x, y, buffer) SetPixel(x, y, 1, buffer)

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
LineSegment A_upper[] = {
    {0, 6, 0, 2},
    {4, 2, 4, 6},
    {4, 2, 2, 0},
    {0, 2, 2, 0},
    {4, 3, 0, 3}
};
LineSegment B_upper[] = {
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
LineSegment C_upper[] = {
    {1, 0, 3, 0},
    {0, 1, 0, 5},
    {1, 6, 3, 6},
    {3, 6, 4, 5},
    {3, 0, 4, 1},
    {1, 0, 0, 1},
    {0, 5, 1, 6}
};
LineSegment D_upper[] = {
    {0, 0, 0, 6},
    {0, 0, 3, 0},
    {3, 0, 4, 1},
    {4, 1, 4, 5},
    {4, 5, 3, 6},
    {3, 6, 0, 6}
};
LineSegment E_upper[] = {
    {4, 0, 0, 0},
    {0, 0, 0, 6},
    {0, 6, 4, 6},
    {0, 3, 3, 3}
};
LineSegment F_upper[] = {
    {4, 0, 0, 0},
    {0, 0, 0, 6},
    {0, 3, 3, 3}
};
LineSegment G_upper[] = {
    {0, 1, 0, 5},
    {0, 5, 1, 6},
    {1, 6, 4, 6},
    {4, 6, 4, 4},
    {4, 4, 2, 4},
    {0, 1, 1, 0},
    {3, 0, 1, 0},
    {3, 0, 4, 1}
};
LineSegment H_upper[] = {
    {0, 0, 0, 6},
    {4, 0, 4, 6},
    {0, 3, 4, 3}
};
LineSegment I_upper[] = {
    {3, 0, 1, 0},
    {2, 0, 2, 6},
    {3, 6, 1, 6}
};
LineSegment J_upper[] = {
    {4, 0, 2, 0},
    {3, 0, 3, 5},
    {3, 5, 2, 6},
    {2, 6, 1, 6},
    {1, 6, 0, 5}
};
LineSegment K_upper[] = {
    {0, 0, 0, 6},
    {0, 3, 1, 3},
    {1, 3, 4, 0},
    {1, 3, 4, 6}
};
LineSegment L_upper[] = {
    {0, 0, 0, 6},
    {0, 6, 4, 6}
};
LineSegment M_upper[] = {
    {0, 0, 2, 2},
    {2, 2, 4, 0},
    {0, 0, 0, 6},
    {4, 0, 4, 6},
    {2, 2, 2, 3}
};
LineSegment N_upper[] = {
    {0, 0, 0, 6},
    {4, 0, 4, 6},
    {4, 5, 0, 1}
};
LineSegment O_upper[] = {
    {1, 0, 3, 0},
    {3, 0, 4, 1},
    {4, 1, 4, 5},
    {1, 0, 0, 1},
    {0, 1, 0, 5},
    {0, 5, 1, 6},
    {1, 6, 3, 6},
    {3, 6, 4, 5}
};

LineSegment P_upper[] = {
    {0, 0, 0, 6},
    {0, 0, 3, 0},
    {3, 0, 4, 1},
    {4, 1, 4, 2},
    {4, 2, 3, 3},
    {3, 3, 0, 3}
};

LineSegment Q_upper[] = {
    {0, 1, 0, 5},
    {0, 1, 1, 0},
    {1, 0, 3, 0},
    {3, 0, 4, 1},
    {4, 1, 4, 4},
    {4, 4, 3, 5},
    {3, 5, 2, 6},
    {2, 6, 1, 6},
    {1, 6, 0, 5},
    {2, 4, 4, 6}
};

LineSegment R_upper[] = {
    {0, 0, 0, 6},
    {0, 0, 3, 0},
    {3, 0, 4, 1},
    {4, 1, 4, 2},
    {4, 2, 3, 3},
    {3, 3, 0, 3},
    {1, 3, 4, 6}
};

LineSegment S_upper[] = {
    {4, 1, 3, 0},
    {3, 0, 1, 0},
    {1, 0, 0, 1},
    {0, 1, 0, 2},
    {0, 2, 1, 3},
    {1, 3, 3, 3},
    {3, 3, 4, 4},
    {4, 4, 4, 5},
    {4, 5, 3, 6},
    {3, 6, 1, 6},
    {1, 6, 0, 5}
};
LineSegment T_upper[] = {
    {0, 0, 4, 0},
    {2, 0, 2, 6},
    {0, 0, 0, 1},
    {4, 0, 4, 1}
};

LineSegment U_upper[] = {
    {0, 0, 0, 5},
    {0, 5, 1, 6},
    {1, 6, 3, 6},
    {3, 6, 4, 5},
    {0, 0, 0, 5},
    {4, 0, 4, 5},
    {4, 5, 3, 6},
    {0, 5, 1, 6},
    {1, 6, 3, 6}
};

LineSegment V_upper[] = {
    {0, 0, 0, 4},
    {0, 4, 2, 6},
    {2, 6, 4, 4},
    {4, 4, 4, 0}
};
LineSegment W_upper[] = {
    {0, 0, 0, 5},
    {4, 0, 4, 5},
    {0, 5, 1, 6},
    {4, 5, 3, 6},
    {3, 6, 2, 4},
    {1, 6, 2, 4}
};
LineSegment X_upper[] = {
    {0, 0, 0, 1},
    {4, 0, 4, 1},
    {0, 1, 4, 5},
    {4, 5, 4, 6},
    {4, 1, 0, 5},
    {0, 5, 0, 6}
};
LineSegment Y_upper[] = {
    {0, 0, 0, 1},
    {4, 0, 4, 1},
    {0, 1, 2, 3},
    {4, 1, 2, 3},
    {2, 3, 2, 6}
};
LineSegment Z_upper[] = {
    {0, 0, 4, 0},
    {4, 0, 4, 1},
    {4, 1, 0, 5},
    {0, 5, 0, 6},
    {0, 6, 4, 6}
};
// ======================
// LETTER (a-z)
// ======================

LineSegment a_lower[] = {
    {1, 6, 4, 6},
    {1, 6, 0, 5},
    {0, 5, 1, 4},
    {1, 4, 3, 4},
    {3, 6, 3, 3},
    {3, 3, 2, 2},
    {2, 2, 1, 2}
};
LineSegment b_lower[] = {
    {0, 0, 0, 6},
    {0, 5, 1, 5},
    {1, 5, 2, 6},
    {2, 6, 3, 6},
    {3, 6, 4, 5},
    {4, 5, 4, 3},
    {4, 3, 3, 2},
    {3, 2, 2, 2},
    {2, 2, 1, 3},
    {1, 3, 0, 3}
};
LineSegment c_lower[] = {
    {3, 6, 1, 6},
    {1, 6, 0, 5},
    {0, 5, 0, 3},
    {0, 3, 1, 2},
    {1, 2, 3, 2},
    {3, 2, 4, 3},
    {3, 6, 4, 5}
};
LineSegment d_lower[] = {
    {4, 0, 4, 6},
    {4, 5, 3, 5},
    {3, 5, 2, 6},
    {2, 6, 1, 6},
    {1, 6, 0, 5},
    {0, 5, 0, 3},
    {0, 3, 1, 2},
    {1, 2, 2, 2},
    {2, 2, 3, 3},
    {3, 3, 4, 3}
};

LineSegment e_lower[] = {
    {3, 6, 1, 6},
    {1, 6, 0, 5},
    {0, 5, 0, 3},
    {0, 3, 1, 2},
    {1, 2, 3, 2},
    {3, 2, 4, 3},
    {4, 3, 4, 4},
    {4, 4, 0, 4}
};
LineSegment f_lower[] = {
    {2, 1, 2, 6},
    {3, 3, 1, 3},
    {2, 1, 3, 0},
    {3, 0, 4, 1}
};
LineSegment g_lower[] = {
    {4, 2, 4, 5},
    {4, 5, 3, 6},
    {3, 6, 1, 6},
    {3, 1, 4, 2},
    {3, 1, 1, 1},
    {1, 1, 0, 2},
    {0, 2, 0, 3},
    {0, 3, 1, 4},
    {1, 4, 4, 4}
};
LineSegment h_lower[] = {
    {0, 0, 0, 6},
    {4, 3, 4, 6},
    {4, 3, 3, 2},
    {0, 4, 2, 2}
};
LineSegment i_lower[] = {
    {1, 6, 3, 6},
    {2, 6, 2, 2},
    {2, 2, 1, 2},
    {2, 0, 2, 0}
};
LineSegment j_lower[] = {
    {4, 2, 4, 5},
    {4, 5, 3, 6},
    {3, 6, 2, 6},
    {2, 6, 1, 5},
    {4, 0, 4, 0}
};
LineSegment k_lower[] = {
    {0, 0, 0, 6},
    {3, 6, 1, 4},
    {1, 4, 4, 1},
    {0, 4, 1, 4}
};
LineSegment l_lower[] = {
    {3, 6, 1, 6},
    {2, 6, 2, 1},
    {2, 1, 1, 1}
};
LineSegment m_lower[] = {
    {0, 2, 0, 6},
    {0, 2, 1, 2},
    {1, 2, 2, 3},
    {2, 3, 2, 6},
    {2, 3, 3, 2},
    {3, 2, 4, 3},
    {4, 3, 4, 6}
};
LineSegment n_lower[] = {
    {0, 2, 0, 6},
    {0, 3, 1, 3},
    {1, 3, 2, 2},
    {2, 2, 3, 2},
    {3, 2, 4, 3},
    {4, 3, 4, 6}
};
LineSegment o_lower[] = {
    {3, 6, 1, 6},
    {1, 6, 0, 5},
    {0, 5, 0, 3},
    {0, 3, 1, 2},
    {1, 2, 3, 2},
    {3, 2, 4, 3},
    {4, 3, 4, 5},
    {4, 5, 3, 6}
};

LineSegment p_lower[] = {
    {0, 0, 0, 6},
    {0, 0, 1, 1},
    {0, 3, 1, 2},
    {1, 1, 2, 0},
    {2, 0, 3, 0},
    {3, 0, 4, 1},
    {4, 1, 4, 2},
    {4, 2, 3, 3},
    {3, 3, 2, 3},
    {2, 3, 1, 2}
};

LineSegment q_lower[] = {
    {4, 0, 4, 6},
    {2, 0, 1, 0},
    {1, 0, 0, 1},
    {0, 1, 0, 2},
    {0, 2, 1, 3},
    {1, 3, 2, 3},
    {2, 3, 3, 2},
    {3, 2, 4, 1},
    {2, 0, 3, 1},
    {3, 1, 4, 2}
};

LineSegment r_lower[] = {
    {0, 0, 0, 5},
    {0, 1, 1, 1},
    {1, 1, 2, 0},
    {2, 0, 3, 0},
    {3, 0, 4, 1}
};

LineSegment s_lower[] = {
    {4, 0, 1, 0},
    {1, 0, 0, 1},
    {0, 1, 1, 2},
    {1, 2, 3, 2},
    {3, 2, 4, 3},
    {4, 3, 3, 4},
    {3, 4, 0, 4}
};
LineSegment t_lower[] = {
    {4, 2, 0, 2},
    {2, 0, 2, 5},
    {2, 5, 3, 6},
    {3, 6, 4, 5}
};

LineSegment u_lower[] = {
    {4, 2, 4, 6},
    {4, 5, 3, 5},
    {3, 5, 2, 6},
    {2, 6, 1, 6},
    {1, 6, 0, 5},
    {0, 5, 0, 2}
};

LineSegment v_lower[] = {
    {0, 2, 0, 4},
    {0, 4, 2, 6},
    {2, 6, 4, 4},
    {4, 4, 4, 2}
};
LineSegment w_lower[] = {
    {0, 2, 0, 5},
    {0, 5, 1, 6},
    {1, 6, 2, 5},
    {2, 5, 3, 6},
    {3, 6, 4, 5},
    {4, 5, 4, 2}
};
LineSegment x_lower[] = {
    {0, 2, 4, 6},
    {4, 2, 0, 6}
};
LineSegment y_lower[] = {
    {4, 1, 4, 5},
    {4, 5, 3, 6},
    {3, 6, 1, 6},
    {1, 6, 0, 5},
    {4, 3, 1, 3},
    {1, 3, 0, 2},
    {0, 2, 0, 1}
};
LineSegment z_lower[] = {
    {4, 6, 0, 6},
    {0, 6, 3, 3},
    {4, 2, 0, 2}
};

// ======================
// DIGITS (0-9)
// ======================
LineSegment _0_upper[] = {
    {1, 0, 3, 0},
    {3, 0, 4, 1},
    {4, 1, 4, 5},
    {4, 5, 3, 6},
    {3, 6, 1, 6},
    {1, 6, 0, 5},
    {0, 5, 0, 1},
    {0, 1, 1, 0},
    {4, 1, 0, 5}
};

LineSegment _1_upper[] = {
    {3, 6, 1, 6},
    {2, 6, 2, 0},
    {2, 0, 1, 1}
};

LineSegment _2_upper[] = {

    {0, 1, 1, 0},
    {1, 0, 3, 0},
    {3, 0, 4, 1},
    {4, 1, 4, 2},
    {4, 2, 0, 6},
    {0, 6, 4, 6}
};

LineSegment _3_upper[] = {
    {0, 0, 4, 0},
    {4, 0, 4, 1},
    {4, 1, 2, 3},
    {2, 3, 4, 4},
    {4, 4, 4, 5},
    {4, 5, 3, 6},
    {3, 6, 1, 6},
    {1, 6, 0, 5}
};

LineSegment _4_upper[] = {
    {3, 0, 3, 6},
    {0, 4, 4, 4},
    {3, 0, 0, 3},
    {0, 3, 0, 4}
};

LineSegment _5_upper[] = {
    {0, 0, 4, 0},
    {0, 0, 0, 2},
    {0, 2, 3, 2},
    {3, 2, 4, 3},
    {4, 3, 4, 5},
    {4, 5, 3, 6},
    {3, 6, 1, 6},
    {1, 6, 0, 5}
};
LineSegment _6_upper[] = {
    {0, 2, 0, 5},
    {0, 5, 1, 6},
    {1, 6, 3, 6},
    {3, 6, 4, 5},
    {4, 5, 4, 4},
    {4, 4, 3, 3},
    {3, 3, 0, 3},
    {0, 2, 2, 0},
    {2, 0, 4, 0}
};
LineSegment _7_upper[] = {
    {0, 0, 4, 0},
    {4, 0, 4, 2},
    {4, 2, 0, 6}
};

LineSegment _8_upper[] = {
    {1, 0, 3, 0},
    {3, 0, 4, 1},
    {4, 1, 4, 2},
    {4, 2, 3, 3},
    {3, 3, 1, 3},
    {1, 3, 0, 2},
    {0, 2, 0, 1},
    {0, 1, 1, 0},
    {1, 3, 0, 4},
    {0, 4, 0, 5},
    {0, 5, 1, 6},
    {1, 6, 3, 6},
    {3, 6, 4, 5},
    {4, 5, 4, 4},
    {4, 4, 3, 3}
};

LineSegment _9_upper[] = {
    {1, 0, 3, 0},
    {1, 0, 0, 1},
    {0, 1, 0, 2},
    {0, 2, 1, 3},
    {3, 0, 4, 1},
    {4, 1, 4, 4},
    {1, 3, 4, 3},
    {4, 4, 2, 6},
    {2, 6, 0, 6}
};

// ======================
// SYMBOLS (! ? . , : ;)
// ======================
LineSegment _excl[] = {
    {2, 0, 2, 4},
    {2, 6, 2, 6}
};
LineSegment _slash[] = {
    {4, 0, 0, 6}
};

LineSegment _backslash[] = {

    {0, 0, 4, 6}
};

LineSegment _lsquarebracket[] = {
    {4, 0, 0, 0},
    {0, 0, 0, 6},
    {0, 6, 4, 6}
};
LineSegment _rsquarebracket[] = {
    {0, 0, 4, 0},
    {4, 0, 4, 6},
    {4, 6, 0, 6}
};

LineSegment _underline[] = {
    {0, 6, 4, 6}
};

LineSegment _circumflex[] = {
    {2, 0, 0, 2},
    {2, 0, 4, 2}
};

LineSegment _rparenthes[] = {

    {2, 0, 4, 2},
    {4, 2, 4, 4},
    {4, 4, 2, 6}
};
LineSegment _larenthes[] = {
    {2, 0, 0, 2},
    {0, 2, 0, 4},
    {0, 4, 2, 6}
};

LineSegment _tilde[] = {
    {0, 1, 1, 0},
    {1, 0, 3, 2},
    {3, 2, 4, 1}
};

LineSegment _dot[] = {
    {2, 0, 4, 2},
    {4, 2, 4, 4},
    {4, 4, 2, 6}
};

LineSegment _minus[] = {
    {0, 3, 4, 3}
};

LineSegment _plus[] = {
    {0, 3, 4, 3},
    {2, 1, 2, 5}
};

LineSegment _comma[] = {
    {1, 3, 3, 3},
    {1, 4, 3, 4},
    {3, 4, 1, 6}
};

LineSegment _asterisk[] = {
    {0, 3, 4, 3},
    {2, 0, 2, 6},
    {4, 0, 0, 6},
    {0, 0, 4, 6}
};

LineSegment _equal[] = {
    {0, 2, 4, 2},
    {0, 4, 4, 4}
};

LineSegment _question[] = {
    {0, 1, 1, 0},
    {1, 0, 3, 0},
    {3, 0, 4, 1},
    {4, 1, 4, 2},
    {4, 2, 3, 3},
    {3, 3, 2, 4},
    {2, 6, 2, 6}
};
LineSegment _lessthan[] = {
    {3, 0, 0, 3},
    {0, 3, 3, 6}
};
LineSegment _greaterthan[] = {
    {1, 0, 4, 3},
    {4, 3, 1, 6}
};

LineSegment _colon[] = {
    {2, 2, 2, 2},
    {2, 4, 2, 4}
};

LineSegment _percent[] = {
    {4, 0, 0, 6},
    {0, 0, 1, 0},
    {0, 1, 1, 1},
    {3, 6, 4, 6},
    {3, 5, 4, 5}
};

LineSegment _and[] = {
    {1, 0, 0, 1},
    {0, 1, 0, 2},
    {0, 2, 1, 3},
    {1, 3, 2, 2},
    {2, 2, 2, 1},
    {2, 1, 1, 0},
    {1, 3, 0, 4},
    {0, 4, 0, 5},
    {0, 5, 1, 6},
    {1, 6, 2, 6},
    {2, 6, 4, 4},
    {1, 3, 4, 6}
};
LineSegment _uarrow[] = {
    {0, 2, 2, 0},
    {2, 0, 4, 2},
    {2, 0, 2, 6}
};

LineSegment _darrow[] = {
    {2, 0, 2, 6},
    {2, 6, 4, 4},
    {2, 6, 0, 4}
};
LineSegment _rarrow[] = {
    {0, 3, 4, 3},
    {4, 3, 1, 0},
    {4, 3, 1, 6}
};
LineSegment _larrow[] = {
    {0, 3, 4, 3},
    {0, 3, 3, 0},
    {0, 3, 3, 6}
};

// ======================
// FONT LOOKUP TABLE
// ======================
Glyph_Line font_table[] = {
    // Letters A-Z
    {'A',  sizeof(A_upper) / linepoint,         A_upper        },
    {'B',  sizeof(B_upper) / linepoint,         B_upper        },
    {'C',  sizeof(C_upper) / linepoint,         C_upper        },
    {'D',  sizeof(D_upper) / linepoint,         D_upper        },
    {'E',  sizeof(E_upper) / linepoint,         E_upper        },
    {'F',  sizeof(F_upper) / linepoint,         F_upper        },
    {'G',  sizeof(G_upper) / linepoint,         G_upper        },
    {'H',  sizeof(H_upper) / linepoint,         H_upper        },
    {'I',  sizeof(I_upper) / linepoint,         I_upper        },
    {'J',  sizeof(J_upper) / linepoint,         J_upper        },
    {'K',  sizeof(K_upper) / linepoint,         K_upper        },
    {'L',  sizeof(L_upper) / linepoint,         L_upper        },
    {'M',  sizeof(M_upper) / linepoint,         M_upper        },
    {'N',  sizeof(N_upper) / linepoint,         N_upper        },
    {'O',  sizeof(O_upper) / linepoint,         O_upper        },
    {'P',  sizeof(P_upper) / linepoint,         P_upper        },
    {'Q',  sizeof(Q_upper) / linepoint,         Q_upper        },
    {'R',  sizeof(R_upper) / linepoint,         R_upper        },
    {'S',  sizeof(S_upper) / linepoint,         S_upper        },
    {'T',  sizeof(T_upper) / linepoint,         T_upper        },
    {'U',  sizeof(U_upper) / linepoint,         U_upper        },
    {'V',  sizeof(V_upper) / linepoint,         V_upper        },
    {'W',  sizeof(W_upper) / linepoint,         W_upper        },
    {'X',  sizeof(X_upper) / linepoint,         X_upper        },
    {'Y',  sizeof(Y_upper) / linepoint,         Y_upper        },
    {'Z',  sizeof(Z_upper) / linepoint,         Z_upper        },
    // Letters a-z
    {'a',  sizeof(a_lower) / linepoint,         a_lower        },
    {'b',  sizeof(b_lower) / linepoint,         b_lower        },
    {'c',  sizeof(c_lower) / linepoint,         c_lower        },
    {'d',  sizeof(d_lower) / linepoint,         d_lower        },
    {'e',  sizeof(e_lower) / linepoint,         e_lower        },
    {'f',  sizeof(f_lower) / linepoint,         f_lower        },
    {'g',  sizeof(g_lower) / linepoint,         g_lower        },
    {'h',  sizeof(h_lower) / linepoint,         h_lower        },
    {'i',  sizeof(i_lower) / linepoint,         i_lower        },
    {'j',  sizeof(j_lower) / linepoint,         j_lower        },
    {'k',  sizeof(k_lower) / linepoint,         k_lower        },
    {'l',  sizeof(l_lower) / linepoint,         l_lower        },
    {'m',  sizeof(m_lower) / linepoint,         m_lower        },
    {'n',  sizeof(n_lower) / linepoint,         n_lower        },
    {'o',  sizeof(o_lower) / linepoint,         o_lower        },
    {'p',  sizeof(p_lower) / linepoint,         p_lower        },
    {'q',  sizeof(q_lower) / linepoint,         q_lower        },
    {'r',  sizeof(r_lower) / linepoint,         r_lower        },
    {'s',  sizeof(s_lower) / linepoint,         s_lower        },
    {'t',  sizeof(t_lower) / linepoint,         t_lower        },
    {'u',  sizeof(u_lower) / linepoint,         u_lower        },
    {'v',  sizeof(v_lower) / linepoint,         v_lower        },
    {'w',  sizeof(w_lower) / linepoint,         w_lower        },
    {'x',  sizeof(x_lower) / linepoint,         x_lower        },
    {'y',  sizeof(y_lower) / linepoint,         y_lower        },
    {'z',  sizeof(z_lower) / linepoint,         z_lower        },

    // Digits 0-9
    {'0',  sizeof(_0_upper) / linepoint,        _0_upper       },
    {'1',  sizeof(_1_upper) / linepoint,        _1_upper       },
    {'2',  sizeof(_2_upper) / linepoint,        _2_upper       },
    {'3',  sizeof(_3_upper) / linepoint,        _3_upper       },
    {'4',  sizeof(_4_upper) / linepoint,        _4_upper       },
    {'5',  sizeof(_5_upper) / linepoint,        _5_upper       },
    {'6',  sizeof(_6_upper) / linepoint,        _6_upper       },
    {'7',  sizeof(_7_upper) / linepoint,        _7_upper       },
    {'8',  sizeof(_8_upper) / linepoint,        _8_upper       },
    {'9',  sizeof(_9_upper) / linepoint,        _9_upper       },

    // Symbols
    {'!',  sizeof(_excl) / linepoint,           _excl          },
    {'/',  sizeof(_slash) / linepoint,          _slash         },
    {'\\', sizeof(_backslash) / linepoint,      _backslash     },
    {'_',  sizeof(_underline) / linepoint,      _underline     },
    {'(',  sizeof(_larenthes) / linepoint,      _larenthes     },
    {')',  sizeof(_rparenthes) / linepoint,     _rparenthes    },
    {'^',  sizeof(_circumflex) / linepoint,     _circumflex    },
    {'[',  sizeof(_lsquarebracket) / linepoint, _lsquarebracket},
    {']',  sizeof(_rsquarebracket) / linepoint, _rsquarebracket},
    {'~',  sizeof(_tilde) / linepoint,          _tilde         },
    {'.',  sizeof(_dot) / linepoint,            _dot           },
    {'-',  sizeof(_minus) / linepoint,          _minus         },
    {',',  sizeof(_comma) / linepoint,          _comma         },
    {'+',  sizeof(_plus) / linepoint,           _plus          },
    {'*',  sizeof(_asterisk) / linepoint,       _asterisk      },
    {'=',  sizeof(_equal) / linepoint,          _equal         },
    {'?',  sizeof(_question) / linepoint,       _question      },
    {'<',  sizeof(_lessthan) / linepoint,       _lessthan      },
    {'>',  sizeof(_greaterthan) / linepoint,    _greaterthan   },
    {':',  sizeof(_colon) / linepoint,          _colon         },
    {'%',  sizeof(_percent) / linepoint,        _percent       },
    {'&',  sizeof(_and) / linepoint,            _and           },
    {24,   sizeof(_uarrow) / linepoint,         _uarrow        },
    {25,   sizeof(_darrow) / linepoint,         _darrow        },
    {26,   sizeof(_rarrow) / linepoint,         _rarrow        },
    {27,   sizeof(_larrow) / linepoint,         _larrow        },
};
// void drawline(uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1, uint8_t *buffer);
// Glyph_Line *get_glyph_Line(uint8_t c);
// void draw_text(char *str, int16_t x, int16_t y, uint8_t scale, uint8_t deph);
// void GLCD_DrawChar(char c, uint8_t x, uint8_t y, uint8_t scale, uint8_t deph);

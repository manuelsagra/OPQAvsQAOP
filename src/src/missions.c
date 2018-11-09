#include <cpctelera.h>
#include "missions.h"
#include "blocks.h"
#include "board.h"
#include "game.h"
#include "video.h"

TMission const missions[MISSIONS] = {
    // 00
    {
        0x09DFB5,
        {
            0,          0,          0,          0,          0,          0,
            0,          0,          0,          0,          0,          0,
            0,          0,          0,          0,          0,          0,
            0,          0,          0,          0,          0,          0,
            0,          0,          0,          0,          0,          0,
            0,          0,          0,          0,          0,          0,
            0,          0,          0,          0,          0,          0,
            0,          0,          0,          0,          0,          0,
            0,          0,          0,          0,          0,          0,
            0,          0,          0,          0,          0,          0,
            0,          0, PIECE_GARB, PIECE_GARB,          0,          0,
            0,          0, PIECE_BL_Q, PIECE_BL_A,          0,          0
        },
        MISSION_TYPE_SCORE | MISSION_SCORE_1K | MISSION_LANDINGS_1
    },
    // 01
    {
        0x05E7C5,
        {
            0,          0,          0,          0,          0,          0,
            0,          0,          0,          0,          0,          0,
            0,          0,          0,          0,          0,          0,
            0,          0,          0,          0,          0,          0,
            0,          0,          0,          0,          0,          0,
            0,          0,          0,          0,          0,          0,
            0,          0,          0,          0,          0,          0,
            0,          0,          0,          0,          0,          0,
            0,          0, PIECE_GR_A, PIECE_RD_O, PIECE_MG_Q,          0,
            0,          0, PIECE_BL_A, PIECE_GR_Q, PIECE_RD_P,          0,
            0,          0, PIECE_BL_A, PIECE_GR_Q, PIECE_RD_P,          0,
            0,          0 ,PIECE_BL_A, PIECE_GR_Q, PIECE_RD_P,          0
        },
        MISSION_TYPE_COMBO | MISSION_COMBOS_3 | MISSION_LANDINGS_1
    },
    // 02
    {
        0x015C34,
        {
            0,          0,          0,          0,          0,          0,
            0,          0,          0,          0,          0,          0,
            0,          0,          0,          0,          0,          0,
            0,          0,          0,          0,          0,          0,
            0,          0,          0,          0,          0,          0,
            0,          0,          0,          0,          0,          0,
            0,          0,          0,          0,          0,          0,
            0,          0, PIECE_RD_Q,          0,          0,          0,
            0,          0, PIECE_RD_O,          0,          0,          0,
            0,          0, PIECE_BL_A,          0,          0,          0,
            0, PIECE_BL_O, PIECE_RD_A, PIECE_BL_Q,          0,          0,
   PIECE_GARB, PIECE_BL_P, PIECE_RD_P, PIECE_BL_A, PIECE_GARB,          0
        },
        MISSION_TYPE_COLOR | MISSION_COLOR_RD | MISSION_LANDINGS_1
    },
    // 03
    {
        0x01447C,
        {
            0,          0,          0,          0,          0,          0,
            0,          0,          0,          0,          0,          0,
            0,          0,          0,          0,          0,          0,
            0,          0,          0,          0,          0,          0,
            0,          0,          0,          0,          0,          0,
            0,          0,          0,          0,          0,          0,
            0,          0,          0,          0,          0,          0,
            0,          0,          0,          0,          0,          0,
            0,          0,          0,          0,          0,          0,
   PIECE_BL_Q, PIECE_BL_Q, PIECE_BL_Q, PIECE_GR_A, PIECE_BL_A, PIECE_BL_A,
   PIECE_RD_A, PIECE_RD_A, PIECE_RD_A, PIECE_GR_Q, PIECE_RD_A, PIECE_RD_A,
   PIECE_BL_Q, PIECE_BL_Q, PIECE_BL_Q, PIECE_GR_O, PIECE_BL_A, PIECE_BL_A
        },
        MISSION_TYPE_CLEAR | MISSION_LANDINGS_2
    },
    // 04
    {
        0x066CB9,
        {
            0,          0,          0,          0,          0,          0,
            0,          0,          0,          0,          0,          0,
            0,          0,          0,          0,          0,          0,
            0,          0,          0,          0,          0,          0,
            0,          0,          0,          0,          0,          0,
            0,          0,          0,          0,          0,          0,
            0,          0,          0,          0,          0,          0,
            0, PIECE_BL_O,          0, PIECE_MG_A,          0,          0,
            0, PIECE_BL_P, PIECE_MG_P, PIECE_GR_Q, PIECE_RD_Q, PIECE_BL_O,
   PIECE_GARB, PIECE_BL_O, PIECE_MG_A, PIECE_GR_Q, PIECE_RD_O, PIECE_BL_O,
   PIECE_BL_A, PIECE_GR_Q, PIECE_MG_Q, PIECE_RD_P, PIECE_MG_O, PIECE_GARB,
   PIECE_BL_Q, PIECE_GR_A, PIECE_GR_O, PIECE_RD_A, PIECE_MG_P, PIECE_MG_A
        },
        MISSION_TYPE_COMBO | MISSION_COMBOS_5 | MISSION_LANDINGS_2
    },
    // 05
    {
        0x03FB90,
        {
            0,          0,          0,          0,          0,          0,
            0,          0,          0,          0,          0,          0,
            0,          0,          0,          0,          0,          0,
            0,          0,          0,          0,          0,          0,
            0,          0,          0,          0,          0,          0,
            0,          0,          0,          0,          0,          0,
   PIECE_RD_O,          0,          0,          0,          0,          0,
   PIECE_BL_Q, PIECE_BL_Q, PIECE_BL_O,          0,          0,          0,
   PIECE_RD_Q, PIECE_RD_O, PIECE_MG_P,          0,          0,          0,
   PIECE_BL_A, PIECE_BL_P, PIECE_BL_Q,          0,          0,          0,
   PIECE_RD_O, PIECE_RD_Q, PIECE_RD_A,          0,          0,          0,
   PIECE_BL_P, PIECE_BL_A, PIECE_BL_A, PIECE_GARB,          0,          0
        },
        MISSION_TYPE_COLOR | MISSION_COLOR_BL | MISSION_LANDINGS_2
    },
    // 06
    {
        0x00CF14,
        {
            0,          0,          0,          0,          0,          0,
            0,          0,          0,          0,          0,          0,
            0,          0,          0,          0,          0,          0,
            0,          0,          0,          0,          0,          0,
            0,          0,          0,          0,          0,          0,
            0,          0,          0,          0,          0,          0,
            0,          0,          0,          0,          0,          0,
            0,          0,          0,          0,          0,          0,
   PIECE_GARB, PIECE_GARB, PIECE_GR_O, PIECE_MG_Q, PIECE_GARB, PIECE_GARB,
   PIECE_GARB, PIECE_GR_A, PIECE_GR_Q, PIECE_MG_Q, PIECE_MG_P, PIECE_GARB,
   PIECE_GARB, PIECE_GARB, PIECE_GARB, PIECE_GARB, PIECE_GARB, PIECE_GARB,
   PIECE_GR_Q, PIECE_GR_A, PIECE_GR_P, PIECE_MG_O, PIECE_MG_P, PIECE_MG_Q
        },
        MISSION_TYPE_COLOR | MISSION_COLOR_GR | MISSION_LANDINGS_3
    },
    // 07
    {
        0x09918E,
        {
            0,          0,          0,          0,          0,          0,
            0,          0,          0,          0,          0,          0,
            0,          0,          0,          0,          0,          0,
            0,          0,          0,          0,          0,          0,
            0,          0,          0,          0,          0,          0,
            0,          0,          0,          0,          0,          0,
            0,          0,          0,          0,          0,          0,
            0,          0,          0,          0,          0,          0,
            0,          0, PIECE_BL_A, PIECE_BL_A,          0,          0,
   PIECE_GARB, PIECE_GARB, PIECE_GARB, PIECE_GARB, PIECE_GARB, PIECE_GARB,
   PIECE_MG_A, PIECE_MG_A, PIECE_MG_A, PIECE_GR_Q, PIECE_GR_A, PIECE_GR_A,
   PIECE_GR_Q, PIECE_GR_Q, PIECE_GR_Q, PIECE_RD_O, PIECE_RD_A, PIECE_RD_A
        },
        MISSION_TYPE_SCORE | MISSION_SCORE_5K | MISSION_LANDINGS_3
    },
    // 08
    {
        0x089369,
        {
            0,          0,          0, PIECE_GARB,          0,          0,
            0,          0,          0, PIECE_GARB,          0,          0,
            0,          0,          0, PIECE_GARB,          0,          0,
            0,          0,          0, PIECE_GARB,          0,          0,
            0,          0,          0, PIECE_GARB,          0, PIECE_BL_Q,
            0,          0,          0, PIECE_GARB,          0, PIECE_BL_Q,
            0,          0,          0, PIECE_GARB,          0, PIECE_BL_Q,
            0, PIECE_GARB,          0, PIECE_GARB,          0, PIECE_MG_Q,
   PIECE_RD_P, PIECE_GARB, PIECE_RD_O, PIECE_GARB,          0, PIECE_MG_P,
   PIECE_RD_P, PIECE_GARB, PIECE_RD_O, PIECE_GARB,          0, PIECE_MG_A,
   PIECE_RD_P, PIECE_GARB, PIECE_RD_O, PIECE_GARB,          0, PIECE_BL_A,
   PIECE_GARB, PIECE_GARB, PIECE_GARB, PIECE_GARB, PIECE_GARB, PIECE_BL_A
        },
        MISSION_TYPE_COLOR | MISSION_COLOR_MG | MISSION_LANDINGS_2
    },
    // 09
    {
        0x0B5E63,
        {
            0,          0,          0,          0,          0,          0,
            0,          0,          0,          0,          0,          0,
            0,          0,          0,          0,          0,          0,
            0,          0,          0,          0,          0,          0,
   PIECE_MG_Q,          0,          0,          0,          0,          0,
   PIECE_MG_Q, PIECE_RD_A,          0,          0,          0,          0,
   PIECE_MG_O, PIECE_RD_A,          0,          0,          0,          0,
   PIECE_GR_A, PIECE_MG_O,          0,          0,          0,          0,
   PIECE_GR_P, PIECE_BL_P,          0,          0,          0,          0,
   PIECE_GR_O, PIECE_BL_O,          0,          0,          0,          0,
   PIECE_BL_Q, PIECE_GR_A, PIECE_MG_O, PIECE_RD_Q,          0,          0,
   PIECE_BL_A, PIECE_GARB, PIECE_MG_Q, PIECE_MG_P, PIECE_RD_O, PIECE_GARB
        },
        MISSION_TYPE_COMBO | MISSION_COMBOS_5 | MISSION_LANDINGS_1
    },
    // 10
    {
        0x0F3E73,
        {
            0,          0,          0,          0,          0,          0,
            0,          0,          0,          0,          0,          0,
            0,          0,          0, PIECE_GR_O, PIECE_GR_O,          0,
   PIECE_MG_A, PIECE_MG_A, PIECE_MG_A, PIECE_BL_A, PIECE_BL_A,          0,
   PIECE_BL_O, PIECE_BL_O, PIECE_BL_O, PIECE_GR_O, PIECE_GR_O,          0,
   PIECE_GR_A, PIECE_GR_A, PIECE_GR_A, PIECE_BL_A, PIECE_BL_A,          0,
   PIECE_BL_O, PIECE_BL_O, PIECE_BL_O, PIECE_GR_O, PIECE_GR_O,          0,
   PIECE_GR_A, PIECE_GR_A, PIECE_GR_A, PIECE_BL_A, PIECE_BL_A,          0,
   PIECE_BL_O, PIECE_BL_O, PIECE_BL_O, PIECE_GR_O, PIECE_GR_O,          0,
   PIECE_GR_A, PIECE_GR_A, PIECE_GR_A, PIECE_BL_A, PIECE_BL_A,          0,
   PIECE_BL_O, PIECE_BL_O, PIECE_BL_O, PIECE_GR_O, PIECE_GR_O,          0,
   PIECE_GR_A, PIECE_GR_A, PIECE_GR_A, PIECE_BL_A, PIECE_BL_A, PIECE_BL_A
        },
        MISSION_TYPE_COMBO | MISSION_COMBOS_7 | MISSION_LANDINGS_3
    },
    // 11
    {
        0x0C44BB,
        {
            0,          0,          0,          0,          0,          0,
            0,          0,          0,          0,          0,          0,
            0,          0,          0,          0,          0,          0,
            0,          0,          0,          0,          0,          0,
            0,          0,          0,          0,          0,          0,
            0,          0,          0,          0,          0,          0,
            0,          0,          0,          0,          0,          0,
            0,          0,          0,          0,          0,          0,
            0,          0,          0,          0,          0,          0,
   PIECE_MG_O,          0,          0,          0,          0,          0,
   PIECE_MG_A, PIECE_GR_A, PIECE_GR_Q,          0,          0,          0,
   PIECE_GARB, PIECE_GARB, PIECE_GARB,          0,          0,          0
        },
        MISSION_TYPE_CLEAR | MISSION_LANDINGS_4
    },
    // 12
    {
        0x053C1F,
        {
            0,          0,          0,          0,          0,          0,
            0,          0,          0,          0,          0,          0,
            0,          0,          0,          0,          0,          0,
            0,          0,          0,          0,          0,          0,
            0,          0,          0,          0,          0,          0,
            0,          0,          0,          0,          0,          0,
            0,          0,          0,          0,          0,          0,
            0,          0,          0,          0,          0,          0,
            0,          0,          0,          0,          0,          0,
            0,          0, PIECE_MG_O, PIECE_MG_Q,          0,          0,
            0,          0, PIECE_GARB, PIECE_GARB,          0,          0,
            0, PIECE_GARB, PIECE_RD_O, PIECE_RD_O, PIECE_GARB,          0
        },
        MISSION_TYPE_COLOR | MISSION_COLOR_RD | MISSION_LANDINGS_5
    },
    // 13
    {
        0x0981C8,
        {
            0,          0,          0,          0,          0,          0,
            0,          0,          0,          0,          0,          0,
            0,          0,          0,          0,          0,          0,
            0,          0,          0,          0,          0,          0,
            0,          0,          0,          0,          0,          0,
            0,          0,          0,          0,          0,          0,
            0,          0,          0,          0,          0,          0,
            0,          0,          0,          0,          0,          0,
            0,          0,          0,          0,          0,          0,
            0,          0,          0,          0,          0,          0,
            0,          0, PIECE_MG_Q, PIECE_MG_A,          0,          0,
   PIECE_GARB, PIECE_GARB, PIECE_BL_A, PIECE_BL_O, PIECE_GARB, PIECE_GARB
        },
        MISSION_TYPE_SCORE | MISSION_SCORE_10K | MISSION_LANDINGS_2
    },
    // 14
    {
        0x0EC161,
        {
            0,          0,          0,          0,          0,          0,
            0,          0,          0,          0,          0,          0,
            0,          0,          0,          0,          0,          0,
            0,          0,          0,          0,          0,          0,
            0,          0,          0,          0,          0,          0,
            0,          0,          0,          0,          0,          0,
            0,          0,          0,          0, PIECE_GARB,          0,
            0,          0,          0,          0, PIECE_GR_A,          0,
            0,          0,          0, PIECE_GR_O, PIECE_RD_Q,          0,
            0, PIECE_BL_Q, PIECE_RD_Q, PIECE_GR_O, PIECE_RD_O,          0,
   PIECE_BL_A, PIECE_BL_O, PIECE_RD_A, PIECE_BL_A, PIECE_RD_O,          0,
   PIECE_GARB, PIECE_RD_O, PIECE_MG_A, PIECE_BL_A, PIECE_BL_Q,          0
        },
        MISSION_TYPE_COMBO | MISSION_COMBOS_3 | MISSION_LANDINGS_2
    },
    // 15
    {
        0x0785C8,
        {
            0,          0,          0,          0,          0,          0,
            0,          0,          0,          0,          0,          0,
            0,          0,          0,          0,          0,          0,
            0,          0,          0,          0,          0,          0,
            0,          0,          0,          0,          0,          0,
            0,          0,          0,          0,          0,          0,
            0,          0,          0,          0,          0,          0,
            0, PIECE_GARB,          0,          0, PIECE_GARB,          0,
            0, PIECE_BL_A,          0,          0, PIECE_BL_Q,          0,
            0, PIECE_BL_O,          0,          0, PIECE_BL_A,          0,
   PIECE_MG_O, PIECE_BL_O,          0,          0, PIECE_BL_Q, PIECE_MG_A,
   PIECE_MG_Q, PIECE_MG_A,          0,          0, PIECE_MG_A, PIECE_MG_Q
        },
        MISSION_TYPE_COLOR | MISSION_COLOR_BL | MISSION_LANDINGS_2
    },
    // 16
    {
        0x3466631,
        {
            0,          0,          0,          0,          0,          0,
            0,          0,          0,          0,          0,          0,
            0,          0,          0,          0,          0,          0,
            0,          0,          0,          0,          0,          0,
            0,          0,          0,          0,          0,          0,
            0,          0,          0,          0,          0,          0,
            0,          0,          0,          0,          0,          0,
            0,          0,          0,          0,          0,          0,
            0,          0,          0,          0,          0,          0,
            0, PIECE_RD_O, PIECE_MG_P, PIECE_BL_A, PIECE_GR_A,          0,
            0, PIECE_RD_Q, PIECE_MG_O, PIECE_BL_Q, PIECE_GR_O,          0,
            0, PIECE_RD_A, PIECE_MG_A, PIECE_BL_O, PIECE_GR_P,          0
        },
        MISSION_TYPE_COMBO | MISSION_COMBOS_4 | MISSION_LANDINGS_3
    },
    // 17
    {
        0x072818,
        {
            0,          0,          0,          0,          0,          0,
            0,          0,          0,          0,          0,          0,
            0,          0,          0,          0,          0,          0,
            0,          0,          0,          0,          0,          0,
            0,          0,          0,          0,          0,          0,
            0,          0,          0,          0,          0,          0,
            0,          0,          0,          0,          0,          0,
            0,          0,          0,          0,          0,          0,
   PIECE_GARB, PIECE_GARB, PIECE_GARB,          0,          0,          0,
   PIECE_GARB, PIECE_GR_P, PIECE_GARB, PIECE_RD_A, PIECE_RD_Q, PIECE_RD_O,
   PIECE_GARB, PIECE_GR_P, PIECE_BL_A, PIECE_GARB, PIECE_GARB, PIECE_GARB,
   PIECE_GARB, PIECE_GR_P, PIECE_BL_O, PIECE_BL_Q, PIECE_GARB, PIECE_GARB
        },
        MISSION_TYPE_COLOR | MISSION_COLOR_GR | MISSION_LANDINGS_5
    },
    // 18
    {
        0x04C38,
        {
            0,          0,          0,          0,          0,          0,
            0,          0,          0,          0,          0,          0,
            0,          0,          0,          0,          0,          0,
            0,          0,          0,          0,          0,          0,
            0,          0,          0,          0,          0,          0,
            0,          0,          0,          0,          0,          0,
            0,          0,          0,          0,          0,          0,
            0,          0,          0,          0,          0,          0,
            0,          0,          0,          0,          0,          0,
   PIECE_MG_A, PIECE_MG_O, PIECE_MG_P, PIECE_GARB, PIECE_GARB, PIECE_GARB,
   PIECE_GARB, PIECE_GR_O, PIECE_GR_A, PIECE_BL_Q, PIECE_BL_Q, PIECE_GARB,
   PIECE_GARB, PIECE_RD_A, PIECE_RD_Q, PIECE_RD_O, PIECE_BL_A, PIECE_GARB
        },
        MISSION_TYPE_SCORE | MISSION_SCORE_12K | MISSION_LANDINGS_6
    },
    // 19
        {
        0x019E10,
        {
            0,          0,          0,          0,          0,          0,
            0,          0,          0,          0,          0,          0,
            0,          0,          0,          0,          0,          0,
            0,          0,          0,          0,          0,          0,
            0,          0,          0,          0,          0,          0,
            0,          0,          0,          0,          0,          0,
            0,          0,          0,          0,          0,          0,
            0,          0,          0,          0,          0,          0,
            0,          0,          0,          0,          0,          0,
            0,          0,          0,          0,          0,          0,
            0,          0,          0,          0,          0,          0,
   PIECE_GARB, PIECE_GARB, PIECE_GARB,          0, PIECE_GARB, PIECE_GARB
        },
        MISSION_TYPE_CLEAR | MISSION_LANDINGS_0
    }
};

// Private functions
u32         opqa_getMissionScore(TMission* m);

// Getters
TMission* opqa_getMission(u8 mission) {
    return &missions[mission];
}

// Functions
u8 opqa_checkMissionStatus() {
    TState* s = opqa_getState();
    TPlayer* p = opqa_getPlayer(0);
    TMission* m = opqa_getMission(s->level);
    u8 color;

    switch (m->type & MISSION_TYPE) {
        case MISSION_TYPE_CLEAR: 
            if (opqa_isBoardCleared(0)) {
                return MISSION_ST_CLEARED;
            }
            break;

        case MISSION_TYPE_COLOR: 
            color = (m->type & MISSION_COLOR) >> 1;
            if (opqa_isColorCleared(0, color)) {
                return MISSION_ST_CLEARED;
            }
            break;

        case MISSION_TYPE_COMBO: 
            if (p->combos >= ((m->type & MISSION_COMBOS) >> 3)) {
                return MISSION_ST_CLEARED;
            }
            break;

        case MISSION_TYPE_SCORE: 
            if (p->score >= opqa_getMissionScore(m)) {
                return MISSION_ST_CLEARED;
            }
            break;
    }

    return (m->type & MISSION_LANDINGS) ? (p->landings >= (m->type & MISSION_LANDINGS)) : MISSION_ST_PENDING;
}

void opqa_showMissionObjectives() {
    TState* s = opqa_getState();
    TMission* m = opqa_getMission(s->level);

    opqa_drawText(54, 20, "__________");
    opqa_drawText(54, 16, "MISSION");
    opqa_drawNumber(68, 16, NUMBER_RED, s->level + 1, 2);

    switch (m->type & MISSION_TYPE) {
        case MISSION_TYPE_CLEAR: 
            opqa_drawText(55, 48, "Clear all");            
            if (m->type & MISSION_LANDINGS) {
                opqa_drawText(55, 64, "pieces in");
                if ((m->type & MISSION_LANDINGS) > 1) {
                    opqa_drawText(56, 94, "landings");
                } else {
                    opqa_drawText(57, 94, "landing");
                }
                opqa_drawNumber(61, 82, NUMBER_YELLOW, m->type & MISSION_LANDINGS, 1);
            } else {
                opqa_drawText(58, 64, "pieces");
            }
            break;

        case MISSION_TYPE_COLOR: 
            opqa_drawText(55, 48, "Clear all");
            if ((m->type & MISSION_COLOR) == MISSION_COLOR_BL) {
                opqa_drawText(60, 70, "BLUE");
            } else if ((m->type & MISSION_COLOR) == MISSION_COLOR_GR) {
                opqa_drawText(59, 70, "GREEN");
            } else if ((m->type & MISSION_COLOR) == MISSION_COLOR_RD) {
                opqa_drawText(61, 70, "RED");
            } else {
                opqa_drawText(57, 70, "MAGENTA");
            }
            opqa_drawText(55, 86, "pieces in");

            if ((m->type & MISSION_LANDINGS) > 1) {
                opqa_drawText(56, 116, "landings");
            } else {
                opqa_drawText(57, 116, "landing");
            }

            opqa_drawNumber(61, 104, NUMBER_YELLOW, m->type & MISSION_LANDINGS, 1);
            break;

        case MISSION_TYPE_COMBO: 
            opqa_drawText(60, 48, "Make");
            opqa_drawText(55, 78, "combos in");
            if ((m->type & MISSION_LANDINGS) > 1) {
                opqa_drawText(56, 108, "landings");
            } else {
                opqa_drawText(57, 108, "landing");
            }

            opqa_drawNumber(61, 66, NUMBER_YELLOW, (m->type & MISSION_COMBOS) >> 3, 1);
            opqa_drawNumber(61, 96, NUMBER_YELLOW, m->type & MISSION_LANDINGS, 1);

            break;

        case MISSION_TYPE_SCORE: 
            opqa_drawText(59, 48, "Score");                      
            opqa_drawText(55, 78, "points in");            
            if ((m->type & MISSION_LANDINGS) > 1) {
                opqa_drawText(56, 108, "landings");
            } else {
                opqa_drawText(57, 108, "landing");
            }

            opqa_drawNumber(56, 66, NUMBER_YELLOW, opqa_getMissionScore(m), 6);
            opqa_drawNumber(61, 96, NUMBER_YELLOW, m->type & MISSION_LANDINGS, 1);
            
            break;
    }
}

u32 opqa_getMissionScore(TMission* m) {
    u8 type = m->type & MISSION_SCORE;

    switch (type) {
        case MISSION_SCORE_1K:
            return 1000;

        case MISSION_SCORE_5K:
            return 5000;

        case MISSION_SCORE_10K:
            return 10000;

        case MISSION_SCORE_12K:
            return 12000;
    }

    return 0;
}
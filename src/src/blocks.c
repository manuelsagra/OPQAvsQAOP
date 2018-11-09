#include <cpctelera.h>
#include "blocks.h"
#include "board.h"
#include "game.h"
#include "sound.h"
#include "utils.h"

const TBlock current_block[2] = {
    {
        {
            0,
            0
        },
        0,
        0,
        0
    },
    {
        {
            0,
            0
        },
        0,
        0,
        0
    }
};
const TBlock next_block[2] = {
    {
        {
            0,
            0
        },
        BOARD_WIDTH,
        BOARD_HEIGHT,
        0
    },
    {
        {
            0,
            0
        },
        BOARD_WIDTH,
        BOARD_HEIGHT,
        0
    }
};
const TBlock prev_block[2] = {
    {
        {
            0,
            0
        },
        BOARD_WIDTH,
        BOARD_HEIGHT,
        0
    },
    {
        {
            0,
            0
        },
        BOARD_WIDTH,
        BOARD_HEIGHT,
        0
    }
};

// Getters
TBlock* opqa_getCurrentBlock(u8 player) { return &current_block[player]; }
TBlock* opqa_getNextBlock(u8 player) { return &next_block[player]; }
TBlock* opqa_getPrevBlock(u8 player) { return &prev_block[player]; } 

// Functions
u8 opqa_newRandomPiece() {
    u8 p;

    p = cpct_rand();
    // Only return normal or joker pieces
    if ((p & PIECE_TYPE) == PIECE_TYPE_SPECIAL && p != PIECE_JOKER && p != PIECE_JOKER2) {
        p |= PIECE_TYPE_NORMAL;
    }

    return p;
}

void opqa_newRandomBlock(TBlock* b) {
    b->pieces[0] = opqa_newRandomPiece();
    b->pieces[1] = opqa_newRandomPiece();
    // Prevent double jokers
    if (
        (b->pieces[0] & PIECE_TYPE) == PIECE_TYPE_SPECIAL &&
        (b->pieces[1] & PIECE_TYPE) == PIECE_TYPE_SPECIAL
    ) {
        b->pieces[0] |= PIECE_TYPE_NORMAL;
    }
    b->rotation = ROTATION_VERTICAL_10;
    b->x = 2;
    b->y = 0;
}

void opqa_copyBlock(TBlock* from, TBlock* to) {
    u8 i;
    u8* t = (u8*) to;
    u8* f = (u8*) from;
    
    for (i = 0; i < BLOCK_OBJ_SIZE; i++) {
        *t++ = *f++;
    }
}

void opqa_checkBlockRotation(u8 player) {
    TBlock* b = opqa_getCurrentBlock(player);
    u8* bd = opqa_getBoard(player);

    switch (b->rotation) {
        case ROTATION_VERTICAL_01:
            if (b->y == BOARD_HEIGHT - 1) {
                b->rotation++;
                opqa_checkBlockRotation(player);
            }
            break;

        case ROTATION_HORIZONTAL_01:
            if (b->x == BOARD_WIDTH - 1 || *(bd + (b->x + 1) + (b->y * 6)))  {
                if (opqa_blockCanMove(0, KEY_LEFT)) {
                    b->x--;
                } else {
                    b->rotation++;
                    opqa_checkBlockRotation(player);
                }                
            }
            break;

        case ROTATION_HORIZONTAL_10:
            if (!b->x || *(bd + (b->x - 1) + (b->y * 6))) {
                if (opqa_blockCanMove(0, KEY_RIGHT)) {
                    b->x++;
                } else {
                    b->rotation++;
                    opqa_checkBlockRotation(player);
                }
            }
            break;
    }
}

u8 opqa_blockHasLanded(u8 player) {
    TBlock* b = opqa_getCurrentBlock(player);
    u8* bd = opqa_getBoard(player);

    switch (b->rotation) {
        case ROTATION_VERTICAL_01:
            if (b->y + 1 == BOARD_HEIGHT - 1 || *(bd + (b->x) + (b->y + 2) * 6)) {
                return 1;
            }
            break;

        case ROTATION_VERTICAL_10:
            if (b->y == BOARD_HEIGHT - 1 || *(bd + (b->x) + (b->y + 1) * 6)) {
                return 1;
            }
            break;

        case ROTATION_HORIZONTAL_01:
            if (b->y == BOARD_HEIGHT - 1 || *(bd + (b->x)  + (b->y + 1) * 6) || *(bd + (b->x + 1) + (b->y + 1) * 6)) {
                return 1;
            }
            break;

        case ROTATION_HORIZONTAL_10:
            if (b->y == BOARD_HEIGHT - 1 || *(bd + (b->x) + (b->y + 1) * 6) || *(bd + (b->x - 1) +  (b->y + 1) * 6)) {
                return 1;
            }
            break;
    }
    return 0;
}

u8 opqa_blockCanMove(u8 player, u8 move) {
    TBlock* b = opqa_getCurrentBlock(player);
    u8* bd = opqa_getBoard(player);

    switch (move) {
        case KEY_RIGHT:
            if (b->rotation == ROTATION_HORIZONTAL_01) {
                return ((b->x < BOARD_WIDTH - 2) && !*(bd + (b->x + 2) + (b->y) * 6));
            } else if (b->rotation == ROTATION_HORIZONTAL_10) {
                return ((b->x < BOARD_WIDTH - 1) && !*(bd + (b->x + 1) + (b->y) * 6));
            } else if (b->rotation == ROTATION_VERTICAL_10) {
                return ((b->x < BOARD_WIDTH - 1) && !*(bd + (b->x + 1) + (b->y) * 6) && ((b->y == 0) || !*(bd + (b->x + 1) + (b->y - 1) * 6)));
            } else {
                return ((b->x < BOARD_WIDTH - 1) && !*(bd + (b->x + 1) + (b->y) * 6) && !*(bd + (b->x + 1) + (b->y + 1) * 6));
            }

        case KEY_LEFT:
            if (b->rotation == ROTATION_HORIZONTAL_10) {
                return ((b->x > 1) && !*(bd + (b->x - 2) + (b->y) * 6));
            } else if (b->rotation == ROTATION_HORIZONTAL_01) {
                return ((b->x > 0) && !*(bd + (b->x - 1) + (b->y) * 6));
            } else if (b->rotation == ROTATION_VERTICAL_10) {
                return ((b->x > 0) && !*(bd + (b->x - 1) + (b->y) * 6) && ((b->y == 0) || !*(bd + (b->x - 1) + (b->y - 1) * 6)));
            } else {
                return ((b->x > 0) && !*(bd + (b->x - 1) + (b->y) * 6) && !*(bd + (b->x - 1) + (b->y + 1) * 6));
            }

        case KEY_DOWN:
            if (b->rotation == ROTATION_HORIZONTAL_10) {
                return ((b->y < BOARD_HEIGHT - 1) && !*(bd + (b->x) + (b->y + 1) * 6) && !*(bd + (b->x - 1) + (b->y + 1) * 6));
            } else if (b->rotation == ROTATION_HORIZONTAL_10) {
                return ((b->y < BOARD_HEIGHT - 1) && !*(bd + (b->x) + (b->y + 1) * 6) && !*(bd + (b->x + 1) + (b->y + 1) * 6));
            } else if (b->rotation == ROTATION_VERTICAL_10) {
                return ((b->y < BOARD_HEIGHT - 1) && !*(bd + (b->x) + (b->y + 1) * 6));
            } else {
                return ((b->y < BOARD_HEIGHT - 1) && !*(bd + (b->x) + (b->y + 2) * 6));
            }
    }
    return 1;
}

u8 opqa_landBlock(u8 player) {
    TBlock* b = opqa_getCurrentBlock(player);
    TPlayer* p = opqa_getPlayer(player);
    TPlayer* po = opqa_getPlayer(player ? 0 : 1);
    TUpdate* u = opqa_getUpdate(player);
    TState* s = opqa_getState();
    u8* bd = opqa_getBoard(player);
    u8* f = opqa_getFlash(player);
    u8 i;
    i8 y = BOARD_HEIGHT - 1;
    u8 inc_score1 = 0, inc_score2 = 0;

    // Horizontal
    if (b->rotation == ROTATION_HORIZONTAL_10 || b->rotation == ROTATION_HORIZONTAL_01) {
        for (i = ((BOARD_HEIGHT - 1) * 6) + b->x; y >= 0 && *(bd + i); y--) {
            i -= 6;
        }
        *(bd + i) = b->pieces[0];
        inc_score1 = y - b->y;

        y = BOARD_HEIGHT - 1;
        for (i = ((BOARD_HEIGHT - 1) * 6) + b->x + ((b->rotation == ROTATION_HORIZONTAL_10) ? -1 : 1); y >= 0 && *(bd + i); y--) {
            i -= 6;
        }
        *(bd + i) = b->pieces[1];
        inc_score2 = y - b->y;

        if (inc_score1 > inc_score2) {
            p->score += (inc_score2 << 1);
        } else {
            p->score += (inc_score1 << 1);
        }
    // Vertical
    } else {
        for (i = ((BOARD_HEIGHT - 1) * 6) + b->x; y >= 0 && *(bd + i); y--) {
            i -= 6;
        }
        *(bd + i) = (b->rotation == ROTATION_VERTICAL_10) ? b->pieces[0] : b->pieces[1];
        if (i < 6) {
            // Game Over
            return 0;
        }
        *(bd + i - 6) = (b->rotation == ROTATION_VERTICAL_10) ? b->pieces[1] : b->pieces[0];

        p->score += ((y - b->y) << 1);
    }

    // Get new block in the next tick
    b->pieces[0] = 0;

    p->score += opqa_checkBoard(player);
    u->score = 1;

    if (!u->flash) {
        opqa_playFX(SFX_FALL, player ? AY_CHANNEL_C : AY_CHANNEL_A);
    }

    // Check game over
    if (*(bd + 2) && !*(f + 2)) {
        return 0;
    }   

    // Receive garbage
    if (po->combo && s->mode != MODE_ENDLESS && s->mode != MODE_MISSION) {
        if (opqa_receiveGarbage(player)) {
            u->garbage = FLASH_VALUE;
        }
    }   

    return 1;
}


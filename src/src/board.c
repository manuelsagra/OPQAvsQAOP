#include <cpctelera.h>
#include "board.h"
#include "blocks.h"
#include "game.h"
#include "sound.h"
#include "video.h"
#include "utils.h"
#include "missions.h"

// Private functions
void        opqa_copyTmpFlash(u8 player);
u8          opqa_findPiecesSameColour(u8 player, u8 x, u8 y);
u8          opqa_removePieces(u8 player, u8 color);

// Getters
u8* opqa_getBoard(u8 player) { return (u8*) (BOARD_POINTER + (player ? BOARD_OBJ_SIZE : 0)); }
u8* opqa_getFlash(u8 player) { return (u8*) (FLASH_POINTER + (player ? BOARD_OBJ_SIZE : 0)); }
u8* opqa_getGarbage(u8 player) { return (u8*) (GARBAGE_POINTER + (player ? BOARD_OBJ_SIZE : 0)); }
u8* opqa_getGarbageX(u8 player) { return (u8*) (GARBAGEX_POINTER + (player ? 1 : 0)); }
u8* opqa_getTmpFlash() { return (u8*) TMPFLASH_POINTER; }

// Resets
void opqa_resetBoardArray(u8* array) {
    u8 i = 0;

    for (; i < BOARD_WIDTH * BOARD_HEIGHT; i++) {
        *array++ = 0;
    }
}

void opqa_resetGarbageX() {
    u8* gx = opqa_getGarbageX(0);
    *gx++ = 0;
    *gx = 0;
}

// Functions
u32 opqa_checkBoard(u8 player) {
    u8 i = 0, x = 0, y = 0, opqa_good = 0, opqa_bad = 0, found = 0, pieces = 0;
    TUpdate* u = opqa_getUpdate(player);
    TPlayer* p = opqa_getPlayer(player); 
    TPlayer* po = opqa_getPlayer(player ? 0 : 1);
    TBlock* nb = opqa_getNextBlock(player);
    u8* b = opqa_getBoard(player);
    u8* f = opqa_getFlash(player);
    u8* t = opqa_getTmpFlash();
    u32 score = 0, tmp = 0;

    // Joker
    for (; i < BOARD_WIDTH * BOARD_HEIGHT; i++) {
        if ((*b & PIECE_TYPE) == PIECE_TYPE_SPECIAL && (*b & PIECE_SUBTYPE) == PIECE_SUBTYPE_JOKER) {
            found = 1;
            *f = 1;
            if (i < 66 && (*(b + 6) & PIECE_TYPE) == PIECE_TYPE_NORMAL) {
                pieces += opqa_removePieces(player, *(b + 6) & PIECE_COLOR);
            }
        }
        b++;
        f++;
    }

    if (found) {
        if (pieces) {
            score = 10 * pieces;
        } else {
            score = 500;
            p->combo += 2;
        }
    }

    // Colours
    x = 0;
    y = 0;
    b = opqa_getBoard(player);
    f = opqa_getFlash(player);
    for (i = 0; i < BOARD_WIDTH * BOARD_HEIGHT; i++) {
        if (*b && *b != PIECE_GARBAGE && !*f) {
            opqa_resetBoardArray(t);
            pieces = opqa_findPiecesSameColour(player, x, y);
            if (pieces > 3) {
                found = 1;
                opqa_copyTmpFlash(player);
                p->combo++;
                p->combos++;
                tmp = 10 * pieces * p->combo;
                if (tmp > 999) {
                    tmp = 999;
                }
                score += tmp;
            }
        }
        b++;
        f++;
        x++;
        if (x == BOARD_WIDTH) {
            y++;
            x = 0;
        }
    }
    if (found) {
        opqa_playFXCombo(player ? AY_CHANNEL_C : AY_CHANNEL_A, p->combo);
        opqa_removeGarbage(player);
    }    

    // OPQA/QAOP same colour
    x = 0;
    y = 0;
    b = opqa_getBoard(player);
    f = opqa_getFlash(player);    
    for (i = 0; i < BOARD_WIDTH * BOARD_HEIGHT; i++) {
        if (*b) {
            if (x < 3) { // Check right
                if (*(b + 1) && *(b + 2) && *(b + 3)) {
                    opqa_good = 0;
                    opqa_bad = 0;
                    
                    if (
                        (*(b + 1) & PIECE_COLOR) == (*b & PIECE_COLOR) &&
                        (*(b + 2) & PIECE_COLOR) == (*b & PIECE_COLOR) &&
                        (*(b + 3) & PIECE_COLOR) == (*b & PIECE_COLOR)
                    ) {
                        if (
                            (*b & PIECE_LETTER) == PIECE_LETTER_O &&
                            (*(b + 1) & PIECE_LETTER) == PIECE_LETTER_P &&
                            (*(b + 2) & PIECE_LETTER) == PIECE_LETTER_Q &&
                            (*(b + 3) & PIECE_LETTER) == PIECE_LETTER_A
                        ) {
                            if ((p->avatar & PLAYER_TEAM) == PLAYER_TEAM_OPQA) {
                                opqa_good = 1;
                            } else {
                                opqa_bad = 1;
                            }
                        }

                        if (
                            (*b & PIECE_LETTER) == PIECE_LETTER_Q &&
                            (*(b + 1) & PIECE_LETTER) == PIECE_LETTER_A &&
                            (*(b + 2) & PIECE_LETTER) == PIECE_LETTER_O &&
                            (*(b + 3) & PIECE_LETTER) == PIECE_LETTER_P
                        ) {
                            if ((p->avatar & PLAYER_TEAM) == PLAYER_TEAM_OPQA) {
                                opqa_bad = 1;
                            } else {
                                opqa_good = 1;
                            }
                        }
                        
                        if (opqa_good) {
                            score += OPQA_SCORE;
                            p->combo += 2;
                            if (
                                ((nb->pieces[0] && PIECE_TYPE) != PIECE_TYPE_SPECIAL) && 
                                ((nb->pieces[1] && PIECE_TYPE) != PIECE_TYPE_SPECIAL)
                            ) {
                                nb->pieces[0] = PIECE_JOKER;
                            }
                        } 
                        if (opqa_bad) {
                            p->score = 0;
                            po->combo += 2;
                        }
                    }                        
                }
            }
            if (y < 9) { // Check bottom
                if (*(b + 6) && *(b + 12) && *(b + 18)) {
                    opqa_good = 0;
                    opqa_bad = 0;

                    if (
                        (*(b + 6) & PIECE_COLOR) == (*b & PIECE_COLOR) &&
                        (*(b + 12) & PIECE_COLOR) == (*b & PIECE_COLOR) &&
                        (*(b + 18) & PIECE_COLOR) == (*b & PIECE_COLOR)
                    ) {
                        if (
                            (*b & PIECE_LETTER) == PIECE_LETTER_O &&
                            (*(b + 6) & PIECE_LETTER) == PIECE_LETTER_P &&
                            (*(b + 12) & PIECE_LETTER) == PIECE_LETTER_Q &&
                            (*(b + 18) & PIECE_LETTER) == PIECE_LETTER_A
                        ) {
                            if ((p->avatar & PLAYER_TEAM) == PLAYER_TEAM_OPQA) {
                                opqa_good = 1;
                            } else {
                                opqa_bad = 1;
                            }
                        }

                        if (
                            (*b & PIECE_LETTER) == PIECE_LETTER_Q &&
                            (*(b + 6) & PIECE_LETTER) == PIECE_LETTER_A &&
                            (*(b + 12) & PIECE_LETTER) == PIECE_LETTER_O &&
                            (*(b + 18) & PIECE_LETTER) == PIECE_LETTER_P
                        ) {
                            if ((p->avatar & PLAYER_TEAM) == PLAYER_TEAM_OPQA) {
                                opqa_bad = 1;
                            } else {
                                opqa_good = 1;
                            }
                        }

                        if (opqa_good) {
                            score += OPQA_SCORE;
                            p->combo += 2;

                            if (
                                ((nb->pieces[0] && PIECE_TYPE) != PIECE_TYPE_SPECIAL) && 
                                ((nb->pieces[1] && PIECE_TYPE) != PIECE_TYPE_SPECIAL)
                            ) {
                                nb->pieces[0] = PIECE_JOKER;
                            }
                        }
                        if (opqa_bad) {
                            p->score = 0;
                            score = 0;
                            po->combo += 2;
                        }
                    }
                }
            }
        }

        b++;
        f++;
        x++;
        if (x == BOARD_WIDTH) {
            y++;
            x = 0;
        }
    }

    if (found) {
        u->flash = FLASH_VALUE;        
    }
    u->score = 1;

    return score;
}

u8 opqa_isBoardCleared(u8 player) {
    u8* b = opqa_getBoard(player);
    u8 i = 0, c = 0;
    
    for (; i < BOARD_WIDTH * BOARD_HEIGHT; i++) {
        if (*b) {
            return 0;
        }
        b++;
    }

    return 1;
}

u8 opqa_isColorCleared(u8 player, u8 color) {
    u8* b = opqa_getBoard(player);
    u8 i = 0, c = 0;
    
    for (; i < BOARD_WIDTH * BOARD_HEIGHT; i++) {
        if (*b && *b != PIECE_GARBAGE && (*b & PIECE_COLOR) == color) {
            return 0;
        }
        b++;
    }

    return 1;
}

u8 opqa_flashBoard(u8 player) {
    TUpdate* u = opqa_getUpdate(player);
    TPlayer* p = opqa_getPlayer(player);
    TIA* ia = opqa_getIA(player);
    TState* s = opqa_getState();
    u8* b = opqa_getBoard(player);
    u8* f = opqa_getFlash(player);
    i8 i = 0, x = 0, y = 0;
    u8* bf;
    u8 completed = 0;

    // Flash pieces
    if ((u->flash & 0x7) == 0x7) {            
        for (; i < BOARD_WIDTH * BOARD_HEIGHT; i++) {            
            if (*f) {
                opqa_drawBoardPiece(PIECE_WHITE, player, x, y);
            }
            f++;
            x++;
            if (x == BOARD_WIDTH) {
                x = 0;
                y++;
            }
        }
    } else if ((u->flash & 0x7) == 0x3) {
        for (; i < BOARD_WIDTH * BOARD_HEIGHT; i++) {
            if (*f) {
                opqa_drawBoardPiece(*b, player, x, y);
            }
            f++;
            b++;
            x++;
            if (x == BOARD_WIDTH) {
                x = 0;
                y++;
            }
        }
    }

    u->flash--;  
    if (!u->flash) {
        // Remove flashing pieces
        b = opqa_getBoard(player);
        f = opqa_getFlash(player);
        for (i = 0; i < BOARD_WIDTH * BOARD_HEIGHT; i++) {
            if (*f) {
                *b = 0;
            }
            f++;
            b++;
        }
        f = opqa_getFlash(player);
        opqa_resetBoardArray(f);

        // Fall blocks
        for (x = 0; x < BOARD_WIDTH; x++) {
            bf = OPQA_GETBUFFER;
            for (i = 0; i < BOARD_HEIGHT; i++) {
                *(bf + i) = 0;
            }            
            i = 0;
            b = opqa_getBoard(player) + x + (BOARD_HEIGHT - 1) * 6;
            for (y = 0; y < BOARD_HEIGHT; y++) {
                if (*b) {
                    *bf = *b;
                    i++;
                    bf++;
                }
                b -= 6;
            }
            if (i) {
                bf = OPQA_GETBUFFER;
                b = opqa_getBoard(player) + x + (BOARD_HEIGHT - 1) * 6;                
                for (i = 0; i < BOARD_HEIGHT; i++) {
                    *b = *bf;
                    bf++;
                    b -= 6;
                }
            }
        }

        // Update score
        if (opqa_isBoardCleared(player)) {
            p->score += 200;
        }
        p->score += opqa_checkBoard(player);
        
        if (s->mode == MODE_MISSION) {
            if (!u->flash) { // If there aren't more chained combos...
                completed = opqa_checkMissionStatus();
            }
        }

        // Update speed
        if (p->combos >= COMBOS_PER_SPEED) {
            if (s->mode != MODE_MISSION) { 
                p->combos = 0; 
            }
            if (p->cycles_per_movement > MININUM_CYCLESPM) {
                p->cycles_per_movement--;
            }
        }      

        u->landed = 1;
        u->score = 1;
    } 

    return completed;
}

void opqa_flashGarbage(u8 player) {
    TUpdate* u = opqa_getUpdate(player);
    TPlayer* p = opqa_getPlayer(player);
    TPlayer* po = opqa_getPlayer(!player);
    u8* b = opqa_getBoard(player);
    u8* g = opqa_getGarbage(player);
    i8 i = 0, x = 0, y = 0;

    // Flash pieces
    if (u->garbage == FLASH_VALUE) {
        opqa_playFX(SFX_GARBAGE, player ? AY_CHANNEL_C : AY_CHANNEL_A);
        opqa_drawAvatar(!player, player ? AVATAR_ELLIOT_RIGHT : AVATAR_ELLIOT_LEFT);
    }
    if ((u->garbage & 0x7) == 0x7) {            
        for (; i < BOARD_WIDTH * BOARD_HEIGHT; i++) {            
            if (*g) {
                opqa_drawBoardPiece(PIECE_EMPTY, player, x, y);
            }
            g++;
            x++;
            if (x == BOARD_WIDTH) {
                x = 0;
                y++;
            }            
        }
        opqa_drawAvatar(player, AVATAR_RED);
    } else if ((u->garbage & 0x7) == 0x3) {
        for (; i < BOARD_WIDTH * BOARD_HEIGHT; i++) {
            if (*g) {
                opqa_drawBoardPiece(*b, player, x, y);
            }
            g++;
            b++;
            x++;
            if (x == BOARD_WIDTH) {
                x = 0;
                y++;
            }
        }
        opqa_drawAvatar(player, p->avatar);
    }

    u->garbage--;
    if (!u->garbage) {
        opqa_resetBoardArray(g);
        opqa_drawAvatar(player, p->avatar);
        opqa_drawAvatar(!player, po->avatar);
    }
}

// Private
void opqa_fillBoard(u8 player, u8* newboard) {
    u8* bd = opqa_getBoard(player);
    u8 i;

    for (i = 0; i < BOARD_WIDTH * BOARD_HEIGHT; i++) {
        *bd++ = *newboard++;
    }
}

u8 opqa_findPiecesSameColour(u8 player, u8 x, u8 y) {
    u8* b = opqa_getBoard(player);
    u8* f = opqa_getFlash(player);
    u8* t = opqa_getTmpFlash();
    u8 c = 1;

    b += x + (y * 6);
    f += x + (y * 6);
    t += x + (y * 6);
    
    *t = 1;

    // Check every direction for pieces not checked before

    // Left
    if (x > 0 && *(b - 1) && !*(f - 1) && !*(t - 1) && *(b - 1) != PIECE_GARBAGE && (*b & PIECE_COLOR) == (*(b - 1) & PIECE_COLOR)) {
        c += opqa_findPiecesSameColour(player, x - 1, y);
    }

    // Right
    if (x < (BOARD_WIDTH - 1) && *(b + 1) && !*(f + 1) && !*(t + 1) && *(b + 1) != PIECE_GARBAGE && (*b & PIECE_COLOR) == (*(b + 1) & PIECE_COLOR)) {
        c += opqa_findPiecesSameColour(player, x + 1, y);
    }

    // Top
    if (y > 0 && *(b - 6) && !*(f - 6) && !*(t - 6) && *(b - 6) != PIECE_GARBAGE && (*b & PIECE_COLOR) == (*(b - 6) & PIECE_COLOR)) {
        c += opqa_findPiecesSameColour(player, x, y - 1);
    }

    // Bottom
    if (y < (BOARD_HEIGHT - 1) && *(b + 6) && !*(f + 6) && !*(t + 6) && *(b + 6) != PIECE_GARBAGE && (*b & PIECE_COLOR) == (*(b + 6) & PIECE_COLOR)) {
        c += opqa_findPiecesSameColour(player, x, y + 1);
    }

    return c;
}

void opqa_copyTmpFlash(u8 player) {
    u8* f = opqa_getFlash(player);
    u8* t = opqa_getTmpFlash();
    u8 i;

    for (i = 0; i < BOARD_HEIGHT * BOARD_WIDTH; i++) {
        if (*t) {
            *f = *t;
        }
        f++;
        t++;
    }
}

u8 opqa_removePieces(u8 player, u8 color) {
    u8* b = opqa_getBoard(player);
    u8* f = opqa_getFlash(player);
    u8 i, c = 0;

    for (i = 0; i < BOARD_WIDTH * BOARD_HEIGHT; i++) {
        if (*b && (*b != PIECE_GARBAGE) && (*b & PIECE_COLOR) == color) {
            c++;
            *f = 1;
        }
        b++;
        f++;
    }

    return c;
}

u8 opqa_receiveGarbage(u8 player) {
    u8* bd = opqa_getBoard(player);
    u8* gb = opqa_getGarbage(player);
    TPlayer* po = opqa_getPlayer(player ? 0 : 1);
    TUpdate* u = opqa_getUpdate(player);
    u8 garbage = 0;
    u8 i, y, c = 0, prev_x;
    u8* bf = OPQA_GETBUFFER;
    u8* tmp;

    // Calculate garbage amount
    garbage = po->combo << 2;
    if (garbage > 30) {
        garbage = 30;
    }
    po->combo = 0;

    if (garbage) {
        // Empty buffer and get height from every row
        for (i = 0; i < BOARD_WIDTH; i++) {
            tmp = bd + i;
            *(bf + i) = BOARD_HEIGHT - 1;
            for (y = 0; y < BOARD_HEIGHT; y++) {
                if (*tmp) {
                    *(bf + i) = y - 1;
                    break;
                }
                tmp += 6;
            }
        }

        // Send garbage to board
        for (i = garbage; i > 0; i--) {
            c = 0;
            do {
                tmp = opqa_getGarbageX(player);
                prev_x = *tmp;
                y = *(bf + prev_x);
                (*tmp)++;
                if (*tmp >= BOARD_WIDTH) {
                    *tmp = 0;
                }
                c++;
            } while (c < 6 && (y == BOARD_HEIGHT || *(bd + prev_x + (y * 6))));

            // Check if board is full
            if (c == 6) {
                break;
            } else {
                *(bd + prev_x + (y * 6)) = PIECE_GARBAGE;
                *(gb + prev_x + (y * 6)) = 1;
                if (!y) {
                    *(bf + prev_x) = BOARD_HEIGHT;
                } else {
                    *(bf + prev_x) = y - 1;
                }
            }
        }

        u->landed = 1; 
    }   

    return garbage;
}

void opqa_removeGarbage(u8 player) {
    TPlayer* p = opqa_getPlayer(player);
    TUpdate* u = opqa_getUpdate(player);
    u8* bd = opqa_getBoard(player);
    u8* f = opqa_getFlash(player);
    u8 i = 0, x = 0, y = 0;

    for (i = 0; i < BOARD_WIDTH * BOARD_HEIGHT; i++) {
        if (*f && (*bd & PIECE_TYPE) == PIECE_TYPE_NORMAL) {    // Don't clear nearby garbage if the cleared piece is garbage too
            // Left
            if (x > 0 && *(bd - 1) == PIECE_GARBAGE) {
                *(f - 1) = 1;
                p->score += 10;
            }

            // Right
            if (x < BOARD_WIDTH - 1 && *(bd + 1) == PIECE_GARBAGE) {
                *(f + 1) = 1;
                p->score += 10;
            }

            // Top
            if (y > 0 && *(bd - 6) == PIECE_GARBAGE) {
                *(f - 6) = 1;
                p->score += 10;
            }

            // Bottom
            if (y < BOARD_HEIGHT - 1 && *(bd + 6) == PIECE_GARBAGE) {
                *(f + 6) = 1;
                p->score += 10;
            }
        }
        bd++;
        f++;
        x++;
        if (x == BOARD_WIDTH) {
            x = 0;
            y++;
        }
    }

    u->score = 1;
}
#include <cpctelera.h>
#include "video.h"
#include "game.h"
#include "utils.h"
#include "blocks.h"
#include "board.h"

#include "gfx/bg.h"
#include "gfx/letters.h"
#include "gfx/numbers.h"
#include "gfx/pieces.h"
#include "gfx/avatars.h"

const u8 palette[4][16] = {
    {
        HW_BLACK,	
        HW_WHITE, 
        HW_BRIGHT_WHITE,
        HW_RED,

        HW_BRIGHT_RED,
        HW_PINK,
        HW_BRIGHT_YELLOW,
        HW_YELLOW,

        HW_ORANGE,
        HW_BRIGHT_BLUE,
        HW_BLUE,
        HW_SKY_BLUE,

        HW_GREEN,
        HW_MAGENTA,
        HW_MAUVE,
        HW_PASTEL_YELLOW
    },

    {
        HW_BLACK,
        HW_BLACK,
        HW_WHITE,
        HW_BRIGHT_BLUE,

        HW_BRIGHT_BLUE,
        HW_BRIGHT_BLUE,
        HW_BRIGHT_BLUE,
        HW_BRIGHT_BLUE,

        HW_BRIGHT_BLUE,
        HW_BRIGHT_BLUE,
        HW_BLUE,
        HW_BLUE,

        HW_BRIGHT_BLUE,
        HW_BRIGHT_BLUE,
        HW_BRIGHT_BLUE,
        HW_BRIGHT_BLUE
    },

    {
        HW_BLACK,
        HW_BLACK,
        HW_BLACK,
        HW_BLUE,

        HW_BLUE,
        HW_BLUE,
        HW_BLUE,
        HW_BLUE,

        HW_BLUE,
        HW_BLUE,
        HW_BLACK,
        HW_BLACK,

        HW_BLUE,
        HW_BLUE,
        HW_BLUE,
        HW_BLUE
    },

    {
        HW_BLACK,
        HW_BLACK,
        HW_BLACK,
        HW_BLACK,

        HW_BLACK,
        HW_BLACK,
        HW_BLACK,
        HW_BLACK,

        HW_BLACK,
        HW_BLACK,
        HW_BLACK,
        HW_BLACK,

        HW_BLACK,
        HW_BLACK,
        HW_BLACK,
        HW_BLACK
    }
};  

const u8 avatar_positions[16][2] = {
    {4, 8},
    {4, 48},
    {4, 88},
    {4, 128},

    {16, 8},
    {16, 48},
    {16, 88},
    {16, 128},

    {56, 8},
    {56, 48},
    {56, 88},
    {56, 128},

    {68, 8},
    {68, 48},
    {68, 88},
    {68, 128}
};

// General
void opqa_fade(u8 inout) {
	u16 i;
    // inout: 1 -> FADE_IN, 0 -> FADE_OUT
    u8 p = (inout ? 3 : 0);
    u8 to = (inout ? 0 : 3);

    do {
        for (i = 0; i < FADE_LENGTH; i++) {
            cpct_waitVSYNC();
            __asm__ ("halt");
            __asm__ ("halt");
        }

        if (inout) {
            p--;
        } else {
            p++;
        }

        cpct_setPalette(palette[p], 16);       
    } while (p != to);
}

void opqa_drawText(u8 x, u8 y, u8 *str) {
    u8 i = 0;
	u8* strp;
	u8* pvmem;

	for (strp = str; *strp != '\0'; strp++) {
		pvmem = cpctm_screenPtr(CPCT_VMEM_START, x + i, y);
		cpct_drawSprite(lt_tileset[*strp - 32], pvmem, 2, 16);
		i += 2;

		if (*strp == '\n') {
			i = 0;
			y += LETTER_HEIGHT + LINE_SEPARATION;
		}
	}
}

void opqa_drawCenteredText(u8 x, u8 y, u8 *str, u8 width) {
	u8* strp;
    u8 c = 0;
    
    for (strp = str; *strp != '\0'; strp++) {		
		c++;
    }

    opqa_drawText(x + ((width - (c << 1)) >> 1), y, str);
}

void opqa_drawVerticalText(u8 x, u8 y, u8 *str) {
	u8* strp;
	u8* pvmem;

    pvmem = cpctm_screenPtr(CPCT_VMEM_START, x, y);
	for (strp = str; *strp != '\0'; strp++) {		
		cpct_drawSprite(lt_tileset[*strp - 32], pvmem, 2, 16);
		pvmem += 0xA0;
	}
}

void opqa_drawNumber(u8 x, u8 y, u8 color, u32 number, u8 width) {
    u8 i = width;
    u8 n;
    u8* pvmem;

    for (; i > 0; i--) {
        n = number % 10;
        pvmem = cpctm_screenPtr(CPCT_VMEM_START, x + (i << 1), y);
        cpct_drawSprite(nb_tileset[n + color], pvmem, 2, 16);
        number /= 10;
    }
}

// Screens
void opqa_drawTitle(u8 scroll) {
    TState* s = opqa_getState();

    cpct_clearScreen_f64(0);

    opqa_drawPiece(PIECE_BL_O, 17, 0);
    opqa_drawPiece(PIECE_BL_P, 21, 0);
    opqa_drawPiece(PIECE_BL_Q, 25, 0);
    opqa_drawPiece(PIECE_BL_A, 29, 0);

    opqa_drawText(37, 0, "vs.");

    opqa_drawPiece(PIECE_RD_Q, 47, 0);
    opqa_drawPiece(PIECE_RD_A, 51, 0);
    opqa_drawPiece(PIECE_RD_O, 55, 0);
    opqa_drawPiece(PIECE_RD_P, 59, 0);

    opqa_drawText(24, 16, "the final battle");

    opqa_drawText(25, 48, "1 story mode");
    opqa_drawText(25, 64, "2 versus mode");
    opqa_drawText(25, 80, "3 mission mode");
    opqa_drawText(25, 96, "4 endless mode");
    opqa_drawText(25, 112, "5 redefine keys");

    opqa_drawText(22, 168, "HIGH SCORE");
    opqa_drawNumber(44, 168, NUMBER_YELLOW, s->hiscore, 6);

    opqa_drawText(22, 184, "@manuelsagra  2018");

    opqa_showScrolledAvatars(scroll);
}

void opqa_drawLevel() {
	u16 i;
	u8* pvmem;
    TPlayer* p1 = opqa_getPlayer(0);
    TPlayer* p2 = opqa_getPlayer(1);
    TState *s = opqa_getState();
    u8* tiles = (u8*) LEVEL_TILES;

    cpct_clearScreen_f64(0);

	pvmem = (u8 *) 0xC000;
	for (i = 0; i < 40 * 25; i++) {
		cpct_drawTileAligned2x8_f(bg_tileset[*tiles++], pvmem);
		pvmem += 2;
    }
    
    opqa_drawText(36, 8, "NEXT");
    opqa_drawText(35, 136, "SCORE");

    switch (s->mode) {
        case MODE_STORY:
            opqa_drawText(32, 72, "STAGE");
            opqa_drawNumber(42, 72, NUMBER_RED, s->level + 1, 2);
            break;

        case MODE_VERSUS:
            opqa_drawText(34, 72, "FIGHT!");
            break;

        case MODE_ENDLESS:
            opqa_drawText(33, 72, "ENDLESS");
            break;

        case MODE_MISSION:
            opqa_drawText(33, 72, "MISSION");
            break;
    }

    opqa_drawScore(0);
    if (s->mode != MODE_ENDLESS) {
        opqa_drawScore(1);
    }

    if (s->mode == MODE_MISSION) {
        pvmem = cpctm_screenPtr(CPCT_VMEM_START, 52, 0);
        cpct_drawSolidBox(pvmem, 0, 24, 192);

        for (i = 0; i < 24; i++) {
            pvmem = cpctm_screenPtr(CPCT_VMEM_START, 50, i << 3);
            cpct_drawTileAligned2x8_f(bg_tileset[1], pvmem);
            pvmem = cpctm_screenPtr(CPCT_VMEM_START, 76, i << 3);
            cpct_drawTileAligned2x8_f(bg_tileset[1], pvmem);
        }

        for (i = 0; i < 24; i++) {
            pvmem = cpctm_screenPtr(CPCT_VMEM_START, 52 + i++, 192);
            cpct_drawTileAligned2x8_f(bg_tileset[1], pvmem);
        }
    }

    opqa_drawAvatar(0, p1->avatar);

    if (s->mode == MODE_STORY || s->mode == MODE_VERSUS || s->mode == MODE_DEMO) {   
        opqa_drawAvatar(1, p2->avatar);
    }
}

void opqa_drawSelectionScreen() {
    u8* pvmem;
    u16 i;
    TState* s = opqa_getState();

    pvmem = (u8 *) 0xC000;
	for (i = 0; i < 40 * 25; i++) {
		cpct_drawTileAligned2x8_f(bg_tileset[1], pvmem);
		pvmem += 2;
    }

    for (i = 0; i < CHARACTERS; i++) {
        pvmem = cpctm_screenPtr(CPCT_VMEM_START, avatar_positions[i][0], avatar_positions[i][1]);
        cpct_drawSprite(av_tileset[i], pvmem, 8, 32);
    }

    pvmem = cpctm_screenPtr(CPCT_VMEM_START, 28, 8);
    cpct_drawSolidBox(pvmem, 0, 6, 152);
    opqa_drawVerticalText(30, 14, "TEAM");
    pvmem = cpctm_screenPtr(CPCT_VMEM_START, 29, 84);
    cpct_drawSprite(pc_tileset[4], pvmem, 4, 16);
    pvmem = cpctm_screenPtr(CPCT_VMEM_START, 29, 102);
    cpct_drawSprite(pc_tileset[5], pvmem, 4, 16);
    pvmem = cpctm_screenPtr(CPCT_VMEM_START, 29, 120);
    cpct_drawSprite(pc_tileset[6], pvmem, 4, 16);
    pvmem = cpctm_screenPtr(CPCT_VMEM_START, 29, 138);
    cpct_drawSprite(pc_tileset[7], pvmem, 4, 16);

    pvmem = cpctm_screenPtr(CPCT_VMEM_START, 46, 8);
    cpct_drawSolidBox(pvmem, 0, 6, 152);
    opqa_drawVerticalText(48, 14, "TEAM");
    pvmem = cpctm_screenPtr(CPCT_VMEM_START, 47, 84);
    cpct_drawSprite(pc_tileset[10], pvmem, 4, 16);
    pvmem = cpctm_screenPtr(CPCT_VMEM_START, 47, 102);
    cpct_drawSprite(pc_tileset[11], pvmem, 4, 16);
    pvmem = cpctm_screenPtr(CPCT_VMEM_START, 47, 120);
    cpct_drawSprite(pc_tileset[8], pvmem, 4, 16);
    pvmem = cpctm_screenPtr(CPCT_VMEM_START, 47, 138);
    cpct_drawSprite(pc_tileset[9], pvmem, 4, 16);

    if (s->mode == MODE_VERSUS) {
        pvmem = cpctm_screenPtr(CPCT_VMEM_START, 4, 168);
        cpct_drawSolidBox(pvmem, 0, 30, 24);
        pvmem = cpctm_screenPtr(CPCT_VMEM_START, 46, 168);
        cpct_drawSolidBox(pvmem, 0, 30, 24);

        opqa_selectAvatar(0);
        opqa_selectAvatar(1);
    } else {
        pvmem = cpctm_screenPtr(CPCT_VMEM_START, 4, 168);
        cpct_drawSolidBox(pvmem, 0, 36, 24);
        pvmem = cpctm_screenPtr(CPCT_VMEM_START, 40, 168);
        cpct_drawSolidBox(pvmem, 0, 36, 24);
        
        opqa_selectAvatar(0);
    }   
}

void opqa_drawStageScreen() {
    TState* s = opqa_getState();
    TPlayer* p1 = opqa_getPlayer(0);
    TPlayer* p2 = opqa_getPlayer(1);
    char** names = opqa_getNames();  
    u32 c = 0;
    u8* pvmem;

    cpct_waitVSYNC();

    cpct_clearScreen_f64(0);

    opqa_drawText(32, 48, "STAGE");
    opqa_drawNumber(42, 48, NUMBER_RED, s->level + 1, 2);

    opqa_drawText(37, 80, "vs.");
    pvmem = cpctm_screenPtr(CPCT_VMEM_START, 16, 64);
    cpct_drawSprite(av_tileset[p1->avatar], pvmem, 8, 32);
    pvmem = cpctm_screenPtr(CPCT_VMEM_START, 56, 64);
    cpct_drawSprite(av_tileset[p2->avatar], pvmem, 8, 32);

    opqa_drawCenteredText(0, 110, names[p1->avatar], 40);
    opqa_drawCenteredText(40, 110, names[p2->avatar], 40);

    opqa_fade(FADE_IN);
}

void opqa_drawGameOver() {
    u8* pvmem; 
    TState* s = opqa_getState();
    TPlayer* p1 = opqa_getPlayer(0);

    cpct_waitVSYNC();

    pvmem = cpctm_screenPtr(CPCT_VMEM_START, 24, s->mode == MODE_VERSUS ? 64 : 72);
    cpct_drawSolidBox(pvmem, 0, 32, s->mode == MODE_VERSUS ? 72 : 56);

    opqa_drawText(31, s->mode == MODE_VERSUS ? 80 : 92, "GAME OVER");

    if (s->mode == MODE_VERSUS) {
        opqa_drawText(27, 104, "PLAYER   WINS");
        if (p1->gameover) {
            opqa_drawNumber(39, 104, NUMBER_RED, 2, 1);
        } else {
            opqa_drawNumber(39, 104, NUMBER_RED, 1, 1);
        }
    }
}

void opqa_drawSuccess() {
    TPlayer* p = opqa_getPlayer(0);
    char** names = opqa_getNames();
    u8* pvmem;
    
    cpct_waitVSYNC();

    cpct_clearScreen_f64(0);

    opqa_drawCenteredText(0, 0, "CONGRATULATIONS!", 80);

    pvmem = cpctm_screenPtr(CPCT_VMEM_START, 36, 24);
    cpct_drawSprite(av_tileset[p->avatar], pvmem, 8, 32);

    opqa_drawCenteredText(0, 64, names[p->avatar], 80);

    if ((p->avatar & PLAYER_TEAM) == PLAYER_TEAM_OPQA) {
        opqa_drawPiece(PIECE_BL_O, 32, 112);
        opqa_drawPiece(PIECE_BL_P, 36, 112);
        opqa_drawPiece(PIECE_BL_Q, 40, 112);
        opqa_drawPiece(PIECE_BL_A, 44, 112);

        opqa_drawCenteredText(0, 184, "Peace spreads around the world...", 80);
    } else {
        opqa_drawPiece(PIECE_RD_Q, 32, 112);
        opqa_drawPiece(PIECE_RD_A, 36, 112);
        opqa_drawPiece(PIECE_RD_O, 40, 112);
        opqa_drawPiece(PIECE_RD_P, 44, 112);

        opqa_drawCenteredText(0, 184, "The gates of hell just opened...", 80);
    }

    opqa_drawCenteredText(0, 136, "is now the default configuration", 80);
    opqa_drawCenteredText(0, 160, "for all 8-bit computer games.", 80);

    opqa_fade(FADE_IN);
}

// Avatars
void opqa_drawAvatar(u8 player, u8 avatar) {
    u8* pvmem;
    pvmem = cpctm_screenPtr(CPCT_VMEM_START, player ? 40 : 32, 96);
    if (avatar <= AVATAR_ELLIOT_LEFT) {
        cpct_drawSprite(av_tileset[avatar], pvmem, 8, 32);
    } else {
        cpct_drawSolidBox(pvmem, 0x30, 8, 32);
    }
}

void opqa_selectAvatar(u8 player) {
    u8 i, j;
    u8* pvmem;    
    TPlayer* p = opqa_getPlayer(player);
    u8 avatar = p->avatar;
    char** names = opqa_getNames();    
    TState* s = opqa_getState();
        
    if (s->mode == MODE_VERSUS) {
        opqa_drawCenteredText(player ? 46 : 4, 172, names[avatar], 30);
    } else {
        opqa_drawCenteredText(4, 172, names[avatar], 72);
    }

    j = avatar_positions[avatar][1] - 8;
    for (i = avatar_positions[avatar][0]; i < avatar_positions[avatar][0] + 8; i += 2) {
        pvmem = cpctm_screenPtr(CPCT_VMEM_START, i, j);
        cpct_drawTileAligned2x8_f(bg_tileset[player ? 12 : 11], pvmem);
        pvmem += 0x190;
        cpct_drawTileAligned2x8_f(bg_tileset[player ? 6 : 3], pvmem);
    }
    i = avatar_positions[avatar][0] - 2;
    for (j = avatar_positions[avatar][1]; j < avatar_positions[avatar][1] + 32; j += 8) {
        pvmem = cpctm_screenPtr(CPCT_VMEM_START, i, j);
        cpct_drawTileAligned2x8_f(bg_tileset[player ? 5 : 2], pvmem);
        pvmem += 10;
        cpct_drawTileAligned2x8_f(bg_tileset[player ? 7 : 4], pvmem);
    }
}

void opqa_unselectAvatar(u8 player) {
    u8 i, j;
    u8* pvmem;   
    TPlayer* p = opqa_getPlayer(player); 
    u8 avatar = p->avatar;    
    TState* s = opqa_getState();

    if (s->mode != MODE_VERSUS) {
        pvmem = cpctm_screenPtr(CPCT_VMEM_START, 4, 168);
        cpct_drawSolidBox(pvmem, 0, 36, 24);
        pvmem = cpctm_screenPtr(CPCT_VMEM_START, 40, 168);
        cpct_drawSolidBox(pvmem, 0, 36, 24);
    } else {
        pvmem = cpctm_screenPtr(CPCT_VMEM_START, player ? 46 : 4, 168);
        cpct_drawSolidBox(pvmem, 0, 30, 24);
    }

    j = avatar_positions[avatar][1] - 8;
    for (i = avatar_positions[avatar][0]; i < avatar_positions[avatar][0] + 8; i += 2) {
        pvmem = cpctm_screenPtr(CPCT_VMEM_START, i, j);
        cpct_drawTileAligned2x8_f(bg_tileset[1], pvmem);
        pvmem += 0x190;
        cpct_drawTileAligned2x8_f(bg_tileset[1], pvmem);
    }
    i = avatar_positions[avatar][0] - 2;
    for (j = avatar_positions[avatar][1]; j < avatar_positions[avatar][1] + 32; j += 8) {
        pvmem = cpctm_screenPtr(CPCT_VMEM_START, i, j);
        cpct_drawTileAligned2x8_f(bg_tileset[1], pvmem);
        pvmem += 10;
        cpct_drawTileAligned2x8_f(bg_tileset[1], pvmem);
    }
}

void opqa_showScrolledAvatars(u8 scroll) {
    u8 i, y, h;
    u8* pvmem;

    for (i = 0; i < 8; i++) {
        y = scroll + (i << 5);
        if (y < 200) {               
            h = 32;
            if (y > 168) {
                h = 200 - y;
            }

            // Left
            pvmem = cpctm_screenPtr(CPCT_VMEM_START, 0, y);
            cpct_drawSprite(av_tileset[i], pvmem, 8, h);

            // Right
            pvmem = cpctm_screenPtr(CPCT_VMEM_START, 72, y);
            cpct_drawSprite(av_tileset[i + 8], pvmem, 8, h);
        }
        if (y && y < 32) {
            h = (32 - y) << 3;
            // Left
            pvmem = cpctm_screenPtr(CPCT_VMEM_START, 0, 0);
            cpct_drawSprite(av_tileset[i ? i - 1 : 7] + h, pvmem, 8, y);

            // Right
            pvmem = cpctm_screenPtr(CPCT_VMEM_START, 72, 0);
            cpct_drawSprite(av_tileset[i ? i + 7 : 15] + h, pvmem, 8, y);
        }
    }
}

// Blocks / Pieces
void opqa_drawBoardPiece(u8 piece, u8 player, u8 board_x, u8 board_y) {
    if (board_x < BOARD_WIDTH && board_y < BOARD_HEIGHT) {
        opqa_drawPiece(piece, (player ? 52 : 4) + (board_x << 2), board_y << 4);
    }
}

void opqa_drawPiece(u8 piece, u8 x, u8 y) {
    u8* pvmem;
    u8 t = 0;

    // Convert piece to piece tile number (0: Empty, 1: Trash, 2: White, 3: Joker, 4-7: Blue, 8-11: Red, 12-15: Green, 16-19: Orange)
    if ((piece & PIECE_TYPE) == PIECE_TYPE_SPECIAL) {
        t = (piece & PIECE_SUBTYPE) >> 4;
    } else {
        t = (piece & 0xF) + 4;
    }

    pvmem = cpctm_screenPtr(CPCT_VMEM_START, x, y);
    cpct_drawTileAligned4x8_f(pc_tileset[t], pvmem);
    cpct_drawTileAligned4x8_f(pc_tileset[t] + 32, pvmem + 0x50);
}

void opqa_drawNextBlock(u8 player) {
    TBlock* n = opqa_getNextBlock(player);

    opqa_drawPiece(n->pieces[1], (!player ? 32 : 44), 32);
    opqa_drawPiece(n->pieces[0], (!player ? 32 : 44), 48);
}

void opqa_drawCurrentBlock(u8 player) {
    TBlock* b = opqa_getCurrentBlock(player);

    if (b->pieces[0]) {
        switch(b->rotation) {
            case ROTATION_VERTICAL_01:
                opqa_drawBoardPiece(b->pieces[1], player, b->x, b->y + 1);
                opqa_drawBoardPiece(b->pieces[0], player, b->x, b->y);
                break;

            case ROTATION_VERTICAL_10:
                opqa_drawBoardPiece(b->pieces[0], player, b->x, b->y);
                if (b->y > 0) {
                    opqa_drawBoardPiece(b->pieces[1], player, b->x, b->y - 1);
                }
                break;

            case ROTATION_HORIZONTAL_01:
                opqa_drawBoardPiece(b->pieces[0], player, b->x, b->y);
                opqa_drawBoardPiece(b->pieces[1], player, b->x + 1, b->y);
                break;

            case ROTATION_HORIZONTAL_10:
                opqa_drawBoardPiece(b->pieces[0], player, b->x, b->y);
                opqa_drawBoardPiece(b->pieces[1], player, b->x - 1, b->y);
                break;
        }
    }
}

void opqa_erasePrevBlock(u8 player) {
    TBlock* b = opqa_getPrevBlock(player);

    if (b->pieces[0]) {
        switch(b->rotation) {
            case ROTATION_VERTICAL_01:
                opqa_drawBoardPiece(0, player, b->x, b->y);
                opqa_drawBoardPiece(0, player, b->x, b->y + 1);
                break;

            case ROTATION_VERTICAL_10:
                opqa_drawBoardPiece(0, player, b->x, b->y);
                if (b->y > 0) {
                    opqa_drawBoardPiece(0, player, b->x, b->y - 1);
                }
                break;

            case ROTATION_HORIZONTAL_01:
                opqa_drawBoardPiece(0, player, b->x, b->y);
                opqa_drawBoardPiece(0, player, b->x + 1, b->y);
                break;

            case ROTATION_HORIZONTAL_10:
                opqa_drawBoardPiece(0, player, b->x, b->y);
                opqa_drawBoardPiece(0, player, b->x - 1, b->y);
                break;
        }
    }
}

void opqa_updateBoard(u8 player) {
    u8* bd = opqa_getBoard(player);
    u8 i, x = 0, y = 0;

    for (i = 0; i < BOARD_WIDTH * BOARD_HEIGHT; i++) {
        opqa_drawBoardPiece(*(bd + i), player, x, y);
        x++;
        if (x == BOARD_WIDTH) {
            x = 0;
            y++;
        }
    }
}

void opqa_drawScore(u8 player) {
    TPlayer* p = opqa_getPlayer(player);

    opqa_drawNumber(player ? 33 : 31, player ? 176 : 160, player ? NUMBER_YELLOW : NUMBER_RED, p->score, 6);
}
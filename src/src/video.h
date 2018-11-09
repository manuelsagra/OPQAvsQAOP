#ifndef _VIDEO_H_
#define _VIDEO_H_

// Constants
#define FADE_LENGTH         10
#define FADE_IN             1
#define FADE_OUT            0

#define LETTER_HEIGHT       16
#define LINE_SEPARATION     4

#define NUMBER_RED          0
#define NUMBER_YELLOW       10

#define AVATAR_ELLIOT_RIGHT 16
#define AVATAR_ELLIOT_LEFT  17
#define AVATAR_RED          18

#define LEVEL_TILES_END     0xBBFF
#define LEVEL_TILES_LENGTH  1000
#define LEVEL_TILES         LEVEL_TILES_END - (LEVEL_TILES_LENGTH - 1)

// General
void        opqa_fade(u8 inout);
void        opqa_drawText(u8 x, u8 y, u8 *str);
void        opqa_drawCenteredText(u8 x, u8 y, u8 *str, u8 width);
void        opqa_drawVerticalText(u8 x, u8 y, u8 *str);
void        opqa_drawNumber(u8 x, u8 y, u8 color, u32 number, u8 width);

// Screens
void        opqa_drawTitle(u8 scroll);
void        opqa_drawSelectionScreen();
void        opqa_drawStageScreen();
void        opqa_drawLevel();
void        opqa_drawGameOver();
void        opqa_drawSuccess();

// Avatars
void        opqa_drawAvatar(u8 player, u8 avatar);
void        opqa_selectAvatar(u8 player);
void        opqa_unselectAvatar(u8 player);
void        opqa_showScrolledAvatars(u8 scroll);

// Blocks / Pieces / Score
void        opqa_drawBoardPiece(u8 piece, u8 player, u8 board_x, u8 board_y);
void        opqa_drawPiece(u8 piece, u8 x, u8 y);
void        opqa_drawNextBlock(u8 player);
void        opqa_drawCurrentBlock(u8 player);
void        opqa_erasePrevBlock(u8 player);
void        opqa_updateBoard(u8 player);
void        opqa_drawScore(u8 player);

#endif
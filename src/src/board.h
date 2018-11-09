#ifndef _BOARD_H_
#define _BOARD_H_

// Board constants
#define BOARD_WIDTH             6
#define BOARD_HEIGHT            12

#define FLASH_VALUE             63

// Memory constants
#define BOARD_OBJ_SIZE          BOARD_WIDTH * BOARD_HEIGHT

#define BOARD_POINTER           0xB000
#define FLASH_POINTER           BOARD_POINTER + (2 * BOARD_OBJ_SIZE)
#define GARBAGE_POINTER         FLASH_POINTER + (2 * BOARD_OBJ_SIZE)
#define TMPFLASH_POINTER        GARBAGE_POINTER + (2 * BOARD_OBJ_SIZE)
#define GARBAGEX_POINTER        TMPFLASH_POINTER + BOARD_OBJ_SIZE

// Getters
u8*         opqa_getBoard(u8 player);
u8*         opqa_getFlash(u8 player);
u8*         opqa_getGarbage(u8 player);
u8*         opqa_getGarbageX(u8 player);

// Resets
void        opqa_resetBoardArray(u8* array);
void        opqa_resetGarbageX();

// Functions
u8          opqa_flashBoard(u8 player);
void        opqa_flashGarbage(u8 player);
u32         opqa_checkBoard(u8 player);
u8          opqa_isBoardCleared(u8 player);
u8          opqa_isColorCleared(u8 player, u8 color);
void        opqa_fillBoard(u8 player, u8* newboard);
u8          opqa_removePieces(u8 player, u8 color);
u8          opqa_receiveGarbage(u8 player);
void        opqa_removeGarbage(u8 player);

#endif
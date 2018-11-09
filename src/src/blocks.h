#ifndef _BLOCKS_H_
#define _BLOCKS_H_

// Piece constants
#define PIECE_TYPE              0x80
#define PIECE_TYPE_NORMAL       0x80
#define PIECE_TYPE_SPECIAL      0x00          

#define PIECE_SUBTYPE           0x30
#define PIECE_SUBTYPE_EMPTY     0x00
#define PIECE_SUBTYPE_TRASH     0x10
#define PIECE_SUBTYPE_WHITE     0x20
#define PIECE_SUBTYPE_JOKER     0x30     

#define PIECE_COLOR             0x0C
#define PIECE_COLOR_BLUE        0x00             
#define PIECE_COLOR_RED         0x04      
#define PIECE_COLOR_GREEN       0x08    
#define PIECE_COLOR_MAGENTA     0x0C

#define PIECE_LETTER            0x03
#define PIECE_LETTER_O          0x00
#define PIECE_LETTER_P          0x01
#define PIECE_LETTER_Q          0x02
#define PIECE_LETTER_A          0x03

#define PIECE_EMPTY             0x00
#define PIECE_GARBAGE           0x10
#define PIECE_GARB              0x10
#define PIECE_WHITE             0x20
#define PIECE_JOKER             0x30
#define PIECE_JOKER2            0x38

#define PIECE_BL_O              0x80
#define PIECE_BL_P              0x81
#define PIECE_BL_Q              0x82
#define PIECE_BL_A              0x83

#define PIECE_RD_O              0x84
#define PIECE_RD_P              0x85
#define PIECE_RD_Q              0x86
#define PIECE_RD_A              0x87

#define PIECE_GR_O              0x88
#define PIECE_GR_P              0x89
#define PIECE_GR_Q              0x8A
#define PIECE_GR_A              0x8B

#define PIECE_MG_O              0x8C
#define PIECE_MG_P              0x8D
#define PIECE_MG_Q              0x8E
#define PIECE_MG_A              0x8F

// Block constants
#define ROTATION_VERTICAL_10    0x00
/*
    ---
    |1|
    |0|
    ---
*/
#define ROTATION_HORIZONTAL_01  0x01
/*
    -----
    |0|1|
    -----
*/
#define ROTATION_VERTICAL_01    0x02
/*
    ---
    |0|
    |1|
    ---
*/
#define ROTATION_HORIZONTAL_10  0x03
/*
    -----
    |1|0|
    -----
*/

// Memory constants
#define BLOCK_OBJ_SIZE          5

// Types
typedef struct {
    u8 pieces[2];
    u8 rotation;
    u8 x;
    u8 y;
} TBlock;

// Getters
TBlock*     opqa_getCurrentBlock(u8 player);
TBlock*     opqa_getNextBlock(u8 player);
TBlock*     opqa_getPrevBlock(u8 player);

// Functions
u8          opqa_newRandomPiece();
void        opqa_newRandomBlock(TBlock* b);
void        opqa_copyBlock(TBlock* from, TBlock* to);
void        opqa_checkBlockRotation(u8 player);
u8          opqa_blockHasLanded(u8 player);
u8          opqa_blockCanMove(u8 player, u8 move);
u8          opqa_landBlock(u8 player);

#endif
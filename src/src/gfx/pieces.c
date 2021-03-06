#include "pieces.h"
// Data created with Img2CPC - (c) Retroworks - 2007-2017
u8* const pc_tileset[20] = { 
	pc_pieces_00, pc_pieces_01, pc_pieces_02, pc_pieces_03, pc_pieces_04, pc_pieces_05, pc_pieces_06, pc_pieces_07, pc_pieces_08, pc_pieces_09, pc_pieces_10, pc_pieces_11, pc_pieces_12, pc_pieces_13, pc_pieces_14, pc_pieces_15, pc_pieces_16, pc_pieces_17, pc_pieces_18, pc_pieces_19
};
// Tile pc_pieces_00: 8x16 pixels, 4x16 bytes.
const u8 pc_pieces_00[4 * 16] = {
	0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x40,
	0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x40,
	0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x40,
	0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x40,
	0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x40,
	0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x40,
	0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x40,
	0x00, 0x00, 0x00, 0x00,
	0x40, 0x40, 0x40, 0x40
};

// Tile pc_pieces_01: 8x16 pixels, 4x16 bytes.
const u8 pc_pieces_01[4 * 16] = {
	0x55, 0x0c, 0x0c, 0x08,
	0xae, 0x0c, 0x0c, 0x0c,
	0x08, 0x00, 0x00, 0x04,
	0x08, 0x00, 0x00, 0x04,
	0x08, 0x00, 0x04, 0x04,
	0x08, 0x00, 0x04, 0x04,
	0x08, 0x00, 0x40, 0x04,
	0x08, 0x00, 0x40, 0x04,
	0x08, 0x00, 0x00, 0x04,
	0x08, 0x00, 0x00, 0x04,
	0x08, 0x00, 0x00, 0x04,
	0x08, 0x00, 0x00, 0x04,
	0x08, 0x00, 0x00, 0x04,
	0x0c, 0x0c, 0x0c, 0x0c,
	0x84, 0x0c, 0x0c, 0x48,
	0x40, 0xc0, 0xc0, 0x80
};

// Tile pc_pieces_02: 8x16 pixels, 4x16 bytes.
const u8 pc_pieces_02[4 * 16] = {
	0x55, 0x0c, 0x0c, 0x08,
	0xae, 0x0c, 0x0c, 0x0c,
	0x0c, 0x0c, 0x0c, 0x0c,
	0x0c, 0x0c, 0x0c, 0x0c,
	0x0c, 0x0c, 0x0c, 0x0c,
	0x0c, 0x0c, 0x0c, 0x0c,
	0x0c, 0x0c, 0x0c, 0x0c,
	0x0c, 0x0c, 0x0c, 0x0c,
	0x0c, 0x0c, 0x0c, 0x0c,
	0x0c, 0x0c, 0x0c, 0x0c,
	0x0c, 0x0c, 0x0c, 0x0c,
	0x0c, 0x0c, 0x0c, 0x0c,
	0x0c, 0x0c, 0x0c, 0x0c,
	0x0c, 0x0c, 0x0c, 0x0c,
	0x84, 0x0c, 0x0c, 0x48,
	0x40, 0xc0, 0xc0, 0x80
};

// Tile pc_pieces_03: 8x16 pixels, 4x16 bytes.
const u8 pc_pieces_03[4 * 16] = {
	0x55, 0x0c, 0x0c, 0x08,
	0xae, 0x0c, 0x0c, 0x0c,
	0x09, 0x03, 0x03, 0x06,
	0x09, 0x03, 0x03, 0x06,
	0x09, 0x16, 0x29, 0x06,
	0x09, 0x3c, 0x5d, 0x06,
	0x09, 0x3c, 0x7d, 0x06,
	0x09, 0x3c, 0x7d, 0x06,
	0x09, 0x3c, 0x7d, 0x06,
	0x09, 0xfd, 0xfe, 0x06,
	0x09, 0xfc, 0xfc, 0x06,
	0x09, 0x56, 0xa9, 0x06,
	0x09, 0x03, 0x03, 0x06,
	0x0c, 0x0c, 0x0c, 0x0c,
	0x84, 0x0c, 0x0c, 0x48,
	0x40, 0xc0, 0xc0, 0x80
};

// Tile pc_pieces_04: 8x16 pixels, 4x16 bytes.
const u8 pc_pieces_04[4 * 16] = {
	0x45, 0xc3, 0xc3, 0x82,
	0xcb, 0xc3, 0xc3, 0xc3,
	0xc3, 0x0c, 0x0c, 0xc3,
	0xc3, 0x0c, 0x0c, 0xc3,
	0x86, 0xc0, 0xc0, 0x49,
	0x86, 0xc0, 0xc0, 0x49,
	0x86, 0xc3, 0xc3, 0x49,
	0x86, 0xc3, 0xc3, 0x49,
	0x86, 0xc3, 0xc3, 0x49,
	0xc2, 0x0c, 0x0c, 0xc1,
	0xc2, 0x0c, 0x0c, 0xc1,
	0xc3, 0xc0, 0xc0, 0xc3,
	0xc3, 0xc0, 0xc0, 0xc3,
	0xc3, 0xc3, 0xc3, 0xc3,
	0x4b, 0xc3, 0xc3, 0x87,
	0x05, 0x0f, 0x0f, 0x0a
};

// Tile pc_pieces_05: 8x16 pixels, 4x16 bytes.
const u8 pc_pieces_05[4 * 16] = {
	0x45, 0xc3, 0xc3, 0x82,
	0xcb, 0xc3, 0xc3, 0xc3,
	0x86, 0x0c, 0x0c, 0xc3,
	0x86, 0x0c, 0x0c, 0xc3,
	0x86, 0xc0, 0xc0, 0x49,
	0x86, 0xc0, 0xc0, 0x49,
	0x86, 0x0c, 0x0c, 0xc1,
	0x86, 0x0c, 0x0c, 0xc1,
	0x86, 0xc0, 0xc0, 0xc3,
	0x86, 0xc0, 0xc0, 0xc3,
	0x86, 0xc3, 0xc3, 0xc3,
	0xc2, 0xc3, 0xc3, 0xc3,
	0xc2, 0xc3, 0xc3, 0xc3,
	0xc3, 0xc3, 0xc3, 0xc3,
	0x4b, 0xc3, 0xc3, 0x87,
	0x05, 0x0f, 0x0f, 0x0a
};

// Tile pc_pieces_06: 8x16 pixels, 4x16 bytes.
const u8 pc_pieces_06[4 * 16] = {
	0x45, 0xc3, 0xc3, 0x82,
	0xcb, 0xc3, 0xc3, 0xc3,
	0xc3, 0x0c, 0x0c, 0xc3,
	0xc3, 0x0c, 0x0c, 0xc3,
	0x86, 0xc0, 0xc0, 0x49,
	0x86, 0xc0, 0xc0, 0x49,
	0x86, 0xc3, 0x49, 0x49,
	0x86, 0xc3, 0x49, 0x49,
	0x86, 0xc3, 0x84, 0xc1,
	0xc2, 0x0c, 0x48, 0x49,
	0xc2, 0x0c, 0x48, 0x49,
	0xc3, 0xc0, 0xc1, 0xc1,
	0xc3, 0xc0, 0xc1, 0xc1,
	0xc3, 0xc3, 0xc3, 0xc3,
	0x4b, 0xc3, 0xc3, 0x87,
	0x05, 0x0f, 0x0f, 0x0a
};

// Tile pc_pieces_07: 8x16 pixels, 4x16 bytes.
const u8 pc_pieces_07[4 * 16] = {
	0x45, 0xc3, 0xc3, 0x82,
	0xcb, 0xc3, 0xc3, 0xc3,
	0xc3, 0x0c, 0x0c, 0xc3,
	0xc3, 0x0c, 0x0c, 0xc3,
	0x86, 0xc0, 0xc0, 0x49,
	0x86, 0xc0, 0xc0, 0x49,
	0x86, 0x0c, 0x0c, 0x49,
	0x86, 0x0c, 0x0c, 0x49,
	0x86, 0xc0, 0xc0, 0x49,
	0x86, 0xc0, 0xc0, 0x49,
	0x86, 0xc3, 0xc3, 0x49,
	0xc2, 0xc3, 0xc3, 0xc1,
	0xc2, 0xc3, 0xc3, 0xc1,
	0xc3, 0xc3, 0xc3, 0xc3,
	0x4b, 0xc3, 0xc3, 0x87,
	0x05, 0x0f, 0x0f, 0x0a
};

// Tile pc_pieces_08: 8x16 pixels, 4x16 bytes.
const u8 pc_pieces_08[4 * 16] = {
	0x50, 0x30, 0x30, 0x20,
	0xb0, 0x30, 0x30, 0x30,
	0x30, 0x0c, 0x0c, 0x30,
	0x30, 0x0c, 0x0c, 0x30,
	0x24, 0xc0, 0xc0, 0x18,
	0x24, 0xc0, 0xc0, 0x18,
	0x24, 0x30, 0x30, 0x18,
	0x24, 0x30, 0x30, 0x18,
	0x24, 0x30, 0x30, 0x18,
	0x60, 0x0c, 0x0c, 0x90,
	0x60, 0x0c, 0x0c, 0x90,
	0x30, 0xc0, 0xc0, 0x30,
	0x30, 0xc0, 0xc0, 0x30,
	0x30, 0x30, 0x30, 0x30,
	0x98, 0x30, 0x30, 0x64,
	0x44, 0xcc, 0xcc, 0x88
};

// Tile pc_pieces_09: 8x16 pixels, 4x16 bytes.
const u8 pc_pieces_09[4 * 16] = {
	0x50, 0x30, 0x30, 0x20,
	0xb0, 0x30, 0x30, 0x30,
	0x24, 0x0c, 0x0c, 0x30,
	0x24, 0x0c, 0x0c, 0x30,
	0x24, 0xc0, 0xc0, 0x18,
	0x24, 0xc0, 0xc0, 0x18,
	0x24, 0x0c, 0x0c, 0x90,
	0x24, 0x0c, 0x0c, 0x90,
	0x24, 0xc0, 0xc0, 0x30,
	0x24, 0xc0, 0xc0, 0x30,
	0x24, 0x30, 0x30, 0x30,
	0x60, 0x30, 0x30, 0x30,
	0x60, 0x30, 0x30, 0x30,
	0x30, 0x30, 0x30, 0x30,
	0x98, 0x30, 0x30, 0x64,
	0x44, 0xcc, 0xcc, 0x88
};

// Tile pc_pieces_10: 8x16 pixels, 4x16 bytes.
const u8 pc_pieces_10[4 * 16] = {
	0x50, 0x30, 0x30, 0x20,
	0xb0, 0x30, 0x30, 0x30,
	0x30, 0x0c, 0x0c, 0x30,
	0x30, 0x0c, 0x0c, 0x30,
	0x24, 0xc0, 0xc0, 0x18,
	0x24, 0xc0, 0xc0, 0x18,
	0x24, 0x30, 0x18, 0x18,
	0x24, 0x30, 0x18, 0x18,
	0x24, 0x30, 0x84, 0x90,
	0x60, 0x0c, 0x48, 0x18,
	0x60, 0x0c, 0x48, 0x18,
	0x30, 0xc0, 0x90, 0x90,
	0x30, 0xc0, 0x90, 0x90,
	0x30, 0x30, 0x30, 0x30,
	0x98, 0x30, 0x30, 0x64,
	0x44, 0xcc, 0xcc, 0x88
};

// Tile pc_pieces_11: 8x16 pixels, 4x16 bytes.
const u8 pc_pieces_11[4 * 16] = {
	0x50, 0x30, 0x30, 0x20,
	0xb0, 0x30, 0x30, 0x30,
	0x30, 0x0c, 0x0c, 0x30,
	0x30, 0x0c, 0x0c, 0x30,
	0x24, 0xc0, 0xc0, 0x18,
	0x24, 0xc0, 0xc0, 0x18,
	0x24, 0x0c, 0x0c, 0x18,
	0x24, 0x0c, 0x0c, 0x18,
	0x24, 0xc0, 0xc0, 0x18,
	0x24, 0xc0, 0xc0, 0x18,
	0x24, 0x30, 0x30, 0x18,
	0x60, 0x30, 0x30, 0x90,
	0x60, 0x30, 0x30, 0x90,
	0x30, 0x30, 0x30, 0x30,
	0x98, 0x30, 0x30, 0x64,
	0x44, 0xcc, 0xcc, 0x88
};

// Tile pc_pieces_12: 8x16 pixels, 4x16 bytes.
const u8 pc_pieces_12[4 * 16] = {
	0x54, 0x33, 0x33, 0x22,
	0xb9, 0x33, 0x33, 0x33,
	0x33, 0x0c, 0x0c, 0x33,
	0x33, 0x0c, 0x0c, 0x33,
	0x26, 0xc0, 0xc0, 0x19,
	0x26, 0xc0, 0xc0, 0x19,
	0x26, 0x33, 0x33, 0x19,
	0x26, 0x33, 0x33, 0x19,
	0x26, 0x33, 0x33, 0x19,
	0x62, 0x0c, 0x0c, 0x91,
	0x62, 0x0c, 0x0c, 0x91,
	0x33, 0xc0, 0xc0, 0x33,
	0x33, 0xc0, 0xc0, 0x33,
	0x33, 0x33, 0x33, 0x33,
	0x1b, 0x33, 0x33, 0x27,
	0x05, 0x0f, 0x0f, 0x0a
};

// Tile pc_pieces_13: 8x16 pixels, 4x16 bytes.
const u8 pc_pieces_13[4 * 16] = {
	0x54, 0x33, 0x33, 0x22,
	0xb9, 0x33, 0x33, 0x33,
	0x26, 0x0c, 0x0c, 0x33,
	0x26, 0x0c, 0x0c, 0x33,
	0x26, 0xc0, 0xc0, 0x19,
	0x26, 0xc0, 0xc0, 0x19,
	0x26, 0x0c, 0x0c, 0x91,
	0x26, 0x0c, 0x0c, 0x91,
	0x26, 0xc0, 0xc0, 0x33,
	0x26, 0xc0, 0xc0, 0x33,
	0x26, 0x33, 0x33, 0x33,
	0x62, 0x33, 0x33, 0x33,
	0x62, 0x33, 0x33, 0x33,
	0x33, 0x33, 0x33, 0x33,
	0x1b, 0x33, 0x33, 0x27,
	0x05, 0x0f, 0x0f, 0x0a
};

// Tile pc_pieces_14: 8x16 pixels, 4x16 bytes.
const u8 pc_pieces_14[4 * 16] = {
	0x54, 0x33, 0x33, 0x22,
	0xb9, 0x33, 0x33, 0x33,
	0x33, 0x0c, 0x0c, 0x33,
	0x33, 0x0c, 0x0c, 0x33,
	0x26, 0xc0, 0xc0, 0x19,
	0x26, 0xc0, 0xc0, 0x19,
	0x26, 0x33, 0x19, 0x19,
	0x26, 0x33, 0x19, 0x19,
	0x26, 0x33, 0x84, 0x91,
	0x62, 0x0c, 0x48, 0x19,
	0x62, 0x0c, 0x48, 0x19,
	0x33, 0xc0, 0x91, 0x91,
	0x33, 0xc0, 0x91, 0x91,
	0x33, 0x33, 0x33, 0x33,
	0x1b, 0x33, 0x33, 0x27,
	0x05, 0x0f, 0x0f, 0x0a
};

// Tile pc_pieces_15: 8x16 pixels, 4x16 bytes.
const u8 pc_pieces_15[4 * 16] = {
	0x54, 0x33, 0x33, 0x22,
	0xb9, 0x33, 0x33, 0x33,
	0x33, 0x0c, 0x0c, 0x33,
	0x33, 0x0c, 0x0c, 0x33,
	0x26, 0xc0, 0xc0, 0x19,
	0x26, 0xc0, 0xc0, 0x19,
	0x26, 0x0c, 0x0c, 0x19,
	0x26, 0x0c, 0x0c, 0x19,
	0x26, 0xc0, 0xc0, 0x19,
	0x26, 0xc0, 0xc0, 0x19,
	0x26, 0x33, 0x33, 0x19,
	0x62, 0x33, 0x33, 0x91,
	0x62, 0x33, 0x33, 0x91,
	0x33, 0x33, 0x33, 0x33,
	0x1b, 0x33, 0x33, 0x27,
	0x05, 0x0f, 0x0f, 0x0a
};

// Tile pc_pieces_16: 8x16 pixels, 4x16 bytes.
const u8 pc_pieces_16[4 * 16] = {
	0x15, 0xf3, 0xf3, 0xa2,
	0x7b, 0xf3, 0xf3, 0xf3,
	0xf3, 0x0c, 0x0c, 0xf3,
	0xf3, 0x0c, 0x0c, 0xf3,
	0xa6, 0xc0, 0xc0, 0x59,
	0xa6, 0xc0, 0xc0, 0x59,
	0xa6, 0xf3, 0xf3, 0x59,
	0xa6, 0xf3, 0xf3, 0x59,
	0xa6, 0xf3, 0xf3, 0x59,
	0xe2, 0x0c, 0x0c, 0xd1,
	0xe2, 0x0c, 0x0c, 0xd1,
	0xf3, 0xc0, 0xc0, 0xf3,
	0xf3, 0xc0, 0xc0, 0xf3,
	0xf3, 0xf3, 0xf3, 0xf3,
	0x5b, 0xf3, 0xf3, 0xa7,
	0x05, 0x0f, 0x0f, 0x0a
};

// Tile pc_pieces_17: 8x16 pixels, 4x16 bytes.
const u8 pc_pieces_17[4 * 16] = {
	0x15, 0xf3, 0xf3, 0xa2,
	0x7b, 0xf3, 0xf3, 0xf3,
	0xa6, 0x0c, 0x0c, 0xf3,
	0xa6, 0x0c, 0x0c, 0xf3,
	0xa6, 0xc0, 0xc0, 0x59,
	0xa6, 0xc0, 0xc0, 0x59,
	0xa6, 0x0c, 0x0c, 0xd1,
	0xa6, 0x0c, 0x0c, 0xd1,
	0xa6, 0xc0, 0xc0, 0xf3,
	0xa6, 0xc0, 0xc0, 0xf3,
	0xa6, 0xf3, 0xf3, 0xf3,
	0xe2, 0xf3, 0xf3, 0xf3,
	0xe2, 0xf3, 0xf3, 0xf3,
	0xf3, 0xf3, 0xf3, 0xf3,
	0x5b, 0xf3, 0xf3, 0xa7,
	0x05, 0x0f, 0x0f, 0x0a
};

// Tile pc_pieces_18: 8x16 pixels, 4x16 bytes.
const u8 pc_pieces_18[4 * 16] = {
	0x15, 0xf3, 0xf3, 0xa2,
	0x7b, 0xf3, 0xf3, 0xf3,
	0xf3, 0x0c, 0x0c, 0xf3,
	0xf3, 0x0c, 0x0c, 0xf3,
	0xa6, 0xc0, 0xc0, 0x59,
	0xa6, 0xc0, 0xc0, 0x59,
	0xa6, 0xf3, 0x59, 0x59,
	0xa6, 0xf3, 0x59, 0x59,
	0xa6, 0xf3, 0x84, 0xd1,
	0xe2, 0x0c, 0x48, 0x59,
	0xe2, 0x0c, 0x48, 0x59,
	0xf3, 0xc0, 0xd1, 0xd1,
	0xf3, 0xc0, 0xd1, 0xd1,
	0xf3, 0xf3, 0xf3, 0xf3,
	0x5b, 0xf3, 0xf3, 0xa7,
	0x05, 0x0f, 0x0f, 0x0a
};

// Tile pc_pieces_19: 8x16 pixels, 4x16 bytes.
const u8 pc_pieces_19[4 * 16] = {
	0x15, 0xf3, 0xf3, 0xa2,
	0x7b, 0xf3, 0xf3, 0xf3,
	0xf3, 0x0c, 0x0c, 0xf3,
	0xf3, 0x0c, 0x0c, 0xf3,
	0xa6, 0xc0, 0xc0, 0x59,
	0xa6, 0xc0, 0xc0, 0x59,
	0xa6, 0x0c, 0x0c, 0x59,
	0xa6, 0x0c, 0x0c, 0x59,
	0xa6, 0xc0, 0xc0, 0x59,
	0xa6, 0xc0, 0xc0, 0x59,
	0xa6, 0xf3, 0xf3, 0x59,
	0xe2, 0xf3, 0xf3, 0xd1,
	0xe2, 0xf3, 0xf3, 0xd1,
	0xf3, 0xf3, 0xf3, 0xf3,
	0x5b, 0xf3, 0xf3, 0xa7,
	0x05, 0x0f, 0x0f, 0x0a
};


#include "avatars.h"
// Data created with Img2CPC - (c) Retroworks - 2007-2017
u8* const av_tileset[18] = { 
	av_avatars_00, av_avatars_01, av_avatars_02, av_avatars_03, av_avatars_04, av_avatars_05, av_avatars_06, av_avatars_07, av_avatars_08, av_avatars_09, av_avatars_10, av_avatars_11, av_avatars_12, av_avatars_13, av_avatars_14, av_avatars_15, av_avatars_16, av_avatars_17
};
// Tile av_avatars_00: 16x32 pixels, 8x32 bytes.
const u8 av_avatars_00[8 * 32] = {
	0x0f, 0x0f, 0x0f, 0x00, 0x00, 0x0f, 0x0f, 0x0f,
	0xc3, 0xc3, 0x82, 0x00, 0x00, 0xc1, 0xc3, 0xc3,
	0x0f, 0x0f, 0x00, 0x00, 0x00, 0x40, 0x0f, 0x0f,
	0xc3, 0xc2, 0x00, 0x00, 0x00, 0x00, 0xc3, 0xc3,
	0x0f, 0x0a, 0x00, 0x00, 0x00, 0x00, 0x05, 0x0f,
	0x0f, 0x0a, 0x00, 0x00, 0x80, 0x00, 0x05, 0x0f,
	0xc3, 0x82, 0x40, 0x00, 0xf0, 0x40, 0x00, 0xc3,
	0x0f, 0x0a, 0x50, 0xf0, 0xf0, 0xf0, 0x00, 0x0f,
	0x0f, 0x00, 0x50, 0xf0, 0xf0, 0xf0, 0x80, 0x0f,
	0x0f, 0x00, 0xd0, 0xf0, 0xf0, 0xf0, 0x80, 0x0f,
	0xc3, 0x00, 0xa0, 0x00, 0xa0, 0x00, 0xa0, 0x41,
	0x0f, 0x00, 0xf0, 0xa0, 0xa0, 0xf0, 0xa0, 0x05,
	0x0f, 0x40, 0xa4, 0xd8, 0xf0, 0x4c, 0xe0, 0x05,
	0x0f, 0x00, 0xa4, 0xd8, 0xf0, 0x4c, 0xa0, 0x05,
	0x0f, 0x40, 0xf0, 0xf0, 0xf0, 0xf0, 0xe0, 0x05,
	0xc3, 0x00, 0xf0, 0xf0, 0xf0, 0xf0, 0xa0, 0x41,
	0x0f, 0x00, 0xf0, 0xe4, 0xe4, 0xf0, 0xa0, 0x05,
	0x0f, 0x00, 0xf0, 0xf0, 0xd8, 0xf0, 0xa0, 0x05,
	0x0f, 0x00, 0xf0, 0xf0, 0xf0, 0xf0, 0xa0, 0x05,
	0x0f, 0x00, 0xf0, 0x00, 0x00, 0x50, 0xa0, 0x05,
	0x0f, 0x0a, 0xa0, 0xd8, 0xf0, 0x88, 0xa0, 0x0f,
	0xc3, 0x82, 0x00, 0xe4, 0xcc, 0xa0, 0x00, 0xc3,
	0x0f, 0x0a, 0x00, 0x50, 0xf0, 0x00, 0x05, 0x0f,
	0x0f, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x05, 0x0f,
	0x0f, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x0f,
	0x0f, 0x0f, 0x5a, 0x00, 0x00, 0x50, 0x0f, 0x0f,
	0x0f, 0x0f, 0x5a, 0xa0, 0x00, 0xf0, 0x0f, 0x0f,
	0x0f, 0x5b, 0xf2, 0xf0, 0xf0, 0xf0, 0xf3, 0x0f,
	0xd3, 0xf3, 0xf3, 0xf3, 0xf3, 0xf3, 0xf3, 0xf3,
	0xf3, 0xa6, 0xa6, 0xa6, 0x84, 0xc0, 0x59, 0xf3,
	0xf3, 0xa6, 0x0c, 0xa6, 0x84, 0x84, 0x59, 0xf3,
	0xf3, 0xf3, 0xa6, 0xa6, 0x84, 0x84, 0xd1, 0xf3
};

// Tile av_avatars_01: 16x32 pixels, 8x32 bytes.
const u8 av_avatars_01[8 * 32] = {
	0xcc, 0xcc, 0x88, 0x00, 0x00, 0x00, 0xcc, 0xcc,
	0x30, 0x30, 0x60, 0x40, 0x40, 0x40, 0x30, 0x30,
	0xcc, 0xcc, 0x80, 0x00, 0x00, 0x00, 0xc4, 0xcc,
	0x30, 0x30, 0x40, 0xf0, 0xf0, 0xe0, 0x10, 0x30,
	0xcc, 0xcc, 0x50, 0xf0, 0xf0, 0xf0, 0x44, 0xcc,
	0xcc, 0xcc, 0x50, 0xf0, 0xf0, 0xf0, 0x44, 0xcc,
	0x30, 0x30, 0xd0, 0xf0, 0xf0, 0xf0, 0x90, 0x30,
	0xcc, 0xcc, 0x50, 0xf0, 0xf0, 0xf0, 0x44, 0xcc,
	0xcc, 0xcc, 0xd0, 0x00, 0xa0, 0x50, 0xc4, 0xcc,
	0xcc, 0xcc, 0x80, 0xf0, 0xf0, 0xa0, 0xc4, 0xcc,
	0x30, 0x30, 0xd0, 0x4c, 0xa4, 0xd8, 0x90, 0x30,
	0xcc, 0xd8, 0xf0, 0x4c, 0xa4, 0xd8, 0xf0, 0xcc,
	0xcc, 0xd8, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xcc,
	0xcc, 0xd8, 0xa1, 0x52, 0xf0, 0x03, 0xf0, 0xcc,
	0xcc, 0xd8, 0xf0, 0xe4, 0xe4, 0xf0, 0xf0, 0xcc,
	0x30, 0x30, 0xf0, 0xf0, 0xd8, 0xf0, 0xb0, 0x30,
	0xcc, 0xcc, 0xf0, 0xf0, 0xf0, 0xf0, 0xe4, 0xcc,
	0xcc, 0xcc, 0xd8, 0xf0, 0xf0, 0xf0, 0xcc, 0xcc,
	0xcc, 0xcc, 0xd8, 0xd8, 0xf0, 0xd8, 0xcc, 0xcc,
	0xcc, 0xcc, 0xd8, 0xe4, 0xcc, 0xf0, 0xcc, 0xcc,
	0xcc, 0xcc, 0xd8, 0xf0, 0xf0, 0xf0, 0xcc, 0xcc,
	0x30, 0x30, 0x30, 0xf0, 0xf0, 0xb0, 0x30, 0x30,
	0xcc, 0xcc, 0xcc, 0xd8, 0xf0, 0xcc, 0xcc, 0xcc,
	0xcc, 0xcc, 0xcc, 0xd8, 0xf0, 0xcc, 0xcc, 0xcc,
	0xcc, 0xcc, 0xcc, 0x50, 0xf0, 0x44, 0xcc, 0xcc,
	0xcc, 0x88, 0x00, 0x80, 0xa0, 0x80, 0x00, 0xcc,
	0x00, 0x00, 0x00, 0x40, 0x40, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x04, 0x08, 0x0c, 0x04, 0x20, 0x00,
	0x00, 0x00, 0x04, 0x00, 0x0c, 0x10, 0x00, 0x00,
	0x00, 0x00, 0x04, 0x08, 0x08, 0x04, 0x08, 0x00
};

// Tile av_avatars_02: 16x32 pixels, 8x32 bytes.
const u8 av_avatars_02[8 * 32] = {
	0xfc, 0xfc, 0xa8, 0x80, 0x00, 0xd4, 0xfc, 0xfc,
	0x3c, 0x3c, 0x40, 0x00, 0x40, 0x40, 0x3c, 0x3c,
	0xfc, 0xfc, 0x80, 0xf0, 0xa0, 0x80, 0xfc, 0xfc,
	0x3c, 0x3c, 0x40, 0xf0, 0xf0, 0x40, 0x3c, 0x3c,
	0xfc, 0xfc, 0xd0, 0xf0, 0xf0, 0xa0, 0xfc, 0xfc,
	0xfc, 0xfc, 0x50, 0xf0, 0xf0, 0xa0, 0xfc, 0xfc,
	0x3c, 0x3c, 0x50, 0xf0, 0xf0, 0xa0, 0x3c, 0x3c,
	0xfc, 0xfc, 0x00, 0x50, 0xa0, 0x00, 0xfc, 0xfc,
	0xfc, 0xfc, 0x50, 0xf0, 0xf0, 0xa0, 0xfc, 0xfc,
	0xfc, 0xfc, 0xc0, 0xc0, 0xc0, 0xc0, 0xfc, 0xfc,
	0x3c, 0x78, 0xa4, 0x40, 0xa4, 0x40, 0xb4, 0x3c,
	0xfc, 0xf8, 0x06, 0x40, 0xa4, 0x40, 0xf4, 0xfc,
	0xfc, 0xf8, 0xe0, 0xc0, 0xe0, 0xc0, 0xf4, 0xfc,
	0xfc, 0xf8, 0x52, 0xd8, 0xd8, 0xd8, 0xf4, 0xfc,
	0xfc, 0xfc, 0xe4, 0xf0, 0xd8, 0xe4, 0xfc, 0xfc,
	0x3c, 0x3c, 0x52, 0x52, 0xd8, 0xf0, 0x3c, 0x3c,
	0xfc, 0xfc, 0xa1, 0xe4, 0xd8, 0xf0, 0xfc, 0xfc,
	0xfc, 0xfc, 0x52, 0x52, 0xf0, 0xf0, 0xfc, 0xfc,
	0xfc, 0xfc, 0xa9, 0xf0, 0xf0, 0xf4, 0xfc, 0xfc,
	0xfc, 0xfc, 0xf8, 0xd8, 0xe4, 0xf4, 0xfc, 0xfc,
	0xfc, 0xfc, 0xa9, 0xe4, 0xd8, 0xf4, 0xfc, 0xfc,
	0x3c, 0x3c, 0x3c, 0x52, 0xf0, 0x3c, 0x3c, 0x3c,
	0xfc, 0xfc, 0xfc, 0xf0, 0xf0, 0xfc, 0xfc, 0xfc,
	0xfc, 0xfc, 0xfc, 0xf8, 0xf4, 0xfc, 0xfc, 0xfc,
	0xfc, 0xfc, 0xe8, 0xd0, 0xe0, 0xd4, 0xfc, 0xfc,
	0xfc, 0xe8, 0x80, 0xc0, 0xc0, 0x40, 0xd4, 0xfc,
	0xe8, 0xc0, 0xc0, 0x00, 0x00, 0xc0, 0xc0, 0xd4,
	0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0,
	0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0,
	0xc0, 0x80, 0x00, 0x00, 0x34, 0x67, 0x40, 0xc0,
	0xc0, 0x80, 0x00, 0x10, 0x39, 0x8a, 0x40, 0xc0,
	0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x40, 0xc0
};

// Tile av_avatars_03: 16x32 pixels, 8x32 bytes.
const u8 av_avatars_03[8 * 32] = {
	0xc3, 0x83, 0xc3, 0x16, 0x29, 0xc3, 0x43, 0xc3,
	0x0f, 0x0b, 0x1e, 0x16, 0x29, 0x2d, 0x07, 0x0f,
	0xc3, 0x83, 0x16, 0x03, 0x21, 0x16, 0x43, 0xc3,
	0x0f, 0x0b, 0x3c, 0x12, 0x21, 0x3c, 0x07, 0x0f,
	0xc3, 0x83, 0x16, 0x03, 0x21, 0x16, 0x43, 0xc3,
	0xc3, 0x83, 0x3c, 0x03, 0x29, 0x16, 0x43, 0xc3,
	0x0f, 0x0b, 0x16, 0x16, 0x29, 0x3c, 0x07, 0x0f,
	0xc3, 0xc2, 0x3c, 0x78, 0xb4, 0x3c, 0xc1, 0xc3,
	0xc3, 0xc6, 0xd8, 0xf0, 0xf0, 0xe4, 0xc9, 0xc3,
	0xc3, 0xc4, 0xd8, 0xf0, 0xf0, 0xe4, 0xc8, 0xc3,
	0x0f, 0xcc, 0xd8, 0xf0, 0xf0, 0xe4, 0xcc, 0x0f,
	0xc3, 0xcc, 0xcc, 0xd8, 0xe4, 0xcc, 0xcc, 0xc3,
	0xc3, 0xcc, 0xd8, 0xf0, 0xf0, 0xe4, 0xcc, 0xc3,
	0xc3, 0xcc, 0x8c, 0x5a, 0xa4, 0x4e, 0xcc, 0xc3,
	0xc3, 0xcc, 0xf0, 0xf0, 0xf0, 0xf0, 0xcc, 0xc3,
	0x0f, 0xcc, 0xf0, 0xf0, 0xf0, 0xf0, 0xcc, 0x0f,
	0xc3, 0xc4, 0xf0, 0xf0, 0xf0, 0xf0, 0xc8, 0xc3,
	0xc3, 0xc6, 0xd8, 0xf0, 0xf0, 0xe4, 0xc9, 0xc3,
	0xc3, 0xc2, 0xd8, 0xf0, 0xf0, 0xe4, 0xc1, 0xc3,
	0xc3, 0xc3, 0xd8, 0xe4, 0xd8, 0xe4, 0xc3, 0xc3,
	0xc3, 0xc3, 0xd8, 0xe0, 0xd0, 0xe4, 0xc3, 0xc3,
	0xc3, 0xc3, 0xcc, 0xcc, 0xcc, 0xcc, 0xc3, 0xc3,
	0x0f, 0x0f, 0xcc, 0x84, 0x48, 0xcc, 0x0f, 0x0f,
	0xc3, 0xc3, 0xd8, 0xe4, 0xd8, 0xe4, 0xc3, 0xc3,
	0xc3, 0x86, 0xcc, 0xf0, 0xf0, 0xcc, 0xc3, 0xc3,
	0xc3, 0x2c, 0xc4, 0xf0, 0xf0, 0xc8, 0x1c, 0xc3,
	0x96, 0x06, 0x4c, 0xcc, 0xcc, 0x8c, 0x09, 0x69,
	0x29, 0x2c, 0x4c, 0xcc, 0xcc, 0x8c, 0x1c, 0x16,
	0x16, 0x06, 0x48, 0xcc, 0xcc, 0x84, 0x09, 0x29,
	0x29, 0x2c, 0x0c, 0xcc, 0xcc, 0x0c, 0x1c, 0x16,
	0x16, 0x06, 0x0c, 0xcc, 0xcc, 0x0c, 0x09, 0x29,
	0x29, 0x29, 0x0c, 0xc4, 0xc8, 0x0c, 0x16, 0x16
};

// Tile av_avatars_04: 16x32 pixels, 8x32 bytes.
const u8 av_avatars_04[8 * 32] = {
	0x30, 0x30, 0x10, 0x30, 0x30, 0x30, 0x30, 0x30,
	0xcc, 0x88, 0x00, 0xcc, 0x00, 0x44, 0xcc, 0xcc,
	0x30, 0x00, 0x00, 0x20, 0x00, 0x00, 0x30, 0x30,
	0xcc, 0x00, 0x00, 0x88, 0x00, 0x00, 0xcc, 0xcc,
	0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x30,
	0x20, 0x00, 0x10, 0x00, 0x00, 0x00, 0x10, 0x30,
	0x00, 0x00, 0x88, 0x00, 0x00, 0x00, 0x00, 0xcc,
	0x00, 0x00, 0x20, 0x50, 0x00, 0x50, 0x00, 0x30,
	0x00, 0x98, 0x20, 0xf0, 0xa0, 0xf0, 0xa0, 0x30,
	0x10, 0x30, 0x20, 0xa0, 0xf0, 0xa0, 0xa0, 0x30,
	0x88, 0xcc, 0x88, 0xf0, 0x50, 0x50, 0xa0, 0xcc,
	0x20, 0x30, 0xa0, 0xa4, 0x58, 0x0c, 0xa0, 0xd0,
	0x30, 0x30, 0xa0, 0xa4, 0x50, 0x04, 0xa0, 0xd0,
	0x30, 0x30, 0xa0, 0xa4, 0x50, 0x04, 0xa0, 0xd0,
	0x30, 0x30, 0xa0, 0xa4, 0x58, 0x0c, 0xa0, 0xd0,
	0xcc, 0xcc, 0x88, 0xf0, 0xf0, 0xf0, 0xa0, 0x70,
	0x30, 0x30, 0x70, 0xf0, 0xe4, 0xf0, 0xf0, 0x30,
	0x30, 0x30, 0x70, 0xf0, 0xf0, 0xf0, 0xf0, 0x30,
	0x30, 0x30, 0x30, 0xf0, 0xf0, 0xe4, 0xb0, 0x30,
	0x30, 0x30, 0x30, 0xf0, 0xcc, 0xd8, 0xb0, 0x30,
	0x30, 0x30, 0x20, 0x50, 0xe0, 0xf0, 0x10, 0x30,
	0xcc, 0xcc, 0x88, 0x00, 0xf0, 0xa0, 0x44, 0xcc,
	0x30, 0x30, 0x00, 0x00, 0x50, 0x00, 0x30, 0x30,
	0x30, 0x30, 0x00, 0x00, 0x00, 0x00, 0x10, 0x30,
	0x30, 0x30, 0x20, 0x00, 0x44, 0x98, 0x10, 0x30,
	0x30, 0x30, 0x20, 0x50, 0x10, 0x20, 0xf0, 0x30,
	0x30, 0x30, 0x20, 0xf0, 0x00, 0xf0, 0xe0, 0x30,
	0x30, 0x30, 0x30, 0xf0, 0xf0, 0xf0, 0xf0, 0x30,
	0xcc, 0xcc, 0xcc, 0xf0, 0xf0, 0x50, 0xe0, 0xcc,
	0x30, 0x30, 0x30, 0x5a, 0xf0, 0x50, 0xf0, 0x4b,
	0x30, 0x30, 0x30, 0x82, 0xf0, 0x50, 0xe0, 0x87,
	0x30, 0x30, 0x61, 0x4b, 0xf0, 0x40, 0xe1, 0x4b
};

// Tile av_avatars_05: 16x32 pixels, 8x32 bytes.
const u8 av_avatars_05[8 * 32] = {
	0x33, 0x33, 0x80, 0x00, 0x00, 0x00, 0x91, 0x33,
	0xfc, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x54, 0xfc,
	0x33, 0x33, 0x00, 0x00, 0x00, 0xcc, 0x11, 0x33,
	0xfc, 0xe8, 0x00, 0xdc, 0xf8, 0x03, 0xdc, 0xfc,
	0x33, 0x62, 0x44, 0xf0, 0xff, 0xab, 0x99, 0x33,
	0x33, 0x22, 0x44, 0x57, 0xae, 0x58, 0x13, 0x33,
	0xfc, 0x80, 0x44, 0x57, 0xae, 0x09, 0xf4, 0xfc,
	0x33, 0x80, 0x44, 0x52, 0xae, 0x58, 0xb1, 0x33,
	0x33, 0x80, 0x44, 0x03, 0xae, 0x58, 0xb1, 0x33,
	0x33, 0x80, 0x01, 0x57, 0xae, 0x5d, 0xb1, 0x33,
	0xfc, 0x80, 0x21, 0xf0, 0x57, 0xfa, 0xd4, 0xfc,
	0x33, 0x22, 0x03, 0xf0, 0x04, 0xa0, 0x33, 0x33,
	0x33, 0x22, 0xa1, 0xf0, 0xf5, 0xf0, 0x33, 0x33,
	0x33, 0x62, 0xa1, 0xf5, 0x5d, 0xf0, 0x33, 0x33,
	0x33, 0x33, 0x03, 0x06, 0x5d, 0xff, 0x33, 0x33,
	0xfc, 0xfc, 0x03, 0x57, 0xf5, 0xab, 0xfc, 0xfc,
	0x33, 0x33, 0x03, 0x03, 0xfa, 0xf0, 0x33, 0x33,
	0x33, 0x33, 0xa1, 0x03, 0xfa, 0x52, 0x33, 0x33,
	0x33, 0x33, 0x58, 0x57, 0x0c, 0xfa, 0x33, 0x33,
	0x33, 0x22, 0x58, 0xf0, 0xff, 0xbb, 0x33, 0x33,
	0xfc, 0x80, 0x0c, 0xf0, 0xab, 0xf4, 0xfc, 0xfc,
	0x33, 0x80, 0x84, 0xf0, 0xff, 0xb1, 0x33, 0x33,
	0x62, 0x00, 0x84, 0x48, 0xff, 0xb1, 0x33, 0x33,
	0x22, 0x00, 0x04, 0x0c, 0xd4, 0x33, 0x33, 0x33,
	0x80, 0x00, 0x40, 0x0c, 0x08, 0x91, 0x33, 0x33,
	0x00, 0x00, 0x40, 0x0c, 0x08, 0x11, 0x33, 0x33,
	0x00, 0x00, 0x00, 0x84, 0x08, 0x11, 0x33, 0x33,
	0x00, 0x00, 0x00, 0x84, 0x08, 0x40, 0xfc, 0xfc,
	0x00, 0x00, 0x00, 0x04, 0x0c, 0x40, 0x33, 0x33,
	0x00, 0x00, 0x00, 0x40, 0x0c, 0x00, 0x91, 0x33,
	0x00, 0x00, 0x00, 0x00, 0x84, 0x00, 0x91, 0x33,
	0x00, 0x00, 0x00, 0x00, 0xc0, 0x00, 0x40, 0x33
};

// Tile av_avatars_06: 16x32 pixels, 8x32 bytes.
const u8 av_avatars_06[8 * 32] = {
	0xcf, 0xcf, 0xcf, 0xc0, 0xc5, 0xcf, 0xcf, 0xcf,
	0xc3, 0xc3, 0xc0, 0x0c, 0x48, 0xc3, 0xc3, 0xc3,
	0xcf, 0xcf, 0x0c, 0x0c, 0x0c, 0xc5, 0xcf, 0xcf,
	0xc3, 0xc3, 0x0c, 0x0c, 0x84, 0x49, 0xc3, 0xc3,
	0xc3, 0xc3, 0x0c, 0x48, 0xa4, 0x49, 0xc3, 0xc3,
	0xcf, 0xcf, 0x84, 0xd0, 0xa4, 0x4d, 0xcf, 0xcf,
	0xc3, 0xc3, 0xc0, 0xf0, 0xa4, 0xc1, 0xc3, 0xc3,
	0xc3, 0xc3, 0xf0, 0xf0, 0xa0, 0x80, 0xc3, 0xc3,
	0xc3, 0xc3, 0x04, 0x04, 0xe4, 0x00, 0xc3, 0xc3,
	0xcf, 0xcf, 0x04, 0x04, 0xe4, 0x40, 0xcf, 0xcf,
	0xc3, 0xc3, 0x04, 0x04, 0xe4, 0xc0, 0x41, 0xc3,
	0xc3, 0x82, 0xf0, 0xf0, 0xe4, 0xc0, 0x41, 0xc3,
	0xc3, 0xc2, 0x4c, 0x0c, 0x0c, 0xc0, 0x41, 0xc3,
	0xc3, 0x86, 0x0c, 0x0c, 0x0c, 0x80, 0xc3, 0xc3,
	0xcf, 0x8e, 0x08, 0x84, 0x0c, 0x80, 0x45, 0xcf,
	0xc3, 0xc2, 0x0c, 0x0c, 0x48, 0x80, 0x80, 0xc3,
	0xc3, 0xc2, 0x0c, 0x84, 0xc0, 0x80, 0xc0, 0xc3,
	0xc3, 0x00, 0x0c, 0x0c, 0xc0, 0x80, 0x48, 0xc3,
	0xc3, 0x80, 0x0c, 0x0c, 0xc0, 0x04, 0xc0, 0x41,
	0xc3, 0xc0, 0x84, 0x48, 0xc0, 0x04, 0x48, 0x41,
	0xcf, 0x0c, 0x40, 0xc0, 0x80, 0x00, 0x48, 0x45,
	0x82, 0x0c, 0x08, 0xc0, 0x00, 0x00, 0x0c, 0x41,
	0x82, 0x84, 0x48, 0x00, 0x04, 0xc0, 0x84, 0xc1,
	0x82, 0x84, 0x08, 0x04, 0x48, 0x84, 0x0c, 0x80,
	0x82, 0x04, 0x00, 0x00, 0x08, 0x48, 0x0c, 0x80,
	0xc2, 0x40, 0x40, 0x04, 0xc0, 0x48, 0x48, 0x80,
	0xc2, 0x40, 0xc0, 0x40, 0x04, 0xc0, 0x80, 0x00,
	0xd8, 0x04, 0x48, 0x00, 0x0c, 0x48, 0xd8, 0xa0,
	0xd8, 0x04, 0x48, 0x04, 0x0c, 0x08, 0xd8, 0xa0,
	0xe4, 0x04, 0xc0, 0x04, 0x0c, 0x80, 0xf0, 0x88,
	0xd8, 0x84, 0x48, 0x04, 0x48, 0x80, 0xd8, 0xa0,
	0xe4, 0x84, 0x0c, 0x04, 0x0c, 0xc0, 0xf0, 0x88
};

// Tile av_avatars_07: 16x32 pixels, 8x32 bytes.
const u8 av_avatars_07[8 * 32] = {
	0x3f, 0x3f, 0x3f, 0xf0, 0xf0, 0x3f, 0x3f, 0x3f,
	0xf0, 0xf0, 0xf0, 0x52, 0xf0, 0xf0, 0xf0, 0xf0,
	0x3f, 0x3f, 0x2b, 0xf0, 0xa4, 0xb5, 0x3f, 0x3f,
	0xf0, 0xf0, 0xd0, 0x52, 0xf0, 0xe0, 0xf0, 0xf0,
	0x3f, 0x3f, 0x81, 0xf0, 0xf0, 0xe0, 0x3f, 0x3f,
	0x3f, 0x3f, 0xd0, 0x52, 0xf0, 0xe0, 0x3f, 0x3f,
	0xf0, 0xf0, 0x81, 0xf0, 0xf0, 0xe0, 0xf0, 0xf0,
	0x3f, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x3f,
	0x3f, 0x7a, 0xa0, 0x40, 0xa0, 0x40, 0xb5, 0x3f,
	0x3f, 0x7a, 0xa0, 0x00, 0xa0, 0x00, 0xb5, 0x3f,
	0xf0, 0xf0, 0xa0, 0x00, 0xa0, 0x00, 0xf0, 0xf0,
	0x3f, 0x7a, 0x52, 0x52, 0xf0, 0xf0, 0xb5, 0x3f,
	0x3f, 0x7a, 0xa1, 0xf0, 0xd8, 0xf0, 0xb5, 0x3f,
	0x3f, 0x3f, 0x52, 0x52, 0xd8, 0xf0, 0x3f, 0x3f,
	0x3f, 0x3f, 0xa1, 0xe4, 0xd8, 0xf0, 0x3f, 0x3f,
	0xf0, 0xf0, 0x52, 0x52, 0xf0, 0xf0, 0xf0, 0xf0,
	0x3f, 0x3f, 0x2b, 0xf0, 0xe4, 0xb5, 0x3f, 0x3f,
	0x3f, 0x3f, 0x7a, 0x46, 0xd8, 0xb5, 0x3f, 0x3f,
	0x3f, 0x3f, 0x3f, 0xf0, 0xf0, 0x3f, 0x3f, 0x3f,
	0x3f, 0x3f, 0x3f, 0xf0, 0xf0, 0x3f, 0x3f, 0x3f,
	0x3f, 0x3f, 0x3f, 0x7a, 0xb5, 0x3f, 0x3f, 0x3f,
	0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0,
	0x3f, 0x3f, 0x40, 0x50, 0xa0, 0x80, 0x3f, 0x3f,
	0x3f, 0x00, 0x40, 0x00, 0x00, 0x80, 0x00, 0x3f,
	0x00, 0x00, 0x00, 0xc0, 0xc0, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x24, 0x18, 0x0c, 0x24, 0x18, 0x0c, 0x20,
	0x00, 0x2c, 0x1c, 0x0c, 0x2c, 0x1c, 0x0c, 0x28,
	0x00, 0x26, 0x19, 0x48, 0x26, 0x19, 0xc0, 0x22,
	0x00, 0x8e, 0xcf, 0x0c, 0x8a, 0x4d, 0x0c, 0x8a,
	0x15, 0x04, 0x00, 0x0c, 0x00, 0x08, 0x0c, 0x00
};

// Tile av_avatars_08: 16x32 pixels, 8x32 bytes.
const u8 av_avatars_08[8 * 32] = {
	0xc3, 0xc3, 0xc3, 0xcc, 0xcc, 0xc9, 0xc3, 0xc3,
	0xcf, 0xcf, 0xce, 0xcc, 0xcc, 0xcc, 0xcf, 0xcf,
	0xc3, 0xc3, 0xc6, 0xe4, 0xcc, 0xe4, 0xc3, 0xc3,
	0xcf, 0xcf, 0xcc, 0xe4, 0xcc, 0xe4, 0xcd, 0xcf,
	0xc3, 0xc6, 0xd8, 0xf0, 0xd8, 0xf0, 0xcc, 0xc3,
	0xc3, 0xe4, 0xd8, 0xf0, 0xf0, 0xf0, 0xcc, 0xe1,
	0xda, 0xe4, 0xf0, 0x0c, 0xa4, 0x58, 0xe4, 0xf0,
	0xc6, 0xe4, 0xd8, 0x08, 0xa0, 0x58, 0xcc, 0xe4,
	0xc6, 0xe4, 0xd8, 0xf0, 0xf0, 0xf0, 0xcc, 0xe4,
	0xc6, 0xd8, 0xd8, 0xe4, 0xcc, 0xf0, 0xd8, 0xcc,
	0xcc, 0xcc, 0xf0, 0xf0, 0xf0, 0xf0, 0xe4, 0xcc,
	0xcc, 0xd8, 0xa4, 0x8c, 0x0c, 0x8c, 0xf0, 0xcc,
	0xcc, 0xd8, 0xe4, 0xcc, 0x4c, 0xcc, 0xf0, 0xcc,
	0xcc, 0xd8, 0xa4, 0x8c, 0x0c, 0x8c, 0xf0, 0xcc,
	0xcc, 0xcc, 0xf0, 0x0c, 0x0c, 0x58, 0xe4, 0xcc,
	0xcc, 0xcc, 0xd8, 0xf0, 0xf0, 0xf0, 0xcc, 0xcc,
	0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc,
	0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc,
	0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc,
	0xcc, 0xcc, 0xf0, 0xe4, 0xcc, 0xf0, 0xe4, 0xcc,
	0xcc, 0xd8, 0xf0, 0xf0, 0xd8, 0xf0, 0xf0, 0xcc,
	0xcc, 0xd8, 0xf0, 0xf0, 0xd8, 0xf0, 0xf0, 0xcc,
	0xcc, 0xd8, 0xf0, 0xf0, 0xd8, 0xf0, 0xf0, 0xcc,
	0xcc, 0xd8, 0xf0, 0xf0, 0xd8, 0xf0, 0xf0, 0xcc,
	0xcc, 0xd8, 0xf0, 0xf0, 0xd8, 0xf0, 0xf0, 0xcc,
	0xcc, 0xd8, 0xd8, 0xf0, 0xd8, 0xf0, 0xd8, 0xcc,
	0xcc, 0xcc, 0xf0, 0xe4, 0xcc, 0xf0, 0xe4, 0xcc,
	0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc,
	0xcc, 0xcc, 0xd8, 0xcc, 0xcc, 0xd8, 0xcc, 0xcc,
	0xcc, 0xcc, 0xcc, 0xf0, 0xf0, 0xe4, 0xcc, 0xcc,
	0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc,
	0xcc, 0xcc, 0xd8, 0xcc, 0xcc, 0xd8, 0xcc, 0xcc
};

// Tile av_avatars_09: 16x32 pixels, 8x32 bytes.
const u8 av_avatars_09[8 * 32] = {
	0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc,
	0x3c, 0x3c, 0x3c, 0x28, 0x00, 0x3c, 0x3c, 0x3c,
	0xfc, 0xfc, 0xfc, 0x40, 0x00, 0x54, 0xfc, 0xfc,
	0x3c, 0x3c, 0x28, 0x40, 0x80, 0x00, 0x3c, 0x3c,
	0xfc, 0xfc, 0xa8, 0x00, 0x00, 0x00, 0x54, 0xfc,
	0xfc, 0xfc, 0x00, 0x00, 0x80, 0x40, 0x54, 0xfc,
	0x3c, 0x28, 0x00, 0x00, 0x80, 0x80, 0xc0, 0x3c,
	0xfc, 0xa8, 0x40, 0x50, 0xa0, 0x40, 0x40, 0xd4,
	0xfc, 0x00, 0x40, 0x50, 0xa0, 0x80, 0x00, 0xfc,
	0xfc, 0x00, 0x80, 0x50, 0xa0, 0x80, 0x00, 0x54,
	0x3c, 0x40, 0x00, 0x50, 0xa0, 0x40, 0x00, 0x14,
	0xfc, 0x00, 0x00, 0xf0, 0xf0, 0x00, 0x80, 0x54,
	0xfc, 0x80, 0x00, 0x00, 0xa0, 0x00, 0x00, 0x54,
	0xfc, 0x00, 0x50, 0xf0, 0xf0, 0xf0, 0x00, 0x54,
	0xfc, 0x00, 0xf0, 0x08, 0xa4, 0x50, 0x00, 0x54,
	0x3c, 0x00, 0xf0, 0x08, 0xa4, 0x50, 0x00, 0x14,
	0xfc, 0x00, 0x52, 0xf0, 0xf0, 0xf0, 0xa0, 0x54,
	0xfc, 0x00, 0xa1, 0xa1, 0xf0, 0xf0, 0xa0, 0x54,
	0xfc, 0x00, 0x52, 0x52, 0xf0, 0xf0, 0xa0, 0x54,
	0xfc, 0x00, 0xa1, 0xa1, 0xf0, 0xf0, 0xa0, 0x54,
	0xfc, 0x00, 0x52, 0x46, 0xe4, 0xf0, 0xa0, 0x54,
	0x3c, 0x00, 0xa1, 0xd0, 0xd8, 0xd0, 0xa0, 0x3c,
	0xfc, 0xa8, 0x42, 0xc8, 0xc0, 0xc8, 0xa0, 0xfc,
	0xfc, 0xa8, 0x40, 0xe4, 0xcc, 0xe0, 0x00, 0xfc,
	0xfc, 0xa8, 0x40, 0xf0, 0xf0, 0xe0, 0x54, 0xfc,
	0xfc, 0xfc, 0x40, 0xe0, 0xc0, 0xe0, 0xfc, 0xfc,
	0xfc, 0xfc, 0xfc, 0xf0, 0xd0, 0xf4, 0xfc, 0xfc,
	0xfc, 0xfc, 0xfc, 0xf8, 0xf0, 0xfc, 0xfc, 0xfc,
	0x3c, 0x6c, 0xcc, 0xc8, 0xe0, 0xcc, 0xcc, 0x3c,
	0xec, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc,
	0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc,
	0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc
};

// Tile av_avatars_10: 16x32 pixels, 8x32 bytes.
const u8 av_avatars_10[8 * 32] = {
	0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc,
	0x30, 0x30, 0x30, 0x10, 0x00, 0x20, 0x30, 0x30,
	0xcc, 0xcc, 0xcc, 0x88, 0x00, 0x44, 0xcc, 0xcc,
	0x30, 0x30, 0x10, 0x00, 0x00, 0x10, 0x30, 0x30,
	0xcc, 0xcc, 0x88, 0x00, 0x00, 0x00, 0xcc, 0xcc,
	0xcc, 0x88, 0x88, 0x00, 0x00, 0x00, 0xcc, 0xcc,
	0x30, 0x20, 0x00, 0x00, 0x00, 0x00, 0x10, 0x30,
	0x88, 0x88, 0x00, 0x00, 0xa0, 0x00, 0x00, 0x44,
	0xcc, 0x00, 0x00, 0x50, 0xe4, 0x00, 0x00, 0xcc,
	0x88, 0x00, 0x00, 0xf0, 0xe4, 0xa0, 0x00, 0xcc,
	0x20, 0x00, 0x50, 0xe4, 0xe4, 0xf0, 0x00, 0x10,
	0x00, 0x00, 0xf0, 0xf0, 0xd8, 0xf0, 0x00, 0x00,
	0x40, 0x00, 0x50, 0xe4, 0xcc, 0xf0, 0xa0, 0x00,
	0x80, 0x00, 0x00, 0xf0, 0xf0, 0xe0, 0x80, 0x00,
	0x00, 0x00, 0x00, 0xc0, 0xf0, 0xc0, 0x00, 0x00,
	0x80, 0x00, 0x00, 0xc0, 0xc0, 0x80, 0x00, 0x00,
	0xc0, 0x00, 0x00, 0xc0, 0xc0, 0x80, 0x00, 0x00,
	0xc0, 0x80, 0x00, 0x80, 0xc0, 0xc0, 0x00, 0x00,
	0x40, 0x80, 0x00, 0x40, 0xc0, 0xc0, 0x40, 0x00,
	0xc0, 0x80, 0x00, 0xc0, 0xc0, 0xc0, 0xc0, 0x80,
	0x80, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0x80,
	0x80, 0xc0, 0xc0, 0x40, 0xc0, 0x40, 0xc0, 0xc0,
	0xc0, 0x00, 0x00, 0xc0, 0xc0, 0x80, 0x00, 0x00,
	0xc0, 0xc0, 0xc0, 0x81, 0x03, 0xc0, 0xc0, 0xc0,
	0xc0, 0xc0, 0xc0, 0x03, 0x03, 0x42, 0xc0, 0xc0,
	0xc0, 0xc0, 0x81, 0x29, 0x03, 0x29, 0xc0, 0xc0,
	0xc0, 0xc0, 0x03, 0x3c, 0x16, 0x29, 0x42, 0xc0,
	0xc0, 0xc0, 0x03, 0x03, 0x03, 0x03, 0x42, 0xc0,
	0xc0, 0xc0, 0x03, 0x03, 0x03, 0x03, 0x42, 0xc0,
	0xc0, 0xc0, 0x03, 0x29, 0x29, 0x29, 0x42, 0xc0,
	0xc0, 0xc0, 0x81, 0x16, 0x16, 0x03, 0xc0, 0xc0,
	0xc0, 0xc0, 0xc0, 0x03, 0x03, 0x42, 0xc0, 0xc0
};

// Tile av_avatars_11: 16x32 pixels, 8x32 bytes.
const u8 av_avatars_11[8 * 32] = {
	0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c, 0x3c,
	0x03, 0x03, 0x02, 0x00, 0x81, 0x03, 0x03, 0x03,
	0x3c, 0x68, 0x00, 0x00, 0x00, 0x94, 0x3c, 0x3c,
	0x03, 0x02, 0x00, 0x00, 0x00, 0x01, 0x03, 0x03,
	0x3c, 0x80, 0x00, 0x00, 0x00, 0x40, 0x3c, 0x3c,
	0x68, 0x00, 0x00, 0x00, 0x00, 0x40, 0x3c, 0x3c,
	0x02, 0x50, 0xe0, 0x00, 0x00, 0x40, 0x03, 0x03,
	0x80, 0x52, 0xf0, 0xf0, 0xf0, 0xb4, 0x3c, 0x3c,
	0x00, 0xf0, 0xf0, 0xf0, 0xf0, 0xb4, 0x3c, 0x3c,
	0x00, 0xf0, 0xf0, 0xf0, 0xf0, 0xb4, 0x3c, 0x3c,
	0x00, 0xf0, 0xf0, 0xf0, 0x08, 0xa1, 0x03, 0x03,
	0x00, 0x52, 0xf0, 0x08, 0x08, 0xb4, 0x3c, 0x3c,
	0x80, 0x40, 0xf0, 0x08, 0xf0, 0x81, 0x3c, 0x3c,
	0x28, 0x00, 0xf0, 0xf0, 0xe0, 0xf0, 0x16, 0x3c,
	0x68, 0x00, 0xf0, 0xf0, 0xf0, 0xf0, 0xb4, 0x3c,
	0x03, 0x00, 0xf0, 0xf0, 0xf0, 0xf0, 0xa1, 0x03,
	0x3c, 0xd0, 0xf0, 0xf0, 0xf0, 0xf0, 0xb4, 0x3c,
	0x3c, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0x16, 0x3c,
	0x3c, 0xf0, 0xf0, 0xf0, 0xe0, 0xf0, 0x78, 0x3c,
	0x3c, 0x52, 0xf0, 0xd0, 0xf0, 0x94, 0x78, 0xd0,
	0x3c, 0x3c, 0xd0, 0x94, 0xf0, 0x3c, 0xd0, 0xf0,
	0x3c, 0x3c, 0x78, 0xb4, 0x3c, 0x3c, 0x50, 0x81,
	0x03, 0x03, 0x42, 0xe0, 0x03, 0x02, 0xd0, 0xf0,
	0x3c, 0x3c, 0x3c, 0xf0, 0x94, 0x40, 0xd0, 0x78,
	0x3c, 0x28, 0x00, 0xd0, 0xa0, 0xc0, 0xd0, 0xb4,
	0x3c, 0x80, 0x80, 0xc0, 0x40, 0xc0, 0x14, 0xb4,
	0x3c, 0x00, 0xc0, 0xc0, 0x40, 0x80, 0x3c, 0x3c,
	0x28, 0xc0, 0xc0, 0x40, 0xc0, 0x14, 0x3c, 0x3c,
	0x28, 0xc0, 0xc0, 0x80, 0xc0, 0x14, 0x3c, 0x3c,
	0x02, 0x80, 0xc0, 0xc0, 0xc0, 0x40, 0x03, 0x03,
	0x68, 0xc0, 0x40, 0xc0, 0xc0, 0x80, 0x3c, 0x3c,
	0x3c, 0x40, 0x40, 0xc0, 0xc0, 0x80, 0x3c, 0x3c
};

// Tile av_avatars_12: 16x32 pixels, 8x32 bytes.
const u8 av_avatars_12[8 * 32] = {
	0xf3, 0xf3, 0xf3, 0x80, 0x40, 0x51, 0xf3, 0xf3,
	0xf0, 0xf0, 0xe0, 0x00, 0x00, 0x40, 0xf0, 0xf0,
	0xf3, 0xf3, 0xa2, 0x00, 0x00, 0x00, 0xf3, 0xf3,
	0xf0, 0xf0, 0x80, 0xf0, 0xf0, 0xa0, 0x50, 0xf0,
	0xf3, 0xf3, 0x00, 0xf0, 0xf0, 0xa0, 0x51, 0xf3,
	0xf3, 0xf3, 0x50, 0xf0, 0xf0, 0xf0, 0x51, 0xf3,
	0xf0, 0xf0, 0x50, 0x08, 0xa4, 0x50, 0x50, 0xf0,
	0xf3, 0xf3, 0xd0, 0x08, 0xa4, 0x50, 0xd1, 0xf3,
	0xf3, 0xf3, 0xf0, 0xc0, 0xe0, 0xd0, 0xf1, 0xf3,
	0xf3, 0xf3, 0xf0, 0xf0, 0xf0, 0xf0, 0xf1, 0xf3,
	0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0,
	0xf3, 0xf3, 0xf0, 0xe4, 0xe4, 0xf0, 0xf1, 0xf3,
	0xf3, 0xf3, 0xf0, 0xf0, 0xd8, 0xf0, 0xf1, 0xf3,
	0xf3, 0xf3, 0xf2, 0xf0, 0xf0, 0xf0, 0xf3, 0xf3,
	0xf3, 0xf3, 0xf2, 0xf0, 0xf0, 0xd8, 0xf3, 0xf3,
	0xf0, 0xf0, 0xf0, 0xe4, 0xcc, 0xf0, 0xf0, 0xf0,
	0xf3, 0xf3, 0xf2, 0xf0, 0xf0, 0xf0, 0xf3, 0xf3,
	0xf3, 0xf3, 0xf3, 0xf0, 0xf0, 0xf1, 0xf3, 0xf3,
	0xf3, 0xf3, 0xf3, 0xf0, 0xf0, 0xf1, 0xf3, 0xf3,
	0xf3, 0xf3, 0xf3, 0xf2, 0xd0, 0xf3, 0xf3, 0xf3,
	0xf3, 0xf3, 0xf3, 0xf2, 0xf0, 0xf3, 0xf3, 0xf3,
	0xf0, 0xe0, 0x86, 0xc3, 0xc3, 0x86, 0xc0, 0xf0,
	0xf3, 0xc1, 0xc3, 0x0c, 0x0c, 0x49, 0xc3, 0xd1,
	0xe2, 0xc3, 0xc3, 0xc2, 0xc0, 0xc3, 0xc3, 0xc2,
	0xc1, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3,
	0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3,
	0xc3, 0x86, 0x86, 0x04, 0x0c, 0x04, 0x86, 0x41,
	0xc3, 0x86, 0x0c, 0x04, 0x82, 0x04, 0x86, 0x41,
	0xc3, 0x86, 0x04, 0x04, 0x0c, 0x41, 0x08, 0x41,
	0xc3, 0x86, 0x04, 0x41, 0x86, 0x04, 0x86, 0x41,
	0xc3, 0x86, 0x04, 0x41, 0x86, 0x04, 0x86, 0x41,
	0xc3, 0x86, 0x04, 0x04, 0x0c, 0x04, 0x86, 0x41
};

// Tile av_avatars_13: 16x32 pixels, 8x32 bytes.
const u8 av_avatars_13[8 * 32] = {
	0x03, 0x03, 0x03, 0x42, 0x81, 0x03, 0x03, 0x03,
	0x3c, 0x3c, 0x3c, 0x80, 0x40, 0x3c, 0x3c, 0x3c,
	0x03, 0x03, 0x42, 0x00, 0x00, 0x81, 0x03, 0x03,
	0x3c, 0x3c, 0x28, 0x00, 0x00, 0x14, 0x3c, 0x3c,
	0x03, 0x03, 0x80, 0x00, 0x00, 0x40, 0x03, 0x03,
	0x03, 0x03, 0x40, 0xa0, 0x00, 0x00, 0x03, 0x03,
	0x3c, 0x3c, 0x50, 0xf0, 0xa0, 0x00, 0x3c, 0x3c,
	0x03, 0x03, 0x40, 0xf0, 0xe0, 0x00, 0x03, 0x03,
	0x03, 0x42, 0x00, 0x4c, 0x04, 0x00, 0x81, 0x03,
	0x03, 0x02, 0x50, 0xe4, 0xf0, 0x00, 0x01, 0x03,
	0x3c, 0x28, 0x50, 0xe4, 0xf0, 0x50, 0x14, 0x3c,
	0x03, 0x02, 0x50, 0xc8, 0xf0, 0x50, 0x01, 0x03,
	0x03, 0x02, 0x00, 0x00, 0x00, 0x40, 0x40, 0x03,
	0x03, 0x02, 0x00, 0x0c, 0x08, 0x40, 0x00, 0x03,
	0x03, 0x02, 0x00, 0xf0, 0xa0, 0x00, 0x00, 0x03,
	0x3c, 0x28, 0x00, 0x00, 0x80, 0x00, 0x00, 0x94,
	0x03, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
	0x03, 0x00, 0x50, 0x00, 0x50, 0x80, 0x00, 0x80,
	0x42, 0x80, 0x50, 0xd0, 0xf0, 0x80, 0x00, 0xc0,
	0x80, 0x80, 0x50, 0xd0, 0xf0, 0x80, 0x00, 0xc0,
	0x40, 0x08, 0x40, 0xd0, 0xe0, 0x00, 0x00, 0xc0,
	0xc0, 0x80, 0x50, 0xc0, 0xd0, 0x40, 0x00, 0xc0,
	0xc0, 0x80, 0x50, 0xe0, 0xf0, 0x40, 0x00, 0xc0,
	0xc0, 0x80, 0x50, 0xe0, 0xf0, 0x40, 0x00, 0xc0,
	0xc0, 0x00, 0x50, 0xe0, 0xf0, 0x40, 0x00, 0x40,
	0xc0, 0x00, 0x50, 0xe0, 0xf0, 0x40, 0x00, 0x40,
	0xc0, 0x00, 0x50, 0xe0, 0xa0, 0xc0, 0x00, 0x40,
	0xc0, 0x00, 0x00, 0xe0, 0xa0, 0x84, 0x00, 0x40,
	0xc0, 0x00, 0x00, 0xe0, 0x00, 0xc0, 0x00, 0x40,
	0x80, 0x00, 0x00, 0x00, 0x00, 0x84, 0x80, 0x00,
	0x80, 0x00, 0x00, 0x00, 0x40, 0xc0, 0x80, 0x00,
	0x80, 0x00, 0x80, 0x00, 0x40, 0xc0, 0x80, 0x00
};

// Tile av_avatars_14: 16x32 pixels, 8x32 bytes.
const u8 av_avatars_14[8 * 32] = {
	0x33, 0x33, 0x27, 0xc3, 0xc7, 0x33, 0x33, 0x33,
	0xfc, 0xfc, 0x4b, 0x4b, 0xc3, 0xde, 0xfc, 0xfc,
	0x33, 0x27, 0x87, 0xc3, 0xc7, 0xc7, 0x33, 0x33,
	0xfc, 0xad, 0x4b, 0x4b, 0xc3, 0xcb, 0xfc, 0xfc,
	0x33, 0x27, 0x87, 0xc3, 0xc7, 0xc7, 0x33, 0x33,
	0x33, 0x27, 0x0f, 0x0f, 0x0f, 0xcb, 0x33, 0x33,
	0xfc, 0xad, 0x0f, 0x0f, 0x0f, 0x0f, 0xfc, 0xfc,
	0x33, 0x0f, 0x5a, 0xf0, 0xf0, 0x0f, 0x1b, 0x33,
	0x33, 0x5a, 0x00, 0xf0, 0xa0, 0x50, 0x1b, 0x33,
	0x33, 0xe0, 0xa0, 0x50, 0x00, 0xe0, 0xb1, 0x33,
	0xfc, 0xa0, 0x50, 0x50, 0x50, 0x00, 0xf4, 0xfc,
	0x33, 0xe0, 0x0d, 0x08, 0x0d, 0x48, 0xb1, 0x33,
	0x33, 0xe0, 0x00, 0x50, 0x00, 0x40, 0xb1, 0x33,
	0x33, 0xa0, 0xf0, 0xf0, 0xf0, 0xa0, 0xb1, 0x33,
	0x33, 0xa0, 0xf0, 0xf0, 0xf0, 0xa0, 0xb1, 0x33,
	0x33, 0x22, 0xd0, 0xd8, 0xd8, 0x80, 0x33, 0x33,
	0xfc, 0xa8, 0x50, 0xe4, 0xf0, 0x00, 0xfc, 0xfc,
	0x33, 0x22, 0x40, 0xc0, 0xc0, 0x00, 0x33, 0x33,
	0x33, 0x62, 0x44, 0xf0, 0xe4, 0x40, 0x33, 0x33,
	0x33, 0x33, 0x50, 0xcc, 0xd8, 0x11, 0x33, 0x33,
	0x33, 0x33, 0x00, 0xf0, 0xa0, 0x11, 0x33, 0x33,
	0x33, 0x33, 0x80, 0xd0, 0x80, 0x91, 0x33, 0x33,
	0xfc, 0xfc, 0xa8, 0x00, 0x00, 0xfc, 0xfc, 0xfc,
	0x33, 0x33, 0x33, 0x00, 0x11, 0x33, 0x33, 0x33,
	0x33, 0x66, 0xc4, 0xf0, 0xe4, 0xc4, 0x33, 0x33,
	0x66, 0xcc, 0xc4, 0xd8, 0xcc, 0xc4, 0xcc, 0x33,
	0xcc, 0xcc, 0xc8, 0xcc, 0xc8, 0xcc, 0xcc, 0x99,
	0xcc, 0xcc, 0xcc, 0xc0, 0xc4, 0xcc, 0xcc, 0xcc,
	0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc,
	0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc,
	0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc,
	0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc
};

// Tile av_avatars_15: 16x32 pixels, 8x32 bytes.
const u8 av_avatars_15[8 * 32] = {
	0xcf, 0xcf, 0xcf, 0x00, 0x45, 0xcf, 0xcf, 0xcf,
	0xc3, 0xc3, 0x82, 0x00, 0x00, 0xc3, 0xc3, 0xc3,
	0xcf, 0xcf, 0x00, 0x00, 0x00, 0x45, 0xcf, 0xcf,
	0xc3, 0xc2, 0x00, 0x50, 0x00, 0x40, 0xc3, 0xc3,
	0xcf, 0x8a, 0x50, 0xf0, 0xa0, 0x00, 0xcf, 0xcf,
	0xcf, 0x8a, 0xf0, 0xf0, 0xf0, 0xa0, 0xcf, 0xcf,
	0xc3, 0x82, 0x00, 0xf0, 0xa0, 0x00, 0xc3, 0xc3,
	0xcf, 0x8a, 0xf0, 0x50, 0x50, 0xa0, 0xcf, 0xcf,
	0xcf, 0x8a, 0x00, 0x50, 0x00, 0x00, 0xcf, 0xcf,
	0xcf, 0xca, 0x08, 0x08, 0x08, 0x48, 0xcf, 0xcf,
	0xc3, 0xc2, 0xf0, 0xd0, 0xd0, 0xe0, 0xc3, 0xc3,
	0xcf, 0xda, 0xc0, 0xd0, 0xc0, 0xd0, 0xcf, 0xcf,
	0xcf, 0xda, 0xf0, 0xf0, 0xf0, 0xf0, 0xcf, 0xcf,
	0xcf, 0xda, 0xf0, 0xd8, 0xd8, 0xf0, 0xcf, 0xcf,
	0xcf, 0xca, 0xf0, 0xe4, 0xf0, 0xe0, 0xcf, 0xcf,
	0xc3, 0xc3, 0xf0, 0xf0, 0xf0, 0xe1, 0xc3, 0xc3,
	0xcf, 0xcf, 0xc0, 0xf0, 0xe0, 0xc5, 0xcf, 0xcf,
	0xcf, 0xcf, 0x80, 0xc0, 0x80, 0xc5, 0xcf, 0xcf,
	0xcf, 0xcf, 0xc0, 0x00, 0x40, 0xc5, 0xcf, 0xcf,
	0xcf, 0xcf, 0xca, 0xc0, 0xc0, 0xcf, 0xcf, 0xcf,
	0xcf, 0xcf, 0xda, 0xc0, 0xd0, 0xcf, 0xcf, 0xcf,
	0xc3, 0xc3, 0xd0, 0xf4, 0xf0, 0xc1, 0xc3, 0xc3,
	0xcf, 0xca, 0x50, 0xf0, 0xf0, 0x40, 0xcf, 0xcf,
	0xcf, 0x40, 0x00, 0xf0, 0xa0, 0x40, 0x45, 0xcf,
	0x8a, 0x00, 0x80, 0x00, 0x00, 0x80, 0x00, 0xcf,
	0x00, 0x00, 0x40, 0xc0, 0xc0, 0x00, 0x00, 0x45,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x0c, 0x84, 0x48, 0x18, 0x30, 0x08, 0x00,
	0x00, 0x0c, 0x84, 0xc0, 0x30, 0x24, 0x08, 0x00,
	0x00, 0x0c, 0x84, 0x18, 0x30, 0x84, 0x08, 0x00,
	0x00, 0x48, 0x84, 0x30, 0x24, 0x84, 0x80, 0x00
};

// Tile av_avatars_16: 16x32 pixels, 8x32 bytes.
const u8 av_avatars_16[8 * 32] = {
	0x10, 0x44, 0xcc, 0x98, 0x98, 0x44, 0x98, 0xcc,
	0x44, 0x44, 0x4c, 0xcc, 0x98, 0x44, 0xcc, 0xcc,
	0x44, 0x45, 0x8e, 0xcc, 0x98, 0x44, 0xcc, 0xcc,
	0x00, 0x45, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x30, 0x00, 0x45, 0x08, 0x30, 0x10, 0x30, 0x10,
	0x98, 0x45, 0x8a, 0x44, 0x98, 0x44, 0x98, 0x10,
	0x98, 0x82, 0x44, 0x44, 0x98, 0x44, 0x98, 0x44,
	0x00, 0x00, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x10, 0x20, 0xe4, 0x30, 0x10, 0x30, 0x10, 0x30,
	0x44, 0x41, 0xe4, 0x98, 0x44, 0x98, 0x44, 0x98,
	0x44, 0x00, 0xda, 0x10, 0x44, 0x98, 0x44, 0x98,
	0x00, 0x04, 0x82, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x20, 0x8e, 0x45, 0x10, 0x30, 0x10, 0x30, 0x10,
	0x88, 0x8e, 0x45, 0x00, 0x98, 0x44, 0x98, 0x00,
	0x88, 0x8e, 0x00, 0x41, 0x10, 0x44, 0xcc, 0x40,
	0x00, 0x8a, 0xc0, 0x00, 0x00, 0x45, 0x00, 0x40,
	0x00, 0x8a, 0xc0, 0xc0, 0x41, 0xc3, 0x10, 0x20,
	0x00, 0x8e, 0x00, 0x00, 0x0f, 0xa0, 0x44, 0x98,
	0x00, 0x8e, 0x0c, 0x50, 0x02, 0x10, 0x44, 0x98,
	0x00, 0xcf, 0x0c, 0x50, 0x00, 0x00, 0x00, 0x00,
	0x20, 0x45, 0xcf, 0x08, 0x30, 0x10, 0x30, 0x10,
	0x88, 0x82, 0x00, 0x44, 0x98, 0x44, 0x98, 0x44,
	0x88, 0xc7, 0xcf, 0x44, 0x98, 0x44, 0x98, 0x44,
	0x00, 0xcf, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x10, 0x45, 0x8e, 0x08, 0x10, 0x30, 0x10, 0x30,
	0x44, 0x45, 0x8e, 0x08, 0x44, 0x98, 0x10, 0x98,
	0x44, 0x45, 0x8e, 0x00, 0x44, 0x98, 0x44, 0x98,
	0x00, 0x45, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x20, 0x82, 0x8e, 0x10, 0x30, 0x10, 0x30, 0x10,
	0x88, 0xc7, 0x45, 0x08, 0x98, 0x10, 0x98, 0x44,
	0x88, 0xc7, 0x45, 0x08, 0x98, 0x44, 0x98, 0x44,
	0x00, 0xc7, 0x45, 0x08, 0x00, 0x00, 0x00, 0x00
};

// Tile av_avatars_17: 16x32 pixels, 8x32 bytes.
const u8 av_avatars_17[8 * 32] = {
	0xcc, 0x64, 0x88, 0x64, 0x64, 0xcc, 0x88, 0x20,
	0xcc, 0xcc, 0x88, 0x64, 0xcc, 0x8c, 0x88, 0x88,
	0xcc, 0xcc, 0x88, 0x64, 0xcc, 0x4d, 0x8a, 0x88,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x8a, 0x00,
	0x20, 0x30, 0x20, 0x30, 0x04, 0x8a, 0x00, 0x30,
	0x20, 0x64, 0x88, 0x64, 0x88, 0x45, 0x8a, 0x64,
	0x88, 0x64, 0x88, 0x64, 0x88, 0x88, 0x41, 0x64,
	0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x00, 0x00,
	0x30, 0x20, 0x30, 0x20, 0x30, 0xd8, 0x10, 0x20,
	0x64, 0x88, 0x64, 0x88, 0x64, 0xd8, 0x82, 0x88,
	0x64, 0x88, 0x64, 0x88, 0x20, 0xe5, 0x00, 0x88,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x41, 0x08, 0x00,
	0x20, 0x30, 0x20, 0x30, 0x20, 0x8a, 0x4d, 0x10,
	0x00, 0x64, 0x88, 0x64, 0x00, 0x8a, 0x4d, 0x44,
	0x80, 0xcc, 0x88, 0x20, 0x82, 0x00, 0x4d, 0x44,
	0x80, 0x00, 0x8a, 0x00, 0x00, 0xc0, 0x45, 0x00,
	0x10, 0x20, 0xc3, 0x82, 0xc0, 0xc0, 0x45, 0x00,
	0x64, 0x88, 0x50, 0x0f, 0x00, 0x00, 0x4d, 0x00,
	0x64, 0x88, 0x20, 0x01, 0xa0, 0x0c, 0x4d, 0x00,
	0x00, 0x00, 0x00, 0x00, 0xa0, 0x0c, 0xcf, 0x00,
	0x20, 0x30, 0x20, 0x30, 0x04, 0xcf, 0x8a, 0x10,
	0x88, 0x64, 0x88, 0x64, 0x88, 0x00, 0x41, 0x44,
	0x88, 0x64, 0x88, 0x64, 0x88, 0xcf, 0xcb, 0x44,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0xcf, 0x00,
	0x30, 0x20, 0x30, 0x20, 0x04, 0x4d, 0x8a, 0x20,
	0x64, 0x20, 0x64, 0x88, 0x04, 0x4d, 0x8a, 0x88,
	0x64, 0x88, 0x64, 0x88, 0x00, 0x4d, 0x8a, 0x88,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x8a, 0x00,
	0x20, 0x30, 0x20, 0x30, 0x20, 0x4d, 0x41, 0x10,
	0x88, 0x64, 0x20, 0x64, 0x04, 0x8a, 0xcb, 0x44,
	0x88, 0x64, 0x88, 0x64, 0x04, 0x8a, 0xcb, 0x44,
	0x00, 0x00, 0x00, 0x00, 0x04, 0x8a, 0xcb, 0x00
};

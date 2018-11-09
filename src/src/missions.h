#ifndef _MISSIONS_H_
#define _MISSIONS_H_

#define MISSIONS            20

#define MISSION_TYPE        0xC0
#define MISSION_TYPE_SCORE  0xC0
#define MISSION_TYPE_CLEAR  0x80
#define MISSION_TYPE_COMBO  0x40
#define MISSION_TYPE_COLOR  0x00

#define MISSION_SCORE       0x38
#define MISSION_SCORE_1K    0x00
#define MISSION_SCORE_5K    0x08
#define MISSION_SCORE_10K   0x10
#define MISSION_SCORE_12K   0x18

#define MISSION_COLOR       0x38
#define MISSION_COLOR_BL    0x00
#define MISSION_COLOR_RD    0x08
#define MISSION_COLOR_GR    0x10
#define MISSION_COLOR_MG    0x18

#define MISSION_COMBOS      0x38
#define MISSION_COMBOS_1    0x08
#define MISSION_COMBOS_2    0x10
#define MISSION_COMBOS_3    0x18
#define MISSION_COMBOS_4    0x20
#define MISSION_COMBOS_5    0x28
#define MISSION_COMBOS_6    0x30
#define MISSION_COMBOS_7    0x38

#define MISSION_LANDINGS    0x07
#define MISSION_LANDINGS_0  0x00
#define MISSION_LANDINGS_1  0x01
#define MISSION_LANDINGS_2  0x02
#define MISSION_LANDINGS_3  0x03
#define MISSION_LANDINGS_4  0x04
#define MISSION_LANDINGS_5  0x05
#define MISSION_LANDINGS_6  0x06
#define MISSION_LANDINGS_7  0x07

#define MISSION_ST_PENDING  0
#define MISSION_ST_GAMEOVER 1
#define MISSION_ST_CLEARED  2

// Types
typedef struct {
    u32 seed;
    u8 board[72];
    u8 type;
} TMission;

// Functions
TMission*   opqa_getMission(u8 mission);
u8          opqa_checkMissionStatus();
void        opqa_showMissionObjectives();
 
#endif
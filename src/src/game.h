#ifndef _GAME_H_
#define _GAME_H_

// Player constants
#define PLAYER_TEAM             0x08
#define PLAYER_TEAM_OPQA        0x00
#define PLAYER_TEAM_QAOP        0x08

// IA constants
#define CYCLES_PER_STATE_CHANGE 12

#define STATE_THINKING          0
#define STATE_ROTATING          1
#define STATE_MOVING            2
#define STATE_DESCENDING        3

// Keyboard constants
#define KEY_LEFT                0
#define KEY_RIGHT               1
#define KEY_UP                  2
#define KEY_DOWN                3
#define KEY_FIRE1               4
#define KEY_FIRE2               5

#define KEY_PAUSE               0
#define KEY_ABORT               1

#define KEY_DELAY_FIRST         8
#define KEY_DELAY_REPEAT        3
#define KEY_DELAY_FALL_REPEAT   255

// Game constants
#define CHARACTERS              16

#define MODE_STORY              0
#define MODE_VERSUS             1
#define MODE_ENDLESS            2
#define MODE_MISSION            3
#define MODE_DEMO               4

#define PLAYER_HUMAN            0
#define PLAYER_CPU              1
#define PLAYER_NONE             2

#define CYCLES_PER_MOVEMENT     35
#define MININUM_CYCLESPM        4
#define COMBOS_PER_SPEED        3

#define DEMO_FLASH_SPEED        50

#define OPQA_SCORE              1000

// Macros
#define PLAYER_LANDBLOCK if (!opqa_landBlock(player)) {\
                        gameover = 1;\
                    } else {\
                        u->landed = 1;\
                        if (s->mode == MODE_MISSION) { p->landings++; }\
                    }

#define IA_LANDBLOCK if (!opqa_landBlock(player)) {\
                        gameover = 1;\
                    } else {\
                        u->landed = 1;\
                        ia->state = STATE_THINKING;\
                    }

// Memory constants
#define UPDATE_OBJ_SIZE         6
#define KEYDELAY_OBJ_SIZE       12

// Types
typedef struct {
    u8 avatar;
    u32 score;
    u8 combo;
    u8 combos;
    u8 flashing;
    u8 cycles_per_movement;
    u8 current_cycle;
    u8 gameover;
    u8 landings;
} TPlayer;

typedef struct {
    u8 state;
    u8 cycle;
    u8 rotation;
    u8 x;
} TIA;

typedef struct {
    u8 block;
    u8 next;
    u8 score;
    u8 landed;
    u8 flash;
    u8 garbage;
} TUpdate;

typedef struct {
    u8 mode;
    u8 level;
    u32 hiscore;
} TState;

// Getters
TPlayer*    opqa_getPlayer(u8 player);
TIA*        opqa_getIA(u8 player);
TUpdate*    opqa_getUpdate(u8 player);
TState*     opqa_getState();
char**      opqa_getNames();

// Resets
void        opqa_resetState();
void        opqa_resetIA(u8 player);
void        opqa_resetKeyDelay();
void        opqa_resetKeyRepeat();
void        opqa_resetUpdate();

// Screens
void        opqa_title();
void        opqa_selectCharacter();
void        opqa_stageScreen();
void        opqa_playRound();
u8          opqa_playMission();
void        opqa_gameOver();
void        opqa_success();

// Functions
void        opqa_init();
void        opqa_playFX(u8 fx, u8 channel);

#endif
#include <cpctelera.h>
#include "game.h"
#include "blocks.h"
#include "board.h"
#include "video.h"
#include "sound.h"
#include "utils.h"
#include "missions.h"

#include "sound/menu.h"
#include "sound/select.h"
#include "sound/stage.h"
#include "sound/gameover.h"
#include "sound/complete.h"
#include "sound/sfx.h"

#include "gfx/avatars.h"
#include "gfx/level.h"

const TPlayer player_state[2] = {
    {
        0,
        0,
        0,
        0,
        CYCLES_PER_MOVEMENT,
        0,
        0
    },
    {
        8,
        0,
        0,
        0,
        CYCLES_PER_MOVEMENT,
        0,
        0
    }
};

const TIA ia_state[2] = {
    {
        STATE_THINKING,
        0,
        0,
        0
    },
    {
        STATE_THINKING,
        0,
        0,
        0
    }
};

const TUpdate update[2] = {
    {
        0,
        0,
        0,
        0,
        0
    },
    {
        0,
        0,
        0,
        0,
        0
    }
};

const u8 key_delay[2][6] = {
    {
        0,
        0,
        0,
        0,
        0,
        0
    },
    {
        0,
        0,
        0,
        0,
        0,
        0
    }
};

const u8 key_repeat[2] = {
    0,
    0
};

const cpct_keyID player_keys[2][6] = {
    {
        Joy0_Left,
        Joy0_Right,
        Joy0_Up,
        Joy0_Down,
        Joy0_Fire1,
        Joy0_Fire2
    },
    {
        Joy1_Left,
        Joy1_Right,
        Joy1_Up,
        Joy1_Down,
        Joy1_Fire1,
        Joy1_Fire2
    }
};

const cpct_keyID game_keys[2] = {
    Key_P,
    Key_Esc
};

const TState state = {
    0,
    0
};

const char* names[CHARACTERS];


// Private functions
void        opqa_resetPlayer(u8 player);
u8          opqa_checkKeyboardSelection(u8 player);
u8          opqa_updateGame(u8 player);
void        opqa_playFXCombo(u8 channel, u8 note);
void        opqa_playDemo();
u8          opqa_checkPlayer(u8 player);
u8          opqa_doPlayerIA(u8 player);
void        opqa_doIAThink(u8 player);

// Getters
TPlayer* opqa_getPlayer(u8 player) { return &player_state[player]; }
TIA* opqa_getIA(u8 player) { return &ia_state[player]; }
TUpdate* opqa_getUpdate(u8 player) { return &update[player]; }
TState* opqa_getState() { return &state; }
u8* opqa_getKeyDelay(u8 player) { return (u8*) key_delay[player]; }
u8* opqa_getKeyRepeat(u8 player) { return (u8*) key_repeat[player]; }
cpct_keyID* opqa_getKeys(u8 player) { return (cpct_keyID*) &player_keys[player]; }
cpct_keyID* opqa_getGameKeys() { return (cpct_keyID*) &game_keys; }
char** opqa_getNames() { return (char**) &names; }

// Resets
void opqa_resetState() {
    TState* s = opqa_getState();
    TBlock* b1 = opqa_getCurrentBlock(0);
    TBlock* b2 = opqa_getCurrentBlock(1);

    s->level = 0;
    opqa_resetPlayer(0);
    opqa_resetPlayer(1);
    opqa_resetIA(0);
    opqa_resetIA(1);

    b1->pieces[0] = 0;
    b1->y = 0;
    b2->pieces[0] = 0;
    b2->y = 0;

    opqa_resetKeyDelay();
    opqa_resetKeyRepeat();
    opqa_resetUpdate();
    opqa_resetBoardArray(opqa_getBoard(0));
    opqa_resetBoardArray(opqa_getBoard(1));
    opqa_resetBoardArray(opqa_getFlash(0));
    opqa_resetBoardArray(opqa_getFlash(1));
    opqa_resetBoardArray(opqa_getGarbage(0));
    opqa_resetBoardArray(opqa_getGarbage(1));

    opqa_resetGarbageX();
}

void opqa_resetPlayer(u8 player) {
    TPlayer* p = opqa_getPlayer(player);

    p->avatar = player ? 8 : 0;
    p->score = 0;
    p->combo = 0;
    p->combos = 0;
    p->cycles_per_movement = CYCLES_PER_MOVEMENT;
    p->current_cycle;
    p->gameover = 0;
    p->landings = 0;
}

void opqa_resetIA(u8 player) {
    TIA* ia = opqa_getIA(player);

    ia->state = STATE_THINKING;
}

void opqa_resetKeyDelay() {
    u8* kdp = (u8*) key_delay;
    u8 i;

    for (i = 0; i < KEYDELAY_OBJ_SIZE; i++) {
        *kdp++ = 0;
    }
}

void opqa_resetKeyRepeat() {
    u8* kr = opqa_getKeyRepeat(0);

    *kr++ = 0;
    *kr = 0;
}

void opqa_resetUpdate() {
    u8* u1 = (u8*) opqa_getUpdate(0);
    u8* u2 = (u8*) opqa_getUpdate(1);
    u8 i = 0;

    for (; i < UPDATE_OBJ_SIZE; i++) {
        *u1++ = 0;
        *u2++ = 0;
    }
}

// Screens
void opqa_title() {
    u8 finished = 0;
    cpct_keyID key;
    u8* pvmem;
    TState* s = opqa_getState();
    TPlayer* p2 = opqa_getPlayer(1);
    cpct_keyID* pk = opqa_getKeys(0);
    cpct_keyID* gk = opqa_getGameKeys();
    u8 s1 = 0, s2 = 0;
    u32 seed = 0;

    cpct_akp_musicInit(msc_menu);

    opqa_drawTitle(s1);
    opqa_fade(FADE_IN);

    while (!finished) {
        cpct_scanKeyboard_f();
        if (cpct_isAnyKeyPressed_f()) {
            key = opqa_getKey();
            opqa_waitForKeyRelease(key);

            if (!seed) {
                seed = 0x5423;
            }
            cpct_srand(seed);

            switch (key) {
                case Key_1:
                case Joy0_Fire1:
                    s->mode = MODE_STORY;
                    finished = 1;
                    break;

                case Key_2:
                case Joy1_Fire1:
                    s->mode = MODE_VERSUS;
                    finished = 1;
                    break;

                case Key_3:
                case Joy0_Fire2:
                    s->mode = MODE_MISSION;
                    finished = 1;
                    break;

                case Key_4:
                case Key_P:
                    s->mode = MODE_ENDLESS;
                    finished = 1;
                    break;

                case Key_5:
                    *pk++ = opqa_redefineKey("player 1 - move left");
                    *pk++ = opqa_redefineKey("player 1 - move right");
                    *pk++ = opqa_redefineKey("player 1 - instant fall");
                    *pk++ = opqa_redefineKey("player 1 - quick fall");
                    *pk++ = opqa_redefineKey("player 1 - rotate clockwise");
                    *pk++ = opqa_redefineKey("player 1 - rotate anticlockwise");

                    *pk++ = opqa_redefineKey("player 2 - move left");
                    *pk++ = opqa_redefineKey("player 2 - move right");
                    *pk++ = opqa_redefineKey("player 2 - instant fall");
                    *pk++ = opqa_redefineKey("player 2 - quick fall");
                    *pk++ = opqa_redefineKey("player 2 - rotate clockwise");
                    *pk++ = opqa_redefineKey("player 2 - rotate anticlockwise");

                    *gk++ = opqa_redefineKey("pause");
                    *gk++ = opqa_redefineKey("quit game");

                    pk = opqa_getKeys(0);
                    gk = opqa_getGameKeys();

                    cpct_waitVSYNC();
                    pvmem = cpctm_screenPtr(CPCT_VMEM_START, 8, 136);
                    cpct_drawSolidBox(pvmem, 0, 64, 16);

                    break;
            }
        }

        cpct_waitVSYNC();

        // Counters
        seed++;
        s2++;

        // Scroll avatars        
        if (s2 == 3) {
            s1++;
            s2 = 0;
            opqa_showScrolledAvatars(s1);
        }

        // Rolling demo
        if (cpct_akp_songLoopTimes) {
            cpct_akp_musicInit(sfx);
            opqa_fade(FADE_OUT);            

            opqa_playDemo();

            opqa_fade(FADE_OUT);
            opqa_resetState();
            cpct_akp_musicInit(msc_menu);
            opqa_drawTitle(s1);
            opqa_fade(FADE_IN);
        }
    }

    opqa_fade(FADE_OUT);
    cpct_akp_musicInit(sfx);
}

void opqa_playDemo() {
    u8 gameover1 = 0;
    u8 gameover2 = 0;
    TBlock* nextb1 = opqa_getNextBlock(0);
    TBlock* nextb2 = opqa_getNextBlock(1);
    TPlayer* p1 = opqa_getPlayer(0);
    TPlayer* p2 = opqa_getPlayer(1);
    TUpdate* u1 = opqa_getUpdate(0);
    TUpdate* u2 = opqa_getUpdate(1);
    TState* s = opqa_getState();
    u8* pvmem;
    u8 c = 0;

    opqa_resetBoardArray(opqa_getBoard(0));
    opqa_resetBoardArray(opqa_getBoard(1));
    p1->avatar = cpct_rand() & 0x7;
    p2->avatar = p1->avatar + 8;
    s->mode = MODE_DEMO;

    opqa_drawLevel();
    pvmem = cpctm_screenPtr(CPCT_VMEM_START, 32, 72);
    cpct_drawSolidBox(pvmem, 0, 16, 16);
    opqa_fade(FADE_IN); 

    opqa_newRandomBlock(nextb1);
    opqa_drawNextBlock(0);
    opqa_newRandomBlock(nextb2);
    opqa_drawNextBlock(1);

    do {
        // Check player movements if board isn't flashing
        if (!u1->flash && !u1->garbage) {
            gameover1 = opqa_doPlayerIA(0);
        }
        if (!u2->flash && !u2->garbage) {   
            gameover2 = opqa_doPlayerIA(1);
        }

        // Check for pause and abort keys
        cpct_scanKeyboard_f();
        if (cpct_isAnyKeyPressed_f()) {
            gameover1 = 1;
            gameover2 = 1;
        }

        cpct_waitVSYNC();

        opqa_updateGame(0);
        opqa_updateGame(1);

        c++;
        if (c == DEMO_FLASH_SPEED) {
            opqa_drawText(36, 72, "DEMO");
        } else if (c == DEMO_FLASH_SPEED * 2) {
            cpct_drawSolidBox(pvmem, 0, 16, 16);
            c = 0;
        }
    } while (!gameover1 && !gameover2);
}

void opqa_selectCharacter() {
    TState* s = opqa_getState();    
    TPlayer* p1 = opqa_getPlayer(0);
    TPlayer* p2 = opqa_getPlayer(1);
    u8 finished1 = 0, finished2 = 0;

    cpct_akp_musicInit(msc_select);

    opqa_drawSelectionScreen();
    opqa_fade(FADE_IN);

    do {
        cpct_scanKeyboard_f();

        if (cpct_isAnyKeyPressed_f()) {
            // Player 1
            if (!finished1) {
                finished1 = opqa_checkKeyboardSelection(0);
            }

            // Player 2
            if (s->mode == MODE_VERSUS && !finished2) {
                finished2 = opqa_checkKeyboardSelection(1);
            }
        } else {
            opqa_resetKeyRepeat();
            opqa_resetKeyDelay();
        }

        cpct_waitVSYNC();
    } while ((s->mode == MODE_VERSUS && (!finished1 || !finished2)) || (s->mode != MODE_VERSUS && !finished1));

    if (s->mode == MODE_STORY) {
        p2->avatar = ((p1->avatar & PLAYER_TEAM) == PLAYER_TEAM_OPQA) ? 8 : 0;
    }

    opqa_fade(FADE_OUT);
    cpct_akp_musicInit(sfx);
}

u8 opqa_checkKeyboardSelection(u8 player) {
    u8* kd = opqa_getKeyDelay(player);
    u8* kr = opqa_getKeyRepeat(player);
    cpct_keyID* k = opqa_getKeys(player);    
    TPlayer* p = opqa_getPlayer(player);
    TState* s = opqa_getState();

    if (cpct_isKeyPressed(k[KEY_LEFT])) {
        if (!kd[KEY_LEFT]) { 
            opqa_unselectAvatar(player);
            p->avatar = (p->avatar - 4) & 0xF;
            if (s->mode == MODE_VERSUS) {
                if (player && p->avatar < 8) {
                    p->avatar += 8;
                }
                if (!player && p->avatar >= 8) {
                    p->avatar -= 8;
                }
            }            
            opqa_selectAvatar(player);
            kd[KEY_LEFT] = !(*kr & (1 << KEY_LEFT)) ? KEY_DELAY_FIRST : KEY_DELAY_REPEAT;
            *kr |= (1 << KEY_LEFT);
        } else {
            kd[KEY_LEFT]--;
        }
    } else {
        kd[KEY_LEFT] = 0;
        *kr &= ~(1 << KEY_LEFT);
    }

    if (cpct_isKeyPressed(k[KEY_RIGHT])) {
        if (!kd[KEY_RIGHT]) { 
            opqa_unselectAvatar(player);
            p->avatar = (p->avatar + 4) & 0xF;
            if (s->mode == MODE_VERSUS) {
                if (player && p->avatar < 8) {
                    p->avatar += 8;
                }
                if (!player && p->avatar >= 8) {
                    p->avatar -= 8;
                }
            }
            opqa_selectAvatar(player);
            kd[KEY_RIGHT] = !(*kr & (1 << KEY_RIGHT)) ? KEY_DELAY_FIRST : KEY_DELAY_REPEAT;
            *kr |= (1 << KEY_RIGHT);
        } else {
            kd[KEY_RIGHT]--;
        }
    } else {
        kd[KEY_RIGHT] = 0;
        *kr &= ~(1 << KEY_RIGHT);
    }

    if (cpct_isKeyPressed(k[KEY_UP])) {
        if (!kd[KEY_UP]) { 
            opqa_unselectAvatar(player);
            p->avatar = (p->avatar & 0xC) + (((p->avatar & 0x3) - 1) & 0x3);
            opqa_selectAvatar(player);
            kd[KEY_UP] = !(*kr & (1 << KEY_UP)) ? KEY_DELAY_FIRST : KEY_DELAY_REPEAT;
            *kr |= (1 << KEY_UP);
        } else {
            kd[KEY_UP]--;
        }
    } else {
        kd[KEY_UP] = 0;
        *kr &= ~(1 << KEY_UP);
    }

    if (cpct_isKeyPressed(k[KEY_DOWN])) {
        if (!kd[KEY_DOWN]) { 
            opqa_unselectAvatar(player);
            p->avatar = (p->avatar & 0xC) + (((p->avatar & 0x3) + 1) & 0x3);
            opqa_selectAvatar(player);
            kd[KEY_DOWN] = !(*kr & (1 << KEY_DOWN)) ? KEY_DELAY_FIRST : KEY_DELAY_REPEAT;
            *kr |= (1 << KEY_DOWN);
        } else {
            kd[KEY_DOWN]--;
        }
    } else {
        kd[KEY_DOWN] = 0;
        *kr &= ~(1 << KEY_DOWN);
    }

    if (cpct_isKeyPressed(k[KEY_FIRE1])) {
        return 1;
    }
    
    return 0;
}

void opqa_stageScreen() {
    opqa_drawStageScreen();

    opqa_playJingle(msc_stage, 0);
}

void opqa_playRound() {
    u8 gameover1 = 0;
    u8 gameover2 = 0;
    u8 paused = 0;
    TState* s = opqa_getState();
    TBlock* nextb1 = opqa_getNextBlock(0);
    TBlock* nextb2 = opqa_getNextBlock(1);
    TUpdate* u1 = opqa_getUpdate(0);
    TUpdate* u2 = opqa_getUpdate(1);
    cpct_keyID* gk = opqa_getGameKeys();
    TPlayer* p1 = opqa_getPlayer(0);
    TPlayer* p2 = opqa_getPlayer(1);

    opqa_resetBoardArray(opqa_getBoard(0));
    opqa_resetBoardArray(opqa_getBoard(1));
    opqa_drawLevel();
    opqa_fade(FADE_IN); 

    opqa_newRandomBlock(nextb1);
    opqa_drawNextBlock(0);

    if (s->mode != MODE_ENDLESS) {
        opqa_newRandomBlock(nextb2);
        opqa_drawNextBlock(1);
    }

    do {
        if (!paused) {
            // Check player movements if board isn't flashing
            if (!u1->flash && !u1->garbage) {
                gameover1 = opqa_checkPlayer(0);
            }
            if (!u2->flash && !u2->garbage) {   
                switch (s->mode) {
                    case MODE_STORY:
                        gameover2 = opqa_doPlayerIA(1);
                        break;

                    case MODE_VERSUS:
                        gameover2 = opqa_checkPlayer(1);
                        break;
                }
            }
        }

        // Check for pause and abort keys
        cpct_scanKeyboard_f();
        if (cpct_isKeyPressed(gk[KEY_ABORT])) {
            opqa_waitForKeyRelease(gk[KEY_ABORT]);
            gameover1 = 1;
            gameover2 = 1;
        }
        if (cpct_isKeyPressed(gk[KEY_PAUSE])) {
            opqa_waitForKeyRelease(gk[KEY_PAUSE]);
            paused = !paused;
        }

        cpct_waitVSYNC();

        if (!paused && !gameover1 && !gameover2) {
            opqa_updateGame(0);

            if (s->mode != MODE_ENDLESS) {
                opqa_updateGame(1);
            }
        }
    } while (!gameover1 && !gameover2);

    if (gameover1) {
        opqa_updateBoard(0);
    } else {
        opqa_updateBoard(1);
    }

    p1->gameover = gameover1;
    p2->gameover = gameover2;
}

u8 opqa_playMission() {
    u8 gameover = 0;
    u8 paused = 0;
    u8 completed = 0;
    TState* s = opqa_getState();
    TBlock* nb = opqa_getNextBlock(0);
    TUpdate* u = opqa_getUpdate(0);
    cpct_keyID* gk = opqa_getGameKeys();
    TPlayer* p = opqa_getPlayer(0);
    TMission* m = opqa_getMission(s->level);
    
    opqa_drawLevel();

    opqa_fillBoard(0, m->board);
    opqa_updateBoard(0);

    opqa_showMissionObjectives();

    cpct_srand(m->seed);
    opqa_newRandomBlock(nb);
    opqa_drawNextBlock(0);

    opqa_fade(FADE_IN); 

    do {
        if (!paused) {
            // Check player movements if board isn't flashing
            if (!u->flash) {
                gameover = opqa_checkPlayer(0);
                if (gameover) {
                    completed = MISSION_ST_GAMEOVER;
                }
            }
        }

        // Check for pause and abort keys
        cpct_scanKeyboard_f();
        if (cpct_isKeyPressed(gk[KEY_ABORT])) {
            opqa_waitForKeyRelease(gk[KEY_ABORT]);
            gameover = 1;
            completed = MISSION_ST_GAMEOVER;
        }
        if (cpct_isKeyPressed(gk[KEY_PAUSE])) {
            opqa_waitForKeyRelease(gk[KEY_PAUSE]);
            paused = !paused;
        }

        cpct_waitVSYNC();

        if (!paused && !gameover) {
            completed = opqa_updateGame(0);
            if (completed) {
                gameover = 1;
            }
        }
    } while (!gameover);

    return completed;
}

void opqa_gameOver() {
    opqa_drawGameOver();

    opqa_playJingle(msc_gameover, 0);
}

void opqa_success() {
    opqa_drawSuccess();

    opqa_playJingle(msc_gameover, 1);
}

// Functions
void opqa_init() {  
    names[0] = "Sabrino";
    names[1] = "CPCGamer";
    names[2] = "Spectrunks";
    names[3] = "Burrizking";
    
    names[4] = "Zarrancio";
    names[5] = "Julito";
    names[6] = "Professor CPC";
    names[7] = "PriniVanilli";
    
    names[8] = "Rastapan";
    names[9] = "HalfMetr";
    names[10] = "Chemastran";
    names[11] = "TotalJamao";
    
    names[12] = "Yards";
    names[13] = "HeavyLong";
    names[14] = "TorreznoMan";
    names[15] = "Whiteless";

    // Disable firmware, set video mode, palette and clear screen
    cpct_disableFirmware();
    cpct_akp_SFXInit(sfx);    
    cpct_akp_musicInit(sfx);
    cpct_setInterruptHandler(opqa_interruptHandler);
    cpct_setVideoMode(0);    
    cpct_setBorder(HW_BLACK);
    opqa_fade(FADE_OUT); 

    // Uncompress level tiles
    cpct_zx7b_decrunch_s((u8*) LEVEL_TILES_END, level_end);
}

u8 opqa_checkPlayer(u8 player) {
    u8 gameover = 0;
    TBlock* currb = opqa_getCurrentBlock(player);
    TBlock* nextb = opqa_getNextBlock(player);
    TBlock* prevb = opqa_getPrevBlock(player);
    TPlayer* p = opqa_getPlayer(player);
    TUpdate* u = opqa_getUpdate(player);
    TState* s = opqa_getState();
    u8* kd = opqa_getKeyDelay(player);
    u8* kr = opqa_getKeyRepeat(player);
    cpct_keyID* keys = opqa_getKeys(player);

    opqa_copyBlock(currb, prevb);

    // If current block is empty...
    if (!currb->pieces[0]) {
        opqa_copyBlock(nextb, currb);
        opqa_newRandomBlock(nextb);
        u->block = 1;
        u->next = 1;
    }

    // Check input
    cpct_scanKeyboard_f();
    if (cpct_isAnyKeyPressed_f()) {
        // Left
        if (cpct_isKeyPressed(keys[KEY_LEFT])) {         
            if (!kd[KEY_LEFT]) { 
                if (opqa_blockCanMove(player, KEY_LEFT)) {
                    currb->x--;
                    u->block = 1;
                    kd[KEY_LEFT] = !(*kr & (1 << KEY_LEFT)) ? KEY_DELAY_FIRST : KEY_DELAY_REPEAT;
                    *kr |= (1 << KEY_LEFT);
                }
            } else {
                kd[KEY_LEFT]--;
            }
        } else {
            kd[KEY_LEFT] = 0;      
            *kr |= (1 << KEY_LEFT);
        }

        // Right
        if (cpct_isKeyPressed(keys[KEY_RIGHT])) {
            if (!kd[KEY_RIGHT]) {
                if (opqa_blockCanMove(player, KEY_RIGHT)) {
                    currb->x++;
                    u->block = 1;
                    kd[KEY_RIGHT] = !(*kr & (1 << KEY_RIGHT)) ? KEY_DELAY_FIRST : KEY_DELAY_REPEAT;
                    *kr |= (1 << KEY_RIGHT);
                }
            } else {
                kd[KEY_RIGHT]--;
            }
        } else {
            kd[KEY_RIGHT] = 0;
            *kr |= (1 << KEY_RIGHT);
        }  

        // Down
        if (cpct_isKeyPressed(keys[KEY_DOWN])) {
            if (!kd[KEY_DOWN]) {
                if (opqa_blockCanMove(player, KEY_DOWN)) {
                    currb->y++;
                    p->score++;
                    u->score = 1;
                    if (opqa_blockHasLanded(player)) {
                        PLAYER_LANDBLOCK
                    }
                    kd[KEY_DOWN] = !(*kr & (1 << KEY_DOWN)) ? KEY_DELAY_FIRST : KEY_DELAY_REPEAT;
                    *kr |= (1 << KEY_DOWN);
                } else {
                    PLAYER_LANDBLOCK
                }
                p->current_cycle = 0;
                u->block = 1;
            } else {
                kd[KEY_DOWN]--;
            }
        } else {
            kd[KEY_DOWN] = 0;
            *kr |= (1 << KEY_DOWN);
        }

        // Up
        if (cpct_isKeyPressed(keys[KEY_UP])) {
            if (!kd[KEY_UP]) {
                PLAYER_LANDBLOCK
                u->block = 1;
                p->current_cycle = 0;
                kd[KEY_UP] = KEY_DELAY_FALL_REPEAT;
                *kr |= (1 << KEY_UP);
            } else {
                kd[KEY_UP]--;
            }
        } else {
            kd[KEY_UP] = 0;
            *kr |= (1 << KEY_UP);
        }

        // Fire1
        if (cpct_isKeyPressed(keys[KEY_FIRE1])) {
            if (!kd[KEY_FIRE1]) {
                currb->rotation = (currb->rotation + 1) & 0x3;
                opqa_checkBlockRotation(player);
                u->block = 1;
                kd[KEY_FIRE1] = !(*kr & (1 << KEY_FIRE1)) ? KEY_DELAY_FIRST : KEY_DELAY_REPEAT;
                *kr |= (1 << KEY_FIRE1);

                opqa_playFX(SFX_TURN, player ? AY_CHANNEL_C : AY_CHANNEL_A);
            } else {
                kd[KEY_FIRE1]--;
            }
        } else {
            kd[KEY_FIRE1] = 0;
            *kr |= (1 << KEY_FIRE1);
        }

        // Fire2
        if (cpct_isKeyPressed(keys[KEY_FIRE2])) {
            if (!kd[KEY_FIRE2]) {
                currb->rotation = (currb->rotation - 1) & 0x3;
                opqa_checkBlockRotation(player);
                u->block = 1;
                kd[KEY_FIRE2] = !(*kr & (1 << KEY_FIRE2)) ? KEY_DELAY_FIRST : KEY_DELAY_REPEAT;
                *kr |= (1 << KEY_FIRE2);

                opqa_playFX(SFX_TURN, player ? AY_CHANNEL_C : AY_CHANNEL_A);
            } else {
                kd[KEY_FIRE2]--;
            }
        } else {
            kd[KEY_FIRE2] = 0;
            *kr |= (1 << KEY_FIRE2);
        }
    } else {
        opqa_resetKeyDelay();
        opqa_resetKeyRepeat();
    }
    
    // Check automatic down movement
    if (p->current_cycle >= p->cycles_per_movement) {
        p->current_cycle = 0;
        if (opqa_blockCanMove(player, KEY_DOWN)) {
            currb->y++;
            if (opqa_blockHasLanded(player)) {
                PLAYER_LANDBLOCK
            }
        } else {
            PLAYER_LANDBLOCK
        }       
        u->block = 1;
    }
    p->current_cycle++;

    return gameover;
}

u8 opqa_doPlayerIA(u8 player) {
    u8 gameover = 0;
    u8 rndmask = 0x1F;
    TBlock* currb = opqa_getCurrentBlock(player);
    TBlock* nextb = opqa_getNextBlock(player);
    TBlock* prevb = opqa_getPrevBlock(player);
    TPlayer* p = opqa_getPlayer(player);
    TUpdate* u = opqa_getUpdate(player);
    TState* s = opqa_getState();
    TIA* ia = opqa_getIA(player);

    opqa_copyBlock(currb, prevb);

    // If current block is empty...
    if (!currb->pieces[0]) {
        opqa_copyBlock(nextb, currb);
        opqa_newRandomBlock(nextb);
        u->block = 1;
        u->next = 1;
    }

    // Decide where to move pieces and move them (higher level -> faster)
    if ((ia->cycle + s->level) >= CYCLES_PER_STATE_CHANGE) {
        ia->cycle = 0;

        switch (ia->state) {
            case STATE_THINKING:
                opqa_doIAThink(player);
                ia->state = STATE_ROTATING;
                break;

            case STATE_ROTATING:
                if (currb->rotation != ia->rotation) {
                    if (currb->rotation < ia->rotation) {
                        currb->rotation = (currb->rotation + 1) & 0x3;
                    } else {
                        currb->rotation = (currb->rotation - 1) & 0x3;
                    }
                    u->block = 1;
                    opqa_playFX(SFX_TURN, player ? AY_CHANNEL_C : AY_CHANNEL_A);
                    if (currb->rotation == ia->rotation) {
                        ia->state = STATE_MOVING;
                    }
                    opqa_checkBlockRotation(player);
                } else {
                    ia->state = STATE_MOVING;
                }
                break;

            case STATE_MOVING:
                if (currb->x != ia->x) {
                    if (currb->x > ia->x) {
                        if (opqa_blockCanMove(player, KEY_LEFT)) {
                            currb->x--;
                            u->block = 1;
                        } else {
                            ia->state = STATE_DESCENDING;
                        }
                    } else {
                        if (opqa_blockCanMove(player, KEY_RIGHT)) {
                            currb->x++;
                            u->block = 1;
                        } else {
                            ia->state = STATE_DESCENDING;
                        }
                    }
                } else {
                    ia->state = STATE_DESCENDING;
                }
                break;

            case STATE_DESCENDING:
                u->block = 1;
                
                // Try to move if block can't be moved previously
                if (currb->x != ia->x) {
                    if (currb->x > ia->x) {
                        if (opqa_blockCanMove(player, KEY_LEFT)) {
                            currb->x--;
                        }
                    } else {
                        if (opqa_blockCanMove(player, KEY_RIGHT)) {
                            currb->x++;
                        }
                    }
                }

                // Chance for instant fall (by default, one chance in 32)
                switch(s->level) {
                    case 2:
                    case 3:
                        rndmask = 0xF;  // One chance in 16
                        break;
                    
                    case 4:
                    case 5:
                        rndmask = 0x7;  // One chance in 8
                        break;

                    case 6:
                        rndmask = 0x3;  // One chance in 4
                        break;

                    case 7:
                        rndmask = 0x1;  // One chance in 2
                        break;
                }

                if (!(cpct_rand() & rndmask)) {
                    // Instant fall
                    IA_LANDBLOCK             
                } else {
                    // Quick fall
                    if (opqa_blockCanMove(player, KEY_DOWN)) {
                        currb->y++;
                        p->score++;
                        u->score = 1;
                        if (opqa_blockHasLanded(player)) {
                            IA_LANDBLOCK
                        }
                    } else {
                        IA_LANDBLOCK
                    }       
                }
                p->current_cycle = 0;
                break;
        }
    }
    ia->cycle++;
    
    // Check automatic down movement
    if (p->current_cycle >= p->cycles_per_movement) {
        p->current_cycle = 0;
        if (opqa_blockCanMove(player, KEY_DOWN)) {
            currb->y++;
            if (opqa_blockHasLanded(player)) {
                IA_LANDBLOCK
            }
        } else {
            IA_LANDBLOCK
        }       
        u->block = 1;
    }
    p->current_cycle++;

    return gameover;
}

void opqa_doIAThink(u8 player) {
    TIA* ia = opqa_getIA(player);
    TBlock* b = opqa_getCurrentBlock(player);
    u8* bd = opqa_getBoard(player);
    u8* bf = OPQA_GETBUFFER;
    u8* tmp;
    u8 i, y;

    // If block has joker, put it vertically to clear the other colour
    // TODO: Count colours and clear the most predominant?
    if (
        (b->pieces[0] & PIECE_TYPE) == PIECE_TYPE_SPECIAL && 
        (b->pieces[0] & PIECE_SUBTYPE) == PIECE_SUBTYPE_JOKER
    ) {
        ia->x = 2;
        ia->rotation = ROTATION_VERTICAL_01;
        return;
    }
    if (
        (b->pieces[1] & PIECE_TYPE) == PIECE_TYPE_SPECIAL && 
        (b->pieces[1] & PIECE_SUBTYPE) == PIECE_SUBTYPE_JOKER
    ) {
        ia->x = 2;
        ia->rotation = ROTATION_VERTICAL_10;
        return;
    }
    
    // Empty buffer
    for (i = 0; i < BOARD_HEIGHT; i++) {
        *(bf + i) = 0;
    }

    // Look for the top pieces and height of every row in the board
    for (i = 0; i < BOARD_WIDTH; i++) {
        tmp = bd + i;
        *(bf + i + 6) = BOARD_HEIGHT - 1;
        for (y = 0; y < BOARD_HEIGHT; y++) {
            if (*tmp) {
                *(bf + i) = *tmp;
                *(bf + i + 6) = y;
                break;
            }
            tmp += 6;
        }
    }

    // Check if some color matches and there is space in the top
    for (i = 0; i < BOARD_WIDTH; i++) {
        if (*bf && *(bf + 6) && (*bf != PIECE_GARBAGE) && (*bf & PIECE_COLOR) == (b->pieces[0] & PIECE_COLOR)) {
            ia->x = i;
            if ((b->pieces[0] & PIECE_COLOR) == (b->pieces[1] & PIECE_COLOR)) {
                ia->rotation = ROTATION_VERTICAL_01;
            } else {
                if (i == BOARD_WIDTH - 1) {
                    ia->rotation = ROTATION_HORIZONTAL_10;
                } else {
                    ia->rotation = ROTATION_HORIZONTAL_01;
                }
            }            
            return;
        } else if (*bf && *(bf + 6) && (*bf != PIECE_GARBAGE) && (*bf & PIECE_COLOR) == (b->pieces[1] & PIECE_COLOR)) {            
            if ((b->pieces[0] & PIECE_COLOR) == (b->pieces[1] & PIECE_COLOR)) {
                ia->x = i;
                ia->rotation = ROTATION_VERTICAL_01;
            } else {
                if (i == BOARD_WIDTH - 1) {
                    ia->x = i - 1;
                    ia->rotation = ROTATION_HORIZONTAL_01;                    
                } else {
                    ia->x = i + 1;
                    ia->rotation = ROTATION_HORIZONTAL_10;
                    
                }                
            }            
            return;
        }
        bf++;
    }

    // If there is no colour match, find the lowest space and put the block vertically there
    bf = (OPQA_GETBUFFER) + 6;
    y = 0;
    ia->rotation = ROTATION_VERTICAL_10;
    for (i = 0; i < BOARD_WIDTH; i++) {
        if (*bf > y) {
            ia->x = i;
            y = *bf;
        }
        bf++;
    }
}

u8 opqa_updateGame(u8 player) {
    TUpdate* u = opqa_getUpdate(player);
    TPlayer* p = opqa_getPlayer(player);
    TState* s = opqa_getState();
    u8 completed = 0;

    if (u->block) {
        opqa_erasePrevBlock(player);        
        opqa_drawCurrentBlock(player);
        u->block = 0;
    }
    if (u->next) {
        opqa_drawNextBlock(player);
        u->next = 0;
    }
    if (u->flash) {
        completed = opqa_flashBoard(player);
    }
    if (u->garbage) {
        opqa_flashGarbage(player);
    }
    if (u->landed) {
        opqa_updateBoard(player);
        if (s->mode == MODE_MISSION) {
            if (!u->flash && !completed) {
                completed = opqa_checkMissionStatus();
            }
        }
        u->landed = 0;
    }
    if (u->score) {
        if (p->score > 999999) {
            p->score = 999999;
        }
        opqa_drawScore(player);
        u->score = 0;
    }

    return completed;
}
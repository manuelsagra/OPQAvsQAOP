#include <cpctelera.h>
#include "game.h"
#include "missions.h"
#include "video.h"
#include "sound.h"
#include "board.h"
#include "blocks.h"
#include "sound/complete.h"

void main(void) {
    u32 score;
    u8 status = 0;
    TState* s = opqa_getState();
    TPlayer* p1 = opqa_getPlayer(0);
    TPlayer* p2 = opqa_getPlayer(1);
    TBlock* b1 = opqa_getCurrentBlock(0);
    TBlock* b2 = opqa_getCurrentBlock(1);

    opqa_init();

    while(1) {        
        opqa_resetState();
        opqa_title();
        opqa_selectCharacter();

        if (s->mode == MODE_STORY) {
            status = 0;
            do {
                opqa_stageScreen();

                opqa_playRound();

                if (!p1->gameover) {
                    opqa_playJingle(msc_complete, 0);                    
                }
                
                opqa_resetBoardArray(opqa_getBoard(0));
                opqa_resetBoardArray(opqa_getBoard(1));
                opqa_resetBoardArray(opqa_getFlash(0));
                opqa_resetBoardArray(opqa_getFlash(1));
                opqa_resetUpdate();
                opqa_resetKeyDelay();
                opqa_resetKeyRepeat();
                opqa_resetIA(1);

                b1->pieces[0] = 0;
                b1->y = 0;
                b2->pieces[0] = 0;
                b2->y = 0;               

                p1->cycles_per_movement = CYCLES_PER_MOVEMENT;
                p1->combos = 0;
                p1->combo = 0;
                p2->avatar++;
                p2->score = 0;
                p2->combos = 0;
                p2->combo = 0;
                s->level++;

                if (s->level == 8) {
                    status = 1;
                }
            } while (!p1->gameover && !status);

            if (p1->gameover) {
                opqa_gameOver();
            } else {
                opqa_success();
            }
        } else if (s->mode == MODE_MISSION) {
            do {
                status = opqa_playMission();

                if (status != MISSION_ST_GAMEOVER) {
                    opqa_drawText(32, 72, "SUCCESS!");
                    opqa_playJingle(msc_complete, 0);
                }

                s->level++;
                p1->landings = 0;
                p1->combos = 0;
                p1->combo = 0;
                p1->cycles_per_movement = CYCLES_PER_MOVEMENT;
                
                opqa_resetUpdate();
            } while (s->level != MISSIONS && status != MISSION_ST_GAMEOVER);  

            if (status == MISSION_ST_GAMEOVER) {
                opqa_gameOver();
            } else {
                opqa_success();
            }
        } else {
            opqa_playRound();

            opqa_gameOver();
        }

        // Check Hi-Score
        score = p1->score;
        if (s->mode == MODE_VERSUS) {
            if (p2->score > score) {
                score = p2->score;
            }
        }
        if (score > s->hiscore) {
            s->hiscore = score;
        }
    }
}

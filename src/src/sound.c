#include <cpctelera.h>
#include "sound.h"
#include "video.h"
#include "utils.h"
#include "sound/sfx.h"

const u8 FX[SFX_SOUNDS][2] = {
    {10, 62},   // Combo
    {12, 55},   // Garbage
    {6, 60},   // Turn
    {8, 50}    // Fall
};

void opqa_interruptHandler() {
    static u8 c;

    c++;

    switch (c) {
        case 5:
            cpct_akp_musicPlay();
            break;

        case 6:
            c = 0;
            break;
    }
}

void opqa_playJingle(u8* jingle, u8 wait) {
    cpct_akp_musicInit(jingle);
    do {
        __asm__ ("halt");
    } while (!cpct_akp_songLoopTimes);
    cpct_akp_musicInit(sfx);

    if (wait) {
        opqa_waitForKey();
    }

    opqa_fade(FADE_OUT);
}

void opqa_playFXCombo(u8 channel, u8 combo) {
    cpct_akp_SFXStop(channel);
    cpct_akp_SFXPlay(SFX_COMBO + 1, FX[SFX_COMBO][0], FX[SFX_COMBO][1] + combo, 0, 0, channel);
}

void opqa_playFX(u8 fx, u8 channel) {
    cpct_akp_SFXStop(channel);
    cpct_akp_SFXPlay(fx + 1, FX[fx][0], FX[fx][1], 0, 0, channel);
} 
#ifndef _SOUND_H_
#define _SOUND_H_

// Sound constants
#define SFX_COMBO               0
#define SFX_GARBAGE             1
#define SFX_TURN                2
#define SFX_FALL                3

#define SFX_SOUNDS              4

void        opqa_interruptHandler();
void        opqa_playJingle(u8* jingle, u8 wait);
void        opqa_playFXCombo(u8 channel, u8 combo);
void        opqa_playFX(u8 fx, u8 channel);

#endif
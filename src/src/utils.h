#ifndef _UTILS_H_
#define _UTILS_H_

#define BUFFER_POINTER          0xAE00

// Macros
#define OPQA_GETBUFFER (u8*) BUFFER_POINTER

// Getters
u8*         opqa_getBuffer();

// Keyboard
void        opqa_waitForKeyRelease(cpct_keyID key);
cpct_keyID  opqa_getKey();
cpct_keyID  opqa_waitForKey();
cpct_keyID  opqa_redefineKey(u8* keytxt);

#endif
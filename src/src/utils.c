#include <cpctelera.h>
#include "utils.h"
#include "video.h"
#include "game.h"

// Keyboard
void opqa_waitForKeyRelease(cpct_keyID key) {
    do {
        cpct_scanKeyboard_f();
    } while (cpct_isKeyPressed(key));
}

cpct_keyID opqa_getKey() {
    u8* kb = cpct_keyboardStatusBuffer;
    u8 i, k;

    for (i = 0; i < 10; i++) {
        k = *kb ^ 0xFF;
        if (k) {
            return (k << 8) | i;
        }
        kb++;
    }

    return 0;
}

cpct_keyID opqa_waitForKey() {
    do {
        cpct_scanKeyboard_f();
    } while (!cpct_isAnyKeyPressed_f());

    return opqa_getKey();
}

cpct_keyID opqa_redefineKey(u8* keytxt) {
    cpct_keyID k;
    u8* pvmem;

    // Erase previous text and show current
    cpct_waitVSYNC();

    pvmem = cpctm_screenPtr(CPCT_VMEM_START, 8, 136);
    cpct_drawSolidBox(pvmem, 0, 64, 16);
    opqa_drawCenteredText(8, 136, keytxt, 64);

    k = opqa_waitForKey();
    opqa_waitForKeyRelease(k);

    return k;
}
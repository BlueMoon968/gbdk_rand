//=========================================
// This is an alternative way for generating
// random numbers. It's not the best, but
// it can replace the broken one offered by
// rand.h.
//=========================================

#include <gb/gb.h>
#include <time.h>

//==========================
// RAND METHOD
//==========================

//=====================================
// CREATE A VARIABLE FOR
// STORING THE CURRENT NUMBER OF THE
// GENERATED SEQUENCE.
//=====================================

static UINT8 current_rand; 

//=================================
// RAND METHOD THAT RETURNS AN UINT8
//=================================

UINT8 rand(void) {
    UINT8 to_add = 123; 
    unsigned bit = 0x7ff;
    current_rand = (rand_state * clock() + to_add) & bit;
    return current_rand;
}

//=================================
// MAIN METHOD
//=================================

void main() {
    UINT8 r; 
    while(1) {
        r = rand(); 
        printf("%d\n", (UWORD)r);
        delay(100);
    }
}

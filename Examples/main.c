
#include <xc.h>
#include "../WS2812B.h"
#include "LCD.h"


//CONFIG bits for PIC18F87J11
#pragma config FOSC=HSPLL
#pragma config WDTEN=OFF
#pragma config XINST=OFF


void main(void) {
    OSCTUNEbits.PLLEN = 1;
    LCDInit();
    LCDClear();
    InitWS2812();
    
    while (1) {
        
    }
}

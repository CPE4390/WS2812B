
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
    LCDWriteLine("Starting", 0);
    InitWS2812();
    RGB color = {0x07, 0x02, 0x03};
    while (1) {
        SetColor(color, 3);
        __delay_ms(200);
    }
}

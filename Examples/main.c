
#include <xc.h>
#include "../WS2812B.h"
#include "LCD.h"
#include "stdio.h"


//CONFIG bits for PIC18F87J11
#pragma config FOSC=HSPLL
#pragma config WDTEN=OFF
#pragma config XINST=OFF


void main(void) {
    OSCTUNEbits.PLLEN = 1;
    char lcd[17];
    LCDInit();
    LCDClear();
    LCDWriteLine("Starting", 0);
    InitWS2812();
    RGB color;
    color.R = 0xff;
    color.G = 0x00;
    color.B = 0x00;
    int i = 1;
    while (1) {
        sprintf(lcd, "%d", i);
        LCDWriteLine(lcd, 1);
        SetColor(color, i);
        __delay_ms(1000);
        if (i < 60) {
            ++i;
        }
    }
}

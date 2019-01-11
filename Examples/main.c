
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
    RGB colors[LEDS];
    for (int i = 0; i < LEDS; ++i) {
        colors[i].R = 4 * i;
        colors[i].B = 255 - 4 * i;
        colors[i].G = 0;
    }

    while (1) {
        SetColor(color);
        __delay_ms(1000);
        SetColors(colors);
        __delay_ms(1000);
    }
}

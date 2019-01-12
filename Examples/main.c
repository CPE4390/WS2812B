
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
    color.R = 255;
    color.G = 0;
    color.B = 0;
    RGB colors[LEDS];
    for (int i = 0; i < LEDS; ++i) {
        if (i % 4 == 0) {
            colors[i].R = 255;
            colors[i].B = 0;
            colors[i].G = 0;
        } else if (i % 4 == 1) {
            colors[i].R = 0;
            colors[i].B = 0;
            colors[i].G = 255;
        } else if (i % 4 == 2) {
            colors[i].R = 0;
            colors[i].B = 255;
            colors[i].G = 0;
        } else {
            colors[i].R = 255;
            colors[i].B = 255;
            colors[i].G = 255;
        }
    }

    while (1) {
        SetColor(color);
        __delay_ms(1000);
        SetColors(colors);
        __delay_ms(1000);
    }
}

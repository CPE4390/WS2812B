#include <xc.h>
#include "WS2812B.h"

void InitWS2812(void) {
    LATDbits.LATD4 = 0;
    TRISDbits.TRISD4 = 0;
    TRISDbits.TRISD5 = 1;
    TRISDbits.TRISD6 = 0;
    SSP2STATbits.CKE = 1;
    SSP2CON1bits.CKP = 0; //SPI mode 0,0
    SSP2CON1bits.SSPM = 0b0000; //SPI Master - FOSC/4 = 8 MHz
    SSP2CON1bits.SSPEN = 1; //Enable MSSP
    PIR3bits.SSP2IF = 0;
}

void SetColor(RGB color, int numLED) {
    char b;
    for (char led = 0; led < numLED; ++led) {
        unsigned char value = color.G;
        b = 8;
        while (b > 0) {
            PIR3bits.SSP2IF = 0;
            if (value & 0b10000000) {
                SSP2BUF = 0b11111000;
            } else {
                SSP2BUF = 0b11000000;
            }
            --b;
            value <<= 1;
            while (!PIR3bits.SSP2IF);
        }
        value = color.R;
        b = 8;
        while (b > 0) {
            PIR3bits.SSP2IF = 0;
            if (value & 0b10000000) {
                SSP2BUF = 0b11111000;
            } else {
                SSP2BUF = 0b11000000;
            }
            --b;
            value <<= 1;
            while (!PIR3bits.SSP2IF);
        }
        value = color.B;
        b = 8;
        while (b > 0) {
            PIR3bits.SSP2IF = 0;
            if (value & 0b10000000) {
                SSP2BUF = 0b11111000;
            } else {
                SSP2BUF = 0b11000000;
            }
            --b;
            value <<= 1;
            while (!PIR3bits.SSP2IF);
        }
    }
    __delay_us(50);
}

void SetColors(RGB *colors, int numLED) {

}
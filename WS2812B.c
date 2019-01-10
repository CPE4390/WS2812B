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
}

void SetColor(RGB color, int numLED) {
    unsigned char buff[24];
    char b;
    char temp;
    for (char led = 0; led < numLED; ++led) {
        char pos = 0;
        unsigned char value = color.G;
        b = 8;
        while (b > 0) {
            if (value & 0b10000000) {
                buff[pos] = 0b11111000;
            } else {
                buff[pos] = 0b11000000;
            }
            --b;
            ++pos;
            value <<= 1;
        }
        value = color.R;
        b = 8;
        while (b > 0) {
            if (value & 0b10000000) {
                buff[pos] = 0b11111000;
            } else {
                buff[pos] = 0b11000000;
            }
            --b;
            ++pos;
            value <<= 1;
        }
        value = color.B;
        b = 8;
        while (b > 0) {
            if (value & 0b10000000) {
                buff[pos] = 0b11111000;
            } else {
                buff[pos] = 0b11000000;
            }
            --b;
            ++pos;
            value <<= 1;
        }

        PIR3bits.SSP2IF = 0;
        pos = 0;
        while (pos < 24) {
            SSP2BUF = buff[pos];
            ++pos;
            while (!PIR3bits.SSP2IF);
            PIR3bits.SSP2IF = 0;
            temp = SSP2BUF;
        }
    }
    __delay_us(50);
}

void SetColors(RGB *colors, int numLED) {

}
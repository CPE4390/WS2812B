#include <xc.h>
#include "WS2812B.h"

void InitWS2812(void) {
    TRISDbits.TRISD4 = 0;
    SSP2STATbits.CKE = 1;
    SSP2CON1bits.CKP = 0; //SPI mode 0,0
    SSP2CON1bits.SSPM = 0b0000; //SPI Master - FOSC/4 = 8 MHz
    SSP2CON1bits.SSPEN = 1; //Enable MSSP
}

void SetColor(RGB color, int numLED) {
    unsigned char buff[30];
  
    }
//    SSP2BUF = byte; //transmit byte
//    while (!PIR3bits.SSP2IF); //Wait until completed
//    PIR3bits.SSP2IF = 0; //Clear flag so it is ready for next transfer
//    r = SSP2BUF; //read received byte
}

void SetColors(RGB *colors, int numLED) {

}
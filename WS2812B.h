
#ifndef WS2812B_H
#define	WS2812B_H

//Defines

#ifdef	__cplusplus
extern "C" {
#endif

    typedef union {
        struct {
        unsigned char R;
        unsigned char G;
        unsigned char B;
        };
        unsigned char bytes[3];
    } RGB;
    
#define LEDS  60
    
    void InitWS2812(void);
    void SetColor(RGB color);
    void SetColors(RGB *colors);
    
    #define _XTAL_FREQ  32000000L

#ifdef	__cplusplus
}
#endif

#endif	/* WS2812B_H */


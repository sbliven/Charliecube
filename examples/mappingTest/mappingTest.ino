/* mappingTest.ino
 *
 * This sketch tests that mappings.h has been configured correctly.
 * It directly turns on each light for a second, bypassing the
 * timing functions in cubeplex.h.
 *
 * The lights should be turned on in the order blue, green, red,
 * with the z coordinate advancing the fastest and x the slowest.
 * (b111,b112,b113,b114,b121,...,r444)
 */
#include "mappings.h"

void setup() {
}


#if NUM_WIRES == 20 && defined P20B
// include 20 wires
byte pinsB[] = {P1B,P2B,P3B,P4B,P5B,P6B,P7B,P8B,P9B,P10B,P11B,P12B,P13B,P14B,P15B,P16B,P17B,P18B,P19B,P20B};
byte pinsC[] = {P1C,P2C,P3C,P4C,P5C,P6C,P7C,P8C,P9C,P10C,P11C,P12C,P13C,P14C,P15C,P16C,P17C,P18C,P19C,P20C};
byte pinsD[] = {P1D,P2D,P3D,P4D,P5D,P6D,P7D,P8D,P9D,P10D,P11D,P12D,P13D,P14D,P15D,P16D,P17D,P18D,P19D,P20D};
#elif NUM_WIRES == 16 && defined P16B
// only 16 wires
byte pinsB[] = {P1B,P2B,P3B,P4B,P5B,P6B,P7B,P8B,P9B,P10B,P11B,P12B,P13B,P14B,P15B,P16B};
byte pinsC[] = {P1C,P2C,P3C,P4C,P5C,P6C,P7C,P8C,P9C,P10C,P11C,P12C,P13C,P14C,P15C,P16C};
byte pinsD[] = {P1D,P2D,P3D,P4D,P5D,P6D,P7D,P8D,P9D,P10D,P11D,P12D,P13D,P14D,P15D,P16D};
#else
#error Unsupported number of wires
#endif


/* Enable a single LED at a time
 * wire1 is the annode, wire2 is the cathode.
 * wires are 1-20
 */
void enableLED(int wire1,int wire2) {
    DDRB = pinsB[wire1-1] | pinsB[wire2-1];
    DDRC = pinsC[wire1-1] | pinsC[wire2-1];
    DDRD = pinsD[wire1-1] | pinsD[wire2-1];
    PORTB = pinsB[wire1-1];
    PORTC = pinsC[wire1-1];
    PORTD = pinsD[wire1-1];
}
#define ENABLE_LED_MACRO(wires) enableLED(wires)


// macro version of enableLED. Useful for inspecting actual pin settings with gcc -E
//#define ENABLE_LED_MACRO(wires) ENABLE_LED_MACRO_2WIRES(wires)
//#define ENABLE_LED_MACRO_2WIRES(wire1,wire2) DDRB = P##wire1##B | P##wire2##B; DDRC = P##wire1##C | P##wire2##C; DDRD = P##wire1##D | P##wire2##D; PORTB = P##wire1##B; PORTC = P##wire1##C; PORTD = P##wire1##D

  
  
void loop() {
  const int waitTime = 50;//time to display each LED
  
  //enableLED(17,9);
  // Turn on each LED sequentially
  // for c=bgr, for x=1:4, for y=1:4, for z=1:4 { enableLED(CXYZ); sleep(waitTime); }
// enable LED with specified color, and position (1-4)
#define ENABLE_LED(c,x,y,z) enableLED(WIRES(c,x,y,z)); delay(waitTime)
//#define ENABLE_LED(c,x,y,z) ENABLE_LED_MACRO(WIRES(c,x,y,z)); delay(waitTime) 
#define WIRES_Z(c,x,y) ENABLE_LED( c,x,y,1 ); ENABLE_LED( c,x,y,2 ); ENABLE_LED( c,x,y,3 ); ENABLE_LED( c,x,y,4 )
#define WIRES_Y(c,x) WIRES_Z(c,x,1); WIRES_Z(c,x,2); WIRES_Z(c,x,3); WIRES_Z(c,x,4)
#define WIRES_X(c) WIRES_Y(c,1); WIRES_Y(c,2); WIRES_Y(c,3); WIRES_Y(c,4)

  WIRES_X(b); WIRES_X(g); WIRES_X(r);

#undef WIRES_X
#undef WIRES_Y
#undef WIRES_Z
#undef ENABLE_LED
}

// vi:filetype=cpp

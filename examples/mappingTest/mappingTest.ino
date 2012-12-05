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
  // All pins to output
  DDRB = 0;
  DDRC = 0;
  DDRD = 0;
}

byte pinsB[] = {P1B,P2B,P3B,P4B,P5B,P6B,P7B,P8B,P9B,P10B,P11B,P12B,P13B,P14B,P15B,P16B};
byte pinsC[] = {P1C,P2C,P3C,P4C,P5C,P6C,P7C,P8C,P9C,P10C,P11C,P12C,P13C,P14C,P15C,P16C};
byte pinsD[] = {P1D,P2D,P3D,P4D,P5D,P6D,P7D,P8D,P9D,P10D,P11D,P12D,P13D,P14D,P15D,P16D};

/* Enable a single LED at a time
 * wire1 is the annode, wire2 is the cathode.
 */
void enableLED(int wire1,int wire2) {
  DDRB = pinsB[wire1] | pinsB[wire2];
  DDRC = pinsC[wire1] | pinsC[wire2];
  DDRD = pinsD[wire1] | pinsD[wire2];
  PORTB = pinsB[wire1];
  PORTC = pinsC[wire1];
  PORTD = pinsD[wire1];
}
  
  
void loop() {
  const int waitTime = 1000;//time to display each LED
  
  // Turn on each LED sequentially
  // for c=bgr, for x=1:4, for y=1:4, for z=1:4 { enableLED(CXYZ); sleep(waitTime); }
#define ENABLE_LED(c,x,y,z) enableLED(WIRES(c,x,y,z)); delay(waitTime);
#define WIRES_Z(c,x,y) ENABLE_LED( c,x,y,1 ); ENABLE_LED( c,x,y,2 ); ENABLE_LED( c,x,y,3 ); ENABLE_LED( c,x,y,4 )
#define WIRES_Y(c,x) WIRES_Z(c,x,1); WIRES_Z(c,x,2); WIRES_Z(c,x,3); WIRES_Z(c,x,4)
#define WIRES_X(c) WIRES_Y(c,1); WIRES_Y(c,2); WIRES_Y(c,3); WIRES_Y(c,4);

  WIRES_X(b); WIRES_X(g); WIRES_X(r);

#undef WIRES_X
#undef WIRES_Y
#undef WIRES_Z
#undef ENABLE_LED
}

// vi:filetype=cpp

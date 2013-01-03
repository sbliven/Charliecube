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

#if NUM_WIRES == 20
// include 20 wires
#define PINS_ARRAY(port) {P1##port,P2##port,P3##port,P4##port,P5##port,P6##port,P7##port,P8##port,P9##port,P10##port,P11##port,P12##port,P13##port,P14##port,P15##port,P16##port,P17##port,P18##port,P19##port,P20##port}

#elif NUM_WIRES == 16
// only 16 wires
#define PINS_ARRAY(port) {P1##port,P2##port,P3##port,P4##port,P5##port,P6##port,P7##port,P8##port,P9##port,P10##port,P11##port,P12##port,P13##port,P14##port,P15##port,P16##port}
#else
#error "Unsupported number of wires"
#endif

byte pinsB[] = PINS_ARRAY(B);
byte pinsC[] = PINS_ARRAY(C);
byte pinsD[] = PINS_ARRAY(D);

#ifdef __AVR_ATmega2560__
// Define additional outputs on Arduino Mega
byte pinsA[] = PINS_ARRAY(A);
byte pinsE[] = PINS_ARRAY(E);
byte pinsF[] = PINS_ARRAY(F);
byte pinsG[] = PINS_ARRAY(G);
byte pinsH[] = PINS_ARRAY(H);
byte pinsJ[] = PINS_ARRAY(J);
byte pinsK[] = PINS_ARRAY(K);
byte pinsL[] = PINS_ARRAY(L);
#endif //__AVR_ATmega2560__


/* Enable a single LED at a time
 * wire1 is the annode, wire2 is the cathode.
 * wires are 1-20
 */
void enableLED(int wire1,int wire2) {
    // set currently lit pins as outputs, all others as high impedance
    DDRB = pinsB[wire1-1] | pinsB[wire2-1];
    DDRC = pinsC[wire1-1] | pinsC[wire2-1];
    DDRD = pinsD[wire1-1] | pinsD[wire2-1];
#ifdef __AVR_ATmega2560__
    DDRA = pinsA[wire1-1] | pinsA[wire2-1];
    DDRE = pinsE[wire1-1] | pinsE[wire2-1];
    DDRF = pinsF[wire1-1] | pinsF[wire2-1];
    DDRG = pinsG[wire1-1] | pinsG[wire2-1];
    DDRH = pinsH[wire1-1] | pinsH[wire2-1];
    DDRJ = pinsJ[wire1-1] | pinsJ[wire2-1];
    DDRK = pinsK[wire1-1] | pinsK[wire2-1];
    DDRL = pinsL[wire1-1] | pinsL[wire2-1];
#endif //__AVR_ATmega2560__

    
    // drive pin1 high and pin2 low
    PORTB = pinsB[wire1-1];
    PORTC = pinsC[wire1-1];
    PORTD = pinsD[wire1-1];
#ifdef __AVR_ATmega2560__
    PORTA = pinsA[wire1-1];
    PORTE = pinsE[wire1-1];
    PORTF = pinsF[wire1-1];
    PORTG = pinsG[wire1-1];
    PORTH = pinsH[wire1-1];
    PORTJ = pinsJ[wire1-1];
    PORTK = pinsK[wire1-1];
    PORTL = pinsL[wire1-1];
#endif //__AVR_ATmega2560__
}
#define ENABLE_LED_MACRO(wires) enableLED(wires)


// macro version of enableLED. Useful for inspecting actual pin settings with gcc -E
//#define ENABLE_LED_MACRO(wires) ENABLE_LED_MACRO_2WIRES(wires)
//#define ENABLE_LED_MACRO_2WIRES(wire1,wire2) DDRB = P##wire1##B | P##wire2##B; DDRC = P##wire1##C | P##wire2##C; DDRD = P##wire1##D | P##wire2##D; PORTB = P##wire1##B; PORTC = P##wire1##C; PORTD = P##wire1##D

  
  
void loop() {
  const int waitTime = 100;//time to display each LED
  
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

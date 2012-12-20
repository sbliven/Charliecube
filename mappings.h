/********************************** SIGNATURE *********************************\
|                                      ,,                                      |
|                     db             `7MM                                      |
|                    ;MM:              MM                                      |
|                   ,V^MM.    ,pP"Ybd  MMpMMMb.  .gP"Ya `7Mb,od8               |
|                  ,M  `MM    8I   `"  MM    MM ,M'   Yb  MM' "'               |
|                  AbmmmqMA   `YMMMa.  MM    MM 8M""""""  MM                   |
|                 A'     VML  L.   I8  MM    MM YM.    ,  MM                   |
|               .AMA.   .AMMA.M9mmmP'.JMML  JMML.`Mbmmd'.JMML.                 |
|                                                                              |
|                                                                              |
|                                  ,,    ,,                                    |
|                      .g8"""bgd `7MM    db        `7MM                        |
|                    .dP'     `M   MM                MM                        |
|                    dM'       `   MM  `7MM  ,p6"bo  MM  ,MP'                  |
|                    MM            MM    MM 6M'  OO  MM ;Y                     |
|                    MM.    `7MMF' MM    MM 8M       MM;Mm                     |
|                    `Mb.     MM   MM    MM YM.    , MM `Mb.                   |
|                      `"bmmmdPY .JMML..JMML.YMbmd'.JMML. YA.                  |
|                                                                              |
\******************************************************************************/
/*********************************** LICENCE **********************************\
| Copyright (c) 2012, Asher Glick                                              |
| All rights reserved.                                                         |
|                                                                              |
| Redistribution and use in source and binary forms, with or without           |
| modification, are permitted provided that the following conditions are met:  |
|                                                                              |
| * Redistributions of source code must retain the above copyright notice,     |
|   this list of conditions and the following disclaimer.                      |
| * Redistributions in binary form must reproduce the above copyright notice,  |
|   this list of conditions and the following disclaimer in the documentation  |
|   and/or other materials provided with the distribution.                     |
|                                                                              |
| THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  |
| AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE    |
| IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE   |
| ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE    |
| LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR          |
| CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF         |
| SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS     |
| INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN      |
| CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)      |
| ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE   |
| POSSIBILITY OF SUCH DAMAGE.                                                  |
\******************************************************************************/

#ifndef _MAPPINGS_H_
#define _MAPPINGS_H_

/****************************** PIN PORT MAPPINGS *****************************\
| There are 16 wires for controlling the LEDs. This defines which              |
| physical pin coresponds to each. For example, to use analogue pin 2 (PORTC   |
| bit 3) for group 15, we set P13C=0x04 and P13B=P13D=0;                       |
|                                                                              |
| See ATmega328 specs for more info about direct port access.                  |
\******************************************************************************/

// Number of wires used. Either 16 or 20
#define NUM_WIRES 20

#define P1B 0x20 //13
#define P1C 0x00
#define P1D 0x00

#define P2B 0x10 //12
#define P2C 0x00
#define P2D 0x00

#define P3B 0x08 //11
#define P3C 0x00
#define P3D 0x00

#define P4B 0x04 //10
#define P4C 0x00
#define P4D 0x00

#define P5B 0x02 //9
#define P5C 0x00
#define P5D 0x00

#define P6B 0x01 //8
#define P6C 0x00
#define P6D 0x00

#define P7B 0x00
#define P7C 0x00
#define P7D 0x80 //7

#define P8B 0x00
#define P8C 0x00
#define P8D 0x40 //6

#define P9B 0x00
#define P9C 0x02 //A1
#define P9D 0x00

#define P10B 0x00
#define P10C 0x01 //A0
#define P10D 0x00

#define P11B 0x00
#define P11C 0x00
#define P11D 0x01 //0

#define P12B 0x00
#define P12C 0x00
#define P12D 0x02 //1

#define P13B 0x00
#define P13C 0x00
#define P13D 0x04 //2

#define P14B 0x00
#define P14C 0x00
#define P14D 0x10 //4

#define P15B 0x00
#define P15C 0x00
#define P15D 0x20 //5

#define P16B 0x00
#define P16C 0x00
#define P16D 0x08 //3

#define P17B 0x00
#define P17C 0x20 //A5
#define P17D 0x00

#define P18B 0x00
#define P18C 0x10 //A4
#define P18D 0x00

#define P19B 0x00
#define P19C 0x08 //A3
#define P19D 0x00

#define P20B 0x00
#define P20C 0x04 //A2
#define P20D 0x00


/* LED to wire mappings
 *
 * This defines which wire to turn on for each LED. The first group specifies
 *   the anode (+5V),
 * the second the cathode (GND).
 * The pins are named based on color, x, y, z.
 */

//System 1: Manually define pins for all 192 LEDs

#define b111 4,12
#define b112 8,4
#define b113 16,8
#define b114 12,16
#define b121 3,11
#define b122 8,3
#define b123 15,8
#define b124 11,15
#define b131 2,10
#define b132 8,2
#define b133 14,8
#define b134 10,14
#define b141 1,9
#define b142 8,1
#define b143 13,8
#define b144 9,13
#define b211 4,11
#define b212 7,4
#define b213 13,7
#define b214 11,13
#define b221 3,12
#define b222 7,3
#define b223 14,7
#define b224 12,14
#define b231 2,9
#define b232 7,2
#define b233 15,7
#define b234 9,15
#define b241 1,10
#define b242 7,1
#define b243 16,7
#define b244 10,16
#define b311 4,10
#define b312 6,4
#define b313 15,6
#define b314 10,15
#define b321 3,9
#define b322 6,3
#define b323 16,6
#define b324 9,16
#define b331 2,12
#define b332 6,2
#define b333 13,6
#define b334 12,13
#define b341 1,11
#define b342 6,1
#define b343 14,6
#define b344 11,14
#define b411 4,9
#define b412 5,4
#define b413 14,5
#define b414 9,14
#define b421 3,10
#define b422 5,3
#define b423 13,5
#define b424 10,13
#define b431 2,11
#define b432 5,2
#define b433 16,5
#define b434 11,16
#define b441 1,12
#define b442 5,1
#define b443 15,5
#define b444 12,15

#define g111 8,12
#define g112 16,4
#define g113 12,8
#define g114 4,16
#define g121 8,11
#define g122 15,3
#define g123 11,8
#define g124 3,15
#define g131 8,10
#define g132 14,2
#define g133 10,8
#define g134 2,14
#define g141 8,9
#define g142 13,1
#define g143 9,8
#define g144 1,13
#define g211 7,11
#define g212 13,4
#define g213 11,7
#define g214 4,13
#define g221 7,12
#define g222 14,3
#define g223 12,7
#define g224 3,14
#define g231 7,9
#define g232 15,2
#define g233 9,7
#define g234 2,15
#define g241 7,10
#define g242 16,1
#define g243 10,7
#define g244 1,16
#define g311 6,10
#define g312 15,4
#define g313 10,6
#define g314 4,15
#define g321 6,9
#define g322 16,3
#define g323 9,6
#define g324 3,16
#define g331 6,12
#define g332 13,2
#define g333 12,6
#define g334 2,13
#define g341 6,11
#define g342 14,1
#define g343 11,6
#define g344 1,14
#define g411 5,9
#define g412 14,4
#define g413 9,5
#define g414 4,14
#define g421 5,10
#define g422 13,3
#define g423 10,5
#define g424 3,13
#define g431 5,11
#define g432 16,2
#define g433 11,5
#define g434 2,16
#define g441 5,12
#define g442 15,1
#define g443 12,5
#define g444 1,15

#define r111 20,12
#define r112 20,4
#define r113 20,8
#define r114 20,16
#define r121 19,11
#define r122 19,3
#define r123 19,8
#define r124 19,15
#define r131 18,10
#define r132 18,2
#define r133 18,8
#define r134 18,14
#define r141 17,9
#define r142 17,1
#define r143 17,8
#define r144 17,13
#define r211 18,11
#define r212 18,4
#define r213 18,7
#define r214 18,13
#define r221 17,12
#define r222 17,3
#define r223 17,7
#define r224 17,14
#define r231 20,9
#define r232 20,2
#define r233 20,7
#define r234 20,15
#define r241 19,10
#define r242 19,1
#define r243 19,7
#define r244 19,16
#define r311 17,10
#define r312 17,4
#define r313 17,6
#define r314 17,15
#define r321 18,9
#define r322 18,3
#define r323 18,6
#define r324 18,16
#define r331 19,12
#define r332 19,2
#define r333 19,6
#define r334 19,13
#define r341 20,11
#define r342 20,1
#define r343 20,6
#define r344 20,14
#define r411 19,9
#define r412 19,4
#define r413 19,5
#define r414 19,14
#define r421 20,10
#define r422 20,3
#define r423 20,5
#define r424 20,13
#define r431 17,11
#define r432 17,2
#define r433 17,5
#define r434 17,16
#define r441 18,12
#define r442 18,1
#define r443 18,5
#define r444 18,15

#define WIRES(c,x,y,z) c##x##y##z
/*
//System 2: Build up pins from complicated macros.
//Quicker to modify, but harder to understand
#define WIRES(c,x,y,z) _WIRES_##x##y(c,x,y,z)

#define _WIRES_11(c,x,y,z) _SPIRE(c,z, 4, 8,12,16,20)
#define _WIRES_12(c,x,y,z) _SPIRE(c,z, 3, 8,11,15,19)
#define _WIRES_13(c,x,y,z) _SPIRE(c,z, 2, 8,10,14,18)
#define _WIRES_14(c,x,y,z) _SPIRE(c,z, 1, 8, 9,13,17)
#define _WIRES_21(c,x,y,z) _SPIRE(c,z, 4, 7,11,13,18)
#define _WIRES_22(c,x,y,z) _SPIRE(c,z, 3, 7,12,14,17)
#define _WIRES_23(c,x,y,z) _SPIRE(c,z, 2, 7, 9,15,20)
#define _WIRES_24(c,x,y,z) _SPIRE(c,z, 1, 7,10,16,19)
#define _WIRES_31(c,x,y,z) _SPIRE(c,z, 4, 6,10,15,17)
#define _WIRES_32(c,x,y,z) _SPIRE(c,z, 3, 6, 9,16,18)
#define _WIRES_33(c,x,y,z) _SPIRE(c,z, 2, 6,12,13,19)
#define _WIRES_34(c,x,y,z) _SPIRE(c,z, 1, 6,11,14,20)
#define _WIRES_41(c,x,y,z) _SPIRE(c,z, 4, 5, 9,14,19)
#define _WIRES_42(c,x,y,z) _SPIRE(c,z, 3, 5,10,13,20)
#define _WIRES_43(c,x,y,z) _SPIRE(c,z, 2, 5,11,16,17)
#define _WIRES_44(c,x,y,z) _SPIRE(c,z, 1, 5,12,15,18)

#define _SPIRE(c,z,bcxg,gbcx,cxgb,xgbc,red) _SPIRE_##z(c,bcxg,gbcx,cxgb,xgbc,red)
#define _SPIRE_1(c,bcxg,gbcx,cxgb,xgbc,red) _SPIRE_##c(red,gbcx,bcxg),cxgb
#define _SPIRE_2(c,bcxg,gbcx,cxgb,xgbc,red) _SPIRE_##c(red,xgbc,gbcx),bcxg
#define _SPIRE_3(c,bcxg,gbcx,cxgb,xgbc,red) _SPIRE_##c(red,cxgb,xgbc),gbcx
#define _SPIRE_4(c,bcxg,gbcx,cxgb,xgbc,red) _SPIRE_##c(red,bcxg,cxgb),xgbc
#define _SPIRE_r(r,g,b) r
#define _SPIRE_g(r,g,b) g
#define _SPIRE_b(r,g,b) b
*/
#endif

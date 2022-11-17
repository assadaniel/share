//
// Created by user on 14/11/2022.
//

// Daniel Assa 327757886

#include "ex1.h"

int is_big_endian() {

    int x = 1; //the number 1 is represented as 00000000 00000000 00000000 00000001.
    char *y = (char *) &x; //char pointer can access each byte seperately.
    return !(*y); // get first byte, = 0 if big-endian, =1 if little endian (see from the binary representation above).
   
}

int get_sign_magnitude(bool bitArray[8]) {
    int sign = (bitArray[7]) ? -1 : 1; // sign of the number, the msb is in the 7th position.
    int res = 0;
    int i;
    for (i = 0; i < 7; i++) {
        res += bitArray[i] << i; // bitArray[i]*(2^i).
    }
    return res * sign;
}

int get_two_comp(bool bitArray[8]) {
    int signed_mag = get_sign_magnitude(bitArray);
    int msb = bitArray[7];
    int sign = msb ? -1 : 1; // see sign of number when under sign magnitude, in order to make it positive.
    return sign*signed_mag - (msb << 7); // after making it positive, subtract msb*(2^7) for twos complement.
    //this is because signed_mag is actually the number given from only 7 bits.
}


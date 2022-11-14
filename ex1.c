//
// Created by user on 14/11/2022.
//

#include "ex1.h"

int is_big_endian() {
    int x = 1;
    char *y = (char *) &x;
    return !(*y);
}

int get_sign_magnitude(bool bitArray[8]) {
    int sign = (bitArray[0]) ? -1 : 1;
    int res = 0;
    for (int i = 0; i < 7; i++) {
        res += bitArray[7 - i] << i;
    }
    return res * sign;
}

int get_two_comp(bool bitArray[8]) {
    int signed_mag = get_sign_magnitude(bitArray);
    int msb = bitArray[0];
    int sign = msb ? -1 : 1;
    return sign*signed_mag - (msb << 7);
}


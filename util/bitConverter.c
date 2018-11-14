//
// Created by Jan Uni on 14.11.18.
//

#include "../DCF/DCF.h"
#include "bitConverter.h"
#include <stdio.h>
uint8_t helper_2bit(bool bit1, bool bit2){
    return bit1 + bit2 * 2;
}

uint8_t helper_3bit(bool bit1, bool bit2, bool bit3){
    return helper_2bit(bit1, bit2) + bit3 * 4;
}

uint8_t helper_4bit(bool bit1, bool bit2, bool bit3, bool bit4){
    return helper_3bit(bit1, bit2, bit3) + bit4 * 8;
}

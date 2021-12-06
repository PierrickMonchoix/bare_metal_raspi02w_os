#include "gpio.h"

#include <stdint.h>

#include "peripherals_addresses/gpio.h"
#include "utils_asm.h"



int digitalWrite(char pin , char signal){
     
    if((pin < 2 )||(pin > 27)){
        return 1;
    }
    if ( (signal != 0) && (signal != 1)){
        return 1;
    }
    uint64_t adressPinModeSelectRegister = PBASE + (pin/10)*4;  //test : 0x3F200008

    uint32_t actualPinModeRegister = get32(adressPinModeSelectRegister);

    uint32_t finalPinModeRegister =  ( actualPinModeRegister| (1<<(3*(pin%10)))  )& (~(0b11 << (3*(pin%10) + 1)) );

    set32(adressPinModeSelectRegister, finalPinModeRegister);  // 8 if  0

    uint64_t adressDigitalWriteRegister = 0;

    if(signal == 0){
        adressDigitalWriteRegister = PBASE + 0x28;
    }
    else {
        adressDigitalWriteRegister = PBASE + 0x1c;
    }

    uint32_t digitalWriteRegister = 1<<pin;

    set32(adressDigitalWriteRegister , digitalWriteRegister);


    return 0;
}

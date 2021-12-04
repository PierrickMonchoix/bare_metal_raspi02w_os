#include <stdint.h>
#include "mmio.h"
#include "gpio.h"


int digitalWrite(char pin , char signal){
     
    if((pin < 2 )||(pin > 27)){
        return 1;
    }
    if ( (signal != 0) && (signal != 1)){
        return 1;
    }
    uint64_t adressPinModeSelectRegister = GPIO_BASE + (pin/10)*4;  //test : 0x3F200008

    uint32_t actualPinModeRegister = readInPhysicalAdress(adressPinModeSelectRegister);

    uint32_t finalPinModeRegister =  ( actualPinModeRegister| (1<<(3*(pin%10)))  )& (~(0b11 << (3*(pin%10) + 1)) );

    writeInPhysicalAdress(adressPinModeSelectRegister, finalPinModeRegister);  // 8 if  0

    uint64_t adressDigitalWriteRegister = 0;

    if(signal == 0){
        adressDigitalWriteRegister = GPIO_BASE + 0x28;
    }
    else {
        adressDigitalWriteRegister = GPIO_BASE + 0x1c;
    }

    uint32_t digitalWriteRegister = 1<<pin;

    writeInPhysicalAdress(adressDigitalWriteRegister , digitalWriteRegister);


    return 0;
}

#include "mmio.h"
#include <stdint.h>

void writeInPhysicalAdress(uint64_t physicalAddress , uint32_t data){
    volatile uint32_t * const ptr = (uint32_t *)physicalAddress;
    *ptr = data;
}

uint32_t readInPhysicalAdress(uint64_t physicalAddress){
    volatile uint32_t * const ptr = (uint32_t *)physicalAddress;
    return *ptr;
}




#ifndef MMIO_H_
#define MMIO_H_

#include <stdint.h>

void writeInPhysicalAdress(uint64_t physicalAddress , uint32_t data);

uint32_t readInPhysicalAdress(uint64_t physicalAddress);

#endif


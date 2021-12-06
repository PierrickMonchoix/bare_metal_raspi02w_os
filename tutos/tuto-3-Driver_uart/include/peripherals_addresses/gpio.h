#ifndef	_P_GPIO_H
#define	_P_GPIO_H

#include "peripherals_addresses/base.h"

#define GPFSEL1         (PBASE+0x00000004)
#define GPSET0          (PBASE+0x0000001C)
#define GPCLR0          (PBASE+0x00000028)
#define GPPUD           (PBASE+0x00000094)
#define GPPUDCLK0       (PBASE+0x00000098)

#endif  /*_P_GPIO_H */

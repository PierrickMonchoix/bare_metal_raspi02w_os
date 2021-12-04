#ifndef GPIO_H_
#define GPIO_H_

#define LOW 0
#define HIGH 1

#define GPIO_BASE 0x3f200000
#define GPFSEL2 0x08

#define GPIO_21_OUTPUT 0x8 ;//# 1 << 3

#define GPFSET0 0x1c
#define GPFCLR0 0x28

#define GPIOVAL 0x200000 ;//# 1 << 21

int digitalWrite(char pin , char signal);

#endif
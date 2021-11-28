default:
	arm-none-eabi-gcc -mcpu=cortex-a7 -fpic -ffreestanding -c start.s -o start.o
	arm-none-eabi-gcc -mcpu=cortex-a7 -fpic -ffreestanding -std=gnu99 -c kernel.c -o kernel.o -O2 -Wall -Wextra
	arm-none-eabi-gcc -T linker.ld -o kernel.elf -ffreestanding -O2 -nostdlib start.o kernel.o
	arm-none-eabi-objcopy kernel.elf -O binary kernel7.img

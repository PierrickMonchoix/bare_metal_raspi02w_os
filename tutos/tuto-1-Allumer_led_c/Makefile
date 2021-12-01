default:

	aarch64-linux-gnu-as start.S -o start.o
	aarch64-linux-gnu-gcc -Wall -Werror -nostdlib -nostartfiles -ffreestanding -c kernel.c -o kernel.o
	aarch64-linux-gnu-ld start.o kernel.o -T ldscript -o kernel.elf
	aarch64-linux-gnu-objcopy kernel.elf -O binary kernel8.img
	aarch64-linux-gnu-objdump -D -S kernel.elf > kernel_objdump
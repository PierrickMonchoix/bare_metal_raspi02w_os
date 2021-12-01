default:

	aarch64-linux-gnu-as start.S -o start.o
	aarch64-linux-gnu-ld start.o -o kernel.elf
	aarch64-linux-gnu-objcopy kernel.elf -O binary kernel8.img
	aarch64-linux-gnu-objdump -D -S kernel.elf > kernel_objdump

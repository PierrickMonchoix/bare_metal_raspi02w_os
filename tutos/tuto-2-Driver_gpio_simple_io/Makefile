CC=aarch64-linux-gnu-gcc

INCLUDE_DIR=includes

CFLAGS =  -Wall -Werror -nostdlib -nostartfiles -ffreestanding 

LDFLAGS=

OBJDUMP=kernel_objdump
IMG=kernel8.img
ELF=kernel.elf

SCR=$(wildcard *.c) $(wildcard */*.c) $(wildcard */*/*.c) $(wildcard */*/*/*.c)  $(wildcard */*/*/*/*.c)
OBJ=$(SCR:.c=.o)


img:$(ELF)
	aarch64-linux-gnu-objcopy $(ELF) -O binary $(IMG)
	aarch64-linux-gnu-objdump -D -S $(ELF) > $(OBJDUMP)

start.o:
	aarch64-linux-gnu-as start.S -o start.o

$(ELF): start.o $(OBJ) 
	aarch64-linux-gnu-ld start.o $(OBJ) -T ldscript -o $(ELF)

%.o: %.c
	aarch64-linux-gnu-gcc -Wall -Werror -nostdlib -nostartfiles -ffreestanding -c $< -o $@ -I $(INCLUDE_DIR)

clean:
	rm -f *.o 
	rm -f *.elf
	rm -f *.img
	rm -f kernel_objdump
	find . -name '*.o' -delete
	

mrproper: clean
	rm -f $(EXEC)
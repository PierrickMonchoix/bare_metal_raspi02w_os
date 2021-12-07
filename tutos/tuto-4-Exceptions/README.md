# Emulation et debogage avec Qemu et Gdb

## Terminal 1 : Objdump
aarch64-linux-gnu-objdump -D build/kernel8.elf > myobjd

## Terminal 2 : Qemu en mode debug distant
qemu-system-aarch64 -M raspi3 -kernel kernel8.img -nographic -s -S

## Terminal 3 : Connexion au serveur distant avec Gdb$
~/development/anotheraarch64/gcc-arm-10.3-2021.07-x86_64-aarch64-none-elf/bin$ ./aarch64-none-elf-gdb

(gdb) b* 0x00000000000807b0

(gdb) target remote localhost:1234

0x0000000000000000 in ?? ()
(gdb) c
Continuing.

Thread 1 hit Breakpoint 1, 0x00000000000807b0 in ?? ()
(gdb) si
0x00000000000807b4 in ?? ()
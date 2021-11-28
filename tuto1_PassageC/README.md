# Passage de l'assembleur au code C

## Comportement OS

On modifie la mémoire depuis du code C

## Code

AS Armv7 puis C

# Test du code

## Créer les bianires

0) sudo apt install gcc-arm-none-eabi                // Chaine de compilation croisée 
   sudo apt intall apt install build-essential       // Make

1) Faire un make pour créer kernel7.img et kernel.elf


## Comment lancer le code sur Qemu et déboger grâce à Gdb

0)  Telecharger les utilistaires de la chaine de compilation pour ARMv7 (Gdb en particulier):
    Dans un nouveau dossier (à creer) gccArmv7:

    wget  https://developer.arm.com/tools-and-software/open-source-software/developer-tools/gnu-toolchain/gnu-rm/downloads
    tar -xf gcc-arm-none-eabi-***********x86_64-linux.tar.bz2

    Telecharger qemu-system-arm qui va émuler notre raspi:

    sudo apt install qemu-system-arm


1)  Émuler notre raspi avec qemu en mode débug (-s -S):

    qemu-system-arm -m 1024 -M raspi2b -serial stdio -kernel kernel.elf -s -S

2)  Dans un autre terminal, déboger en distant:
    
    gccArmv7/bin/arm-none-eabi-gdb

    (gdb) target remote localhost:1234

3) Indiquer les symboles de kernel.elf:

    (gdb) file kernel.elf

4) Placer un breakpoint sur kernel_main

    (gdb) b* kernel_main

5) Continuer jusqu'a atteindre le breakpoint kernel_main

    (gdb) c

6) Faire des si jusqu'a:    8064:	e5832008 	str	r2, [r3, #8]    (voir dans les sources: myobjd)

    0x0000805c in kernel_main ()
    (gdb) si
    0x00008060 in kernel_main ()
    (gdb) si
    0x00008064 in kernel_main ()
    (gdb) x 0x3f200008
    0x3f200008:     0x00000000
    (gdb) si
    0x00008068 in kernel_main ()
    (gdb) x 0x3f200008
    0x3f200008:     0x00000002
    (gdb) 

    On voit alors que la memoire a bien été changé depuis le code C

## Objdump

    On peut faire un objeump de kernel.elf pour voic ce qu'est devenu le code C:

    /home/pierrick/development/gccArm/gcc-arm-none-eabi-10.3-2021.07/bin/arm-none-eabi-objdump -D kernel.elf > myobjd






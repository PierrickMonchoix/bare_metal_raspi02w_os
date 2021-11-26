## Présentation d'un OS Minimaliste pour Raspberi pi zero 2 W

# Comportement OS

Le GPIO 21 alterne entre 0V et 5V ce qui permet d'allumer et eteindre une led periodiquement

# Code

Il n'y a aucun code source en C.
Tout est fait en assembleur ARM

## Test du code

# Créer les bianires

0) sudo apt install gcc-arm-none-eabi                // Chaine de compilation croisée 
   sudo apt intall apt install build-essential       // Make

1) Faire un make pour créer kernel7.img et kernel.elf

# Comment lancer le code sur le raspi physique

0) Telecharger Raspberry Pi Imager et une image de Raspi OS  (anciennement Raspbian)

1) Avec le logiciel Raspberry Pi Imager, installer Raspi OS sur la carte SD.

2) Dans la partition boot de la carte SD, remplir config.txt par :
    kernel_old=1
    disable_commandline_tags=1

3) Dans la partition boot de la carte SD, supprimer tous les kernel*.img (exemple : kernel.img, kernel7.img et kernel8.img)

4) Dans la la partition boot de la carte SD, ajouter kernel7.img créé par le make précédement

5) Ejecter la carte SD, l'insérer dans le raspi et alimenter le raspi

# Comment lancer le code sur Qemu et déboger grâce à Gdb

0)  Telecharger les utilistaires de la chaine de compilation pour ARMv7 (Gdb en particulier):
    Dans un nouveau dossier (à creer) gccArmv7:

    wget  https://developer.arm.com/tools-and-software/open-source-software/developer-tools/gnu-toolchain/gnu-rm/downloads
    tar -xf gcc-arm-none-eabi-***********x86_64-linux.tar.bz2

    Telecharger qemu-system-arm qui va émuler notre raspi:

    sudo apt install qemu-system-arm


1)  Émuler notre raspi avec qemu en mode débug (-s -S):

    qemu-system-arm -m 512 -M raspi0 -serial stdio -kernel kernel.elf -s -S

2)  Dans un autre terminal, déboger en distant:
    
    gccArmv7/bin/arm-none-eabi-gdb
    (gdb) target remote localhost:1234

3)  Voici des commandes gdb utiles:
    (gdb)i r    : affiche le contenu des registres  (info register)
    (gdb)si     : execute la ligne de code assembleur actuelle  (step into)



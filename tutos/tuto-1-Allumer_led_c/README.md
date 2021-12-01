# Création d'un OS pour Raspberry pi zero 2 W

## Objectif

Faire clignoter une LED externe au RPi. Le Vcc de la LED sera branché sur le GPIO 21.
Le début du code source de ce programme est en assembleur et a pour but de faire passer la suite de l'execution sur du code source en C.

## Materiel nécessaire

- Un RPi zero 2 W (Bien que cela puisse marcher sur d'autre RPis)
- Une LED
- Une résistance
- Des connectiques (Breadboard, fils de branchement)
- Un ordinateur sous Linux (Bien que cela puisse marcher sur Windows)

Note:
J'utilise personnelement WSL et vscode sur mon environement Windows pour pouvoir utiliser Linux simplement.

## Lancement sur un RPi zero 2 W

#### Préparation du RPi

1. Connecter le GPIO 21 du RPi au Vcc d'une LED.

2. Connecter le Gnd de cette le

#### Préparation de la carte SD

1. Installer RPi Imager et installer le RPi OS (anciennement Raspbian) sur la carte SD.

2. Une partition "boot" a été créée sur la carte SD par RPi Imager.
Il y a dans cette partition un fichier "config.txt". Remplacer le contenu de ce fichier par :
    ```
    kernel_old=1
    disable_commandline_tags=1
    ```
    Il y a dans cette partition des fichiers kernel*.img.
    Supprimer tout ces fichiers.
    Il nous faudra remplacer ces kernel*.img par notre propre binaire!

#### Création des binaires

1. Si ça n'a pas encore été fait, installer la chaine de compliation Aarch64 et Make:
    ```
    sudo apt-get install gcc-aarch64-linux-gnu
    sudo apt-get install make
    ```
2. À la racine de tuto, exécuter:
    ```
    make
    ```
    Un fichier "kernel8.img" à été créé.

#### Lancement du programme sur le RPi

1. Copier coller kernel8.img dans la partition "boot" de la clé.

2. Éjecter la clé

3. Débrancher le RPi

4. Introduire la carte SD dans le RPi

5. Alimenter le RPi

La led doit alors clignoter

## Explication

//TODO

## Sources

#### Datasheets

- Datasheet de la carte mère du RPi zero 2 W:
https://cs140e.sergio.bz/docs/BCM2837-ARM-Peripherals.pdf
- Instructions assembleur Aarch64 : (Le RPi zero 2 W a un CPU cortex A53 ayant le jeu d'instruction Aarch64)
https://www.keil.com/support/man/docs/armasm/armasm_dom1361289878994.htm

#### Tutoriels sur lequels je me suis appuyé:
- https://www.youtube.com/watch?v=jN7Fm_4ovio&ab_channel=LowLevelLearning
- https://github.com/s-matyukevich/raspberry-pi-os/blob/master/docs/lesson01/rpi-os.md
- https://github.com/cirosantilli/raspberry-pi-bare-metal-blinker
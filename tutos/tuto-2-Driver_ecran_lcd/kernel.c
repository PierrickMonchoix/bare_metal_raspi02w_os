#include <stdint.h>
#include <unistd.h>

/* This is bad. Anything remotely serious should use timers
 * provided by the board. But this makes the code simpler. */
/* #define BUSY_WAIT __asm__ __volatile__("")
#define BUSY_WAIT_N 0x100000 */

#define GPIO_BASE 0x3f200000
#define GPFSEL2 0x08

#define GPIO_21_OUTPUT 0x8 ;//# 1 << 3

#define GPFSET0 0x1c
#define GPFCLR0 0x28

#define GPIOVAL 0x200000 ;//# 1 << 21

#define LOW 0
#define HIGH 1


void writeInPhysicalAdress(uint64_t physicalAddress , uint32_t data){
    volatile uint32_t * const ptr = (uint32_t *)physicalAddress;
    *ptr = data;
}

uint32_t readInPhysicalAdress(uint64_t physicalAddress){
    volatile uint32_t * const ptr = (uint32_t *)physicalAddress;
    return *ptr;
}



int delay(int duree){
    int i = 0;
    while(i < duree*100000){
        i ++;
    }
    return i;
}

void _signal(){
    writeInPhysicalAdress(0x3F20001c,0x200000);
    delay(5);
    writeInPhysicalAdress(0x3F200028,0x200000);
    delay(5);
    writeInPhysicalAdress(0x3F20001c,0x200000);
    delay(5);
    writeInPhysicalAdress(0x3F200028,0x200000);
}

int digitalWrite(char pin , char signal){
     
    if((pin < 2 )||(pin > 27)){
        return 1;
    }
    if ( (signal != 0) && (signal != 1)){
        return 1;
    }
    uint64_t adressPinModeSelectRegister = GPIO_BASE + (pin/10)*4;  //test : 0x3F200008

    
    adressPinModeSelectRegister++;//sup


    uint32_t actualPinModeRegister = 0;//readInPhysicalAdress(adressPinModeSelectRegister);

    uint32_t finalPinModeRegister =  ( actualPinModeRegister| (1<<(3*(pin%10)))  )& (~(0b11 << (3*(pin%10) + 1)) );

/*     if(( (finalPinModeRegister & (1<<3)) == (1<<3))   ){// && ( (finalPinModeRegister | (1<<4)) == (1<<4)) && ((finalPinModeRegister | (1<<5)) == (1<<5)) ){
        _signal();
    }  */

   
    if(finalPinModeRegister == 8){
         
    }

    //writeInPhysicalAdress(adressPinModeSelectRegister, finalPinModeRegister);

    uint64_t adressDigitalWriteRegister = 0;

    if(signal == 0){
        adressDigitalWriteRegister = GPIO_BASE + 0x28;
    }
    else {
        adressDigitalWriteRegister = GPIO_BASE + 0x1c;
    }

    uint32_t digitalWriteRegister = 1<<pin;

    writeInPhysicalAdress(adressDigitalWriteRegister , digitalWriteRegister);


    return 0;
}


int main( void ) { 
    writeInPhysicalAdress(0x3F20001c,0x200000);
    // set pin 21 as "simple" Output 
    //writeInPhysicalAdress(0x3F200008,0x8);
    //digitalWrite(21,HIGH);
    
    

    //uint32_t i;
    /* At the low level, everything is done by writing to magic memory addresses.
     *
     * The device tree files (dtb / dts), which are provided by hardware vendors,
     * tell the Linux kernel about those magic values.
     */
/*     volatile uint32_t * const GPFSEL4 = (uint32_t *)0x3F200010;
    volatile uint32_t * const GPFSEL3 = (uint32_t *)0x3F20000C;
    volatile uint32_t * const GPSET1  = (uint32_t *)0x3F200020;
    volatile uint32_t * const GPCLR1  = (uint32_t *)0x3F20002C; */

    //mp:
/*     volatile uint32_t * const TRUC1 = (uint32_t *)0x3F200008;
    volatile uint32_t * const TRUC2 = (uint32_t *)0x3F20001c;

    *TRUC1 = 0x8;
    *TRUC2 = 0x200000; */

/*    writeInPhysicalAdress(0x3F200008,0x8);
   writeInPhysicalAdress(0x3F20001c,0x200000);

   delay(1000000);

   writeInPhysicalAdress(0x3F200028,0x200000); */
   
/*    delay(1000);
   writeInPhysicalAdress(0x3F20001c,0x200000); */

/*     *GPFSEL4 = (*GPFSEL4 & ~(7 << 21)) | (1 << 21);
    *GPFSEL3 = (*GPFSEL3 & ~(7 << 15)) | (1 << 15); */
   //digitalWrite(21,1);
   
     while (1) {
/*         digitalWrite(21,HIGH);
        delay(5);
        digitalWrite(21,LOW);
        delay(5); */


/*         *GPSET1 = 1 << (47 - 32);
        *GPCLR1 = 1 << (35 - 32);
        for (i = 0; i < BUSY_WAIT_N; ++i) { BUSY_WAIT; }
        *GPCLR1 = 1 << (47 - 32);
        *GPSET1 = 1 << (35 - 32);
        for (i = 0; i < BUSY_WAIT_N; ++i) { BUSY_WAIT; } */
    }
}

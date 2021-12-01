#include <stdint.h>
#include <unistd.h>

/* This is bad. Anything remotely serious should use timers
 * provided by the board. But this makes the code simpler. */
/* #define BUSY_WAIT __asm__ __volatile__("")
#define BUSY_WAIT_N 0x100000 */

void writeInPhysicalAdress(uint64_t physicalAddress , uint32_t data){
    volatile uint32_t * const ptr = (uint32_t *)physicalAddress;
    *ptr = data;
}

int delay(int duree){
    int i = 0;
    while(i < duree*100000){
        i ++;
    }
    return i;
}




int main( void ) { 
    // set pin 21 as "simple" Output 
    writeInPhysicalAdress(0x3F200008,0x8);
    

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
     while (1) {

   writeInPhysicalAdress(0x3F20001c,0x200000);

   delay(5);

   writeInPhysicalAdress(0x3F200028,0x200000);

   delay(5);  

/*         *GPSET1 = 1 << (47 - 32);
        *GPCLR1 = 1 << (35 - 32);
        for (i = 0; i < BUSY_WAIT_N; ++i) { BUSY_WAIT; }
        *GPCLR1 = 1 << (47 - 32);
        *GPSET1 = 1 << (35 - 32);
        for (i = 0; i < BUSY_WAIT_N; ++i) { BUSY_WAIT; } */
    }
}

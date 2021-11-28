void kernel_main()
{


   asm(
    "ldr r0, =0x3f200000;"
    "ldr r1, =0x8;"
    "str r1, [r0, #0x08];"
    "ldr r1, =0x200000;"
    "str r1, [r0, #0x1c];"
  );

  
 
  /*   int *ptrSelectionPinMode = GPIO_BASE + GPFSEL2;
    *ptrSelectionPinMode = GPIO_21_OUTPUT;

    int *ptrSelectionHighPins = GPIO_BASE + GPFSET0;
    *ptrSelectionHighPins = GPIOVAL; */

  // *(volatile uint32_t*)0x3f200008 = 0x8;
  // *(volatile uint32_t*)0x3f20001c = 0x200000;

/*     int * ptr = 0x3f200008;
    *ptr = 0x8; 

    int * ptr2 = 0x3f200001c;
    *ptr2 = 0x200000; */

   
}
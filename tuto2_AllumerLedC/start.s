.section ".text.boot"

.global _start

_start:

    .equ GPIO_BASE, 0x3f200000
.equ GPFSEL2, 0x08

.equ GPIO_21_OUTPUT, 0x8 ;//# 1 << 3

.equ GPFSET0, 0x1c
.equ GPFCLR0, 0x28

.equ GPIOVAL, 0x200000 ;//# 1 << 21

_start:
/* 
 	;//# base of our GPIO structure
	ldr r0, =GPIO_BASE

	;//# set the GPIO 21 function as output
	ldr r1, =GPIO_21_OUTPUT
	str r1, [r0, #GPFSEL2]

	# turn on the LED
	ldr r1, =GPIOVAL ;//# value to write to set register
	str r1, [r0, #GPFSET0] ;//# store in set register 

*/

/*   	;//# base of our GPIO structure
	ldr r0, =0x3f200000

	;//# set the GPIO 21 function as output
	ldr r1, =0x8
	str r1, [r0, #0x08]

	# turn on the LED
	ldr r1, =0x200000 ;//# value to write to set register
	str r1, [r0, #0x1c] ;//# store in set register   */





    mrc p15, #0, r1, c0, c0, #5




    //and r1, r1, #3
//not passed

    ldr r10, =0x3f200000
    ldr r11, =0x8
    str r11, [r10, #0x08]
    ldr r11, =0x200000
    str r11, [r10, #0x1c]


    cmp r1, #0
    bne halt





    mov sp, #0x8000

    ldr r4, =__bss_start
    ldr r9, =__bss_end
    mov r5, #0
    mov r6, #0
    mov r7, #0
    mov r8, #0
    b       2f

1:
    stmia r4!, {r5-r8}

2:
    cmp r4, r9
    blo 1b
/* 
gotoc:
    ldr r3, =kernel_main
    blx r3 */





halt:
    wfe
    b halt






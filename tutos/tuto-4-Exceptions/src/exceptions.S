.globl getCurrentEl
getCurrentEl:
	mrs x0, CurrentEL
	ret

.globl setVectorTable
setVectorTable:
	ldr x0, = whenException
	sub x0, x0, #0x200
	msr VBAR_EL3, x0
	ret

.globl riseException
riseException:
	smc #0
	ret

.globl setVectorTableEl2
setVectorTableEl2:
	ldr x0, = whenException
	sub x0, x0, #0x200
	msr VBAR_EL2, x0
	ret

.globl riseExceptionEl2
riseExceptionEl2:
	hvc #0
	ret



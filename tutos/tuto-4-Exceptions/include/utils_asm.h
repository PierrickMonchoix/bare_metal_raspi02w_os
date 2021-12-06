#ifndef	UTILS_ASM_H_
#define	UTILS_ASM_H_

#include <stdint.h>

extern void delay ( unsigned long);
extern void set32 ( uint64_t, uint32_t );
extern uint32_t get32 ( uint64_t );

#endif  /*_BOOT_H */

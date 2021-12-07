#ifndef	EXCEPTIONS_H_
#define	EXCEPTIONS_H_

#include <stdint.h>


extern uint64_t getCurrentEl();

extern void setVectorTable();

extern void setVectorTableEl2();

extern void riseException();

extern void riseExceptionEl2();

#endif  /*_BOOT_H */
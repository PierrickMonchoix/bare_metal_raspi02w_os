#include "time.h"
#include "utils_asm.h"

void millisDelay(long duree){
    delay(duree*4000);
}
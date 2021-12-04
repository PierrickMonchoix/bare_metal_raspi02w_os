#include "time.h"

int delay(int duree){
    int i = 0;
    while(i < duree*100000){
        i ++;
    }
    return i;
}
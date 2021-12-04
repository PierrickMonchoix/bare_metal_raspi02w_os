#include <stdint.h>
#include <unistd.h>
#include "time.h"
#include "gpio.h"

int main( void ) { 
while (1) {
        digitalWrite(21,HIGH);
        delay(5);
        digitalWrite(21,LOW);
        delay(5); 
    }
}

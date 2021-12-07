#include "mini_uart.h"

void whenException(){
    uart_init();
    uart_send_string("\nException token!!\n");
}
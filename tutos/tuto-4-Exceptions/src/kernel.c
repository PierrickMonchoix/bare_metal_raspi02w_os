#include "mini_uart.h"
#include "time.h"
#include "utils_c.h"
#include "exceptions.h"

void kernel_main(void)
{
	uart_init();
	uart_send_string("\n###### Kernel initialise ! ######\n\n");

   
   
   char ptrStr[65];

   uint64_t currentel = getCurrentEl();
    
   intToString(ptrStr , currentel);

	while (1) {
		uart_send_string("\nExceptions :)\n");
		uart_send_string(ptrStr);
		uart_send_string("\n\n");
		millisDelay(2000);  // mon delay
	}
}

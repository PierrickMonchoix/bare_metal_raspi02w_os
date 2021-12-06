#include "mini_uart.h"
#include "time.h"
#include "exceptions.h"

void kernel_main(void)
{
	uart_init();
	uart_send_string("\n###### Kernel initialise ! ######\n\n");

	while (1) {
		uart_send_string("ok\n");
		millisDelay(100);  // mon delay
	}
}

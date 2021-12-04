#include "mini_uart.h"
#include "time.h"

void kernel_main(void)
{
	uart_init();
	uart_send_string("Hello, world!\r\n");

	while (1) {
		uart_send(5);
		mpdelay(50);
	}
}

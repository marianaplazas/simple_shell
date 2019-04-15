
#include "shell.h"

void manage_sigint(int sig __attribute__((unused)))
{
	_putchar('$');
	_putchar(' ');
	_putchar('\n');
}

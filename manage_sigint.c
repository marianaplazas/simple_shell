
#include "shell.h"

/**
 * manage_sigint - manages the interrupt signal ctrl^C
 * @sig: signal (not used)
 */
void manage_sigint(int sig __attribute__((unused)))
{
	_putchar('\n');
}

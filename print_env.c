#include "shell.h"

/**
 * print_env - prints environment.
 * @environment: array of pointers containing  environment variables.
 */
void print_env(char **environment)
{
	int i, j;

	i = 0;
	while (environment != NULL && environment[i] != NULL)
	{
		j = 0;
		while (environment[i][j] != '\0')
		{
			_putchar(environment[i][j]);
			j++;
		}
		_putchar('\n');
		i++;
	}
}

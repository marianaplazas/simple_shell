#include "shell.h"

/**
 * _strcmp - compares two strings.
 * @s1: string to be compared.
 * @s2: string to be compared.
 *
 * Return: integer less than, equal to or greater than 0
 * if s1 is less than, equal to or greater than s2.
 */

int _strcmp(char *s1, char *s2)
{
	int comp;

	comp = 0;
	while (s2[comp] != '\0')
	{
		if (s1[comp] != s2[comp])
		{
			return (s1[comp] - s2[comp]);
		}
		comp++;
	}
	return (0);
}

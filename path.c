#include "shell.h"

/**
 * path - Gives us the absolute path of a given executable program.
 * @exec_file: executable file being searched.
 *
 * Return: Absolute path of a given executable file.
 */
char *path(char *exec_file)
{
	int i = 0, lenght_palabra = 0, cont = 0, j, y, exist = 0;
	char *aux, *str_tok, *_stat, *dup_env, *palabra;
	char *aux_exec_file;
	struct stat st;

	palabra = "PATH";
	aux_exec_file = _strcat("/", exec_file);
	free(exec_file); 
	lenght_palabra = cont_word(palabra);
	while (environ[i] != NULL)
	{
		aux = environ[i];
		for (y = 0, j = 0, cont = 0; y < lenght_palabra; y++, j++)
		{
			if (aux[j] == palabra[j])
				cont++;
			else
				break;
		}

		if (cont == lenght_palabra)
		{
			dup_env  = strdup(environ[i]);
			str_tok = strtok(dup_env, "=");
			while (str_tok != NULL)
			{
				/* str_tok = malloc(sizeof(char) * 120); */
				str_tok = strtok(NULL, ":");
				while (str_tok != NULL)
				{
					_stat = _strcat(str_tok, aux_exec_file);
					exist = stat(_stat, &st);
					if (exist == 0)
						return (_stat);

					str_tok = strtok(NULL, ":");
					if (str_tok != NULL)
						free(_stat);
				}
			}
			free(dup_env);
			free(aux_exec_file);
			return (_stat);
		}
		i++;
	}
	return (NULL);
}

/**
 * cont_word - counts words
 * @palabra: string containing words.
 *
 * Return: number of words.
 */
int cont_word(char *palabra)
{
	int i;

	for (i = 0; palabra[i] != '\0'; i++)
	{
	}
	return (i);
}

/**
 *_strcat - concatenates two strings
 *
 *@dest: frist pointer
 *@src: second pointer
 *
 *Return: dest
 */
char *_strcat(char *dest, char *src)
{
	int one;
	int two;
	char *aux = dest;

	for (one = 0; dest[one] != '\0'; one++)
		;
	for (two = 0; src[two] != '\0'; two++)
		;
	dest = malloc(sizeof(char) * (one + two + 1));
	for (two = 0; aux[two]; two++)
		dest[two] = aux[two];
	for (two = 0; src[two] != '\0'; two++)
		dest[one + two] = src[two];
	dest[one + two] = '\0';
	return (dest);
}

/**
 *_strdup - duplicates a string
 *
 *@str: the string for duplicate
 *Return: the copy of the string
 */
char *_strdup(char *str)
{
	int i;
	int len = 0;
	char *copy;

	if (!str)
		return (NULL);
	for (i = 0; *(str + i); i++)
		len++;
	copy = malloc(len * sizeof(char) + 1);

	if (copy == NULL)
		return (NULL);
	for (i = 0; i < len; i++)
		*(copy + i) = *(str + i);
	*(copy + i) = '\0';
	return (copy);
}

#include <stdio.h>
#include <stdlib.h>
#include "shell.h"
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	char **token;
/*	int status;
 */
	
	while (1) 
	{
		printf("$ ");
		/* status =*/ getline(&line, &len, stdin);
		/**
		 *aqui debe ir el manejador de errores
		 *usar continue
		 */
		token = _strtok(line);

		if (token[0] == NULL
		    perror("no such a file or directory");

		if (file_exist(token) != 0)
			path(token[0]);

		if (fork() == 0)
		{
			if (execve(token[0], token, NULL) == -1)
				/**
				 *perror
				 */
				break;
		}
		else
		{
			wait(NULL)
		}

	}
	free(line);
	exit(98);
	return(0);
}

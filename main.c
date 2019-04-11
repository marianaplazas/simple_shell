#include <stdio.h>
#include <stdlib.h>
#include "shell.h"

int main(void)
{
	char *line = NULL;
	size_t n = 0;
	ssize_t state;
	char **token;
	
	while (1) 
	{
		printf("$ ");
		state = getline(&line, &n, stdin);

		if (state == -1)
		{
			perror("./shell");
			exit(-1);
		}

		token = _strtok(line);

		if (token[0] == NULL)
		{
			perror("./shell");
		}

		/*if (stat(token) != 0)
			path(token[0]);*/

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
			wait(NULL);
		}

	}
	free(line);
	exit(98);
	return(0);
}

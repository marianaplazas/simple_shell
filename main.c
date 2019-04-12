
#include "shell.h"

int main(int argc __attribute__((unused)), char* argv[])
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
			perror(argv[0]);
			exit(EXIT_FAILURE);
		}

		token = _strtok(line);

		if (token[0] == NULL)
		{
			perror(argv[0]);
			exit(EXIT_FAILURE);
		}

		if (_strcmp(token[0], "exit") == 0)
		{
			exit(EXIT_SUCCESS);
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

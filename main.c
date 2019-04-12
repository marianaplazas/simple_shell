#include "shell.h"
int main()
{
	char *line = NULL;
	char *delimit = " \t\r\n\v\f";
	size_t n = 0;
	ssize_t state;
	char **token;

	while (state != -1) 
	{
		printf("$ ");
		state = getline(&line, &n, stdin);
		if (state != -1 && state != 1)
		{
			token = _strtok(line, delimit);
			/* if (token == NULL) */
			/* { */
			/* 	perror(argv[0]); */
			/* 	exit(EXIT_FAILURE); */
			/* } */
			
			if (_strcmp(token[0], "exit") == 0)
			{
				exit(EXIT_SUCCESS);
			}
			
			if (fork() == 0)
			{
				if (execve(token[0], token, NULL) == -1)
				{
					perror("./hsh");
					exit(-1);
				}
				
			}
			else
			{
				wait(NULL);
			}
		}
	}
	free(line);
	exit(98);
	return(0);
}

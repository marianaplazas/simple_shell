#include "shell.h"
int main()
{
	char *line = NULL;
	char *delimit = " \t\r\n\v\f";
	size_t n = 0;
	ssize_t state;
	char **token;
	pid_t pid;
	int status = 0;

	signal(SIGINT, manage_sigint);
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

			if (_strcmp(token[0], "env") == 0)
			{
				print_env(token);
			}
			token[0] = path(token[0]);
			pid = fork();
			if (pid == 0)
			{
				if (execve(token[0], token, NULL) == -1)
				{
					perror("./hsh");
					exit(-1);
				}	
			}
			else
			{
				waitpid(pid, &status, 0);
			}
		}
	}
	/*free(line);*/
	exit(state);
	return(0);
}

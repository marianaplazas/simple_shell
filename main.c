#include "shell.h"

/**
 * main - shell program
 * @ac: number of arguments. Unused.
 * @argv: arguments typed by the user.
 * @envp: environment variables.
 *
 * Return: 0 if successful.
 */
int main(int ac __attribute__((unused)), char **argv, char **envp)
{
	char *line = NULL, *delimit = " \t\r\n\v\f", **token;
	size_t n = 0;
	ssize_t state;
	pid_t pid;
	int status = 0;
	struct stat st;

	signal(SIGINT, manage_sigint);
	while (state != -1)
	{
		if (isatty(0) != 0)
		{
		}
		state = getline(&line, &n, stdin);
		if (state != -1 && state != 1)
		{			token = _strtok(line, delimit);
			if (token == NULL)
			{	perror(token[0]), exit(EXIT_FAILURE);	}
			if (_strcmp(token[0], "exit") == 0)
			{	free(line), free(token),  exit(EXIT_SUCCESS);	}
			if (_strcmp(token[0], "env") == 0)
				print_env(envp);
			pid = fork();
			if (pid == 0)
			{
				if (stat(token[0], &st) == 0)
					execve(token[0], token, NULL);
				else
					token[0] = path(token[0]);
				if (execve(token[0], token, NULL) == -1)
				{	perror(argv[0]);
					exit(-1);      }	}
			else
				waitpid(pid, &status, 0);	}	  }
	free(token);
	free(line);
	exit(state);
	return (0);
}

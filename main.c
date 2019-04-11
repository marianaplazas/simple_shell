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
		token = _strtok(line);
		if (token[0] == NULL)
			perror("no such a file or directory");
		path();
	}
	free(line);
	exit(98);
	return(0);
}

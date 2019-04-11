#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"
char **_strtok(char *istring)
{
	int i = 0;
	char delimit[]=" \r\n\v\f";
	char **tokens = malloc(sizeof(char));
	char *tok;


	tok = strtok(istring, delimit); 
	while (tok != NULL)
	{
		tokens[i] = tok;
		i++;
		tok = strtok(NULL, delimit);
	}
	return(tokens);
}

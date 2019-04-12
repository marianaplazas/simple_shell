#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"
char **_strtok(char *istring, const char *delimit)
{
	int i = 0;
	char **tokens;
	char *tok;
	char *dup_token;

	dup_token = strcp(istring);
	tok = strtok(istring, delimit);
	i++;
	while (tok != NULL)
	{
		tok = strtok(NULL, delimit);
		i++;
	}
	tokens = malloc(sizeof(char *) * i);
	i = 0;
	tokens[i] = strtok(dup_token, delimit);
	while (tokens[i] != NULL)
	{
		i++;
		tokens[i] = strtok(NULL, delimit);
	}
	return(tokens);
}
/**
 *
 */
char *strcp(char *str)
{
	char *dup = NULL;
	int counter = 0; 
	int size = 0;
	
	if (str == NULL)
		return (NULL);	while (str[size])
		size++;
	dup = malloc(size * sizeof(char));
	while (counter <= size)
	{
		dup[counter] = str[counter];
		counter++;
	}
	return (dup);
}

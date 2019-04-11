#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"
extern char **environ;

typedef struct nodo
{
	char *word;
	struct nodo *next;
}node;

node *new_node(node **head ,char *str)
{
	node *new;

	new = malloc(sizeof(node));
	if (new == NULL)
		return (NULL);

	new->word = str;
	new->next = *head;
	*head = new;
	return(new);
}

void path()
{
	int i = 0, lenght_palabra = 0, cont = 0, j, y;
	char *aux, *str_tok;
	char *palabra = "PATH";
	node *head;
	head = NULL;

	lenght_palabra = cont_word(palabra);

	while(environ[i] != NULL)
	{
		aux = environ[i];

		for (y = 0, j = 0; y < lenght_palabra; y++, j++)
		{
			if(aux[j] == palabra[j])
				cont++;
		}

		if (cont == lenght_palabra)
		{
			str_tok = strtok(environ[i], "=");
			while(str_tok != NULL)
			{
				str_tok = strtok(NULL, ":");
				if(str_tok != NULL)
				new_node(&head, str_tok);
			}
			break;
		}
		i++;
	}
}

int cont_word(char * palabra)
{
	int i;

	for(i = 0; palabra[i] != '\0'; i++)
	{
	}
	return (i);
}

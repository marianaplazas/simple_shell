#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <errno.h>
#include <unistd.h>
int _strcmp(char *s1, char *s2);
char **_strtok(char *istring, const char *delimit);
int hand_errors(char **av);
void path();
int cont_word(char *palabra);
char* strcp(char *str);
#endif

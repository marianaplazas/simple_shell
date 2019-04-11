#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
char **_strtok(char *istring);
int hand_errors(char **av);
void path();
int cont_word(char * palabra);
#endif

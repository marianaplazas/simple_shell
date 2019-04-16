#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <errno.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
extern char **environ;
char *_strcat(char *dest, char *src);
int _putchar(char);
void print_env(char **environment);
int _strcmp(char *s1, char *s2);
char **_strtok(char *istring, const char *delimit);
int hand_errors(char **av);
char *path(char *var);
int cont_word(char *palabra);
char *strcp(char *str);
void manage_sigint(int sig);
char *_strncpy(char *dest, char *src, int n);
char *_strdup(char *str);
#endif

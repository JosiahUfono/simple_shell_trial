#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>

int _builtin(char **arg);
char *path_getter(char *arg);
char *location(char *path, char *arg);
int _putchar(char c);
int _putstring(char *str);



#endif /*MAIN_H*/
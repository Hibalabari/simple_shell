#ifndef _SIMPLESHELL_H_
#define _SIMPLESHELL_H_


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/errno.h>
#include <sys/fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>

#define DELIM " \t\n"

extern char **environ;
char *getline_eror(void);

char *_strdup(const char *str);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);

void emptytable(char **tableau);
int cmd_execute(char **laCommande, char **argv);
char **spliter(char *bufferr);

#endif

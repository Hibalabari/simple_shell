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

char *myStrdup(const char *strr);
int strCompare(char *str1, char *str2);
int getLongueur(char *str);
char *strConcact(char *destination, char *orgin);
char *_strCopy(char *destination, char *orgin);

void emptytable(char **tableau);

int cmd_execute(char **laCommande, char **argv, int id);
char **spliter(char *bufferr);

char *i_toa(int m);
void inverser_strg(char *str, int longg);

char *findEnv(char *x);
char *myPath(char *laCommande);
void errorMsg(char *nom, char *laCommande, int id);

#endif

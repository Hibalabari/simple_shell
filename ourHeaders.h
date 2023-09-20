#ifndef _SIMPLESHELL_H_
#define _SIMPLESHELL_H_


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

void executee(char **argv);
char *path_getting(char *commande);
ssize_t getline_eror(void);

#endif

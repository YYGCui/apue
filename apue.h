
#ifndef _APUE_H
#define _APUE_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define MAXLINE 4096

#define FILE_MODE   (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)

char *path_alloc(int *);

void err_dump(const char *, ...);
void err_quit(const char *, ...);
void err_sys(const char *, ...);
void err_ret(const char *, ...);

#endif

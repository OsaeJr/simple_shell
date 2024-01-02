#ifndef SHELL_H
#define SHELL_H
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>

extern char **environ;

int _strcmp(char *s1, char *s2);
size_t _strncmp(char *s1, char *s2, size_t n);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strcat_custom(char *destination, char *source)
int _putchar(char c);

char *getPath(char **environment)
int _search_path(char **command, char **env);
char *getUserInput(void);
void _getenv(char **env);
char **tokenizeInput(char *inputString)
void _exit_command(char **args, char *lineptr, int _exit);
int executeCommand(char **commandTokens, char **programName, char **environment, char *inputLine, int processID, int checker)
char *custom_strtok(char *str, const char *delim)

#endif

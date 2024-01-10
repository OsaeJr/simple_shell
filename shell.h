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

int _strcmp_custom(char *str1, char *str2);
unsigned int _strncmp_custom(char *str1, char *str2, unsigned int n);
int _strlen_custom(char *str);
char *_strcpy_custom(char *destination, char *source);
char *_strcat_custom(char *destination, char *source)
int _putchar(char c);

char *getPath(char **environment)
int _search_path(char **command, char **env);
char *getUserInput(void);
void printEnvironment(char **environment);
char **tokenizeInput(char *inputStriiing)
void exitCommand(char **arguments, char *inputString, int exitCode);
int executeCommand(char **commandTokens, char **programName, char **environment, char *inputLine, int processID, int checker)
char *custom_strtok(char *str, const char *delim)

#endif

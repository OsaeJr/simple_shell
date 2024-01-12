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

int custom_strcmp(char *a1, char *a2);
size_t custom_strncmp(char *a1, char *a2, unsigned int num);
int custom_strlen(char *str);
char *custom_strcpy(char *destination, char *source);
char *custom_strcat(char *destination, char *source);
int _putchar(char c);

char *get_path(char **env);
int _parse_path(char **command, char **env);
char *read_command(void);
void print_env(char **environment);
char **extract_tokens(char *line);
void exit_command(char **args, char *lin_ptr, int exit_code);
int fork_proc(char **args, char **sh, char **env, char *lin_ptr, int id, int a);
char *_custom_strtok(char *input, const char *delimiters);
int main(int argc, char **argv, char **envp)
#endif 

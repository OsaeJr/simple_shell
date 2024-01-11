#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <limits.h>

#define BUFSIZE 1024
#define TOK_BUFSIZE 128
#define TOK_DELIM " \t\r\n\a"

extern char **environ;

typedef struct data
{
	char **av;
	char *input;
	char **args;
	int status;
	int counter;
	char **_environ;
	char *pid;
} data_shell;

typedef struct sep_list_s
{
	char separator;
	struct sep_list_s *next;
} sep_list;


typedef struct line_list_s
{
	char *line;
	struct line_list_s *next;
} line_list;


typedef struct r_var_list
{
	int len_var;
	char *val;
	int len_val;
	struct r_var_list *next;
} r_var;

typedef struct builtin_s
{
	char *name;
	int (*f)(data_shell *datash);
} builtin_t;

void initialize_data(data_shell *shell_data, char **arguments);
void release_resources(data_shell *shell_data);
int main(int argument_count, char **argument_vector);
int (*find_builtin(char *command))(data_shell *);
void changeToParentDirectory(data_shell *datash);
void changeToDirectory(data_shell *datash);
void changeToPreviousDirectory(data_shell *datash);
void changeToHomeDirectory(data_shell *datash);
int change_current_directory(data_shell *datash);
int count_repeated_chars(char *input, int index);
int find_syntax_error(char *input, int index, char last_char);
int find_first_char(char *input, int *index);
void display_syntax_error(data_shell *datash, char *input, int index, int is_repetition);
int check_syntax_errors(data_shell *datash, char *input);
int compareEnvName(const char *envVar, const char *name);
char *getEnvironmentVariable(const char *name, char **environment);
int printEnvironmentVariables(data_shell *dataShell);
char *copyInfo(char *name, char *value);
void setEnvironmentVariable(char *name, char *value, data_shell *datash);
int _setEnvironment(data_shell *datash);
int _unsetEnvironment(data_shell *datash);
char *generateErrorMessage(data_shell *shellData, int errorType);
char *cdErrorMessage(data_shell *shellData);
char *notFoundErrorMessage(data_shell *shellData);
char *exitShellErrorMessage(data_shell *shellData);
char *generateEnvError(data_shell *shellData);
char *generatePermissionDeniedError(data_shell *shellData);
int isCurrentDirectory(char *path, int *currentIndex);
char *findExecutablePath(char *command, char **environment);
int isExecutableFile(data_shell *dataShell);
int checkExecutePermissions(char *directory, data_shell *dataShell);
int executeCommand(data_shell *dataShell);
int report_error(data_shell *shell_data, int error_code);
int display_help(data_shell *shell_data);
void set_input_buffer(char **line_buffer, size_t *buffer_size, char *buffer, size_t input_size);
ssize_t get_input(char **line_buffer, size_t *buffer_size, FILE *stream);
void handle_sigint(int signal);
void display_help_env(void);
void display_help_setenv(void);
void display_help_unsetenv(void);
void display_help_general(void);
void display_help_exit(void);
void display_help(void);
void display_help_alias(void);
void display_help_cd(void);
int execute_line(data_shell *data);
sep_list *add_separator_node_end(sep_list **separator_list, char separator);
void free_separator_list(sep_list **separator_list);
line_list *add_line_node_end(line_list **line_list, char *line);
void free_line_list(line_list **line_list);
r_var *add_rvar_node(r_var **rvar_list, int length_var, char *value, int length_value);
void free_rvar_list(r_var **rvar_list);
void _memcpy(void *dest, const void *src, unsigned int size);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char **_realloc_double_pointer(char **ptr, unsigned int old_size, unsigned int new_size);
int shell_exit(data_shell *shell_data);
int get_number_length(int num);
char *int_to_string(int num);
int _atoi(char *str);
char *_strcat(char *destination, const char *source);
char *_strcpy(char *destination, char *source);
int _strcmp(char *str1, char *str2);
char *_strchr(char *str, char character);
int _strspn(char *s, char *accept);
char *_strdup(const char *str);
int _strlen(const char *str);
int cmp_chars(char str[], const char *delim);
char *_strtok(char str[], const char *delim);
int _isdigit(const char *str);
void reverse_string(char *str);

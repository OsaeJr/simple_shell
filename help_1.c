#include "main.h"

/**
 * display_help_env - Help information for the builtin env
 * Return: no return
 */
void display_help_env(void)
{
	char *help_message = "env: env [option] [name=value] [command [args]]\n\t";
	write(STDOUT_FILENO, help_message, _strlen(help_message));

	help_message = "Print the environment of the shell.\n";
	write(STDOUT_FILENO, help_message, _strlen(help_message));
}

/**
 * display_help_setenv - Help information for the builtin setenv
 * Return: no return
 */
void display_help_setenv(void)
{
	char *help_message = "setenv: setenv (const char *name, const char *value, int replace)\n\t";
	write(STDOUT_FILENO, help_message, _strlen(help_message));

	help_message = "Add a new definition to the environment\n";
	write(STDOUT_FILENO, help_message, _strlen(help_message));
}

/**
 * display_help_unsetenv - Help information for the builtin unsetenv
 * Return: no return
 */
void display_help_unsetenv(void)
{
	char *help_message = "unsetenv: unsetenv (const char *name)\n\t";
	write(STDOUT_FILENO, help_message, _strlen(help_message));

	help_message = "Remove an entry completely from the environment\n";
	write(STDOUT_FILENO, help_message, _strlen(help_message));
}

/**
 * display_help_general - Entry point for help information for the help builtin
 * Return: no return
 */
void display_help_general(void)
{
	char *help_message = "^-^ bash, version 1.0(1)-release\n";
	write(STDOUT_FILENO, help_message, _strlen(help_message));

	help_message = "These commands are defined internally. Type 'help' to see the list";
	write(STDOUT_FILENO, help_message, _strlen(help_message));

	help_message = "Type 'help name' to find out more about the function 'name'.\n\n ";
	write(STDOUT_FILENO, help_message, _strlen(help_message));

	help_message = " alias: alias [name=['string']]\n cd: cd [-L|[-P [-e]] [-@]] ";
	write(STDOUT_FILENO, help_message, _strlen(help_message));

	help_message = "[dir]\nexit: exit [n]\n  env: env [option] [name=value] [command ";
	write(STDOUT_FILENO, help_message, _strlen(help_message));

	help_message = "[args]]\n  setenv: setenv [variable] [value]\n  unsetenv: ";
	write(STDOUT_FILENO, help_message, _strlen(help_message));

	help_message = "unsetenv [variable]\n";
	write(STDOUT_FILENO, help_message, _strlen(help_message));
}

/**
 * display_help_exit - Help information for the builtin exit
 * Return: no return
 */
void display_help_exit(void)
{
	char *help_message = "exit: exit [n]\n Exit shell.\n";
	write(STDOUT_FILENO, help_message, _strlen(help_message));

	help_message = "Exits the shell with a status of N. If N is omitted, the exit";
	write(STDOUT_FILENO, help_message, _strlen(help_message));

	help_message = "status is that of the last command executed\n";
	write(STDOUT_FILENO, help_message, _strlen(help_message));
}


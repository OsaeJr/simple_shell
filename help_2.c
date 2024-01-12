#include "main.h"

/**
 * display_help - Help information for the builtin help.
 * Return: no return
 */
void display_help(void)
{
	char *help_message = "help: help [-dms] [pattern ...]\n";

	write(STDOUT_FILENO, help_message, _strlen(help_message));
	help_message = "\tDisplay information about builtin commands.\n ";
	write(STDOUT_FILENO, help_message, _strlen(help_message));
	help_message = "Displays brief summaries of builtin commands.\n";
	write(STDOUT_FILENO, help_message, _strlen(help_message));
}

/**
 * display_help_alias - Help information for the builtin alias.
 * Return: no return
 */
void display_help_alias(void)
{
	char *help_message = "alias: alias [-p] [name[=value]...]\n";

	write(STDOUT_FILENO, help_message, _strlen(help_message));
	help_message = "\tDefine or display aliases.\n ";
	write(STDOUT_FILENO, help_message, _strlen(help_message));
}

/**
 * display_help_cd - Help information for the builtin cd.
 * Return: no return
 */
void display_help_cd(void)
{
	char *help_message = "cd: cd [-L|[-P [-e]] [-@]] [dir]\n";

	write(STDOUT_FILENO, help_message, _strlen(help_message));
	help_message = "\tChange the shell working directory.\n ";
	write(STDOUT_FILENO, help_message, _strlen(help_message));
}

#include "shell.h"

/**
 * exit_command - Closes the simple_shell when exit is called
 *
 * @args: Pointer to the arguments
 * @lin_ptr: Standard input string
 * @exit_code: Exit code
 * Return: None
 */
void exit_command(char **args, char *lin_ptr, int exit_code)
{
	int index = 0;

	if (!args[1])
	{
		free(lin_ptr);
		free(args);
		exit(exit_code);
	}
	index = atoi(args[1]);

	free(lin_ptr);
	free(args);
	exit(index);
}

/**
 * print_env - Prints all environment variables
 *
 * @environment: Environment variables
 * Return: None
 */
void print_env(char **environment)
{
	unsigned int exec = 0;

	while (environment[exec])
	{
		write(STDOUT_FILENO, environment[exec], _strlen(environment[exec]));
		write(STDOUT_FILENO, "\n", 1);
		exec++;
	}
}

#include "shell.h"
/**
 * _exit_command - this function closes the simple_shell when
 * @arg: pointer with the direction argument.
 * @lineptr: standar input string
 * @_exit: value of exit
 * Return: None
 */
void _exit_command(char **arg, char *lineptr, int _exit)
{
	int index = 0;

	if (!arg[1])
	{
		free(lineptr);
		free(arg);
		exit(_exit);
	}
	index = atoi(arg[1]);

	free(lineptr);
	free(arg);
	exit(exit_status);
}

/**
 *_getenv - function to get all env
 *@env: enviroment
 *Return: 0
 */

void _getenv(char **env)
{
	unsigned int a = 0;

	while (env[a])
	{
		write(STDOUT_FILENO, env[a], _strlen(env[run]));
		write(STDOUT_FILENO, "\n", 1);
		a++;
	}
}

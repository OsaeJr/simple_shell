#include "shell.h"
/**
 * _getline_command - print "#cisfun$ " and wait for the user type something.
 * Return: line of string input for user
 */

char *_getline_command(void)
{
	char *a = NULL;
	unsigned int b = 0;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);

	if (getline(&a, &b, stdin) == -1)
	{
		free(a);
		return (NULL);
	}

	return (a);
}

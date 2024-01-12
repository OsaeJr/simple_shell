#include "shell.h"

/**
 * read_command - Displays the shell prompt and waits for user input.
 * Return: Pointer to the user input string.
 */
char *read_command(void)
{
	char *ptr = NULL;
	unsigned int user = 0;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);

	if (getline(&ptr, &user, stdin) == -1)
	{
		free(ptr);
		return (NULL);
	}

	return (ptr);
}


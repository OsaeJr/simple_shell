#include "shell.h"

/**
 * getUserInput - Display a prompt and wait for the user to input something.
 * Return: String containing the user input.
 */
char *getUserInput(void)
{
	char *inputLine = NULL;
	size_t bufferSize = 0;
	ssize_t readStatus;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);

	readStatus = getline(&inputLine, &bufferSize, stdin);

	if (readStatus == -1)
	{
		free(inputLine);
		return (NULL);
	}

	return (inputLine);
}

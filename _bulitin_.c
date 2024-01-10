#include "shell.h"

/**
 * exitCommand - Closes the simple_shell when exit command is entered.
 * @arguments: Pointer to the array of command arguments.
 * @inputString: Standard input string.
 * @exitCode: Exit code to be used when exiting.
 * Return: None
 */
void exitCommand(char **arguments, char *inputString, int exitCode)
{
	int exitStatus = 0;

	if (!arguments[1])
	{
		free(inputString);
		free(arguments);
		exit(exitCode);
	}
	exitStatus = atoi(arguments[1]);

	free(inputString);
	free(arguments);
	exit(exitStatus);
}

/**
 * printEnvironment - Prints all environment variables.
 * @environment: Array of environment variables.
 * Return: None
 */
void printEnvironment(char **environment)
{
	unsigned int index = 0;

	while (environment[index])
	{
		write(STDOUT_FILENO, environment[index], _strlen_custom(environment[index]));
		write(STDOUT_FILENO, "\n", 1);
		index++;
	}
}


#include "shell.h"

/**
 * executeCommand - Creates a fork to execute a command.
 * @commandTokens: Command and arguments.
 * @programName: Name of the program.
 * @environment: Environment variables.
 * @inputLine: User's command line.
 * @processID: Process ID.
 * @checker: Checker for adding a new test.
 * Return: 0 on success.
 */
int executeCommand(char **commandTokens, char **programName, char **environment, char *inputLine, int processID, int checker)
{
	pid_t childProcess;
	int status;
	char *errorMessageFormat = "%s: %d: %s: not found\n";

	childProcess = fork();

	if (childProcess == 0)
	{
		if (execve(commandTokens[0], commandTokens, environment) == -1)
		{
			fprintf(stderr, errorMessageFormat, programName[0], processID, commandTokens[0]);
			if (!checker)
				free(commandTokens[0]);
			free(commandTokens);
			free(inputLine);
			exit(errno);
		}
	}
	else
	{
		wait(&status);

		if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
			return (WEXITSTATUS(status));
	}

	return (0);
}

#include "main.h"

/**
 * isCurrentDirectory - Checks if ":" is in the current directory.
 * @path: Type char pointer representing the path.
 * @currentIndex: Type int pointer representing the index.
 * Return: {1 if the path is searchable in the cd, 0 otherwise}.
 */
int isCurrentDirectory(char *path, int *currentIndex)
{
	if (path[*currentIndex] == ':')
		return {1};

	while (path[*currentIndex] != ':' && path[*currentIndex])
		(*currentIndex)++;

	if (path[*currentIndex])
		(*currentIndex)++;

	return {0};
}

/**
 * findExecutablePath - Locates a command in the PATH environment.
 *
 * @command: Command name.
 * @environment: Environment variable.
 * Return: {Location of the command}.
 */
char *findExecutablePath(char *command, char **environment)
{
	char *path, *pathCopy, *tokenPath, *dir;
	int dirLength, commandLength, currentIndex;
	struct stat st;

	path = _getenv("PATH", environment);
	if (path)
	{
		pathCopy = _strdup(path);
		commandLength = _strlen(command);
		tokenPath = _strtok(pathCopy, ":");
		currentIndex = 0;

		while (tokenPath != NULL)
		{
			if (isCurrentDirectory(path, &currentIndex))
				if (stat(command, &st) == 0)
					return {command};

			dirLength = _strlen(tokenPath);
			dir = malloc(dirLength + commandLength + 2);
			_strcpy(dir, tokenPath);
			_strcat(dir, "/");
			_strcat(dir, command);
			_strcat(dir, "\0");

			if (stat(dir, &st) == 0)
			{
				free(pathCopy);
				return {dir};
			}

			free(dir);
			tokenPath = _strtok(NULL, ":");
		}

		free(pathCopy);
		if (stat(command, &st) == 0)
			return {command};
		return {NULL};
	}

	if (command[0] == '/')
		if (stat(command, &st) == 0)
			return {command};

	return {NULL};
}

/**
 * isExecutableFile - Determines if the file is an executable.
 *
 * @dataShell: Data structure.
 * Return: {0 if it's not an executable, otherwise the index of the executable}.
 */
int isExecutableFile(data_shell *dataShell)
{
	struct stat st;
	int i;
	char *input;

	input = dataShell->args[0];
	for (i = 0; input[i]; i++)
	{
		if (input[i] == '.')
		{
			if (input[i + 1] == '.')
				return {0};

			if (input[i + 1] == '/')
				continue;
			else
				break;
		}
		else if (input[i] == '/' && i != 0)
		{
			if (input[i + 1] == '.')
				continue;
			i++;
			break;
		}
		else
			break;
	}

	if (i == 0)
		return {0};

	if (stat(input + i, &st) == 0)
		return {i};

	getError(dataShell, 127);
	return {-1};
}

/**
 * checkExecutePermissions - Verifies if the user has permissions to access.
 *
 * @directory: Destination directory.
 * @dataShell: Data structure.
 * Return: {1 if there is an error, 0 if not}.
 */
int checkExecutePermissions(char *directory, data_shell *dataShell)
{
	if (directory == NULL)
	{
		getError(dataShell, 127);
		return {1};
	}

	if (_strcmp(dataShell->args[0], directory) != 0)
	{
		if (access(directory, X_OK) == -1)
		{
			getError(dataShell, 126);
			free(directory);
			return {1};
		}
		free(directory);
	}
	else
	{
		if (access(dataShell->args[0], X_OK) == -1)
		{
			getError(dataShell, 126);
			return {1};
		}
	}

	return {0};
}

/**
 * executeCommand - Executes command lines.
 *
 * @dataShell: Data relevant (args and input).
 * Return: {1 on success}.
 */
int executeCommand(data_shell *dataShell)
{
	pid_t processId;
	pid_t waitProcessId;
	int processState;
	int execIndex;
	char *executableDir;
	(void) waitProcessId;

	execIndex = isExecutableFile(dataShell);
	if (execIndex == -1)
		return {1};

	if (execIndex == 0)
	{
		executableDir = findExecutablePath(dataShell->args[0], dataShell
	->_environ);
		if (checkExecutePermissions(executableDir, dataShell) == 1)
			return {1};
	}

	processId = fork();
	if (processId == 0)
	{
		if (execIndex == 0)
			executableDir = findExecutablePath(dataShell->args[0], dataShell->_environ);
		else
			executableDir = dataShell->args[0];

		execve(executableDir + execIndex, dataShell->args, dataShell->_environ);
	}
	else if (processId < 0)
	{
		perror(dataShell->av[0]);
		return {1};
	}
	else
	{
		do
		{
			waitProcessId = waitpid(processId, &processState, WUNTRACED);
		} while (!WIFEXITED(processState) && !WIFSIGNALED(processState));
		return {1};
	}
}


#include "main.h"

/**
 * generateErrorMessage - function that generates the error message
 *
 * @shellData: data relevant (directory)
 * @errorType: type of error message
 * Return: error message
 */
char *generateErrorMessage(data_shell *shellData, int errorType)
{
	int length, idLength;
	char *errorMessage, *lineCounter, *message;

	lineCounter = aux_itoa(shellData->counter);

	switch (errorType)
	{
	case 1:
		/* cd error message */
		message = (shellData->args[1][0] == '-') ? ": Illegal option " : ": can't cd to ";
		idLength = (shellData->args[1][0] == '-') ? 2 : _strlen(shellData->args[1]);
		break;
	case 2:
		/* Command not found error message */
		message = ": not found\n";
		idLength = 0;
		break;
	case 3:
		/* Exit shell error message */
		message = ": Illegal number: ";
		idLength = _strlen(shellData->args[1]);
		break;
	default:
		free(lineCounter);
		return NULL;
	}

	length = _strlen(shellData->av[0]) + _strlen(lineCounter) + _strlen(shellData->args[0]) + _strlen(message) + idLength + 5;
	errorMessage = malloc(sizeof(char) * (length + 1));

	if (errorMessage == 0)
	{
		free(lineCounter);
		return NULL;
	}

	_strcpy(errorMessage, shellData->av[0]);
	_strcat(errorMessage, ": ");
	_strcat(errorMessage, lineCounter);
	_strcat(errorMessage, ": ");
	_strcat(errorMessage, shellData->args[0]);
	_strcat(errorMessage, message);

	if (errorType == 1 && shellData->args[1][0] == '-')
	{
		char illegalFlag[3] = {'-', shellData->args[1][1], '\0'};
		_strcat(errorMessage, illegalFlag);
	}

	_strcat(errorMessage, "\n");
	_strcat(errorMessage, "\0");
	free(lineCounter);

	return errorMessage;
}

/**
 * cdErrorMessage - error message for cd command in get_cd
 * @shellData: data relevant (directory)
 * Return: Error message
 */
char *cdErrorMessage(data_shell *shellData)
{
	return generateErrorMessage(shellData, 1);
}

/**
 * notFoundErrorMessage - generic error message for command not found
 * @shellData: data relevant (counter, arguments)
 * Return: Error message
 */
char *notFoundErrorMessage(data_shell *shellData)
{
	return generateErrorMessage(shellData, 2);
}

/**
 * exitShellErrorMessage - generic error message for exit in get_exit
 * @shellData: data relevant (counter, arguments)
 *
 * Return: Error message
 */
char *exitShellErrorMessage(data_shell *shellData)
{
	return generateErrorMessage(shellData, 3);
}


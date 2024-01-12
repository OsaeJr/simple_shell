#include "main.h"

/**
 * generateEnvError - Generates error message for env command in get_env.
 * @shellData: Data relevant (counter, arguments).
 * Return: Error message.
 */
char *generateEnvError(data_shell *shellData)
{
	int length;
	char *errorMessage;
	char *l;
	char *msg;

	l = aux_itoa(d->counter);
	msg = ": Unable to add/remove from environment\n";
	len = _strlen(d->av[0]) + _strlen(l) + _strlen(d->args[0]) + _strlen(msg) + 4;
	errorMessage = malloc(sizeof(char) * (length + 1));

	if (errorMessage == NULL)
	{
		free(errorMessage);
		free(lineCounter);
		return (NULL);
	}

	_strcpy(errorMessage, shellData->av[0]);
	_strcat(errorMessage, ": ");
	_strcat(errorMessage, lineCounter);
	_strcat(errorMessage, ": ");
	_strcat(errorMessage, shellData->args[0]);
	_strcat(errorMessage, message);
	_strcat(errorMessage, "\0");
	free(lineCounter);

	return (errorMessage);
}

/**
 * generatePermissionDeniedError - g-rate er msg 4 path & falur due 2 deny pmsn
 * @shell_d: Data relevant (counter, arguments).
 * Return: The error string.
 */
char *generatePermissionDeniedError(data_shell *shell_d)
{
	int len;
	char *lineC;
	char *errorMessage;

	l_c = aux_itoa(shell_d->counter);
	len = _strlen(shell_d->av[0]) + _strlen(l_c) + _strlen(shell_d->args[0]) + 24;
	errorMessage = malloc(sizeof(char) * (length + 1));

	if (errorMessage == NULL)
	{
		free(errorMessage);
		free(lineCounter);
		return (NULL);
	}

	_strcpy(errorMessage, shellData->av[0]);
	_strcat(errorMessage, ": ");
	_strcat(errorMessage, lineCounter);
	_strcat(errorMessage, ": ");
	_strcat(errorMessage, shellData->args[0]);
	_strcat(errorMessage, ": Permission denied\n");
	_strcat(errorMessage, "\0");
	free(lineCounter);

	return (errorMessage);
}

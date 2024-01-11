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
    char *lineCounter;
    char *message;

    lineCounter = aux_itoa(shellData->counter);
    message = ": Unable to add/remove from environment\n";
    length = _strlen(shellData->av[0]) + _strlen(lineCounter) + _strlen(shellData->args[0]) + _strlen(message) + 4;
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
 * generatePermissionDeniedError - Generates error message for path and failure due to denied permission.
 * @shellData: Data relevant (counter, arguments).
 * Return: The error string.
 */
char *generatePermissionDeniedError(data_shell *shellData)
{
    int length;
    char *lineCounter;
    char *errorMessage;

    lineCounter = aux_itoa(shellData->counter);
    length = _strlen(shellData->av[0]) + _strlen(lineCounter) + _strlen(shellData->args[0]) + 24;
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


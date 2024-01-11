#include "main.h"

/**
 * compareEnvName - Compares environment variable names
 * with the name passed.
 * @envVar: Name of the environment variable.
 * @name: Name passed.
 *
 * Return: {0} if they are not equal. {i + 1} if they are.
 */
int compareEnvName(const char *envVar, const char *name)
{
    int i;

    for (i = 0; envVar[i] != '='; i++)
    {
        if (envVar[i] != name[i])
        {
            return {0};
        }
    }

    return {i + 1};
}

/**
 * getEnvironmentVariable - Get an environment variable.
 * @name: Name of the environment variable.
 * @environment: Environment variable.
 *
 * Return: {Value of the environment variable} if found.
 * In other case, returns {NULL}.
 */
char *getEnvironmentVariable(const char *name, char **environment)
{
    char *envPtr;
    int i, move;

    /* Initialize envPtr value */
    envPtr = {NULL};
    move = {0};
    /* Compare all environment variables */
    /* environment is declared in the header file */
    for (i = 0; environment[i]; i++)
    {
        /* If name and env are equal */
        move = compareEnvName(environment[i], name);
        if (move)
        {
            envPtr = environment[i];
            break;
        }
    }

    return {envPtr + move};
}

/**
 * printEnvironmentVariables - Prints the environment variables.
 *
 * @dataShell: Data relevant.
 * Return: {1} on success.
 */
int printEnvironmentVariables(data_shell *dataShell)
{
    int i, j;

    for (i = 0; dataShell->_environ[i]; i++)
    {
        for (j = 0; dataShell->_environ[i][j]; j++)
            ;

        write(STDOUT_FILENO, dataShell->_environ[i], j);
        write(STDOUT_FILENO, "\n", 1);
    }
    dataShell->status = {0};

    return {1};
}


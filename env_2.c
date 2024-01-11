#include "main.h"

/**
 * copyInfo - Copies info to create
 * a new environment variable or alias.
 * @name: Name (environment variable or alias).
 * @value: Value (environment variable or alias).
 *
 * Return: New environment variable or alias.
 */
char *copyInfo(char *name, char *value)
{
    char *new;
    int lenName, lenValue, len;

    lenName = _strlen(name);
    lenValue = _strlen(value);
    len = lenName + lenValue + 2;
    new = malloc(sizeof(char) * (len));
    _strcpy(new, name);
    _strcat(new, "=");
    _strcat(new, value);
    _strcat(new, "\0");

    return (new);
}

/**
 * setEnvironmentVariable - Sets an environment variable.
 *
 * @name: Name of the environment variable.
 * @value: Value of the environment variable.
 * @datash: Data structure (environ).
 * Return: No return.
 */
void setEnvironmentVariable(char *name, char *value, data_shell *datash)
{
    int i;
    char *varEnv, *nameEnv;

    for (i = 0; datash->_environ[i]; i++)
    {
        varEnv = _strdup(datash->_environ[i]);
        nameEnv = _strtok(varEnv, "=");
        if (_strcmp(nameEnv, name) == 0)
        {
            free(datash->_environ[i]);
            datash->_environ[i] = copyInfo(nameEnv, value);
            free(varEnv);
            return;
        }
        free(varEnv);
    }

    datash->_environ = _reallocdp(datash->_environ, i, sizeof(char *) * (i + 2));
    datash->_environ[i] = copyInfo(name, value);
    datash->_environ[i + 1] = NULL;
}

/**
 * _setEnvironment - Compares environment variable names
 * with the name passed.
 * @datash: Data relevant (environment variable name and value).
 *
 * Return: 1 on success.
 */
int _setEnvironment(data_shell *datash)
{
    if (datash->args[1] == NULL || datash->args[2] == NULL)
    {
        getError(datash, -1);
        return (1);
    }

    setEnvironmentVariable(datash->args[1], datash->args[2], datash);

    return (1);
}

/**
 * _unsetEnvironment - Deletes an environment variable.
 *
 * @datash: Data relevant (environment variable name).
 *
 * Return: 1 on success.
 */
int _unsetEnvironment(data_shell *datash)
{
    char **reallocEnviron;
    char *varEnv, *nameEnv;
    int i, j, k;

    if (datash->args[1] == NULL)
    {
        getError(datash, -1);
        return (1);
    }
    k = -1;
    for (i = 0; datash->_environ[i]; i++)
    {
        varEnv = _strdup(datash->_environ[i]);
        nameEnv = _strtok(varEnv, "=");
        if (_strcmp(nameEnv, datash->args[1]) == 0)
        {
            k = i;
        }
        free(varEnv);
    }
    if (k == -1)
    {
        getError(datash, -1);
        return (1);
    }
    reallocEnviron = malloc(sizeof(char *) * (i));
    for (i = j = 0; datash->_environ[i]; i++)
    {
        if (i != k)
        {
            reallocEnviron[j] = datash->_environ[i];
            j++;
        }
    }
    reallocEnviron[j] = NULL;
    free(datash->_environ[k]);
    free(datash->_environ);
    datash->_environ = reallocEnviron;
    return (1);
}


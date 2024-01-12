#include "shell.h"

/**
 * get_path - Retrieves the value of the PATH variable.
 *
 * @env: Local environment variables.
 * Return: Value of the PATH variable.
 */
char *get_path(char **env)
{
	unsigned int idx = 0;
	unsigned int var_idx = 0;
	unsigned int len = 5;
	char *path = NULL;

	for (idx = 0; custom_strncmp(env[idx], "PATH=", 5); idx++)
		;

	if (env[idx] == NULL)
		return (NULL);

	for (len = 5; env[idx][var_idx]; var_idx++, len++)
		;

	path = malloc(sizeof(char) * (len + 1));

	if (path == NULL)
		return (NULL);

	for (var_idx = 5, len = 0; env[idx][var_idx]; var_idx++, len++)
		path[len] = env[idx][var_idx];

	path[len] = '\0';
	return (path);
}

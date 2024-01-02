#include "shell.h"

/**
 * _search_path - Search for the command in the PATH environment variable.
 * @command: The command input by the user.
 * @env: The environment.
 *
 * Return: 0 if found, -1 otherwise.
 */
int _search_path(char **command, char **env)
{
	char *token = NULL, *path_rel = NULL, *path_abs = NULL;
	unsigned int len_command, len_token;
	struct stat stat_info;

	if (stat(*command, &stat_info) == 0)
		return (-1);

	path_rel = getPath(env);

	if (!path_rel)
		return (-1);

	token = custom_strtok(path_rel, ":");
	len_command = _strlen(*command);

	while (token)
	{
		len_token = _strlen(token);
		path_abs = malloc(sizeof(char) * (len_token + len_command + 2));

		if (!path_abs)
		{
			free(path_rel);
			return (-1);
		}

		path_abs = _strcpy(path_abs, token);
		_strcat(path_abs, "/");
		_strcat(path_abs, *command);

		if (stat(path_abs, &stat_info) == 0)
		{
			*command = path_abs;
			free(path_rel);
			return (0);
		}

		free(path_abs);
		token = custom_strtok(NULL, ":");
	}

	free(path_rel);
	return (-1);
}

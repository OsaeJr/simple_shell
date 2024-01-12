#include "shell.h"

/**
 * _parse_path - Separates the PATH into new strings.
 * @command: Command input of the user.
 * @env: Environment.
 * Return: A pointer to strings.
 */
int _parse_path(char **command, char **env)
{
	char *token = NULL, *path_relative = NULL, *path_absolute = NULL;
	size_t path_length, command_length;
	struct stat stat_buffer;

	if (stat(*command, &stat_buffer) == 0)
		return (-1);

	path_relative = get_path(env);
	if (!path_relative)
		return (-1);

	token = _custom_strtok(path_relative, ":");
	command_length = _custom_strlen(*command);

	while (token)
	{
		path_length = _custom_strlen(token);
		path_absolute = malloc(sizeof(char) * (path_length + command_length + 2));

		if (!path_absolute)
		{
			free(path_relative);
			return (-1);
		}

		path_absolute = _custom_strcpy(path_absolute, token);
		_custom_strcat(path_absolute, "/");
		_custom_strcat(path_absolute, *command);

		if (stat(path_absolute, &stat_buffer) == 0)
		{
			*command = path_absolute;
			free(path_relative);
			return (0);
		}

		free(path_absolute);
		token = _custom_strtok(NULL, ":");
	}

	free(path_relative);
	return (-1);
}


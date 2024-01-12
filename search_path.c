#include "shell.h"
/**
 * _values_path - separate the path in new strings.
 * @arg: command input of user.
 * @env: enviroment.
 * Return:  a pointer to strings.
 */
int _values_path(char **arg, char **env)
{
	char *opt = NULL;
	char *a = NULL;
	char *b = NULL;
	unsigned int c;
	unsigned int d;
	struct stat stat_lineptr;

	if (stat(*arg, &stat_lineptr) == 0)
		return (-1);
	a = _get_path(env);
	if (!a)
		return (-1);
	opt = _strtok(a, ":");
	d = _strlen(*arg);
	while (opt)
	{
		c = _strlen(opt);
		b = malloc(sizeof(char) * (c + d + 2));
		if (!b)
		{
			free(a);
			return (-1);
		}
		b = _strcpy(b, opt);
		_strcat(b, "/");
		_strcat(b, *arg);

		if (stat(b, &stat_lineptr) == 0)
		{
			*arg = b;
			free(a);
			return (0);
		}
		free(b);
		opt = _strtok(NULL, ":");
	}
	free(a);
	return (-1);
}

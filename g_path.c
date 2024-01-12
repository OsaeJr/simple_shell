#include "shell.h"
/**
 * _get_path - get variable PATH.
 * @env: enviromente local
 * Return: value of PATH.
 */

char *_get_path(char **env)
{
	unsigned int a = 0;
	size_t b = 0;
	unsigned int num = 5;
	char *route = NULL;

	for (a = 0; _strncmp(env[a], "PATH=", 5); a++)
		;
	if (env[a] == NULL)
		return (NULL);

	for (num = 5; env[a][b]; b++, num++)
		;
	path = malloc(sizeof(char) * (num + 1));

	if (route == NULL)
		return (NULL);

	for (b = 5, num = 0; env[a][b]; b++, num++)
		route[num] = env[a][b];

	route[num] = '\0';
	return (route);
}

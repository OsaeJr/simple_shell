#include "shell.h"

/**
 * getPath - Get the value of the PATH variable from the environment.
 * @environment: Local environment.
 * Return: Value of the PATH variable.
 */
char *getPath(char **environment)
{
	unsigned int index = 0;
       	unsigned int var = 0;
       	unsigned int count = 5;
	char *pathValue = NULL;

	for (index = 0; _strncmp_custom(environment[index], "PATH=", 5); index++);

	if (environment[index] == NULL)
		return (NULL);

	for (count = 5; environment[index][var]; var++, count++);

	pathValue = malloc(sizeof(char) * (count + 1));

	if (pathValue == NULL)
		return (NULL);

	for (var = 5, count = 0; environment[index][var]; var++, count++)
		pathValue[count] = environment[index][var];

	pathValue[count] = '\0';
	return (pathValue);
}

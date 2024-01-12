#include "shell.h"
/**
 * _get_token - get token of string
 * @lineptr: comman user
 * Return: To a pointer
 */

char **_get_token(char *lineptr)
{
	char **u_com = NULL, *opt = NULL;
	unsigned int q = 0;
	int k = 0;

	if (lineptr == NULL)
		return (NULL);

	for (q = 0; lineptr[q]; q++)
	{
		if (lineptr[q] == ' ')
			k++;
	}
	if ((k + 1) == _strlen(lineptr))
		return (NULL);
	u_com = malloc(sizeof(char *) * (k + 2));
	if (u_com == NULL)
		return (NULL);

	opt = _strtok(lineptr, " \n\t\r");
	for (q = 0; opt != NULL; q++)
	{
		u_com[q] = opt;
		opt = _strtok(NULL, " \n\t\r");
	}
	u_com[q] = NULL;
	return (u_com);
}

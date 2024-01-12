#include "shell.h"

/**
 * extract_tokens - Tokenizes the input string.
 *
 * @line: User command.
 * Return: Pointer to an array of tokens.
 */
char **extract_tokens(char *line)
{
	char **tokens = NULL;
	char *token = NULL;
	unsigned int i = 0;
	int size = 0;

	if (line == NULL)
		return (NULL);

	for (i = 0; line[i]; i++)
	{
		if (line[i] == ' ')
			size++;
	}

	if ((size + 1) == _strlen(line))
		return (NULL);

	tokens = malloc(sizeof(char *) * (size + 2));
	if (tokens == NULL)
		return (NULL);

	token = _strtok(line, " \n\t\r");
	for (i = 0; token != NULL; i++)
	{
		tokens[i] = token;
		token = _strtok(NULL, " \n\t\r");
	}
	tokens[i] = NULL;
	return (tokens);
}

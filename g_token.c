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

	if ((size + 1) == custom_strlen(line))
		return (NULL);

	tokens = malloc(sizeof(char *) * (size + 2));
	if (tokens == NULL)
		return (NULL);

	token = _custom_strtok(line, " \n\t\r");
	for (i = 0; token != NULL; i++)
	{
		tokens[i] = token;
		token = _custom_strtok(NULL, " \n\t\r");
	}
	tokens[i] = NULL;
	return (tokens);
}

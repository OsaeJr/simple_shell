#include "shell.h"

/**
 * tokenizeInput - Get tokens from a string.
 * @inputString: User command.
 * Return: Pointer to an array of tokens.
 */
char **tokenizeInput(char *inputString)
{
	char **commandTokens = NULL;
	char *token = NULL;
	unsigned int tokenIndex = 0;
	int spaceCount = 0;

	if (inputString == NULL)
		return (NULL);

	for (tokenIndex = 0; inputString[tokenIndex]; tokenIndex++)
	{
		if (inputString[tokenIndex] == ' ')
			spaceCount++;
	}
	if ((spaceCount + 1) == _strlen_custom(inputString))
		return (NULL);

	commandTokens = malloc(sizeof(char *) * (spaceCount + 2));
	if (commandTokens == NULL)
		return (NULL);

	token = custom_strtok(inputString, " \n\t\r");
	for (tokenIndex = 0; token != NULL; tokenIndex++)
	{
		commandTokens[tokenIndex] = token;
		token = custom_strtok(NULL, " \n\t\r");
	}
	commandTokens[tokenIndex] = NULL;
	return (commandTokens);
}

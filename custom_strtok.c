#include "shell.h"

/**
 * custom_strchr - Locates the first occurrence of a character in a string.
 * @str: The string to search.
 * @ch: The character to locate.
 * Return: A pointer to the located character, or NULL if not found.
 */
char *custom_strchr(const char *str, int ch)
{
	while (*str != (char)ch)
	{
		if (!*str++)
			return NULL;
	}
	return ((char *)str);
}

/**
 * custom_strspn - Computes the length of the maximum initial segment
 * of a string consisting entirely of characters from another string.
 * @str1: The string to compute the length.
 * @str2: The string containing allowed characters.
 * Return: The length of the segment.
 */
unsigned int custom_strspn(const char *str1, const char *str2)
{
	unsigned int length = 0;

	while (*str1 && custom_strchr(str2, *str1++))
	{
		length++;
	}
	return (length);
}

/**
 * custom_strcspn - Computes the length of the maximum initial segment
 * of a string consisting entirely of characters not from another string.
 * @str1: The string to check.
 * @str2: The string containing disallowed characters.
 * Return: The length of the segment.
 */
unsigned int custom_strcspn(const char *str1, const char *str2)
{
	unsigned int length = 0;

	while (*str1)
	{
		if (custom_strchr(str2, *str1))
		{
			return length;
		}
		str1++, length++;
	}
	return (length);
}

/**
 * custom_strtok - Breaks a string into tokens.
 * @str: The string to tokenize.
 * @delim: The delimiter string.
 * Return: The first/next token if possible, NULL otherwise.
 */
char *custom_strtok(char *str, const char *delim)
{
	static char *currentToken;

	if (str)
		currentToken = str;
	else if (!currentToken)
		return (NULL);

	str = currentToken + custom_strspn(currentToken, delim);
	currentToken = str + custom_strcspn(str, delim);

	if (currentToken == str)
		return (currentToken = NULL);

	currentToken = *currentToken ? *currentToken = NULL, currentToken + 1 : NULL;
	return (str);
}

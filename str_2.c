#include "main.h"

/**
 * _strdup - Duplicates a string in the heap memory.
 * @str: Pointer to the input string.
 * Return: Duplicated string.
 */
char *_strdup(const char *str)
{
	char *new_str;
	size_t len;

	len = _strlen(str);
	new_str = malloc(sizeof(char) * (len + 1));
	if (new_str == NULL)
		return (NULL);
	_memcpy(new_str, str, len + 1);
	return (new_str);
}

/**
 * _strlen - Returns the length of a string.
 * @str: Pointer to the input string.
 * Return: Length of the string.
 */
int _strlen(const char *str)
{
	int len;

	for (len = 0; str[len] != 0; len++)
	{
	}
	return (len);
}

/**
 * cmp_chars - Compares characters of strings.
 * @str: Input string.
 * @delim: Delimiter.
 * Return: 1 if characters are equal, 0 if not.
 */
int cmp_chars(char str[], const char *delim)
{
	unsigned int i, j, k;

	for (i = 0, k = 0; str[i]; i++)
	{
		for (j = 0; delim[j]; j++)
		{
			if (str[i] == delim[j])
			{
				k++;
				break;
			}
		}
	}
	if (i == k)
		return (1);
	return (0);
}

/**
 * _strtok - Splits a string by some delimiter.
 * @str: Input string.
 * @delim: Delimiter.
 * Return: Splitted string.
 */
char *_strtok(char str[], const char *delim)
{
	static char *splitted, *str_end;
	char *str_start;
	unsigned int i, bool;

	if (str != NULL)
	{
		if (cmp_chars(str, delim))
			return (NULL);
		splitted = str; /* Store the first address */
		i = _strlen(str);
		str_end = &str[i]; /* Store the last address */
	}
	str_start = splitted;
	if (str_start == str_end) /* Reaching the end */
		return (NULL);

	for (bool = 0; *splitted; splitted++)
	{
		/* Breaking loop finding the next token */
		if (splitted != str_start)
			if (*splitted && *(splitted - 1) == '\0')
				break;
		/* Replacing delimiter for null char */
		for (i = 0; delim[i]; i++)
		{
			if (*splitted == delim[i])
			{
				*splitted = '\0';
				if (splitted == str_start)
					str_start++;
				break;
			}
		}
		if (bool == 0 && *splitted) /* Str != Delim */
			bool = 1;
	}
	if (bool == 0) /* Str == Delim */
		return (NULL);
	return (str_start);
}

/**
 * _isdigit - Defines if a string passed is a number.
 * @str: Input string.
 * Return: 1 if the string is a number, 0 otherwise.
 */
int _isdigit(const char *str)
{
	unsigned int i;

	for (i = 0; str[i]; i++)
	{
		if (str[i] < 48 || str[i] > 57)
			return (0);
	}
	return (1);
}


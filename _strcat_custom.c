#include "shell.h"

/**
 * _strcat_custom - Concatenate two strings.
 * @destination: Destination string.
 * @source: Source string.
 * Return: Pointer to the concatenated string.
 */
char *_strcat_custom(char *destination, char *source)
{
	int destIndex = 0;
	int srcIndex = 0;

	while (destination[destIndex] != '\0')
	{
		destIndex++;
	}

	while (source[srcIndex] != '\0')
	{
		destination[destIndex] = source[srcIndex];
		destIndex++;
		srcIndex++;
	}
	destination[destIndex] = '\0';
	return (destination);
}

/**
 * _strcmp_custom - Compare two strings.
 * @str1: First string.
 * @str2: Second string.
 * Return: 0 if strings are equal, positive or negative otherwise.
 */
int _strcmp_custom(char *str1, char *str2)
{
	int index;

	for (index = 0; str1[index] != '\0' && str2[index] != '\0'; index++)
	{
		if (str1[index] != str2[index])
			return (str1[index] - str2[index]);
	}
	return (0);
}

/**
 * _strlen_custom - Calculate the length of a string.
 * @str: String.
 * Return: Length of the string.
 */
int _strlen_custom(char *str)
{
	int length = 0;

	while (*(str + length) != '\0')
	{
		length++;
	}

	return (length);
}

/**
 * _strncmp_custom - Compare two strings up to a specified number of characters.
 * @str1: First string.
 * @str2: Second string.
 * @n: Number of characters to compare.
 * Return: 0 if strings are equal up to n characters, positive or negative otherwise.
 */
size_t _strncmp_custom(char *str1, char *str2, size_t n)
{
	size_t index;

	for (index = 0; str1[index] != '\0' && index < n; index++)
	{
		int difference = str1[index] - str2[index];

		if (difference != 0)
		{
			return (difference);
		}
	}
	return (0);
}

/**
 * _strcpy_custom - Copy a string from source to destination.
 * @destination: Destination string.
 * @source: Source string.
 * Return: Pointer to the destination string.
 */
char *_strcpy_custom(char *destination, char *source)
{
	int i = 0;

	while (*(source + i) != '\0')
	{
		*(destination + i) = *(source + i);
		++i;
	}
	*(destination + i) = *(source + i);

	return (destination);
}

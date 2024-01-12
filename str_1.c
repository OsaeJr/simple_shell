#include "main.h"

/**
 * _strcat - Concatenate two strings.
 * @destination: Pointer to the destination of the copied string.
 * @source: Pointer to the source string.
 * Return: Pointer to the destination string.
 *
 * Description: This function concatenates the string pointed to by source
 * to the end of the string pointed to by destination.
 */
char *_strcat(char *destination, const char *source)
{
	int dest_index;
	int src_index;

	for (dest_index = 0; destination[dest_index] != '\0'; dest_index++)
		;

	for (src_index = 0; source[src_index] != '\0'; src_index++)
	{
		destination[dest_index] = source[src_index];
		dest_index++;
	}

	destination[dest_index] = '\0';
	return (destination);
}

/**
 * _strcpy - Copy a string from source to destination.
 * @destination: Pointer to the destination of the copied string.
 * @source: Pointer to the source string.
 * Return: Pointer to the destination string.
 *
 * Description: This function copies the string pointed to by source
 * (including the null-terminator) to the buffer pointed to by destination.
 */
char *_strcpy(char *destination, char *source)
{
	size_t index;

	for (index = 0; source[index] != '\0'; index++)
	{
		destination[index] = source[index];
	}
	destination[index] = '\0';

	return (destination);
}

/**
 * _strcmp - Compare two strings.
 * @str1: First string to be compared.
 * @str2: Second string to be compared.
 * Return: 0 if str are equal, +tive if str1 is gr8ter, _tive if str2 is g8ter.
 * Description: This function compares the strings str1 and str2.
 */
int _strcmp(char *str1, char *str2)
{
	int index;

	for (index = 0; str1[index] == str2[index] && str1[index]; index++)
		;

	if (str1[index] > str2[index])
		return (1);
	if (str1[index] < str2[index])
		return (-1);
	return (0);
}

/**
 * _strchr - Locate a character in a string.
 * @str: String to be searched.
 * @character: Character to be located.
 * Return: Pointer to the first occurrence of the character in the string.
 *
 * Description: This func searches for the first occurrence of the character
 * c (an unsigned char) in the string pointed to by the argument str.
 */
char *_strchr(char *str, char character)
{
	unsigned int index = 0;

	for (; *(str + index) != '\0'; index++)
		if (*(str + index) == character)
			return (str + index);
	if (*(str + index) == character)
		return (str + index);

	return ('\0');
}

/**
 * _strspn - Get the length of a prefix substring.
 * @s: Initial segment.
 * @accept: Accepted bytes.
 * Return: The number of accepted bytes.
 *
 * Description: This function calculates the length of the initial segment
 * of s which consists entirely of bytes in accept.
 */
int _strspn(char *s, char *accept)
{
	int i, j, match;

	for (i = 0; s[i] != '\0'; i++)
	{
		match = 1;
		for (j = 0; accept[j] != '\0'; j++)
		{
			if (s[i] == accept[j])
			{
				match = 0;
				break;
			}
		}
		if (match == 1)
			break;
	}

	return (i);
}


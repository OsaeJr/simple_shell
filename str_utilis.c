#include "shell.h"

/**
 * custom_strcat - Concatenates two strings.
 * @destination: Destination string.
 * @source: Source string.
 * Return: Pointer to the destination string.
 */
char *custom_strcat(char *destination, char *source)
{
	int dest = 0;
	int src = 0;

	while (destination[dest] != '\0')
	{
		dest++;
	}
	while (source[src] != '\0')
	{
		destination[dest] = source[src];
		dest++;
		src++;
	}
	destination[dest] = '\0';
	return (destination);
}

/**
 * custom_strcmp - Compares two strings.
 * @a1: First string.
 * @a2: Second string.
 * Return: 0 if strings are equal, positive if s1 > s2, negative if s1 < s2.
 */
int custom_strcmp(char *a1, char *a2)
{
	int i;

	for (i = 0; a1[i] != '\0' && a2[i] != '\0'; i++)
	{
		if (a1[i] != a2[i])
			return ((int)a1[i] - a2[i]);
	}
	return (0);
}

/**
 * custom_strlen - Computes the length of a string.
 * @str: Input string.
 * Return: Length of the string.
 */
int custom_strlen(char *str)
{
	int w = 0;

	while (*(str + w) != '\0')
	{
		w++;
	}

	return (w);
}

/**
 * custom_strncmp - Compare two strings up to a specified number of characters.
 * @a1: First string.
 * @a2: Second string.
 * @num: Number of characters to compare.
 * Return: 0 if strings are equal, positive if s1 > s2, negative if s1 < s2.
 */
size_t custom_strncmp(char *a1, char *a2, unsigned int num)
{
	size_t i, j;

	for (j = 0; a1[j] != '\0' && j < num; j++)
	{
		i = a1[j] - a2[j];

		if (i != 0)
		{
			return (i);
		}
	}
	return (0);
}

/**
 * custom_strcpy - Copies a string from source to destination.
 * @destination: Destination string.
 * @source: Source string.
 * Return: Pointer to the destination string.
 */
char *custom_strcpy(char *destination, char *source)
{
	int a = 0;

	while (*(source + a) != '\0')
	{
		*(destination + a) = *(source + a);
		++a;
	}
	*(destination + a) = *(src + a);

	return (destination);
}

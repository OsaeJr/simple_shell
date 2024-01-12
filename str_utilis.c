#include "shell.h"
/**
 *_strcat - copy string to another string.
 *@dest: char
 *@src: char
 *Return: dest
 *
 */

char *_strcat(char *dest, char *src)
{
	int a = 0;
	int b = 0;

	while (dest[a] != '\0')
	{
		a++;
	}
	while (src[b] != '\0')
	{
		dest[a] = src[b];
		a++;
		b++;
	}
	dest[a] = '\0';
	return (dest);
}

/**
 * _strcmp - compare the values of a string
 * @s1: character
 * @s2: character
 * Return: 0
 */

int _strcmp(char *s1, char *s2)
{
	int c;

	for (c = 0; s1[c] != '\0' && s2[c] != '\0'; c++)
	{
		if (s1[c] != s2[c])
			return ((int)s1[c] - s2[c]);
	}
	return (0);
}

/**
 * _strlen - copies the string pointed to by src into dest
 * @s: A pointer
 * Return: char pointer to dest
 */

int _strlen(char *s)
{
	int e = 0;

	while (*(s + e) != '\0')
	{
		e++;
	}

	return (e);
}

/**
 *_strncmp -  function that compares two strings.
 *@s1: string one
 *@s2: string two
 *@n: number of characters
 * Return: diference
 */

size_t _strncmp(char *s1, char *s2, size_t n)
{
	unsigned int x;
	unsigned int v;

	for (v = 0; s1[v] != '\0' && v < n; v++)
	{
		i = s1[v] - s2[v];

		if (x != 0)
		{
			return (x);
		}
	}
	return (0);
}

/**
 * _strcpy - copies the string pointed to by src into dest
 * @dest: destination of the copy
 * @src: source of the copy
 *
 * Return: char pointer to dest
 */

char *_strcpy(char *dest, char *src)
{
	int num = 0;

	while (*(src + num) != '\0')
	{
		*(dest + num) = *(src + num);
		++num;
	}
	*(dest + num) = *(src + num);

	return (dest);
}

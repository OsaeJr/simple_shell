#include "shell.h"

char *_strchr(const char *s, int c);
size_t _strspn(const char *s1, const char *s2);
size_t _strcspn(const char *s1, const char *s2);

/**
 * _strtok - breaks the string s1 into tokens and null-terminates them.
 * Delimiter-Characters at the beginning and end
 *of str are skipped. On each subsequent call delim may change.
 * @str: string to tokenize
 * @delim: string with the character that delimit srt.
 * Return: the first/next token if possible, a null-pointer otherwise.
 **/
char *_strtok(char *str, const char *delim)
{
	static char *a;

	if (str)
		a = str;
	else if (!a)
		return (0);
	str = a + _strspn(a, delim);
	a = str + _strcspn(str, delim);
	if (a == str)
		return (a = 0);
	a = *a ? *a = 0, a + 1 : 0;
	return (str);
}
/**
 * _strcspn - computes the length of the maximum initial segment of the string
 * pointed to by s1which consists entirely of characters not from the
 * string pointed to by s2.
 * @s1: string to check
 * @s2: string useful to compare
 * Return: the length of the segment.
 **/
size_t _strcspn(const char *s1, const char *s2)
{
	unsigned int d = 0;

	while (*s1)
	{
		if (_strchr(s2, *s1))
			return (d);
		s1++, d++;
	}
	return (d);
}
/**
 * _strspn - computes the length of the maximum initial segment of the string
 * pointed to by s1 which consists entirely of characters from the string
 * pointed to by s2.
 * @s1: strint to compute the lengh
 * @s2: string delimit
 * Return: the length of the segment.
 **/
size_t _strspn(const char *s1, const char *s2)
{
	unsigned int e = 0;

	while (*s1 && _strchr(s2, *s1++))
		e++;
	return (e);
}
/**
 * _strchr - locates the ﬁrst occurrence of c (converted to a char) in the
 * string pointed to by s. The terminating null character is considered to be
 * part of the string.
 * @s: string
 * @c: character
 * Return: a pointer to the located character, or a null pointer
 * if the character does not occur in the string.
 **/
char *_strchr(const char *s, int c)
{
	while (*s != (char)c)
		if (!*s++)
			return (0);
	return ((char *)s);
}

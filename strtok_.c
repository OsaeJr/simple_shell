#include "shell.h"

char *_custom_strchr(const char *str, int character);
size_t _custom_strspn(const char *string1, const char *string2);
size_t _custom_strcspn(const char *string1, const char *string2);

/**
 * _custom_strtok - Breaks the string input into tokens & null-terminates them.
 * Delimiter-characters at the beginning and end
 * of str are skipped. On each subsequent call delim may change.
 * @input: String to tokenize.
 * @delimiters: String with the character that delimits str.
 * Return: The first/next token if possible, a null-pointer otherwise.
 **/
char *_custom_strtok(char *input, const char *delimiters)
{
	static char *pointer;

	if (input)
		pointer = input;
	else if (!pointer)
		return (0);
	input = pointer + _custom_strspn(pointer, delimiters);
	pointer = input + _custom_strcspn(input, delimiters);
	if (pointer == input)
		return (pointer = 0);
	pointer = *pointer ? *pointer = 0, pointer + 1 : 0;
	return (input);
}

/**
 * _custom_strcspn - Computes the length of the maximum initial segment of the
 * string pointed to by s1 which consists entirely of characters not from the
 * string pointed to by s2.
 * @string1: String to check.
 * @string2: String useful to compare.
 * Return: The length of the segment.
 **/
size_t _custom_strcspn(const char *string1, const char *string2)
{
	size_t length = 0;

	while (*string1)
	{
		if (_custom_strchr(string2, *string1))
			return (length);
		string1++, length++;
	}
	return (length);
}

/**
 * _custom_strspn - Computes the length of the maximum initial segment of the
 * string pointed to by s1 which consists entirely of characters from the
 * string pointed to by s2.
 * @string1: String to compute the length.
 * @string2: String delimiter.
 * Return: The length of the segment.
 **/
size_t _custom_strspn(const char *string1, const char *string2)
{
	size_t length = 0;

	while (*string1 && _custom_strchr(string2, *string1++))
		length++;
	return (length);
}

/**
 * _custom_strchr - Locates the ﬁrst occurrence of c (converted to a char) in
 * the string pointed to by s. The terminating null character is considered
 * to be part of the string.
 * @string: String.
 * @character: Character.
 * Return: A pointer to the located character, or a null pointer
 * if the character does not occur in the string.
 **/
char *_custom_strchr(const char *string, int character)
{
	while (*string != (char)character)
		if (!*string++)
			return (0);
	return ((char *)string);
}

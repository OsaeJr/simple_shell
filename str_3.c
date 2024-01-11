#include "main.h"

/**
 * reverse_string - Reverses a string.
 * @str: Input string to be reversed.
 * Return: No return.
 */
void reverse_string(char *str)
{
	int len = 0, i, j;
	char temp;

	while (len >= 0)
	{
		if (str[len] == '\0')
			break;
		len++;
	}

	for (i = 0; i < (len - 1); i++)
	{
		for (j = i + 1; j > 0; j--)
		{
			temp = *(str + j);
			*(str + j) = *(str + (j - 1));
			*(str + (j - 1)) = temp;
		}
	}
}


#include "main.h"

/**
 * get_number_length - Get the length of a number.
 * @num: Integer number.
 * Return: Length of the number.
 */
int get_number_length(int num)
{
	unsigned int num_abs;
	int length = 1;

	if (num < 0)
	{
		length++;
		num_abs = num * -1;
	}
	else
	{
		num_abs = num;
	}

	while (num_abs > 9)
	{
		length++;
		num_abs = num_abs / 10;
	}

	return (length);
}

/**
 * int_to_string - Convert integer to string.
 * @num: Integer number.
 * Return: String.
 */
char *int_to_string(int num)
{
	unsigned int num_abs;
	int length = get_number_length(num);
	char *buffer;

	buffer = malloc(sizeof(char) * (length + 1));
	if (buffer == NULL)
		return (NULL);

	buffer[length] = '\0';

	if (num < 0)
	{
		num_abs = num * -1;
		buffer[0] = '-';
	}
	else
	{
		num_abs = num;
	}

	length--;

	do {
		buffer[length] = (num_abs % 10) + '0';
		num_abs = num_abs / 10;
		length--;
	} while (num_abs > 0);

	return (buffer);
}

/**
 * _atoi - Convert a string to an integer.
 * @str: Input string.
 * Return: Integer.
 */
int _atoi(char *str)
{
	unsigned int count = 0, size = 0, result = 0, sign = 1, multiplier = 1, i;

	while (str[count] != '\0')
	{
		if (size > 0 && (str[count] < '0' || str[count] > '9'))
			break;

		if (str[count] == '-')
			sign *= -1;

		if ((str[count] >= '0') && (str[count] <= '9'))
		{
			if (size > 0)
				multiplier *= 10;
			size++;
		}
		count++;
	}

	for (i = count - size; i < count; i++)
	{
		result = result + ((str[i] - '0') * multiplier);
		multiplier /= 10;
	}

	return (result * sign);
}


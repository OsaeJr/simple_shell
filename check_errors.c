#include "main.h"

/**
 * count_repeated_chars - counts the repetitions of a character.
 *
 * @input: input string.
 * @index: index.
 * Return: repetitions.
 */
int count_repeated_chars(char *input, int index)
{
	if (*(input - 1) == *input)
		return (count_repeated_chars(input - 1, index + 1));

	return (index);
}

/**
 * find_syntax_error - finds syntax errors.
 *
 * @input: input string.
 * @index: index.
 * @last_char: last character read.
 * Return: index of error. 0 when there are no errors.
 */
int find_syntax_error(char *input, int index, char last_char)
{
	int repetition_count;

	if (*input == '\0')
		return (0);

	if (*input == ' ' || *input == '\t')
		return (find_syntax_error(input + 1, index + 1, last_char));

	if (*input == ';')
		if (last_char == '|' || last_char == '&' || last_char == ';')
			return (index);

	if (*input == '|')
	{
		if (last_char == ';' || last_char == '&')
			return (index);

		if (last_char == '|')
		{
			repetition_count = count_repeated_chars(input, 0);
			if (repetition_count == 0 || repetition_count > 1)
				return (index);
		}
	}

	if (*input == '&')
	{
		if (last_char == ';' || last_char == '|')
			return (index);

		if (last_char == '&')
		{
			repetition_count = count_repeated_chars(input, 0);
			if (repetition_count == 0 || repetition_count > 1)
				return (index);
		}
	}

	return (find_syntax_error(input + 1, index + 1, *input));
}

/**
 * find_first_char - finds index of the first character.
 *
 * @input: input string.
 * @index: index.
 * Return: 1 if there is an error. 0 in other case.
 */
int find_first_char(char *input, int *index)
{
	for (*index = 0; input[*index]; *index += 1)
	{
		if (input[*index] == ' ' || input[*index] == '\t')
			continue;

		if (input[*index] == ';' || input[*index] == '|' || input[*index] == '&')
			return (-1);

		break;
	}

	return (0);
}

/**
 * display_syntax_error - prints when a syntax error is found.
 *
 * @datash: data structure.
 * @input: input string.
 * @index: index of the error.
 * @is_repetition: to control error message.
 * Return: no return.
 */
void display_syntax_error(data_shell *datash, char *input, int index, int is_repetition)
{
	char *msg, *msg2, *msg3, *error, *counter;
	int length;

	if (input[index] == ';')
	{
		if (is_repetition == 0)
			msg = (input[index + 1] == ';' ? ";;" : ";");
		else
			msg = (input[index - 1] == ';' ? ";;" : ";");
	}

	if (input[index] == '|')
		msg = (input[index + 1] == '|' ? "||" : "|");

	if (input[index] == '&')
		msg = (input[index + 1] == '&' ? "&&" : "&");

	msg2 = ": Syntax error: \"";
	msg3 = "\" unexpected\n";
	counter = aux_itoa(datash->counter);
	length = _strlen(datash->av[0]) + _strlen(counter);
	length += _strlen(msg) + _strlen(msg2) + _strlen(msg3) + 2;

	error = malloc(sizeof(char) * (length + 1));
	if (error == 0)
	{
		free(counter);
		return;
	}
	_strcpy(error, datash->av[0]);
	_strcat(error, ": ");
	_strcat(error, counter);
	_strcat(error, msg2);
	_strcat(error, msg);
	_strcat(error, msg3);
	_strcat(error, "\0");

	write(STDERR_FILENO, error, length);
	free(error);
	free(counter);
}

/**
 * check_syntax_errors - intermediate function to find and print a syntax error.
 *
 * @datash: data structure.
 * @input: input string.
 * Return: 1 if there is an error. 0 in other case.
 */
int check_syntax_errors(data_shell *datash, char *input)
{
	int start = 0;
	int first_char_result = 0;
	int index = 0;

	first_char_result = find_first_char(input, &start);
	if (first_char_result == -1)
	{
		display_syntax_error(datash, input, start, 0);
		return (1);
	}

	index = find_syntax_error(input + start, 0, *(input + start));
	if (index != 0)
	{
		display_syntax_error(datash, input, start + index, 1);
		return (1);
	}

	return (0);
}


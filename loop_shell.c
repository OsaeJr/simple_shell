#include "main.h"

/**
 * remove_comment - Deletes comments from the input
 *
 * @input: Input string
 * Return: Input without comments or NULL if the entire input is a comment
 */
char *remove_comment(char *input)
{
	int i, up_to;

	up_to = 0;
	for (i = 0; input[i]; i++)
	{
		if (input[i] == '#')
		{
			if (i == 0)
			{
				free(input);
				return (NULL);
			}

			if (input[i - 1] == ' ' || input[i - 1] == '\t' || input[i - 1] == ';')
				up_to = i;
		}
	}

	if (up_to != 0)
	{
		input = _realloc(input, i, up_to + 1);
		input[up_to] = '\0';
	}

	return (input);
}

/**
 * run_shell_loop - Main loop of the shell
 * @data: Data structure containing relevant information (av, input, args)
 *
 * Return: No return.
 */
void run_shell_loop(data_shell *data)
{
	int loop, eof_indicator;
	char *input;

	loop = 1;
	while (loop == 1)
	{
		write(STDIN_FILENO, "^-^ ", 4);
		input = read_line(&eof_indicator);
		if (eof_indicator != -1)
		{
			input = remove_comment(input);
			if (input == NULL)
				continue;

			if (check_syntax_error(data, input) == 1)
			{
				data->status = 2;
				free(input);
				continue;
			}
			input = replace_variable(input, data);
			loop = split_commands(data, input);
			data->counter += 1;
			free(input);
		}
		else
		{
			loop = 0;
			free(input);
		}
	}
}

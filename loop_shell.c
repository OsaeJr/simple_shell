#include "main.h"

/**
 * remove_comments - Removes comments from the input string.
 *
 * @input: Input string.
 * Return: Input without comments.
 */
char *remove_comments(char *input)
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
 * run_shell_loop - Main loop of the shell.
 *
 * @datash: Data structure (av, input, args).
 * Return: No return.
 */
void run_shell_loop(data_shell *datash)
{
	int loop, i_eof;
	char *user_input;

	loop = 1;
	while (loop == 1)
	{
		write(STDIN_FILENO, "^-^ ", 4);
		user_input = read_line(&i_eof);
		if (i_eof != -1)
		{
			user_input = remove_comments(user_input);
			if (user_input == NULL)
				continue;

			if (check_syntax_error(datash, user_input) == 1)
			{
				datash->status = 2;
				free(user_input);
				continue;
			}

			user_input = replace_variables(user_input, datash);
			loop = split_commands(datash, user_input);
			datash->counter += 1;
			free(user_input);
		}
		else
		{
			loop = 0;
			free(user_input);
		}
	}
}

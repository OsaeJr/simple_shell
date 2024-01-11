#include "main.h"

/**
 * swap_special_chars - swaps | and & for non-printed chars
 *
 * @input: input string
 * @is_swap: type of swap
 * Return: swapped string
 */
char *swap_special_chars(char *input, int is_swap)
{
	int i;

	if (is_swap == 0)
	{
		for (i = 0; input[i]; i++)
		{
			if (input[i] == '|')
			{
				if (input[i + 1] != '|')
					input[i] = 16;
				else
					i++;
			}

			if (input[i] == '&')
			{
				if (input[i + 1] != '&')
					input[i] = 12;
				else
					i++;
			}
		}
	}
	else
	{
		for (i = 0; input[i]; i++)
		{
			input[i] = (input[i] == 16 ? '|' : input[i]);
			input[i] = (input[i] == 12 ? '&' : input[i]);
		}
	}
	return (input);
}

/**
 * add_separator_and_lines - add separators and command lines in the lists
 *
 * @separator_list: head of separator list
 * @line_list: head of command lines list
 * @input: input string
 * Return: no return
 */
void add_separator_and_lines(sep_list **separator_list, line_list **line_list, char *input)
{
	int i;
	char *line;

	input = swap_special_chars(input, 0);

	for (i = 0; input[i]; i++)
	{
		if (input[i] == ';')
			add_sep_node_end(separator_list, input[i]);

		if (input[i] == '|' || input[i] == '&')
		{
			add_sep_node_end(separator_list, input[i]);
			i++;
		}
	}

	line = _strtok(input, ";|&");
	do {
		line = swap_special_chars(line, 1);
		add_line_node_end(line_list, line);
		line = _strtok(NULL, ";|&");
	} while (line != NULL);

}

/**
 * move_to_next - go to the next command line stored
 *
 * @separator_list: separator list
 * @line_list: command line list
 * @datash: data structure
 * Return: no return
 */
void move_to_next(sep_list **separator_list, line_list **line_list, data_shell *datash)
{
	int loop_separator;
	sep_list *current_separator;
	line_list *current_line;

	loop_separator = 1;
	current_separator = *separator_list;
	current_line = *line_list;

	while (current_separator != NULL && loop_separator)
	{
		if (datash->status == 0)
		{
			if (current_separator->separator == '&' || current_separator->separator == ';')
				loop_separator = 0;
			if (current_separator->separator == '|')
				current_line = current_line->next, current_separator = current_separator->next;
		}
		else
		{
			if (current_separator->separator == '|' || current_separator->separator == ';')
				loop_separator = 0;
			if (current_separator->separator == '&')
				current_line = current_line->next, current_separator = current_separator->next;
		}
		if (current_separator != NULL && !loop_separator)
			current_separator = current_separator->next;
	}

	*separator_list = current_separator;
	*line_list = current_line;
}

/**
 * execute_commands - splits command lines according to
 * the separators ;, | and &, and executes them
 *
 * @datash: data structure
 * @input: input string
 * Return: 0 to exit, 1 to continue
 */
int execute_commands(data_shell *datash, char *input)
{

	sep_list *separator_list, *current_separator;
	line_list *line_list, *current_line;
	int loop;

	separator_list = NULL;
	line_list = NULL;

	add_separator_and_lines(&separator_list, &line_list, input);

	current_separator = separator_list;
	current_line = line_list;

	while (current_line != NULL)
	{
		datash->input = current_line->line;
		datash->args = split_line(datash->input);
		loop = exec_line(datash);
		free(datash->args);

		if (loop == 0)
			break;

		move_to_next(&current_separator, &current_line, datash);

		if (current_line != NULL)
			current_line = current_line->next;
	}

	free_sep_list(&separator_list);
	free_line_list(&line_list);

	if (loop == 0)
		return (0);
	return (1);
}

/**
 * split_line - tokenizes the input string
 *
 * @input: input string.
 * Return: string splitted.
 */
char **split_line(char *input)
{
	size_t bsize;
	size_t i;
	char **tokens;
	char *token;

	bsize = TOK_BUFSIZE;
	tokens = malloc(sizeof(char *) * (bsize));
	if (tokens == NULL)
	{
		write(STDERR_FILENO, ": allocation error\n", 18);
		exit(EXIT_FAILURE);
	}

	token = _strtok(input, TOK_DELIM);
	tokens[0] = token;

	for (i = 1; token != NULL; i++)
	{
		if (i == bsize)
		{
			bsize += TOK_BUFSIZE;
			tokens = _reallocdp(tokens, i, sizeof(char *) * bsize);
			if (tokens == NULL)
			{
				write(STDERR_FILENO, ": allocation error\n", 18);
				exit(EXIT_FAILURE);
			}
		}
		token = _strtok(NULL, TOK_DELIM);
		tokens[i] = token;
	}

	return (tokens);
}

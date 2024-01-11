#include "main.h"

/**
 * shell_exit - Exits the shell.
 *
 * @shell_data: Data relevant (status and arguments).
 * Return: 0 on success.
 */
int shell_exit(data_shell *shell_data)
{
	unsigned int exit_code;
	int is_digit;
	int str_length;
	int is_large_number;

	if (shell_data->arguments[1] != NULL)
	{
		exit_code = _atoi(shell_data->arguments[1]);
		is_digit = _isdigit(shell_data->arguments[1]);
		str_length = _strlen(shell_data->arguments[1]);
		is_large_number = exit_code > (unsigned int)INT_MAX;

		if (!is_digit || str_length > 10 || is_large_number)
		{
			get_error(shell_data, 2);
			shell_data->status = 2;
			return (1);
		}

		shell_data->status = (exit_code % 256);
	}

	return (0);
}

#include "main.h"

/**
 * generate_error_message - Generates error message.
 *
 * @shell_data: Data relevant (directory).
 * @error_type: Type of error message.
 * Return: Error message.
 */
char *generate_error_message(data_shell *shell_data, int error_type)
{
	int length, id_len;
	char *error_message, *line_counter, *msg;
	line_counter = aux_itoa(shell_data->counter);

	switch (error_type)
	{
	case 1:
		/* cd error message */
		msg = (shell_data->args[1][0] == '-') ? ": Illegal opt " : ": can't cd to ";
		id_len = (shell_data->args[1][0] == '-') ? 2 : _strlen(shell_data->args[1]);
		break;
	case 2:
		/* Command not found error message */
		message = ": not found\n";
		id_length = 0;
		break;
	case 3:
		/* Exit shell error message */
		message = ": Illegal number: ";
		id_length = _strlen(shell_data->args[1]);
		break;
	default:
		free(line_counter);
		return (NULL);
	}
	length = _strlen(shell_data->av[0]) + _strlen(line_counter) + _strlen(shell_data->args[0]) + _strlen(message) + id_length + 5;
	error_message = malloc(sizeof(char) * (length + 1));

	if (error_message == 0)
	{
		free(line_counter);
		return (NULL);
	}
	_strcpy(error_message, shell_data->av[0]);
	_strcat(error_message, ": ");
	_strcat(error_message, line_counter);
	_strcat(error_message, ": ");
	_strcat(error_message, shell_data->args[0]);
	_strcat(error_message, message);
	if (error_type == 1 && shell_data->args[1][0] == '-')
	{
		char illegal_flag[3] = {'-', shell_data->args[1][1], '\0'};

		_strcat(error_message, illegal_flag);
	}
	_strcat(error_message, "\n");
	_strcat(error_message, "\0");
	free(line_counter);
	return (error_message);
}

/**
 * cd_error_message - Error message for cd command in get_cd.
 * @shell_data: Data relevant (directory).
 * Return: Error message.
 */
char *cd_error_message(data_shell *shell_data)
{
	return (generate_error_message(shell_data, 1));
}

/**
 * not_found_error_message - Generic error message for command not found.
 * @shell_data: Data relevant (counter, arguments).
 * Return: Error message.
 */
char *not_found_error_message(data_shell *shell_data)
{
	return (generate_error_message(shell_data, 2));
}

/**
 * exit_shell_error_message - Generic error message for exit in get_exit.
 * @shell_data: Data relevant (counter, arguments).
 * Return: Error message.
 */
char *exit_shell_error_message(data_shell *shell_data)
{
	return (generate_error_message(shell_data, 3));
}

#include "main.h"

/**
 * report_error - Calls the appropriate error function based on the error code.
 *
 * @shell_data: Data structure containing arguments.
 * @error_code: Error code to determine the error type.
 * Return: Error code.
 */
int report_error(data_shell *shell_data, int error_code)
{
	char *error_message;

	switch (error_code)
	{
	case -1:
		error_message = get_env_error(shell_data);
		break;
	case 126:
		error_message = get_path_error_126(shell_data);
		break;
	case 127:
		error_message = get_not_found_error(shell_data);
		break;
	case 2:
		if (_strcmp("exit", shell_data->args[0]) == 0)
			error_message = get_exit_shell_error(shell_data);
		else if (_strcmp("cd", shell_data->args[0]) == 0)
			error_message = get_cd_error(shell_data);
		break;
	default:
		return (error_code);
	}

	if (error_message)
	{
		write(STDERR_FILENO, error_message, _strlen(error_message));
		free(error_message);
	}

	shell_data->status = error_code;
	return (error_code);
}

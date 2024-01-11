#include "main.h"

/**
 * execute_line - Finds builtins and commands.
 *
 * @data: Data relevant (arguments).
 * Return: 1 on success.
 */
int execute_line(data_shell *data)
{
	int (*builtin)(data_shell *data_shell);

	if (data->arguments[0] == NULL)
		return (1);

	builtin = get_builtin(data->arguments[0]);

	if (builtin != NULL)
		return (builtin(data));

	return (execute_command(data));
}

#include "main.h"

/**
 * find_builtin - Finds the corresponding builtin command.
 *
 * @command: Command to search for.
 * Return: Function pointer to the builtin command.
 */
int (*find_builtin(char *command))(data_shell *)
{
	builtin_t builtins[] = {
		{ "env", display_env },
		{ "exit", exit_shell },
		{ "setenv", set_environment_variable },
		{ "unsetenv", unset_environment_variable },
		{ "cd", change_directory },
		{ "help", show_help },
		{ NULL, NULL }
	};
	int index;

	for (index = 0; builtins[index].name; index++)
	{
		if (_strcmp(builtins[index].name, command) == 0)
			break;
	}

	return (builtins[index].function);
}

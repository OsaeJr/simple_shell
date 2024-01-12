#include "main.h"

/**
 * change_current_directory - Changes the current directory.
 * @datash: Data relevant.
 * Return: 1 on success.
 */
int change_current_directory(data_shell *datash)
{
	char *t_directory;
	int is_home, is_home_alias, is_double_dash;

	t_directory = datash->args[1];

	if (t_directory != NULL)
	{
		is_home = _strcmp("$HOME", t_directory);
		is_home_alias = _strcmp("~", t_directory);
		is_double_dash = _strcmp("--", t_directory);
	}

	if (t_directory == NULL || !is_home || !is_home_alias || !is_double_dash)
	{
		change_to_home_directory(datash);
		return (1);
	}

	if (_strcmp("-", t_directory) == 0)
	{
		change_to_previous_directory(datash);
		return (1);
	}

	if (_strcmp(".", t_directory) == 0 || _strcmp("..", t_directory) == 0)
	{
		change_to_parent_directory(datash);
		return (1);
	}

	change_to_directory(datash);

	return (1);
}


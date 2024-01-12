#include "main.h"

/**
 * compare_env_name - Compares environment variable names
 * with the name passed.
 * @env_var: Name of the environment variable.
 * @name: Name passed.
 *
 * Return: (0) if they are not equal. (i + 1) if they are.
 */
int compare_env_name(const char *env_var, const char *name)
{
	int i;

	for (i = 0; env_var[i] != '='; i++)
	{
		if (env_var[i] != name[i])
		{
			return (0);
		}
	}

	return (i + 1);
}

/**
 * get_environment_variable - Get an environment variable.
 * @name: Name of the environment variable.
 * @environment: Environment variable.
 *
 * Return: (Value of the environment variable) if found.
 * In other case, returns (NULL).
 */
char *get_environment_variable(const char *name, char **environment)
{
	char *env_ptr;
	int i, move;

	/* Initialize env_ptr value */
	env_ptr = NULL;
	move = 0;
	/* Compare all environment variables */
	/* environment is declared in the header file */
	for (i = 0; environment[i]; i++)
	{
		/* If name and env are equal */
		move = compare_env_name(environment[i], name);
		if (move)
		{
			env_ptr = environment[i];
			break;
		}
	}

	return (env_ptr + move);
}

/**
 * print_environment_variables - Prints the environment variables.
 *
 * @data_shell: Data relevant.
 * Return: (1) on success.
 */
int print_environment_variables(data_shell *data_shell)
{
	int i, j;

	for (i = 0; data_shell->_environ[i]; i++)
	{
		for (j = 0; data_shell->_environ[i][j]; j++)
			;

		write(STDOUT_FILENO, data_shell->_environ[i], j);
		write(STDOUT_FILENO, "\n", 1);
	}
	data_shell->status = 0;

	return (1);
}

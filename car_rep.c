#include "main.h"

/**
 * find_env_var - Finds an environment variable by name.
 *
 * @env_vars: Pointer to the array of environment variables.
 * @name: Name of the environment variable to find.
 * Return: Pointer to the value of the environment variable.
 */
char *find_env_var(char **env_vars, const char *name)
{
	int i, name_len;

	for (i = 0; env_vars[i]; i++)
	{
		name_len = 0;
		while (env_vars[i][name_len] && env_vars[i][name_len] != '=')
			name_len++;

		if (_strncmp(env_vars[i], name, name_len) == 0 && env_vars[i][name_len] == '=')
			return (env_vars[i] + name_len + 1);
	}

	return (NULL);
}

/**
 * process_env_vars - Processes environment variables in the input string.
 *
 * @env_vars: Pointer to the array of environment variables.
 * @input: Input string containing environment variables.
 * Return: Processed string with replaced environment variables.
 */
char *process_env_vars(char **env_vars, char *input)
{
	char *result;
	char *value;
	int i, j, k;

	result = malloc(sizeof(char) * (BUFSIZE));
	if (!result)
		return (input);

	for (i = j = 0; input[i]; i++)
	{
		if (input[i] == '$' && input[i + 1] == '{')
		{
			i += 2;
			k = 0;
			while (input[i + k] && input[i + k] != '}')
				k++;

			if (input[i + k] == '}')
			{
				value = find_env_var(env_vars, input + i);
				if (value)
				{
					_strncpy(result + j, value, _strlen(value));
					j += _strlen(value);
				}

				i += k + 1;
			}
			else
			{
				result[j++] = '$';
			}
		}
		else
		{
			result[j++] = input[i];
		}
	}

	result[j] = '\0';
	return (result);
}

/**
 * replace_vars - Replaces variables in the input string.
 *
 * @input: Input string containing variables.
 * @datash: Data structure.
 * Return: Processed string with replaced variables.
 */
char *replace_vars(char *input, data_shell *datash)
{
	char *status;
	char *result;

	status = aux_itoa(datash->status);
	result = process_env_vars(datash->_environ, input);
	result = process_env_vars(datash->_environ, result);
	result = process_env_vars(datash->_environ, result);
	result = process_env_vars(datash->_environ, result);
	result = process_env_vars(datash->_environ, result);

	free(input);
	free(status);

	return (result);
}

#include "main.h"

/**
 * release_resources - Frees the data structure
 *
 * @shell_data: Data structure
 * Return: No return
 */
void release_resources(data_shell *shell_data)
{
	unsigned int i;

	for (i = 0; shell_data->environment[i]; i++)
	{
		free(shell_data->environment[i]);
	}

	free(shell_data->environment);
	free(shell_data->process_id);
}

/**
 * initialize_data - Initializes the data structure
 *
 * @shell_data: Data structure
 * @arguments: Argument vector
 * Return: No return
 */
void initialize_data(data_shell *shell_data, char **arguments)
{
	unsigned int i;

	shell_data->argument_vector = arguments;
	shell_data->input = NULL;
	shell_data->arguments = NULL;
	shell_data->status = 0;
	shell_data->execution_counter = 1;

	for (i = 0; environ[i]; i++)
		;

	shell_data->environment = malloc(sizeof(char *) * (i + 1));

	for (i = 0; environ[i]; i++)
	{
		shell_data->environment[i] = _strdup(environ[i]);
	}

	shell_data->environment[i] = NULL;
	shell_data->process_id = convert_to_string(getpid());
}

/**
 * main - Entry point of the shell program
 *
 * @argument_count: Number of command line arguments
 * @argument_vector: Array of command line arguments
 *
 * Return: 0 on success.
 */
int main(int argument_count, char **argument_vector)
{
	data_shell shell_data;
	(void) argument_count;

	signal(SIGINT, handle_sigint);
	initialize_data(&shell_data, argument_vector);
	shell_loop(&shell_data);
	release_resources(&shell_data);
	if (shell_data.status < 0)
		return (255);
	return (shell_data.status);
}

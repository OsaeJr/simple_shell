#include "main.h"

/**
 * free_data - Frees data structure
 *
 * @data: Data structure
 * Return: No return
 */
void free_data(data_shell *data)
{
	unsigned int j;

	for (j = 0; data->_environ[j]; j++)
	{
		free(data->_environ[j]);
	}

	free(data->_environ);
	free(data->pid);
}

/**
 * init_data - Initializes data structure
 *
 * @data: Data structure
 * @args: Argument vector
 * Return: No return
 */
void init_data(data_shell *data, char **args)
{
	unsigned int j;

	data->av = args;
	data->input = NULL;
	data->args = NULL;
	data->status = 0;
	data->counter = 1;

	for (j = 0; environ[j]; j++)

	data->_environ = malloc(sizeof(char *) * (j + 1));

	for (j = 0; environ[j]; j++)
	{
		data->_environ[j] = _strdup(environ[j]);
	}

	data->_environ[j] = NULL;
	data->pid = aux_itoa(getpid());
}

/**
 * main - Entry point
 *
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Return: 0 on success.
 */
int main(int argc, char **argv)
{
	data_shell data;
	(void) argc;

	signal(SIGINT, handle_sigint);
	init_data(&data, argv);
	run_shell_loop(&data);
	free_data(&data);
	if (data.status < 0)
		return (255);
	return (data.status);
}

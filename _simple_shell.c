#include "shell.h"

/**
 * main - Entry point for the shell program.
 * @argc: Number of command-line arguments.
 * @argv: Array of command-line arguments.
 * @env: Environment variables.
 * Return: 0 on success.
 */
int main(int argc, char **argv, char **env)
{
	char *input_command = NULL;
	char **command_tokens = NULL;
	int path_found = 0;
	int exit_status = 0;
	int iteration = 0;
	(void)argc;

	while (1)
	{
		input_command = getUserInput();

		if (input_command)
		{
			iteration++;
			command_tokens = tokenizeInput(input_command);

			if (!command_tokens)
			{
				free(input_command);
				continue;
			}

			if ((!_strcmp_custom(command_tokens[0], "exit")) && command_tokens[1] == NULL)
				exitCommand(command_tokens, input_command, exit_status);

			if (!_strcmp_custom(command_tokens[0], "env"))
				printEnvironment(env);
			else
			{
				path_found = _search_path(&command_tokens[0], env);
				exit_status = executeCommand(command_tokens, argv, env, input_command, iteration, path_found);

				if (path_found == 0)
					free(command_tokens[0]);
			}

			free(command_tokens);
		}
		else
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			exit(exit_status);
		}

		free(input_command);
	}

	return (exit_status);
}


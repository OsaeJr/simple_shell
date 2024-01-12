#include "shell.h"

/**
 * main - Main function to handle command line arguments.
 * @argc: Count of command line arguments.
 * @argv: Array of command line arguments.
 * @envp: Array of environment variables.
 * Return: Exit code (0 by default).
 */
int main(int argc, char **argv, char **envp)
{
	char *input_command = NULL, **command_tokens = NULL;
	int path_status = 0, exit_code = 0, iteration = 0;
	(void)argc;

	while (1)
	{
		input_command = _read_line_command();
		if (input_command)
		{
			iteration++;
			command_tokens = extract_tokens(input_command);
			if (!command_tokens)
			{
				free(input_command);
				continue;
			}
			if ((!_custom_strcmp(command_tokens[0], "exit")) && command_tokens[1] == NULL)
				exit_command(command_tokens, input_command, exit_code);
			if (!_custom_strcmp(command_tokens[0], "env"))
				print_env(envp);
			else
			{
				path_status = _parse_path(&command_tokens[0], envp);
				exit_code = fork_proc(command_tokens, argv, envp, input_command, iteration, path_status);
				if (path_status == 0)
					free(command_tokens[0]);
			}
			free(command_tokens);
		}
		else
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			exit(exit_code);
		}
		free(input_command);
	}
	return (exit_code);
}

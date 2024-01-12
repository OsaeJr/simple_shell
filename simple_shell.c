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
	char *input_command = NULL, **c_tokens = NULL;
	int path_status = 0, exit_code = 0, i = 0;
	(void)argc;

	while (1)
	{
		input_command = read_command();
		if (input_command)
		{
			i++;
			c_tokens = extract_tokens(input_command);
			if (!c_tokens)
			{
				free(input_command);
				continue;
			}
			if ((!custom_strcmp(c_tokens[0], "exit")) && c_tokens[1] == NULL)
				exit_command(c_tokens, input_command, exit_code);
			if (!custom_strcmp(c_tokens[0], "env"))
				print_env(envp);
			else
			{
				path_status = _parse_path(&command_tokens[0], envp);
				exit_code = fork_proc(c_tokens, argv, envp, input_command, i, path_status);
				if (path_status == 0)
					free(c_tokens[0]);
			}
			free(c_tokens);
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

#include "shell.h"

/**
 * fork_proc - Creates a fork to execute a command
 *
 * @args: Command and arguments
 * @sh: Name of the shell program
 * @env: Environment variables
 * @lin_ptr: User command line
 * @id: Process ID
 * @a: Checker for a new test
 * Return: 0 on success
 */
int fork_proc(char **args, char **sh, char **env, char *lin_ptr, int id, int a)
{
	pid_t child;
	int stat;
	char *fmt = "%s: %d: %s: not found\n";

	child = fork();

	if (child == 0)
	{
		if (execve(args[0], args, env) == -1)
		{
			fprintf(stderr, fmt, she[0], id, args[0]);
			if (!a)
				free(args[0]);
			free(args);
			free(lin_ptr);
			exit(errno);
		}
	}
	else
	{
		wait(&stat);

		if (WIFEXITED(stat) && WEXITSTATUS(stat) != 0)
			return (WEXITSTATUS(stat));
	}

	return (0);
}

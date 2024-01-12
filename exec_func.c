#include "shell.h"
/**
 * _fork_fun - function that create a fork
 *@arg: command and values path
 *@av: Has the name of our program
 *@env: environment
 *@lineptr: command line for the user
 *@np: id of proces
 *@c: Checker add new test
 *Return: 0 success
 */

int _fork_fun(char **arg, char **av, char **env, char *lineptr, int np, int c)
{
	pid_t ch;
	int sta;
	char *fmt = "%s: %d: %s: not found\n";

	ch = fork();

	if (ch == 0)
	{
		if (execve(arg[0], arg, env) == -1)
		{
			fprintf(stderr, fmt, av[0], np, arg[0]);
			if (!c)
				free(arg[0]);
			free(arg);
			free(lineptr);
			exit(errno);
		}
	}
	else
	{
		wait(&sta);

		if (WIFEXITED(sta) && WEXITSTATUS(sta) != 0)
			return (WEXITSTATUS(sta));
	}
	return (0);
}

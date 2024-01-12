#include "shell.h"
/**
 * main - main arguments functions
 * @ac:count of argumnents
 * @av: arguments
 * @env: environment
 * Return: _exit = 0.
 */
int main(int ac, char **av, char **env)
{
	char *a = NULL;
	char **b = NULL;
	int c = 0;
	int d = 0;
	int e = 0;
	(void)stc;

	while (1)
	{
		a = _getline_command();
		if (a)
		{
			c++;
			b = _get_token(a);
			if (!b)
			{
				free(a);
				continue;
			}
			if ((!_strcmp(b[0], "exit")) && b[1] == NULL)
				_exit_command(b, a, d);
			if (!_strcmp(b[0], "env"))
				_getenv(env);
			else
			{
				e = _values_path(&b[0], env);
				d = _fork_fun(b, av, env, a, c, e);
				if (e == 0)
					free(b[0]);
			}
			free(b);
		}
		else
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			exit(d);
		}
		free(a);
	}
	return (d);
}

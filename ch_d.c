#include "main.h"

/**
 * changeToParentDirectory - Changes to the parent directory.
 * @datash: Data relevant (environ).
 * Return: No return.
 */
void changeToParentDirectory(data_shell *datash)
{
	char currentPath[PATH_MAX];
	char *directory, *copyPwd, *copyStrtokPwd;

	getcwd(currentPath, sizeof(currentPath));
	copyPwd = _strdup(currentPath);
	set_env("OLDPWD", copyPwd, datash);
	directory = datash->args[1];

	if (_strcmp(".", directory) == 0)
	{
		set_env("PWD", copyPwd, datash);
		free(copyPwd);
		return;
	}

	if (_strcmp("/", copyPwd) == 0)
	{
		free(copyPwd);
		return;
	}

	copyStrtokPwd = copyPwd;
	rev_string(copyStrtokPwd);
	copyStrtokPwd = _strtok(copyStrtokPwd, "/");

	if (copyStrtokPwd != NULL)
	{
		copyStrtokPwd = _strtok(NULL, "\0");

		if (copyStrtokPwd != NULL)
			rev_string(copyStrtokPwd);
	}

	if (copyStrtokPwd != NULL)
	{
		chdir(copyStrtokPwd);
		set_env("PWD", copyStrtokPwd, datash);
	}
	else
	{
		chdir("/");
		set_env("PWD", "/", datash);
	}

	datash->status = 0;
	free(copyPwd);
}

/**
 * changeToDirectory - Changes to a directory given by the user.
 * @datash: Data relevant (directories).
 * Return: No return.
 */
void changeToDirectory(data_shell *datash)
{
	char currentPath[PATH_MAX];
	char *directory, *copyPwd, *copyDir;

	getcwd(currentPath, sizeof(currentPath));
	directory = datash->args[1];

	if (chdir(directory) == -1)
	{
		get_error(datash, 2);
		return;
	}

	copyPwd = _strdup(currentPath);
	set_env("OLDPWD", copyPwd, datash);

	copyDir = _strdup(directory);
	set_env("PWD", copyDir, datash);

	free(copyPwd);
	free(copyDir);

	datash->status = 0;
	chdir(directory);
}

/**
 * changeToPreviousDirectory - Changes to the previous directory.
 * @datash: Data relevant (environ).
 * Return: No return.
 */
void changeToPreviousDirectory(data_shell *datash)
{
	char currentPath[PATH_MAX];
	char *previousPwd, *previousOldPwd, *copyPwd, *copyOldPwd;

	getcwd(currentPath, sizeof(currentPath));
	copyPwd = _strdup(currentPath);

	previousOldPwd = _getenv("OLDPWD", datash->_environ);

	if (previousOldPwd == NULL)
		copyOldPwd = copyPwd;
	else
		copyOldPwd = _strdup(previousOldPwd);

	set_env("OLDPWD", copyPwd, datash);

	if (chdir(copyOldPwd) == -1)
		set_env("PWD", copyPwd, datash);
	else
		set_env("PWD", copyOldPwd, datash);

	previousPwd = _getenv("PWD", datash->_environ);

	write(STDOUT_FILENO, previousPwd, _strlen(previousPwd));
	write(STDOUT_FILENO, "\n", 1);

	free(copyPwd);
	if (previousOldPwd)
		free(copyOldPwd);

	datash->status = 0;
	chdir(previousPwd);
}

/**
 * changeToHomeDirectory - Changes to the home directory.
 * @datash: Data relevant (environ).
 * Return: No return.
 */
void changeToHomeDirectory(data_shell *datash)
{
	char *previousPwd, *home;
	char currentPath[PATH_MAX];

	getcwd(currentPath, sizeof(currentPath));
	previousPwd = _strdup(currentPath);

	home = _getenv("HOME", datash->_environ);

	if (home == NULL)
	{
		set_env("OLDPWD", previousPwd, datash);
		free(previousPwd);
		return;
	}

	if (chdir(home) == -1)
	{
		get_error(datash, 2);
		free(previousPwd);
		return;
	}

	set_env("OLDPWD", previousPwd, datash);
	set_env("PWD", home, datash);

	free(previousPwd);
	datash->status = 0;
}


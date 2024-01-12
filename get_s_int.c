#include "main.h"

/**
 * handle_sigint - Handles the Ctrl+C signal in the prompt
 * @signal: Signal handler
 */
void handle_sigint(int signal)
{
	(void)signal;
	write(STDOUT_FILENO, "\n^-^ ", 5);
}

#include "main.h"

/**
 * get_input - Reads the input string.
 *
 * @is_end_of_file: Return value of getline function
 * Return: Input string
 */
char *get_input(int *is_end_of_file)
{
	char *user_input = NULL;
	size_t buffer_size = 0;

	*is_end_of_file = getline(&user_input, &buffer_size, stdin);

	return (user_input);
}

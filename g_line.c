#include "main.h"

/**
 * set_input_buffer - assigns the input buffer for get_input
 * @line_buffer: Buffer that stores the input string
 * @buffer: String that is assigned to line_buffer
 * @buffer_size: Size of line_buffer
 * @input_size: Size of buffer
 */
void set_input_buffer(char **line_buffer, size_t *buffer_size, char *buffer, size_t input_size)
{
	if (*line_buffer == NULL)
	{
		if (input_size > INPUT_BUFFER_SIZE)
			*buffer_size = input_size;
		else
			*buffer_size = INPUT_BUFFER_SIZE;
		*line_buffer = buffer;
	}
	else if (*buffer_size < input_size)
	{
		if (input_size > INPUT_BUFFER_SIZE)
			*buffer_size = input_size;
		else
			*buffer_size = INPUT_BUFFER_SIZE;
		*line_buffer = buffer;
	}
	else
	{
		_strcpy(*line_buffer, buffer);
		free(buffer);
	}
}

/**
 * get_input - Read input from stream
 * @line_buffer: Buffer that stores the input
 * @buffer_size: Size of line_buffer
 * @stream: Stream to read from
 * Return: The number of bytes
 */
ssize_t get_input(char **line_buffer, size_t *buffer_size, FILE *stream)
{
	int i;
	static ssize_t input;
	ssize_t retval;
	char *buffer;
	char t = 'z';

	if (input == 0)
		fflush(stream);
	else
		return (-1);
	input = 0;

	buffer = malloc(sizeof(char) * INPUT_BUFFER_SIZE);
	if (buffer == 0)
		return (-1);
	while (t != '\n')
	{
		i = read(STDIN_FILENO, &t, 1);
		if (i == -1 || (i == 0 && input == 0))
		{
			free(buffer);
			return (-1);
		}
		if (i == 0 && input != 0)
		{
			input++;
			break;
		}
		if (input >= INPUT_BUFFER_SIZE)
			buffer = _realloc(buffer, input, input + 1);
		buffer[input] = t;
		input++;
	}
	buffer[input] = '\0';
	set_input_buffer(line_buffer, buffer_size, buffer, input);
	retval = input;
	if (i != 0)
		input = 0;
	return (retval);
}

#include "main.h"

/**
 * set_input_buffer - assigns the input buffer for get_input
 * @l_buff: Buffer that stores the input string
 * @buff: String that is assigned to line_buffer
 * @b_size: Size of line_buffer
 * @i_size: Size of buffer
 */
void set_input_buffer(char **l_buff, size_t *b_size, char *buff, size_t i_size)
{
	if (*l_buff == NULL)
	{
		if (i_size > INPUT_BUFFER_SIZE)
			*b_size = i_size;
		else
			*b_size = INPUT_BUFFER_SIZE;
		*l_buff = buff;
	}
	else if (*b_size < i_size)
	{
		if (i_size > INPUT_BUFFER_SIZE)
			*b_size = input_size;
		else
			*b_size = INPUT_BUFFER_SIZE;
		*l_buff = buff;
	}
	else
	{
		_strcpy(*l_buff, buff);
		free(buff);
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

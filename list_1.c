#include "main.h"

/**
 * add_separator_node_end - Adds a separator found at the end
 * of a separator list.
 * @separator_list: Head of the separator list.
 * @separator: Separator found (; | &).
 * Return: Address of the head.
 */
sep_list *add_separator_node_end(sep_list **separator_list, char separator)
{
    sep_list *new_separator, *temp;

    new_separator = malloc(sizeof(sep_list));
    if (new_separator == NULL)
        return (NULL);

    new_separator->separator = separator;
    new_separator->next = NULL;
    temp = *separator_list;

    if (temp == NULL)
    {
        *separator_list = new_separator;
    }
    else
    {
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = new_separator;
    }

    return (*separator_list);
}

/**
 * free_separator_list - Frees a separator list.
 * @separator_list: Head of the separator list.
 * Return: No return.
 */
void free_separator_list(sep_list **separator_list)
{
    sep_list *temp;
    sep_list *current;

    if (separator_list != NULL)
    {
        current = *separator_list;
        while ((temp = current) != NULL)
        {
            current = current->next;
            free(temp);
        }
        *separator_list = NULL;
    }
}

/**
 * add_line_node_end - Adds a command line at the end
 * of a line list.
 * @line_list: Head of the line list.
 * @line: Command line.
 * Return: Address of the head.
 */
line_list *add_line_node_end(line_list **line_list, char *line)
{
    line_list *new_line, *temp;

    new_line = malloc(sizeof(line_list));
    if (new_line == NULL)
        return (NULL);

    new_line->line = line;
    new_line->next = NULL;
    temp = *line_list;

    if (temp == NULL)
    {
        *line_list = new_line;
    }
    else
    {
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = new_line;
    }

    return (*line_list);
}

/**
 * free_line_list - Frees a line list.
 * @line_list: Head of the line list.
 * Return: No return.
 */
void free_line_list(line_list **line_list)
{
    line_list *temp;
    line_list *current;

    if (line_list != NULL)
    {
        current = *line_list;
        while ((temp = current) != NULL)
        {
            current = current->next;
            free(temp);
        }
        *line_list = NULL;
    }
}


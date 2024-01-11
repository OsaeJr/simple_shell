#include "main.h"

/**
 * add_rvar_node - Adds a variable at the end
 * of an r_var list.
 * @rvar_list: Head of the linked list.
 * @length_var: Length of the variable.
 * @value: Value of the variable.
 * @length_value: Length of the value.
 * Return: Address of the head.
 */
r_var *add_rvar_node(r_var **rvar_list, int length_var, char *value, int length_value)
{
    r_var *new_rvar, *temp;

    new_rvar = malloc(sizeof(r_var));
    if (new_rvar == NULL)
        return (NULL);

    new_rvar->len_var = length_var;
    new_rvar->val = value;
    new_rvar->len_val = length_value;

    new_rvar->next = NULL;
    temp = *rvar_list;

    if (temp == NULL)
    {
        *rvar_list = new_rvar;
    }
    else
    {
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = new_rvar;
    }

    return (*rvar_list);
}

/**
 * free_rvar_list - Frees an r_var list.
 * @rvar_list: Head of the linked list.
 * Return: No return.
 */
void free_rvar_list(r_var **rvar_list)
{
    r_var *temp;
    r_var *current;

    if (rvar_list != NULL)
    {
        current = *rvar_list;
        while ((temp = current) != NULL)
        {
            current = current->next;
            free(temp);
        }
        *rvar_list = NULL;
    }
}


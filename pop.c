#include "data_struct.h"

/**
* pop - pops out top element from stack
* @head: the head pointer to list
* @line_number: not used for this function
*/

void pop(stack_t **head, unsigned int line_number)
{
	stack_t *temp;

	(void)line_number;
	if (*head == NULL)
		error_msg("can't pop an empty stack");
	temp = *head;
	if ((*head)->next != NULL)
	{
		*head = (*head)->next;
		(*head)->prev = NULL;
	}
	else
		*head = NULL;
	free(temp);
}

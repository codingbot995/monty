#include "data_struct.h"

/**
* mod - finds the mod of the first two element of stack
* @head: the head pointer to list
* @line_number: not used for this function
*/

void mod(stack_t **head, unsigned int line_number)
{
	unsigned int result, prev;
	stack_t *current, *temp;

	(void)line_number;
	if (*head == NULL || (*head)->next == NULL)
		error_msg("can't mod, stack too short");
	current = *head;
	temp = current->next;
	prev = current->n;
	result = temp->n;
	if (prev == 0)
		error_msg("division by zero");
	result %= prev;
	temp->n = result;
	temp->prev = NULL;
	*head = temp;
	free(current);
}

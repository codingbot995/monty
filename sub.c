#include "data_struct.h"

/**
* sub - subtracts first two elements of a stack
* @head: the head pointer to list
* @line_number: not used for this function
*/

void sub(stack_t **head, unsigned int line_number)
{
	unsigned int result, prev;
	stack_t *current, *temp;

	(void)line_number;
	if (*head == NULL || (*head)->next == NULL)
		error_msg("can't sub, stack too short");
	current = *head;
	temp = current->next;
	prev = current->n;
	result = temp->n;
	if (result < prev)
		result = prev - result;
	else
		result -= prev;
	temp->n = result;
	temp->prev = NULL;
	*head = temp;
	free(current);
}

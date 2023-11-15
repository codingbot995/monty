#include "data_struct.h"

/**
* mul - multiplies the first two top elements
* @head: the head pointer to list
* @line_number: not used for this function
*/

void mul(stack_t **head, unsigned int line_number)
{
	unsigned int result, prev;
	stack_t *current, *temp;

	(void)line_number;
	if (*head == NULL || (*head)->next == NULL)
		error_msg("can't mul, stack too short");
	current = *head;
	temp = current->next;
	prev = current->n;
	result = temp->n;
	result *= prev;
	temp->n = result;
	temp->prev = NULL;
	*head = temp;
	free(current);
}

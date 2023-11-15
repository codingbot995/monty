#include "data_struct.h"

/**
* swap - swaps first two elements of a stack
* @head: the head pointer to list
* @line_number: not used for this function
*/

void swap(stack_t **head, unsigned int line_number)
{
	unsigned int nex, prev;
	stack_t *current;

	(void)line_number;
	if (*head == NULL || (*head)->next == NULL)
		error_msg("can't swap, stack too short");
	current = *head;
	prev = current->n;
	nex = (current->next)->n;
	(current->next)->n = prev;
	current->n = nex;
}

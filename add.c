#include "monty.h"

/**
* add - adds the first two top element of the stack
* @head: the head pointer to list
* @line_number: not used for this function
*/

void add(stack_t **head, unsigned int line_number)
{
	unsigned int result, prev;
	stack_t *current, *temp;

	(void)line_number;
	if (*head == NULL || (*head)->next == NULL)
		error_msg("can't add, stack too short");
	current = *head;
	temp = current->next;
	prev = current->n;
	result = temp->n;
	result += prev;
	temp->n = result;
	temp->prev = NULL;
	*head = temp;
	free(current);
}

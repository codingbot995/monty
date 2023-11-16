#include "monty.h"

/**
* rotr - rotates the entire stack, bottom to top
* @head: the head pointer to list
* @line_number: not used for this function
*/

void rotr(stack_t **head, unsigned int line_number)
{
	stack_t *copy;

	(void)line_number;
	copy = *head;
	if (*head == NULL || (*head)->next == NULL)
		return;
	while (copy->next)
		copy = copy->next;
	copy->next = *head;
	copy->prev->next = NULL;
	copy->prev = NULL;
	(*head)->prev = copy;
	*head = copy;
}

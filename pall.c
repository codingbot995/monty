#include "monty.h"

/**
* pall - prints all elements in stack
* @head: the head pointer to list
* @line_number: not used for this function
*/

void pall(stack_t **head, unsigned int line_number)
{
	stack_t *current;

	(void)line_number;
	current = *head;
	if (*head == NULL)
		return;
	while (current != NULL)
	{
		fprintf(stdout, "%u\n", current->n);
		current = current->next;
	}
}

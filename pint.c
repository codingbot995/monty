#include "data_struct.h"

/**
* pint - prints the top element of stack
* @head: the head pointer to list
* @line_number: not used for this function
*/

void pint(stack_t **head, unsigned int line_number)
{
	stack_t *current;

	(void)line_number;
	if (*head == NULL)
		error_msg("can't pint, stack empty");
	current = *head;
	fprintf(stdout, "%u\n", (current)->n);
}

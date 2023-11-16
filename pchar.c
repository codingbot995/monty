#include "monty.h"

/**
* pchar - prints the ascii value of first element
* @head: the head pointer to list
* @line_number: not used for this function
*/

void pchar(stack_t **head, unsigned int line_number)
{
	(void)line_number;
	if (*head == NULL)
		error_msg("can't pchar, stack empty");
	if ((*head)->n > 127)
		error_msg("can't pchar, value out of range");
	fprintf(stdout, "%c\n", (*head)->n);
}

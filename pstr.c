#include "data_struct.h"

/**
* pstr - prints the ascii value of each element in stack
* @head: the head pointer to list
* @line_number: not used for this function
*/

void pstr(stack_t **head, unsigned int line_number)
{
	stack_t *current;

	(void)line_number;
	if (*head != NULL)
	{
		current = *head;
		while (current != NULL)
		{
			if (current->n == 0 || current->n > 127)
				break;
			fprintf(stdout, "%c", current->n);
			current = current->next;
		}
	}
	fprintf(stdout, "\n");
}

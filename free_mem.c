#include "monty.h"

/**
* free_alloc - frees all memory allocated to stack
* @head: the head pointer to list
*/
void free_alloc(stack_t *head)
{
	stack_t *temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
	head = NULL;
}


/**
 * error_msg - sends error message to standard error
 * @str: the message it's printing#
*/

void error_msg(char *str)
{
	fprintf(stderr, "L%d: %s\n", number_line(), str);
	free_alloc(HEAD);
	exit(EXIT_FAILURE);
}

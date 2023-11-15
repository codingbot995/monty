#include "data_struct.h"

/**
* rotl - makes top element to bottom
* @head: the head pointer to list
* @line_number: not used for this function
*/

void rotl(stack_t **head,  unsigned int line_number)
{
	stack_t *tmp = *head, *aux;

	(void)line_number;
	if (*head == NULL || (*head)->next == NULL)
		return;
	aux = (*head)->next;
	aux->prev = NULL;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = *head;
	(*head)->next = NULL;
	(*head)->prev = tmp;
	*head = aux;
}

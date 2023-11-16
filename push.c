#include "data_struct.h"

/**
* push - pushes element tot stack
* @head: the head pointer to list
* @line_number: the number to be pushed to stack
*/

void push(stack_t **head, unsigned int line_number)
{
	stack_t *new_node, *current;

	current = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	new_node->n = line_number;
	if (*head == NULL)
	{
		new_node->prev = NULL;
		new_node->next = NULL;
		*head = new_node;
	}
	else
	{
		new_node->prev = NULL;
		new_node->next = *head;
		(*head)->prev = new_node;
		*head = new_node;
	}
}

#include "monty.h"

/**
* push - pushes element tot stack
* @head: the head pointer to list
* @line_number: the number to be pushed to stack
*/

void push(stack_t **head, unsigned int line_number)
{
	stack_t *new_node, *current;

	if (status == 1)
		push2(head, line_number);
	else
	{
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
			current->prev = new_node;
			*head = new_node;
		}
	}
}


/**
* push2 - pushes element to queue
* @head: the head pointer to list
* @line_number: the number to be pushed to stack
*/
void push2(stack_t **head, const int n)
{
	stack_t *new_node, *prev;

	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}

	for (prev = NULL; *head != NULL; head = &(*head)->next)
		prev = *head;

	new_node->next = NULL;
	new_node->prev = prev;
	new_node->n = n;
	*head = new_node;
}
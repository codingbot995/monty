#include "data_struct.h"

/**
* handle_args - handles the arguments parsed
* @opcode_str: the string to handle
* Return: Always 0 for success
*/

int handle_args(char *opcode_str)
{
	instruction_t opfunc[] = {
		{"push", push}, {"pop", pop},
		{"add", add}, {"div", handle_div},
		{"mod", mod}, {"mul", mul},
		{"pall", pall}, {"pall$", pall},
		{"pchar", pchar},
		{"pint", pint},
		{"pstr", pstr},
		{"rotl", rotl},
		{"sub", sub},
		{"swap", swap},
		{"rotr", rotr}
	};
	char *temp;
	long int number;
	size_t i;

	temp = strtok(NULL, " \t\n");
	if (temp == NULL && strcmp(opcode_str, "push") == 0)
		error_msg("usage: push integer");
	else if (temp == NULL)
		temp = "0";
	number = string_to_int(temp, opcode_str);
	for (i = 0; i < sizeof(opfunc) / sizeof(opfunc[0]); i++)
	{
		if (strcmp(opcode_str, opfunc[i].opcode) == 0)
		{
			opfunc[i].f(&HEAD, number);
			break;
		}
	}
	if (i == (sizeof(opfunc) / sizeof(opfunc[0])))
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", number_line(), opcode_str);
		free_alloc(HEAD);
		exit(EXIT_FAILURE);
	}
	return (0);
}

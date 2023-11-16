#include "monty.h"

/**
* string_to_int - converts a string to an unsigned int
* @str_number: the string to convert to number
* @opcode: The command of each line for confirmation
* Return: the integer, 0 for failure
*/

long int string_to_int(char *str_number, char *opcode)
{
	char *endptr;
	long int intValue = strtol(str_number, &endptr, 10);

	if (strlen(endptr) > 1 && strcmp(opcode, "push") == 0)
	{
		error_msg("usage: push integer");
		return (0);
	}
	else if (strlen(endptr) != 0 && strcmp(opcode, "push") != 0)
		return (0);
	else
		return (intValue);
}

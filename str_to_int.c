#include "data_struct.h"

/**
* string_to_int - converts a string to an unsigned int
* @str_number: the string to convert to number
* Return: the integer, 0 for failure
*/

long int string_to_int(char *str_number)
{
	char *endptr;
	long int intValue = strtol(str_number, &endptr, 10);

	if (strlen(endptr) > 1)
	{
		error_msg("usage: push integer");
		return (0);
	}
	else
		return (intValue);
}

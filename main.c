#include "monty.h"

stack_t *HEAD = NULL;
static int line_no;

/**
* main - Entry point of all code
* @argc: the argument count of the strings
* @argv: the arguments as bunch of strings
* Return: Always zero for success
*/

int main(int argc, char *argv[])
{
	char line[1024];
	FILE *file;
	int temp;

	line_no = 1;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (fgets(line, sizeof(line), file) != NULL)
	{
		char *opcode;

		if (line[0] == '#' || line[0] == ' ')
		{
			line_no++;
			continue;
		}
		opcode = strtok(line, " \t\n");
		if (opcode == NULL || strcmp(opcode, "nop") == 0)
		{
			line_no++;
			continue;
		}
		temp = handle_args(opcode);
		if (temp < 0)
			exit(EXIT_FAILURE);
		line_no++;
	}
	free_alloc(HEAD);
	fclose(file);
	return (0);
}


/**
* number_line - function for current file line number
* Return: returns current number line
*/

int number_line(void)
{
	return (line_no);
}

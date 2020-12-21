#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "monty.h"

/**
  * main - entry point
  *
  * @ac: argument counter
  * @av: argument vector
  *
  * Return: EXIT_SUCCESS if succes, EXIT_FAILURE otherwise
  *
  * Description: a simple interpreter for the monty language
  */

int main(int ac, char **av)
{
	int ret = 0, line_number = 0;
	char *line = NULL;
	size_t size = 0;
	FILE *fd;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	fd = open(av[1], O_RDONLY);
	if (*fd == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		return (EXIT_FAILURE);
	}
	input_parse = 0;
	while (ret != -1)
	{
		ret = getline(&line, &size, fd);
		tokline(line);
		input_parse += ret; /* YOU NEED A STRUCTURE THAT CAN HOLD ARRAYS */
		line_number++;
	}
	data_parse = 0;
	instructer(input_parse, line_number);

}

void tokline(char *line)
{
	char delim[] = " \t\r\n";

	data[input_parse] = strtok(line, delim);
	input_parse++; /* THIS IS CONCEPTUALLY WRONG */

	while (data[input_parse] != NULL)
	{
		data[input_parse] = strtok(NULL, delim);
	}
}

void instructer(int input_parse, int line_number)
{
	instruction_t ops[] = {
		{"push", push_node}, {"pint", print_stuck},
		{NULL, NULL}
	};
	int i;
	stack_t *stack = NULL;

	while (data_parse < input_parse)
	{
		for (i = 0; i < 3; i++)
		{
			if (strcmp(ops[i].opcode, data[data_parse]) == 0)
			{
				ops[i].f(&stack, line_number);
				break;
			}
			if (ops[i].opcode == NULL)
			{
				fprintf(stderr, "L%d: unknown instruction %s\n", line_number, data[data_parse]);
				exit(EXIT_FAILURE);
			}
		}
		data_parse++;
	}
}
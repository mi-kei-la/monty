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
	FILE *fd = NULL;
	int i, ret = 0, line_number = 1;
	size_t size = 0;
	char *data = NULL, delims[] = " \t\n\r", *save = NULL;
	instruction_t codes[] = {
		{"push", push_node}, {"pall", print_stuck},
		{"pint", print_int}, {"swap", swapper},
		{"nop", NULL}, {NULL, NULL}
	};
	stack_t *head = NULL;

	fd = getfile(ac, av);
	line = NULL;
	while (ret != -1)
	{
		ret = getline(&line, &size, fd);
		if (line == NULL || strcmp(line, "") == 0)
			break;
		save = strdup(line);
		data = strtok(save, delims);
		while (data != NULL)
		{
			for (i = 0; i < 4; i++)
			{
				if (strcmp(data, codes[i].opcode) == 0)
				{
					codes[i].f(&head, line_number);
					break;
				}
				else if (i == 3)
				{
					fprintf(stderr, "L%d: unknown instruction %s\n", line_number, data);
				}
			}
			data = strtok(NULL, delims);
		}
		line_number++;
	}
	fclose(fd);
	free_stack(head);
	if (ret == EOF)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

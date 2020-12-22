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
	int i, ret = 0, line_number = 1, opcount = 11;
	size_t size = 0;
	char *data = NULL, delims[] = " \t\n\r", *save = NULL;
	instruction_t codes[] = {
		{"push", push_node}, {"pall", print_stuck},
		{"pint", print_int}, {"pop", popper},
		{"swap", swapper}, {"add", adderall},
		{"nop", NULL}, {"sub", sub}, {"div", diva},
		{"mul", emule}, {"mod", mood}, {"pchar", puchero},
		{NULL, NULL}
	};
	stack_t *head = NULL;

	fd = getfile(ac, av);
	if (fd == NULL)
		return (EXIT_FAILURE);
	line = NULL;
	ret = getline(&line, &size, fd);
	while (ret != -1)
	{
		if (line == NULL || strcmp(line, "") == 0)
			break;
		save = strdup(line);
		data = strtok(save, delims);
		while (data != NULL)
		{
			for (i = 0; i < opcount; i++)
			{
				if (strcmp(data, codes[i].opcode) == 0)
				{
					codes[i].f(&head, line_number);
					break;
				}
				else if (i == opcount)
				{
					fprintf(stderr, "L%d: unknown instruction %s\n", line_number, data);
					free(line);
					free(data);
					fclose(fd);
					free(fd);
					free(save);
					free_stack(head);
					return (EXIT_FAILURE);
				}
			}
			data = strtok(NULL, delims);
		}
		line_number++;
		ret = getline(&line, &size, fd);
	}
	free(line);
	free(data);
	fclose(fd);
	free(fd);
	free(save);
	free_stack(head);
	return (EXIT_SUCCESS);
}

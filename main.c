#include "monty.h"
char *line;
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
		{NULL, NULL}
	};
	stack_t *head = NULL;


	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	fd = fopen(av[1], "r");
	if (!fd)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		return (EXIT_FAILURE);
	}
	line = NULL;
	while (ret != -1)
	{
		ret = getline(&line, &size, fd);
		if (line == NULL || strcmp(line, "") == 0)
			break;
/*		len = strlen(line);
		line[len - 1] = '\0';
*/		save = strdup(line);
		data = strtok(save, delims);
		while (data != NULL)
		{
			for (i = 0; i < 3; i++)
			{
				if (strcmp(data, codes[i].opcode) == 0)
				{
					codes[i].f(&head, line_number);
					break;
				}
				else if (i == 2)
				{
					fprintf(stderr, "L%d: unknown instruction %s\n", line_number, data);
				}
			}
			data = strtok(NULL, delims);
		}
		line_number++;
		line = NULL;
	}

	fclose(fd);
	free(save);
	free(line);
	free(data);
	free_stack(head);
	if (ret == EOF)
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

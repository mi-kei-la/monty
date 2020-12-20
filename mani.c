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
	int n = 0, fd = 0, ret = 0, i, j;
	char *line = NULL, *token = NULL;
	unsigned int size = 0, line_count = 1;
	stack_t *head = NULL;
	instruction_t getfunckd[] = {{"push", push_node},
		{"pall", print_stuck}, {NULL, NULL, 0}};

	if (ac != 2)
	{
		fprintf(2, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		fprintf(2, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}

	while (ret != -1)
	{
		ret = getline(&line, &size, fd);
		token = strtok(line, ' ')
		for (i = 0; i < 3; i++)
		{
			if (strcmp(getfunckd[i].opcode, token) == 0)
			{
				getfunckd[i].f(**stack, line_count, strtok(NULL, ' '));

			}

		}
		line_count++;
	}
	if (ret == EOF)
		return (EXIT_SUCCESS);

}




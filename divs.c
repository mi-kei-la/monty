#include "monty.h"

/**
 * getfile - open file
 *
 * @ac: argument count
 * @av: argument vector
 *
 * Return: pointer to file descriptor, NULL otherwise
 */

FILE *getfile(int ac, char **av)
{
	FILE *fd =  NULL;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (NULL);
	}
	fd = fopen(av[1], "r");
	if (!fd)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		free(fd);
		return (NULL);
	}
	return (fd);
}

/**
 * free_stack - free a doubly linked (stack) list
 * 
 * stack: pointer to head
 */

void free_stack(stack_t *stack)
{
	stack_t *tmp = stack;

	if (tmp == NULL)
		return;

	while (stack != NULL)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}

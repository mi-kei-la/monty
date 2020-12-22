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
 * @stack: pointer to head
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

/**
 * adderall - add first two nodes
 *
 * @stack: pointer to beginning of a list
 * @line_number: line number
 */
void adderall(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n = (*stack)->n + (*stack)->next->n;
	popper(stack, line_number);
}

/**
 * sub - substract first two nodes
 *
 * @stack: pointer to beginning of a list
 * @line_number: line number
 */
void sub(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n = (*stack)->next->n - (*stack)->n;
	popper(stack, line_number);
}

/**
 * diva - divide first two nodes
 *
 * @stack: pointer to beginning of a list
 * @line_number: line number
 */
void diva(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->next->n / (*stack)->n;
	popper(stack, line_number);
}

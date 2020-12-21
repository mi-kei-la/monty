#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

/**
  * print_stuck - print all elements of the stack
  *
  * @stack: start of list
  * @line_number: number of line
  */
void print_stuck(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	(void) line_number;

	if (stack == NULL)
		exit(EXIT_FAILURE);

	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
* push_node - add node to the stack
*
* @stack: pointer to beginning of a list
* @line_number: line number
*/

void push_node(stack_t **stack, unsigned int line_number)
{
	stack_t *new = NULL;
	int n = 0;

	data_parse++;
	if (data[data_parse] < 48 || data[data_parse] > 57)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
		n = data[data_parse];

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new->prev = NULL;
	new->n = n;
	new->next = *stack;
	if (*stack == NULL)
		*stack = new;
	else
	{
		(*stack)->prev = new;
		*stack = new;
	}
	
}


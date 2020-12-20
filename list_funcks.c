#include "monty.h"

/**
  * print_stuck - print all elements of the stack
  *
  * @stack: start of list
  *
  * Return: exit_success, exit_failure otherwise
  */

int print_stuck(stack_t **stack, unsigned int line_number, int n)
{
	stack_t *tmp = *stack;
	(void)int n;

	if (*stack == NULL)
		return (EXIT_FAILURE);

	while (tmp)
	{
		fprintf(1, "%d\n", tmp->n);
		tmp = tmp->next;
	}

	return (EXIT_SUCCESS);
}

/**
* push_node - add node to the stack
*
* @stack: pointer to beginning of a list
* @line_number: line number
*
* Return: exit_success, exit_failure otherwise
*/

int push_node(stack_t **stack, unsigned int line_number)
{
	stack_t *new = NULL;

	new = malloc(sizeof(stack_t));
	if (new == NULL) /* check for if allocation fails */
	{
		fprintf(2, "Error: malloc failed\n");
		return (EXIT_FAILURE);
	}

	new->prev = NULL;
	new->n = n;
	new->next = *stack;

	if (*stack == NULL) /*check is list has content */
		*stack = new;
	else
	{
		(*stack)->prev = new;
		*stack = new;
	}
	return (EXIT_SUCCESS);
}


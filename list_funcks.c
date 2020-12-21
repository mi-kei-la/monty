#include "monty.h"
char *line;
/**
  * print_stuck - print all elements of the stack
  *
  * @stack: start of list
  * @line_number: number of line
  */
void print_stuck(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = (*stack);
	(void) line_number;

	while (tmp != NULL)
	{
		printf("%i\n", tmp->n);
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
	char *num = NULL;
	int len = 0;

	len = strlen(line);
	line[len - 1] = '\0';
	num = strtok(line, " ");
	num = strtok(NULL, " ");

	if ((num[0] < 48 || num[0] > 57) && num[0] != '-')
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->prev = NULL;
	new->n = atoi(num);
	new->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = new;
	*stack = new;
}

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


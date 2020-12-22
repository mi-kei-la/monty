#include "monty.h"

/**
 * emule - multiplyfirst two nodes
 * 
 * @stack: pointer to beginning of a list
 * @line_number: line number
 */
void emule(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n = (*stack)->n * (*stack)->next->n;
	popper(stack, line_number);
}

/**
 * mood - mod of first two nodes
 * 
 * @stack: pointer to beginning of a list
 * @line_number: line number
 */
void mood(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->next->n % (*stack)->n ;
	popper(stack, line_number);
}

/**
 * puchero - print first element of the stack as character
 * 
 * @stack: pointer to first node of the stack
 * @line_number: line number
 */
void puchero(stack_t **stack, unsigned int line_number)
{
    int c = (*stack)->n;
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
    if (c < 0 || c > 127)
    {
        fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
        exit(EXIT_FAILURE);
    }
	write(1, &c, 1);
}

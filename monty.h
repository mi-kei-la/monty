#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* extern variables */
extern char *line;

/* divs.c */
FILE *getfile(int ac, char **av);
void free_stack(stack_t *stack);
void adderall(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void diva(stack_t **stack, unsigned int line_number);

/* morefancs.c */
void emule(stack_t **stack, unsigned int line_number);
void mood(stack_t **stack, unsigned int line_number);
void puchero(stack_t **stack, unsigned int line_number);

/* list_funcks.c */
void push_node(stack_t **stack, unsigned int line_number);
void print_stuck(stack_t **stack, unsigned int line_number);
void print_int(stack_t **stack, unsigned int line_number);
void swapper(stack_t **stack, unsigned int line_number);
void popper(stack_t **stack, unsigned int line_number);



#endif

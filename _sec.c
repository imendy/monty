#include "monty.h"

/**
 * _sec - es the second top element of the stack with the
 * top element of the stack
 * @stack: head
 * @dig_line: integer
 */

void _sec(stack_t **stack, unsigned int dig_line)
{
	if (*stack && (*stack)->next)
	{
		stack_t *ptop = *stack;
		stack_t *ptop2 = (*stack)->next;
		int tyms = ptop->n * ptop2->n;

		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		free(ptop);
		(*stack)->n = tyms;
	}
	else
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", dig_line);
		free(global.line);
		fclose(global.fil);
		_list(stack);
		exit(EXIT_FAILURE);
	}
}

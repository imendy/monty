#include "monty.h"

/**
 * _sec - es the second top element of the stack with the
 * top element of the stack
 * @stack: head
 * @dig_line: integer
 */

void _sec(stack_t **stack, unsigned int dig_line)
{
	stack_t *ptop;
	stack_t *ptop2;
	int tyms = 0;

	if (*stack && (*stack)->next)
	{
		ptop2 = (*stack)->next;
		tyms = ptop->n * (*stack)->n;
		ptop = *stack;
		*stack = (*stack)->next;
		if (*stack)
			(*stack)->prev = NULL;
		free(ptop);
		(*stack)->n = tyms;
	}
	else
	{
		fprintf(2, "L%u: can't mul, stack too short\n", dig_line);
		free(global.line);
		fclose(global.fil);
		_list(stack);
		exit(EXIT_FAILURE);
	}
}

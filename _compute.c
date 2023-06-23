#include "monty.h"
/**
 * _compute - computes the rest of the division of the second
 * top element of the stack by the top element of the stack.
 * @stack: head
 * @dig_line: integer
 */

void _compute(stack_t **stack, unsigned int dig_line)
{
	stack_t *ptop;
	stack_t *ptop2;
	int tyms = 0;

	if (*stack && (*stack)->next)
	{
		if ((*stack)->n == 0)
		{
			fprintf(stderr, "L%u: division by zero\n", dig_line);
			free(global.line);
			fclose(global.fil);
			_list(stack);
			exit(EXIT_FAILURE);
		}
		ptop2 = (*stack)->next;
		tyms = ptop2->n % (*stack)->n;
		ptop = *stack;
		*stack = (*stack)->next;
		if (*stack)
			(*stack)->prev = NULL;
		free(ptop);
		(*stack)->n = tyms;
	}
	else
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", dig_line);
		free(global.line);
		fclose(global.fil);
		_list(stack);
		exit(EXIT_FAILURE);
	}
}

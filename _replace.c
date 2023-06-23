#include "monty.h"
/**
 * _replace - subtracts the top element of the stack from
 * the second top element of the stack.
 * @stack: head
 * @dig_line: number line
 */
void _replace(stack_t **stack, unsigned int dig_line)
{
	stack_t *ptop;
	stack_t *ptop2;
	int sp = 0;

	if (*stack && (*stack)->next)
	{
		ptop2 = (*stack)->next;
		sp = ptop2->n - (*stack)->n;
		ptop = *stack;
		*stack = (*stack)->next;
		if (*stack)
			(*stack)->prev = NULL;
		free(ptop);
		(*stack)->n = sp;
	}
	else
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", dig_line);
		free(global.line);
		fclose(global.fil);
		_list(stack);
		exit(EXIT_FAILURE);
	}
}

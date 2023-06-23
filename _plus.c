#include "monty.h"
/**
 * _plus - adds the top two elements of the stack.
 * @stack: head
 * @dig_line: number of line
 */
void _plus(stack_t **stack, unsigned int dig_line)
{
	stack_t *ptop;
	stack_t *ptop2;
	int mix = 0;

	if (*stack && (*stack)->next)
	{
		ptop2 = (*stack)->next;
		mix = (*stack)->n + ptop2->n;
		ptop = *stack;
		*stack = (*stack)->next;
		if (*stack)
			(*stack)->prev = NULL;
		free(ptop);
		(*stack)->n = mix;
	}
	else
	{
		fprintf(2, "L%d: can't add, stack too short\n", dig_line);
		free(global.line);
		fclose(global.fil);
		_list(stack);
		exit(EXIT_FAILURE);
	}
}

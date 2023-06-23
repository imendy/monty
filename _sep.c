#include "monty.h"
/**
 * _sep -des the second top element of the stack
 * by the top element of the stack.
 * @stack: node head
 * @dig_line: number of the line
 */
void _sep(stack_t **stack, unsigned int dig_line)
{
	stack_t *ptop;
	stack_t *ptop2;
	int rem = 0;

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
		rem = ptop2->n / (*stack)->n;
		ptop = *stack;
		*stack = (*stack)->next;
		if (*stack)
			(*stack)->prev = NULL;
		free(ptop);
		(*stack)->n = rem;
	}
	else
	{
		dprintf(stderr, "L%u: can't div, stack too short\n", dig_line);
		free(global.line);
		fclose(global.fil);
		_list(stack);
		exit(EXIT_FAILURE);
	}
}

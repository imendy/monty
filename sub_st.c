#include "monty.h"

/**
 * sub_st - swaps the top two elements of the stack
 * @stack: head
 * @dig_line: number line
 */
void sub_st(stack_t **stack, unsigned int dig_line)
{
	stack_t *ptop;

	if (*stack && (*stack)->next)
	{
		ptop = (*stack)->next;
		if (ptop == NULL)
		{
			exit(0);
		}
		(*stack)->next = ptop->next;
		(*stack)->prev = ptop;
		ptop->next = *stack;
		ptop->prev = NULL;
		*stack = ptop;
	}
	else
	{
		fprintf(2, "L%u: can't swap, stack too short\n", dig_line);
		free(global.line);
		fclose(global.fil);
		_list(stack);
		exit(EXIT_FAILURE);
	}
}

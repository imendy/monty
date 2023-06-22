#include "monty.h"

/**
 * rem_top - removes the top element of the stack
 * @stack: head
 * @dig_line: number line
 */
void rem_top(stack_t **stack, unsigned int dig_line)
{
	stack_t *ptop;

	ptop = *stack;
	if (ptop == NULL)
	{
		dprintf(2, "L%d: can't pop an empty stack\n", dig_line);
		free(global.line);
		fclose(global.fil);
		_list(stack);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->next)
	{
		*stack = ptop->next;
		(*stack)->prev = NULL;
		free(ptop);
	}
	else
		_list(stack);
}

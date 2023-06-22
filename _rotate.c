#include "monty.h"
/**
 * _rotate - rotates the stack to the top.
 * @stack: head
 * @dig_line: num line
 */

void _rotate(stack_t **stack, unsigned int dig_line)
{
	stack_t *ptop;
	stack_t *ptop2;

	if (*stack && (*stack)->next)
	{
		ptop = *stack;
		ptop2 = ptop;
		*stack = ptop->next;
		(*stack)->prev = NULL;
		if (dig_line)
			while (ptop2->next)
			{
				ptop2 = ptop2->next;
			}
		ptop2->next = ptop;
		ptop->prev = ptop2;
		ptop->next = NULL;
	}
}

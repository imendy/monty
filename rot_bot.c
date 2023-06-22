#include "monty.h"
/**
 * rot_bot - rotates the stack to the bottom
 * @stack: head
 * @dig_line: num line
 */

void rot_bot(stack_t **stack, unsigned int dig_line)
{
	stack_t *ptop2;

	if (*stack && (*stack)->next)
	{
		ptop2 = *stack;
		if (dig_line)
			while (ptop2->next)
			{
				ptop2 = ptop2->next;
			}
		ptop2->next = *stack;
		ptop2->prev->next = NULL;
		ptop2->prev = NULL;
		*stack = ptop2;
	}
}

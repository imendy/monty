#include "monty.h"

/**
 * _end - pushes an element to the stack
 * @stack: head
 * @dig_line: number line
 */
void _end(stack_t **stack, unsigned int dig_line)
{
	stack_t *ptop;

	_affirm(stack, dig_line);
	if (global.token)
	{
		ptop = malloc(sizeof(stack_t));
		if (ptop == NULL)
		{
			fputs("Error: malloc failed\n", stderr);
			exit(EXIT_FAILURE);
		}
		ptop->n = global.num, ptop->next = NULL;
		ptop->prev = NULL;
		if (*stack)
		{
			if (global.flag == 1)
			{
				ptop->next = *stack;
				(*stack)->prev = ptop;
				*stack = ptop;
			}
			else
			{
				while ((*stack)->next)
					*stack = (*stack)->next;
				(*stack)->next = ptop, ptop->prev = *stack;
				while ((*stack)->prev)
					*stack = (*stack)->prev;
			}
		}
		else
			*stack = ptop;
	}
	else
	{
		free(global.line), fclose(global.fil);
		dprintf(2, "L%u: usage: push integer\n", dig_line);
		_list(stack);
		exit(EXIT_FAILURE);
	}
}

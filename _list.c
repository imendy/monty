#include "monty.h"
/**
 * _list - free list
 * @stack: head
 */
void _list(stack_t **stack)
{
	stack_t *delete = *stack;

	while (*stack)
	{
		delete = delete->next;
		free(*stack);
		*stack = delete;
	}
}

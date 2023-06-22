#include "monty.h"

/**
 * _print - prints all the values on the stack,
 * starting from the top of the stack
 * @stack: head
 * @dig_line: num linea
 */
void _print(stack_t **stack, unsigned int dig_line)
{
	stack_t *ptop;

	ptop = *stack;
	if (dig_line)
		while (ptop)
		{
			printf("%d\n", ptop->n);
			ptop = ptop->next;
		}
}

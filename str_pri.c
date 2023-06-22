#include "monty.h"

/**
 * str_pri - prints the string starting at the top of the stack
 * @stack: head
 * @dig_line: num line
 */
void str_pri(stack_t **stack, unsigned int dig_line)
{
	stack_t *ptop;

	ptop = *stack;
	if (dig_line)
		while (ptop && ptop->n != 0 && ptop->n > 0 && ptop->n < 128)
		{
			printf("%c", ptop->n);
			ptop = ptop->next;
		}
	printf("\n");
}

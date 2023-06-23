#include "monty.h"
/**
 * _top - prints the value at the top of the stack
 * @stack: head
 * @dig_line: num line
 */
void _top(stack_t **stack, unsigned int dig_line)
{
	stack_t *ptop;

	ptop = *stack;
	if (ptop == NULL)
	{
		free(global.line);
		fclose(global.fil);
		_list(stack);
		fprintf(2, "L%u: can't pint, stack empty\n", dig_line);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", ptop->n);
}

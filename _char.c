#include "monty.h"
/**
 * _char - prints the char at the top of the stack, followed by a new line
 * @stack: head
 * @dig_line: integer
 */

void _char(stack_t **stack, unsigned int dig_line)
{
	stack_t *ptop;

	ptop = *stack;
	if (ptop == NULL)
	{
		free(global.line);
		fclose(global.fil);
		_list(stack);
		fprintf(2, "L%u: can't pchar, stack empty\n", dig_line);
		exit(EXIT_FAILURE);
	}
	if (ptop->n >= 128 || ptop->n < 0)
	{
		free(global.line);
		fclose(global.fil);
		_list(stack);
		fprintf(2, "L%d: can't pchar, value out of range\n", dig_line);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", ptop->n);
}

#include "monty.h"

/**
 * _mistake - manage the error
 * @stack: head
 * @bc: integer
 */
void _mistake(stack_t **stack, unsigned int bc)
{
	fprintf(stderr, "L%u: unknown instruction %s\n", bc, global.line);
	free(global.line);
	fclose(global.fil);
	_list(stack);
	if (stack)
	{
	}
	exit(EXIT_FAILURE);
}

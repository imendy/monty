#include "monty.h"
/**
 * _affirm - confirm two function
 * @stack: head
 * @con: integer
 */
void _affirm(stack_t **stack, unsigned int con)
{
	if (_confirm(global.token) == 0)
		global.num = atoi(global.token);
	else
	{
		fprintf(stderr, "L%u: usage: push integer\n", con);
		_list(stack);
		free(global.line);
		fclose(global.fil);
		exit(EXIT_FAILURE);
	}
}

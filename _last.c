#include "monty.h"
/**
 * _last - sets the format of the data to a stack (LIFO)
 * @stack: head
 * @dig_line: num line
 */

void _last(stack_t **stack, unsigned int dig_line)
{
	if (stack || dig_line)
		global.flag = 1;
}

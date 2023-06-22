#include "monty.h"
/**
 * _first - sets the format of the data to a queue (FIFO)
 * @stack: head
 * @dig_line: num line
 */

void _first(stack_t **stack, unsigned int dig_line)
{
	if (stack || dig_line)
		global.flag = 0;
}

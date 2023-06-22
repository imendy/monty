#include "monty.h"

/**
 * _length - size of the line
 * @line: line to read
 * Return: line
 */
int _length(char *line)
{
	unsigned int bc = 0;

	while (line[bc])
	{
		bc++;
	}
	return (bc);
}

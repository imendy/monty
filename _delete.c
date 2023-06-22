#include "monty.h"

/**
 * _delete - remove line
 * @line: line
 * Return: line
 */
char _delete(char *line)
{
	int lit = _length(line);

	line[lit - 1] = '\0';
	return (*line);
}

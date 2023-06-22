#include "monty.h"

/**
 * func - pointers to functions
 * @tokens: arguments
 * Return: function
 */

void (*func(char *tokens))(stack_t **stack, unsigned int dig_line)
{
	instruction_t ops[] = {
		{"push", _end},
		{"pall", _print},
		{"pint", _top},
		{"pop", rem_top},
		{"swap", sub_st},
		{"add", _plus},
		{"nop", _nothing},
		{"sub", _replace},
		{"div", _sep},
		{"mul", _sec},
		{"mod", _compute},
		{"pchar", _char},
		{"pstr", str_pri},
		{"rotl", _rotate},
		{"rotr", rot_bot},
		{"stack", _last},
		{"queue", _first},
		{"err", _mistake},
		{"#", _nothing},
		{NULL, NULL}};
	int j = 0;
	int pec;

	while (j < 19)
	{
		pec = strcmp(ops[j].opcode, tokens);
		if (pec == 0)
			return (ops[j].f);
		j++;
	}

	return (ops[17].f);
}

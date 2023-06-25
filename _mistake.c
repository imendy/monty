#include "monty.h"

/**
 * _mistake - error messages determined by their error code.
 * @error_code: The error codes are the following:
 * (1) => The user does not give any file or more than one file to the program.
 * (2) => The file provided is not a file that can be opened or read.
 * (3) => The file provided contains an invalid instruction.
 * (4) => When the program is unable to malloc more memory.
 * (5) => When the parameter passed to the instruction "push" is not an int.
 * (6) => When the stack empties for pint.
 * (7) => When the stack empities for pop.
 * (8) => When stack is too short for operation.
 */
void _mistake(int error_code, ...)
{
	va_list ca;
	char *tl;
	int num_li;

	va_start(ca, error_code);
	switch (error_code)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(ca, char *));
			break;
		case 3:
			num_li = va_arg(ca, int);
			tl = va_arg(ca, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", num_li, tl);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(ca, int));
			break;
		default:
			break;
	}
	release_nod();
	exit(EXIT_FAILURE);
}

/**
 * mistake_more - handles errors.
 * @error_code: The error codes are the following:
 * (6) => When the stack it empty for pint.
 * (7) => When the stack it empty for pop.
 * (8) => When stack is too short for operation.
 * (9) => Division by zero.
 */
void mistake_more(int error_code, ...)
{
	va_list ca;
	char *tl;
	int num_li;

	va_start(ca, error_code);
	switch (error_code)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(ca, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(ca, int));
			break;
		case 8:
			num_li = va_arg(ca, unsigned int);
			tl = va_arg(ca, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", num_li, tl);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(ca, unsigned int));
			break;
		default:
			break;
	}
	release_nod();
	exit(EXIT_FAILURE);
}

/**
 * mistake_str - handles errors.
 * @error_code: The error codes are the following:
 * (10) ~> The number inside a node is outside ASCII bounds.
 * (11) ~> The stack is empty.
 */
void mistake_str(int error_code, ...)
{
	va_list ca;
	int num_li;

	va_start(ca, error_code);
	num_li = va_arg(ca, int);
	switch (error_code)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", num_li);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", num_li);
			break;
		default:
			break;
	}
	release_nod();
	exit(EXIT_FAILURE);
}

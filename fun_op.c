#include "monty.h"

/**
 * times_nod - Adds the top two elements of the stack.
 * @ptr_stack: Ptr to a ptr pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void times_nod(stack_t **ptr_stack, unsigned int line_number)
{
	int sum;

	if (ptr_stack == NULL || *ptr_stack == NULL || (*ptr_stack)->next == NULL)
		mistake_more(8, line_number, "mul");

	(*ptr_stack) = (*ptr_stack)->next;
	sum = (*ptr_stack)->n * (*ptr_stack)->prev->n;
	(*ptr_stack)->n = sum;
	free((*ptr_stack)->prev);
	(*ptr_stack)->prev = NULL;
}


/**
 * per_nod - Adds the top two elements of the stack.
 * @ptr_stack: Ptr to a ptr pointing to the top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void per_nod(stack_t **ptr_stack, unsigned int line_number)
{
	int sum;

	if (ptr_stack == NULL || *ptr_stack == NULL || (*ptr_stack)->next == NULL)

		mistake_more(8, line_number, "mod");


	if ((*ptr_stack)->n == 0)
		mistake_more(9, line_number);
	(*ptr_stack) = (*ptr_stack)->next;
	sum = (*ptr_stack)->n % (*ptr_stack)->prev->n;
	(*ptr_stack)->n = sum;
	free((*ptr_stack)->prev);
	(*ptr_stack)->prev = NULL;
}

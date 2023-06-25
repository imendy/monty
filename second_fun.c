#include "monty.h"

/**
 * _nothing - Does nothing.
 * @ptr_stack: Ptr to a ptr pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void _nothing(stack_t **ptr_stack, unsigned int line_number)
{
	(void)ptr_stack;
	(void)line_number;
}


/**
 * nod_replace - Swaps the top two elements of the stack.
 * @ptr_stack: Ptr to a ptr pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void nod_replace(stack_t **ptr_stack, unsigned int line_number)
{
	stack_t *t;

	if (ptr_stack == NULL || *ptr_stack == NULL || (*ptr_stack)->next == NULL)
		mistake_more(8, line_number, "swap");
	t = (*ptr_stack)->next;
	(*ptr_stack)->next = t->next;
	if (t->next != NULL)
		t->next->prev = *ptr_stack;
	t->next = *ptr_stack;
	(*ptr_stack)->prev = t;
	t->prev = NULL;
	*ptr_stack = t;
}

/**
 * plus_nod - Adds the top two elements of the stack.
 * @ptr_stack: Ptr to a ptr pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void plus_nod(stack_t **ptr_stack, unsigned int line_number)
{
	int sum;

	if (ptr_stack == NULL || *ptr_stack == NULL || (*ptr_stack)->next == NULL)
		mistake_more(8, line_number, "add");

	(*ptr_stack) = (*ptr_stack)->next;
	sum = (*ptr_stack)->n + (*ptr_stack)->prev->n;
	(*ptr_stack)->n = sum;
	free((*ptr_stack)->prev);
	(*ptr_stack)->prev = NULL;
}


/**
 * remove_nod - Adds the top two elements of the stack.
 * @ptr_stack: Ptr to a ptr pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void remove_nod(stack_t **ptr_stack, unsigned int line_number)
{
	int sum;

	if (ptr_stack == NULL || *ptr_stack == NULL || (*ptr_stack)->next == NULL)

		mistake_more(8, line_number, "sub");


	(*ptr_stack) = (*ptr_stack)->next;
	sum = (*ptr_stack)->n - (*ptr_stack)->prev->n;
	(*ptr_stack)->n = sum;
	free((*ptr_stack)->prev);
	(*ptr_stack)->prev = NULL;
}


/**
 * cut_nod - Adds the top two elements of the stack.
 * @ptr_stack: Ptr to a ptr pointing to the top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void cut_nod(stack_t **ptr_stack, unsigned int line_number)
{
	int sum;

	if (ptr_stack == NULL || *ptr_stack == NULL || (*ptr_stack)->next == NULL)
		mistake_more(8, line_number, "div");

	if ((*ptr_stack)->n == 0)
		mistake_more(9, line_number);
	(*ptr_stack) = (*ptr_stack)->next;
	sum = (*ptr_stack)->n / (*ptr_stack)->prev->n;
	(*ptr_stack)->n = sum;
	free((*ptr_stack)->prev);
	(*ptr_stack)->prev = NULL;
}

#include "monty.h"


/**
 * put_stack - for adding a node to the stack
 * @nod_new: Pointer to the new node.
 * @ln: Interger representing the line number of of the opcode.
 */
void put_stack(stack_t **nod_new, __attribute__((unused))unsigned int ln)
{
	stack_t *t;

	if (nod_new == NULL || *nod_new == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *nod_new;
		return;
	}
	t = head;
	head = *nod_new;
	head->next = t;
	t->prev = head;
}


/**
 * make_stack - Adds a node to the stack.
 * @ptr_stack: Ptr to a ptr pointing to top node of the stack.
 * @line_number: line number of  the opcode.
 */
void make_stack(stack_t **ptr_stack, unsigned int line_number)
{
	stack_t *t;

	(void) line_number;
	if (ptr_stack == NULL)
		exit(EXIT_FAILURE);
	t = *ptr_stack;
	while (t != NULL)
	{
		printf("%d\n", t->n);
		t = t->next;
	}
}

/**
 * tp_out - Adds a node to the stack.
 * @ptr_stack: Ptr to a ptr pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void tp_out(stack_t **ptr_stack, unsigned int line_number)
{
	stack_t *t;

	if (ptr_stack == NULL || *ptr_stack == NULL)
		mistake_more(7, line_number);

	t = *ptr_stack;
	*ptr_stack = t->next;
	if (*ptr_stack != NULL)
		(*ptr_stack)->prev = NULL;
	free(t);
}

/**
 * make_tp - Prints the top node of the stack.
 * @ptr_stack: Ptr to a ptr pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void make_tp(stack_t **ptr_stack, unsigned int line_number)
{
	if (ptr_stack == NULL || *ptr_stack == NULL)
		mistake_more(6, line_number);
	printf("%d\n", (*ptr_stack)->n);
}

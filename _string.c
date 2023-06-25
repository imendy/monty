#include "monty.h"

/**
 * bring_char - Prints the Ascii value.
 * @ptr_stack: Ptr to a ptr pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void bring_char(stack_t **ptr_stack, unsigned int line_number)
{
	int val_ascii;

	if (ptr_stack == NULL || *ptr_stack == NULL)
		mistake_str(11, line_number);

	val_ascii = (*ptr_stack)->n;
	if (val_ascii < 0 || val_ascii > 127)
		mistake_str(10, line_number);
	printf("%c\n", val_ascii);
}

/**
 * bring_str - for printing a string.
 * @ptr_stack: Ptr to a ptr pointing to top node of the stack.
 * @ln: Interger representing the line number of of the opcode.
 */
void bring_str(stack_t **ptr_stack, __attribute__((unused))unsigned int ln)
{
	int val_ascii;
	stack_t *t;

	if (ptr_stack == NULL || *ptr_stack == NULL)
	{
		printf("\n");
		return;
	}

	t = *ptr_stack;
	while (t != NULL)
	{
		val_ascii = t->n;
		if (val_ascii <= 0 || val_ascii > 127)
			break;
		printf("%c", val_ascii);
		t = t->next;
	}
	printf("\n");
}

/**
 * _rotate - Rotates the first node of the stack to the bottom.
 * @ptr_stack: Ptr to a ptr pointing to top node of the stack.
 * @ln: Interger representing the line number of of the opcode.
 */
void _rotate(stack_t **ptr_stack, __attribute__((unused))unsigned int ln)
{
	stack_t *t;

	if (ptr_stack == NULL || *ptr_stack == NULL || (*ptr_stack)->next == NULL)
		return;

	t = *ptr_stack;
	while (t->next != NULL)
		t = t->next;

	t->next = *ptr_stack;
	(*ptr_stack)->prev = t;
	*ptr_stack = (*ptr_stack)->next;
	(*ptr_stack)->prev->next = NULL;
	(*ptr_stack)->prev = NULL;
}


/**
 * rot_bot - Rotates the last node of the stack to the top.
 * @ptr_stack: Ptr to a ptr pointing to top node of the stack.
 * @ln: Interger representing the line number of of the opcode.
 */
void rot_bot(stack_t **ptr_stack, __attribute__((unused))unsigned int ln)
{
	stack_t *t;

	if (ptr_stack == NULL || *ptr_stack == NULL || (*ptr_stack)->next == NULL)
		return;

	t = *ptr_stack;

	while (t->next != NULL)
		t = t->next;

	t->next = *ptr_stack;
	t->prev->next = NULL;
	t->prev = NULL;
	(*ptr_stack)->prev = t;
	(*ptr_stack) = t;
}

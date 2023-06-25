#include "monty.h"
stack_t *head = NULL;

/**
 * main - the function is the program's main entry point
 * @argc: arguments count
 * @argv: list of arguments
 * Return: always 0
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file_wide(argv[1]);
	release_nod();
	return (0);
}

/**
 * make_nod - Creates a node.
 * @n: Number to go inside the node.
 * Return: Upon sucess a pointer to the node. Otherwise NULL.
 */
stack_t *make_nod(int n)
{
	stack_t *ptr;

	ptr = malloc(sizeof(stack_t));
	if (ptr == NULL)
		_mistake(4);
	ptr->next = NULL;
	ptr->prev = NULL;
	ptr->n = n;
	return (ptr);
}

/**
 * release_nod - Frees nodes in the stack.
 */
void release_nod(void)
{
	stack_t *t;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		t = head;
		head = head->next;
		free(t);
	}
}


/**
 * put_queue - Adds a node to the queue.
 * @nod_new: Pointer to the new node.
 * @ln: line number of the opcode.
 */
void put_queue(stack_t **nod_new, __attribute__((unused))unsigned int ln)
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
	while (t->next != NULL)
		t = t->next;

	t->next = *nod_new;
	(*nod_new)->prev = t;

}

#include "monty.h"

/**
 * file_wide - opens a file
 * @file_name: the file namepath
 * Return: void
 */

void file_wide(char *file_name)
{
	FILE *pf = fopen(file_name, "r");

	if (file_name == NULL || pf == NULL)
		_mistake(2, file_name);

	_reader(pf);
	fclose(pf);
}


/**
 * _reader - reads a file
 * @pf: pointer to file descriptor
 * Return: void
 */

void _reader(FILE *pf)
{
	int line_number, format = 0;
	char *buffer = NULL;
	size_t len = 0;

	for (line_number = 1; getline(&buffer, &len, pf) != -1; line_number++)
	{
		format = _liners(buffer, line_number, format);
	}
	free(buffer);
}


/**
 * _liners - Separates each line into tokens to determine
 * which function to call
 * @buffer: line from the file
 * @line_number: line number
 * @format:  storage format. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 * Return: Returns 0 if the opcode is stack. 1 if queue.
 */

int _liners(char *buffer, int line_number, int format)
{
	char *pcod, *d_val;
	const char *d_lim = "\n ";

	if (buffer == NULL)
		_mistake(4);

	pcod = strtok(buffer, d_lim);
	if (pcod == NULL)
		return (format);
	d_val = strtok(NULL, d_lim);

	if (strcmp(pcod, "stack") == 0)
		return (0);
	if (strcmp(pcod, "queue") == 0)
		return (1);

	_finders(pcod, d_val, line_number, format);
	return (format);
}

/**
 * _finders - find the appropriate function for the opcode
 * @pcod: opcode
 * @d_val: argument of opcode
 * @format:  storage format. If 0 Nodes will be entered as a stack.
 * @ln: line number
 * if 1 nodes will be entered as a queue.
 * Return: void
 */
void _finders(char *pcod, char *d_val, int ln, int format)
{
	int j;
	int flag;

	instruction_t func_list[] = {
		{"push", put_stack},
		{"pall", make_stack},
		{"pint", make_tp},
		{"pop", tp_out},
		{"nop", _nothing},
		{"swap", nod_replace},
		{"add", plus_nod},
		{"sub", remove_nod},
		{"div", cut_nod},
		{"mul", times_nod},
		{"mod", per_nod},
		{"pchar", bring_char},
		{"pstr", bring_str},
		{"rotl", _rotate},
		{"rotr", rot_bot},
		{NULL, NULL}
	};

	if (pcod[0] == '#')
		return;

	for (flag = 1, j = 0; func_list[j].opcode != NULL; j++)
	{
		if (strcmp(pcod, func_list[j].opcode) == 0)
		{
			fun_make(func_list[j].f, pcod, d_val, ln, format);
			flag = 0;
		}
	}
	if (flag == 1)
		_mistake(3, ln, pcod);
}


/**
 * fun_make - Calls the required function.
 * @func: Pointer to the function that is about to be called.
 * @op: string representing the opcode.
 * @val: the string representing a numeric value.
 * @ln: line numeber for the instruction.
 * @format: Format specifier. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 */
void fun_make(op_func func, char *op, char *val, int ln, int format)
{
	stack_t *ptr;
	int flag;
	int j;

	flag = 1;
	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			flag = -1;
		}
		if (val == NULL)
			_mistake(5, ln);
		for (j = 0; val[j] != '\0'; j++)
		{
			if (isdigit(val[j]) == 0)
				_mistake(5, ln);
		}
		ptr = make_nod(atoi(val) * flag);
		if (format == 0)
			func(&ptr, ln);
		if (format == 1)
			put_queue(&ptr, ln);
	}
	else
		func(&head, ln);
}


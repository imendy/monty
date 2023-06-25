#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);


/*These For Math Operations with Nodes*/
void plus_nod(stack_t **, unsigned int);
void remove_nod(stack_t **, unsigned int);
void cut_nod(stack_t **, unsigned int);
void times_nod(stack_t **, unsigned int);
void per_nod(stack_t **, unsigned int);

/*These For String Operations*/
void bring_char(stack_t **, unsigned int);
void bring_str(stack_t **, unsigned int);
void _rotate(stack_t **, unsigned int);

/*These For Error Handling*/
void _mistake(int error_code, ...);
void mistake_more(int error_code, ...);
void mistake_str(int error_code, ...);
void rot_bot(stack_t **, unsigned int);

/*These For Stack Operations*/
stack_t *make_nod(int n);
void release_nod(void);
void make_stack(stack_t **, unsigned int);
void put_stack(stack_t **, unsigned int);
void put_queue(stack_t **, unsigned int);

void fun_make(op_func, char *, char *, int, int);

void make_tp(stack_t **, unsigned int);
void tp_out(stack_t **, unsigned int);
void _nothing(stack_t **, unsigned int);
void nod_replace(stack_t **, unsigned int);

/*These For File Operations*/
void file_wide(char *file_name);
int _liners(char *buffer, int line_number, int format);
void _reader(FILE *);
int _length(FILE *);
void _finders(char *, char *, int, int);

#endif  /* MONTY_H */

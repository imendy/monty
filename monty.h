#ifndef MONTY_H
#define MONTY_H

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * struct globals - variables globales
 * @num: integer
 * @flag: integer
 * @line: string
 * @token: string
 * @opcod: function opcode in Monty
 * @fil: file
 */
typedef struct globals
{
int num;
int flag;
char *line;
char *token;
char *opco;
FILE *fil;
} globals_t;

extern globals_t global;
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
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
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
char *opcode;
void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void _compute(stack_t **stack, unsigned int dig_line);
void _char(stack_t **stack, unsigned int dig_line);
void rot_bot(stack_t **stack, unsigned int dig_line);
void _rotate(stack_t **stack, unsigned int dig_line);
void _last(stack_t **stack, unsigned int dig_line);
void _first(stack_t **stack, unsigned int dig_line);
void str_pri(stack_t **stack, unsigned int dig_line);
void _sec(stack_t **stack, unsigned int dig_line);
void _affirm(stack_t **stack, unsigned int n);
void _mistake(stack_t **stack, unsigned int n);
void _list(stack_t **stack);
void _sep(stack_t **stack, unsigned int dig_line);
void _replace(stack_t **stack, unsigned int dig_line);
void _nothing(stack_t **stack, unsigned int dig_line);
int _confirm(char *num);
int _length(char *line);
char _delete(char *line);
void sub_st(stack_t **stack, __attribute__((unused)) unsigned int dig_line);
void _plus(stack_t **stack, __attribute__((unused)) unsigned int dig_line);
void _top(stack_t **stack, unsigned int dig_line);
void rem_top(stack_t **stack, unsigned int dig_line);
void (*func(char *tokens))(stack_t **stack, unsigned int dig_line);
int main(__attribute__((unused)) int argc, char **argv);
void _print(stack_t **stack, unsigned int dig_line);
void _end(stack_t **stack, unsigned int dig_line);

#endif /* MONTY_H */

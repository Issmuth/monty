#ifndef MONTY_H
#define MONTY_H
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

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

/**
 * struct monty_inf - info about the script
 * @file: opened script file
 * @command: line of command
 * @args: command list
 * @state: queue or stack determiner
 *
 * Description: contains the runtime information of the
 * script
 */
typedef struct monty_inf
{
	FILE *file;
	char *opcom;
	char **args;
	int state;
} monfy;

extern monfy montinf;

void push(stack_t **top_t, unsigned int line_c);
void pall(stack_t **stack, unsigned int line_number);
char **tokenize(char *opcom, stack_t **stack);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void div_s(stack_t **stack, unsigned int line_number);
void mul_s(stack_t **stack, unsigned int line_number);
void mod_s(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);
void rotl(stack_t **stack, unsigned int line_number);
void rotr(stack_t **stack, unsigned int line_number);
void opcheck(char *opcom, unsigned int line_c, stack_t **top_t);
void free_stack(stack_t **stack);
void free_vec(char **vector);
int all_digit(char *num);
void clear_all(stack_t **stack);

#endif

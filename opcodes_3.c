#include "monty.h"

/**
 * mod_s - computes to modulus of
 * second to top
 * @stack: ...
 * @line_number: ...
 */

void mod_s(stack_t **stack, unsigned int line_number)
{
	int rem;

	if (!stack || !(*stack) || !((*stack)->next))
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		clear_all(stack);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		clear_all(stack);
		exit(EXIT_FAILURE);
	}
	rem = (*stack)->next->n % (*stack)->n;
	(*stack)->next->n = rem;
	pop(stack, line_number);
}

/**
 * pchar - prints the char at the
 * top of the stack
 * @stack: pointer to the top of the
 * stack
 * @line_number: script position
 */

void pchar(stack_t **stack, unsigned int line_number)
{
	int n;

	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		clear_all(stack);
		exit(EXIT_FAILURE);
	}
	n = (*stack)->n;
	if (n > 127 || n < 0)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		clear_all(stack);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", n);
}

/**
 * pstr - prints the string from the
 * start of the stack
 * @stack: ...
 * @line_number: ...
 */

void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *iterator = *stack;
	(void) line_number;

	if (!stack || !(*stack))
	{
		printf("\n");
		return;
	}

	while (iterator)
	{
		if (iterator->n == 0)
		{
			printf("\n");
			return;
		}

		if (iterator->n > 127 || iterator->n < 0)
		{
			printf("%c", iterator->n);
			return;
		}
		printf("%c", iterator->n);
		iterator = iterator->next;
	}
	printf("\n");
}

/**
 * rotl - rotates the stack to the top
 * @line_number: ...
 * @stack: ...
 */

void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *iterator = *stack, *temp;
	(void) line_number;

	if (!stack || !(*stack) || !((*stack)->next))
		return;

	temp = (*stack)->next;

	while (iterator->next)
		iterator = iterator->next;

	iterator->next = *stack;
	(*stack)->prev = iterator;
	temp->prev = NULL;
	(*stack)->next = NULL;
	*stack = temp;
}

/**
 * rotr - rotates the stack to the bottom
 * @line_number: ...
 * @stack: ...
 */

void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *iterator = *stack, *temp;
	(void) line_number;

	if (!stack || !(*stack) || !((*stack)->next))
		return;

	while (iterator->next)
		iterator = iterator->next;

	temp = iterator->prev;
	temp->next = NULL;
	iterator->prev = NULL;
	iterator->next = *stack;
	(*stack)->prev = iterator;
	*stack = iterator;
}

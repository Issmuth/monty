#include "monty.h"

/**
 * add - adds the top two elements
 * of the stack
 * @stack: double pointer to the top
 * @line_number: script position
 */

void add(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (!stack || !(*stack) || !((*stack)->next))
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		clear_all(stack);
		exit(EXIT_FAILURE);
	}
	sum = (*stack)->n + (*stack)->next->n;
	(*stack)->next->n = sum;
	pop(stack, line_number);
}

/**
 * nop- does nothing
 * @stack: double pointer to top
 * @line_number: script position
 */

void nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}

/**
 * sub - subtracts the top 2 elements
 * @stack: double pointer to the top
 * @line_number: script position
 */

void sub(stack_t **stack, unsigned int line_number)
{
	int dif;

	if (!stack || !(*stack) || !((*stack)->next))
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		clear_all(stack);
		exit(EXIT_FAILURE);
	}
	dif = (*stack)->next->n - (*stack)->n;
	(*stack)->next->n = dif;
	pop(stack, line_number);
}

/**
 * div_s - divides the second by top
 * @stack: ...
 * @line_number: ...
 */

void div_s(stack_t **stack, unsigned int line_number)
{
	int div;

	if (!stack || !(*stack) || !((*stack)->next))
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		clear_all(stack);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		clear_all(stack);
		exit(EXIT_FAILURE);
	}
	div = (*stack)->next->n / (*stack)->n;
	(*stack)->next->n = div;
	pop(stack, line_number);
}

/**
 * mul_s - multiplies the top two elements
 * @stack: ...
 * @line_number: ...
 */

void mul_s(stack_t **stack, unsigned int line_number)
{
	int prod;

	if (!stack || !(*stack) || !((*stack)->next))
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		clear_all(stack);
		exit(EXIT_FAILURE);
	}
	prod = (*stack)->next->n * (*stack)->n;
	(*stack)->next->n = prod;
	pop(stack, line_number);
}

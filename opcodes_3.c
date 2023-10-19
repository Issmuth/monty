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
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	rem = (*stack)->next->n % (*stack)->n;
	(*stack)->next->n = rem;
	pop(stack, line_number);
}

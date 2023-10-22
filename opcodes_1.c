#include "monty.h"

/**
 * push - pushes an element to the stack
 * @line_c: script line
 * @top_t: top of the stack
 *
 * Return: 0 if successful 1 otherwise
 */

void push(stack_t **top_t, unsigned int line_c)
{
	stack_t *new_stack;
	int n;

	if (!(montinf.args) || !(montinf.args[1]) || !all_digit(montinf.args[1]))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_c);
		clear_all(top_t);
		exit(EXIT_FAILURE);
	}

	new_stack = malloc(sizeof(stack_t));
	if (!new_stack)
	{
		fprintf(stderr, "Error: malloc failed\n");
		clear_all(top_t);
		exit(EXIT_FAILURE);
	}
	n = atoi(montinf.args[1]);
	new_stack->n = n;
	new_stack->prev = NULL;
	if (!top_t || !(*top_t))
	{
		new_stack->next = NULL;
		*top_t = new_stack;
		return;
	}
	(*top_t)->prev = new_stack;
	new_stack->next = *top_t;
	*top_t = new_stack;
}

/**
 * pall - prints all elements of the stack
 * @stack: ...
 * @line_number: ...
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *iterator = *stack;

	(void) line_number;
	if (stack == NULL || *stack == NULL)
		return;

	while (iterator)
	{
		printf("%d\n", iterator->n);
		iterator = iterator->next;
	}
}

/**
 * pint - prints the top element of the stack
 * @line_number: script line
 * @stack: ...
 */

void pint(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		clear_all(stack);
		exit(EXIT_FAILURE);
	} else
		printf("%d\n", (*stack)->n);
}

/**
 * pop - removes top element
 * @line_number: script line
 * @stack: ...
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		clear_all(stack);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = temp->next;
	if (*stack)
		(*stack)->prev = NULL;
	free(temp);
}

/**
 * swap - swaps the top two elements of the stack
 * @stack: double pointer to top of the stack
 * @line_number: opcodes line number in script
 */

void swap(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (!stack || !(*stack) || !((*stack)->next))
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		clear_all(stack);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}

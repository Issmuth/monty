#include "monty.h"

/**
 * all_digit - check if a string if
 * is all digits
 * @num: string checked
 *
 * Return: 1 if all are digit 0 otherwise
 */

int all_digit(char *num)
{
	int i;

	for (i = 0; num[i]; i++)
	{
		if (i == 0 && num[i] == '-')
			continue;

		if (!(isdigit(num[i])))
			return (0);
	}
	return (1);
}

/**
 * free_vec - frees vector
 * @vector: double pointer to the vector
 */

void free_vec(char **vector)
{
	int i = 0;

	if (!vector)
		return;

	while (vector[i])
	{
		free(vector[i]);
		i++;
	}
	free(vector);
}

/**
 * free_stack - frees the stack
 * @stack: double pointer to the top
 * of the stack
 */

void free_stack(stack_t **stack)
{
	stack_t *iterator = *stack, *temp;

	while (iterator)
	{
		temp = iterator->next;
		free(iterator);
		iterator = temp;
	}
}

/**
 * clear_all - frees all allocated memory
 * and closes open files
 * @stack: stack to free
 */

void clear_all(stack_t **stack)
{
	if (montinf.opcom)
		free(montinf.opcom);

	if (montinf.args)
		free_vec(montinf.args);

	if (stack)
		free_stack(stack);

	fclose(montinf.file);
}

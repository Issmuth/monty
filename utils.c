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
		if (num[0] == '-')
			continue;

		if (!(isdigit(num[i])))
			return (0);
	}
	return (1);
}

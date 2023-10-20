#include "monty.h"

/**
 * tokenize - tokenize the opcode
 * @opcom: operation command
 *
 * Return: pointer to pointer of
 * tokenized command
 */

char **tokenize(char *opcom)
{
	int i = 0, j = 0;
	char *token = NULL,  *dupcom;
	char *delim = " \t\n$", **args;

	dupcom = malloc(sizeof(char) * (strlen(opcom) + 1));
	if (dupcom == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(opcom);
		exit(EXIT_FAILURE);
	}
	strcpy(dupcom, opcom);
	token = strtok(opcom, delim);
	while (token)
	{
		token = strtok(NULL, delim);
		i++;
	}
	args = malloc(sizeof(char *) * (i + 1));
	if (args == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	token = strtok(dupcom, delim);
	while (token)
	{
		args[j] = malloc(sizeof(char) * (strlen(token) + 1));
		if (args[j] == NULL)
		{
			fprintf(stderr, "Error: malloc failed\n");
			exit(EXIT_FAILURE);
		}
		strcpy(args[j], token);
		token = strtok(NULL, delim);
		j++;
	}
	args[j] = NULL;
	free(dupcom);
	return (args);
}

/**
 * opcheck - checks if command is a
 * monty operation
 * @opcom: operation command
 * @top_t: top of the stack
 * @line_c: line count
 */

void opcheck(char *opcom, unsigned int line_c, stack_t **top_t)
{
	int i = 0;
	char **args = NULL;
	instruction_t list[] = {
	{"pall", pall}, {"pint", pint},
	{"pop", pop}, {"swap", swap},
	{"add", add}, {"nop", nop},
	{"sub", sub}, {"div", div_s},
	{"mul", mul_s}, {"mod", mod_s},
	{NULL, NULL}
	};

	args = tokenize(opcom);
	if (args == NULL || args[0] == NULL)
		return;
	if (args[0][0] == '#')
		return;
	if (!(strcmp("push", args[0])))
	{
		push(top_t, args[1], line_c);
		return;
	}
	for (i = 0; list[i].opcode; i++)
	{
		if (!(strcmp(list[i].opcode, args[0])))
		{
			list[i].f(top_t, line_c);
			return;
		}
	}
	fprintf(stderr, "L%u: unknown instruction %s\n", line_c, args[0]);
	free(opcom);
	exit(EXIT_FAILURE);
}

#include "monty.h"

/**
 * tokenize - tokenize the opcode
 * @opcom: operation command
 *
 * Return: pointer to pointer of
 * tokenized command
 */

char **tokenize(char *opcom, stack_t **stack)
{
	int i = 0, j = 0;
	char *token = NULL,  *dupcom;
	char *delim = " \t\n$", **args;

	dupcom = malloc(sizeof(char) * (strlen(opcom) + 1));
	if (dupcom == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		clear_all(stack);	
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
		clear_all(stack);
		free(dupcom);
		exit(EXIT_FAILURE);
	}
	token = strtok(dupcom, delim);
	while (token)
	{
		args[j] = malloc(sizeof(char) * (strlen(token) + 1));
		if (args[j] == NULL)
		{
			fprintf(stderr, "Error: malloc failed\n");
			clear_all(stack);
			free(dupcom);
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
	instruction_t list[] = {
	{"pall", pall}, {"pint", pint},
	{"pop", pop}, {"swap", swap},
	{"add", add}, {"nop", nop},
	{"sub", sub}, {"div", div_s},
	{"mul", mul_s}, {"mod", mod_s},
	{"pchar", pchar}, {"pstr", pstr},
	{"rotl", rotl}, {"rotr", rotr},
	{NULL, NULL}
	};

	montinf.args = tokenize(opcom, top_t);
	if (montinf.args == NULL || montinf.args[0] == NULL)
		return;
	if (montinf.args[0][0] == '#')
		return;
	if (!(strcmp("push", montinf.args[0])))
	{
		push(top_t, line_c);
		return;
	}
	for (i = 0; list[i].opcode; i++)
	{
		if (!(strcmp(list[i].opcode, montinf.args[0])))
		{
			list[i].f(top_t, line_c);
			return;
		}
	}
	fprintf(stderr, "L%u: unknown instruction %s\n", line_c, montinf.args[0]);
	clear_all(top_t);
	exit(EXIT_FAILURE);
}

#include "monty.h"


/**
 * main - point of begininning
 * @argc: argument count
 * @argv: list of arguments
 *
 * Return: Always Success (0)
 */


int main(int argc, char **argv)
{
	char *line = NULL;
	size_t len = 0;
	unsigned int line_c = 1;
	stack_t *top_t = NULL;
	FILE *file;

	if (argc != 2)
	{
		write(STDERR_FILENO, "USAGE: monty file\n", 17);
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&line, &len, file) != EOF)
	{
		opcheck(line, line_c, &top_t);
		line_c++;
	}
	fclose(file);
	free(line);
	return (0);
}

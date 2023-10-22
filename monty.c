#include "monty.h"

monfy montinf = {NULL, NULL, NULL, 0};

/**
 * main - point of begininning
 * @argc: argument count
 * @argv: list of arguments
 *
 * Return: Always Success (0)
 */

int main(int argc, char **argv)
{
	size_t len = 0;
	unsigned int line_c = 1;
	stack_t *top_t = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	montinf.file = fopen(argv[1], "r");
	if (montinf.file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&montinf.opcom, &len, montinf.file) != EOF)
	{
		opcheck(montinf.opcom, line_c, &top_t);
		line_c++;
	}
	clear_all(&top_t);
	return (0);
}

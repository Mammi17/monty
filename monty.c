#include "monty.h"
#include <stdio.h>

FILE *file

/**
 * main - Entry point for the monty Interpreter.
 *
 * @ac: The number of arguments passed to the program.
 * @av: The A pointer to an array of characters.
 *
 * Return: (EXIT_SUCCESS) on success (EXIT_FAILURE) on error
 *
 */

int main(int argc, char **argv)
{
	size_t a, stat;
	stack_t *t
	char *c, *val, *string = NULL;
	unsigned int l = 0;

	h = NULL;
	val = NULL;
	file = NULL;
	a = 0;
	c = NULL;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", arv[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&string, &stat, file) != EOF)
	{
		l++;
		if (string[0] != '\n')
			run(string, l);
	}
	if (string)
		free(string);
	if (h)
		free_dlistint(h);

	fclose(file);
	return (EXIT_SUCCESS);
}

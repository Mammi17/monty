#include "monty.h"
#include <stdio.h>

/**
 * main - Entry point for the monty Interpreter.
 * @argc: The number of arguments passed to the program.
 * @argv: The A pointer to an array of characters.
 * Return: (EXIT_SUCCESS) or (EXIT_FAILURE)
 */

int main(int argc, char **argv)
{
	size_t stat;
	char *string = NULL;
	unsigned int l = 0;

	(ensemble.h) = NULL;
	(ensemble.val) = NULL;
	(ensemble.file) = NULL;
	(ensemble.a) = 0;
	(ensemble.c) = NULL;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	(ensemble.file) = fopen(argv[1], "r");
	if ((ensemble.file) == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", arv[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&string, &stat, (ensemble.file)) != EOF)
	{
		l++;
		if (string[0] != '\n')
			run(string, l);
	}
	if (string)
		free(string);
	if (h)
		free_dlistint((ensemble.h));

	fclose((ensemble.file));
	return (EXIT_SUCCESS);
}

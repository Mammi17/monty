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

	(ens.h) = NULL;
	(ens.val) = NULL;
	(ens.file) = NULL;
	(ens.a) = 0;
	(ens.c) = NULL;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	(ens.file) = fopen(argv[1], "r");
	if ((ens.file) == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&string, &stat, (ens.file)) != EOF)
	{
		l++;
		if (string[0] != '\n')
			run(string, l);
	}
	if (string)
		free(string);
	if (ens.h)
		free_dlistint(ens.h);

	fclose(ens.file);
	return (EXIT_SUCCESS);
}

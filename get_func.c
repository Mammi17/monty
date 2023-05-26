#include "monty.h"
#include <stdio.h>
/**
 * ob_funct - Maps functions to the corresponding opcode
 * @opcod: The opcode from the instruction.
 * Return: A pointer to the function.
 */

void (*ob_funct(char *opcod))(stack_t **, unsigned int)
{
	int a = 0;

	instruction_t opera[] = {
		{"push", pusher},
		{"pall", pallium},
		{"pint", pinte},
		{"pop", popu},
		{"swap", swaps},
		{"add", addi},
		{"nop", nop},
		{"sub", subtract},
		{"div", divi},
		{"mul", mult},
		{"mod", modu},
		{"pchar", prchar},
		{"pstr", pstring},
		{"rotl", rotal},
		{"rotr", rotar},
		{"queue", queue},
		{"stack", stack},
		{NULL, NULL}
	};

	while (opera[a].opcode)
	{
		if (strcmp(opcod, opera[a].opcode) == 0)
			return (opera[a].f);
		a++;
	}
	return (NULL);
}

/**
 * run - execute the opcode command
 * @string: The line instruction read from the given file.
 * @l: The line number.
 * Return: void
 */

void run(char *string, unsigned int l)
{
        void (*f)(stack_t **, unsigned int);

        (ensemble.c) = strtok(string, " \r\t\n");
        if (ensemble.c[0] != '#' && ensemble.c)
        {
                f = ob_funct(ensemble.c);
                if (f != NULL)
                {
                        if (strcmp(ensemble.c, "push") == 0)
                                (ensemble.val) = strtok(NULL, " \r\t\n");
                        f(&(ensemble.h), l);
                }
                else
                {
                        fprintf(stderr, "L%u: unknown instruction %s\n", l, (ensemble.c));
                        if (string)
                                free(string);
                        if ((ensemble.h))
                                free_dlistint((ensemble.h));
                        exit(EXIT_FAILURE);
                }
        }
}

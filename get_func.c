/**
 * get_func - Maps functions to the corresponding opcode.
 *
 * @opcode: The opcode from the instruction.
 *
 * Return: A pointer to the function.
 */

void (*ob_funct(char *opcod))(stack_t**, unsigned int)
{
	int a = 0;

	instruction_t opera[] = {
		{"push", pusher},
		{"pall", pallium},
		{"pint", pinte},
		{"pop", popu},
		{"swap", swaps},
		{"add", add},
		{"nop", nop},
		{"sub", subtract},
		{"div", div},
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

	while (opera[a].opcod)
	{
		if (strcmp(opcod, opera[a].opcod) == 0)
			return (opera[a].f);
		a++;
	}

	return (NULL);

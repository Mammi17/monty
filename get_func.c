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
		{"pusher", push},
		{"pallium", pall},
		{"pinte", pint},
		{"popu", pop},
		{"swaps", swap},
		{"add", add},
		{"nop", nop},
		{"subtract", sub},
		{"div", divt},
		{"mult", mul},
		{"modu", mod},
		{"prchar", pchar},
		{"pstring", pstr},
		{"rotal", rotl},
		{"rotar", rotr},
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

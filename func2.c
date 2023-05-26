#include <stdio.h>
#include "monty.h"
/**
 * modu - computes the rest of the division of the second top
 * element of the stack by the top element of the stack.
 * @stak: A double pointer to the beginning of the stack
 * @l: The line number.
 * Return: void
 */
void modu(stack_t **stak, unsigned int l)
{
	int a;
	stack_t *point = *stack;
	int longueur = dlistint_len(*stak);

	if (longueur < 2)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", l);
		exit(EXIT_FAILURE);
	}
	if (point->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", l);
		exit(EXIT_FAILURE);
	}
	a = (point->next->n) % (point->n);
	point->next->n = a;
	point->next->prev = NULL;
	*stak = point->next;
	free(point);
}

/**
 * prchar - prints the char at the top of the stack
 * @stak: A double pointer to the begining of the stack
 * @l: The line number.
 * Return: void
 */

void prchar(stack_t **stak, unsigned int l)
{
	if (!(*stak))
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", l);
		exit(EXIT_FAILURE);
	}
	if ((*stak)->n > 127 || (*stak)->n < 0)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", l);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", (*stak)->n);
}

/**
 * pstring - prints the string starting at the top of the stack,
 * @stak: A double pointer to the begining of the stack
 * @l: The line number,who void.
 * Return: void
 */

void pstring(stack_t **stak, unsigned int l)
{
	stack_t *trav = *stak;

	(void)l;

	while (trav->n < 127 &&  trav->n > 0 && trav)
	{
		printf("%c", trav->n);
		trav = trav->next;
	}
	putchar('\n');
}

/**
 * rotal -  Rotates the stack to the top
 * @stak: A double pointer to the begining of the stack
 * @line_number: The line number, who void
 * Return: void
 */

void rotal(stack_t **stak, unsigned int l)
{
	stack_t *point;

	(void)l;
	if (*stack == NULL || (*stack)->next == NULL)
		return;

	point = *stack;
	*stak = point->next;
	(*stak)->prev = NULL;
	add_dnodeint_end(stak, point->n);
	free(point);
}

/**
 * rotar -  Rotates the stack to the bottom
 * @stak: A double pointer to the begining of the stack
 * @l: The line number.
 * Return: void
 */

void rotar(stack_t **stak, unsigned int l)
{
	stack_t *point;

	(void)l;
	if ((*stak)->next == NULL || (*stak) == NULL)
		return;
	point = get_dnodeint_at_index(*stak,  dlistint_len(*stak) - 1);
	add_dnodeint(stak, point->n);
	delete_dnodeint_at_index(stak, dlistint_len(*stak) - 1);
}

#include "monty.h"
#include <stdio.h>

ens_t ens;
/**
 * pusher - Pushes value to stack.
 * @stak: A pointer to a pointer to the begining of the stack
 * @l: line number.
 * Return: void
 */

void pusher(stack_t **stak, unsigned int l)
{
	int el, b = 0;

	if (ens.val == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", l);
		exit(EXIT_FAILURE);
	}
	if (ens.val[0] == '-')
		b++;
	for (; ens.val[b]; b++)
	{
		if (ens.val[b] >= '0' && (ens.val[b]) <= '9')
			continue;
		fprintf(stderr, "L%u: usage: push integer\n", l);
		exit(EXIT_FAILURE);
	}
	el = atoi(ens.val);
	if (ens.a == 1)
		add_dnodeint_end(stak, el);
	else
		add_dnodeint(stak, el);
}

/**
 * pallium - Prints all the values from the stack.
 * @stak: A double pointer to the begining of the stack
 * @l: The line number
 * Return: void
 */

void pallium(stack_t **stak, unsigned int l)
{
	stack_t *trav;

	(void)l;

	if (*stak == NULL || stak == NULL)
		return;
	trav = *stak;
	while (trav)
	{
		printf("%d\n", trav->n);
		trav = trav->next;
	}
}

/**
 * pinte - Prints the first  the value at the top of the stack.
 * @stak: A double pointer to the begining of the stack
 * @l: The line number
 * Return: void
 */

void pinte(stack_t **stak, unsigned int l)
{
	if (*stak == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", l);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stak)->n);
}

/**
 * popu - Removes the top element of the stack.
 * @stak: A double pointer to the begining of the stack
 * @l: The line number
 * Return: void
 */

void popu(stack_t **stak, unsigned int l)
{
	stack_t *point;
	
	point = *stak;
	if (*stak == NULL || stak == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", l);
		exit(EXIT_FAILURE);
	}

	*stak = point->next;
	if (*stak != NULL)
		(*stak)->prev = NULL;
	free(point);
}

/**
 * swaps - Swaps the top two elements of the stack
 * @stak: A double pointer to the begining of the stack
 * @l: The line number
 * Return: void
 */

void swaps(stack_t **stak, unsigned int l)
{
	stack_t *ncurrent = *stak, *point = NULL;
	int longueur = dlistint_len(*stak);

	if (longueur < 2)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", l);
		exit(EXIT_FAILURE);
	}

	point = (*stak)->next;
	ncurrent->prev = point;
	ncurrent->next = point->next;
	point->next = ncurrent;
	point->prev = NULL;
	*stak = point;
}

#include <stdio.h>
#include "monty.h"

/**
 * addi - Adds the top two elements of the stack
 * @stak: A double pointer to the begining of the stack
 * @l: The line number.
 * Return: void
 */

void addi(stack_t **stak, unsigned int l)
{
	stack_t *ncurrent = *stak, *point = NULL;
	int count, longueur = dlistint_len(*stak);

	if (longueur < 2)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", l)
		exit(EXIT_FAILURE);
	}
	point = ncurrent->next;
	count = (*stak)->n + (((*stak)->next)->n);
	point->n = count;
	*stak = point;
	free(ncurrent);
}

/**
 * nop - Doesn’t do anything.
 * @stak: A double pointer to the begining of the stack, who void
 * @l: The line number, who void
 * Return: void
 */

void nop(stack_t **stak, unsigned int l)
{
	(void)l;
	(void)stak;
}
/**
 * subtract - subtracts the top element of the stack from the
 * second top element of the stack.
 * @stak: A double pointer to the beginning of the stack
 * @l: The line number
 * Return: void
 */

void subtract(stack_t **stak, unsigned int l)
{
	int subt, longueur;
	stack_t *point = *stak;

	longueur = dlistint_len(*stak);
	if (longueur < 2)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", l);
		exit(EXIT_FAILURE);
	}
	subt = (point->next->n) - (point->n);
	point->next->n = subt;
	point->next->prev = NULL;
	*stak = point->next;
	free(point);
}
/**
 * div - divides the second top element of the
 * stack by the top element of the stack
 * @stak: A double pointer to the beginning of the stack
 * @l: The line number
 * Return: void
 */
void divi(stack_t **stak, unsigned int l)
{
	int quot;
	stack_t *point = *stak;
	int longueur = dlistint_len(*stak);

	if (longueur < 2)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", l);
		exit(EXIT_FAILURE);
	}
	if (point->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", l);
		exit(EXIT_FAILURE);
	}
	quot = (point->next->n) / (point->n);
	point->next->n = quot;
	point->next->prev = NULL;
	*stak = point->next;
	free(point);
}
/**
 * mult - multiplies the second top element of the stack
 * with the top element of the stack
 * @stak: a pointer to a pointer to the beginning of the stack
 * @l: The line number
 * Return: void
 */
void mult(stack_t **stak, unsigned int l)
{
	stack_t *point = *stak;
	int a, longueur = dlistint_len(*stak);

	if (longueur < 2)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", l);
		exit(EXIT_FAILURE);
	}
	a = (point->n) * (point->next->n);
	point->next->n = a;
	point->next->prev = NULL;
	*stak = point->next;
	free(point);
}

#include "monty.h"
#include <stdio.h>
/**
 * dlistint_len - Return list len
 * @h: a structure
 * Return: size_t
 */

size_t dlistint_len(const stack_t *h)
{
	size_t l;
	int a;

	a = 0;
	l = 0;
	while (h)
	{
		l += 1;
		h = h->next;
		a++;
	}
	return (l);
}

/**
 * add_dnodeint - add new element at beginiing of list
 * @head: pointer
 * @n: an integer
 * Return: a struct
 */

stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *a;

	a = malloc(sizeof(stack_t));
	if (a == NULL)
		return (NULL);
	a->prev = NULL;
	a->next = *head;
	a->n = n;
	if (*head != NULL)
		(*head)->prev = a;
	*head = a;
	return (a);
}

/**
 * add_dnodeint_end - adds a new node at the end of a dlistint_t list
 * @head: a pointer
 * @n: an integer
 * Return: a pointer
 */

stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *alpha, *current;

	alpha = NULL;
	current = *head;
	alpha = malloc(sizeof(stack_t));
	if (alpha)
	{
		alpha->n = n;
		alpha->next = NULL;
		alpha->prev = NULL;
		if (!(*head))
			*head = alpha;
		else
		{
			while (current->next)
				current = current->next;
			current->next = alpha;
			alpha->prev = current;
		}
	}
	return (alpha);
}

/**
 * get_dnodeint_at_index - returns the nth node of a dlistint_t linked list
 * @head: a pointer
 * @index: an integer
 * Return: a pointer
 */

stack_t *get_dnodeint_at_index(stack_t *head, unsigned int index)
{
	unsigned int a;

	for (a = 0; a != index && head; a++)
	{
		head = head->next;
	}
	if (a == index && head)
		return (head);
	return (NULL);
}

/**
 * insert_dnodeint_at_index - Inserts a new node at a given position
 * @h: A pointer
 * @idx: an unsigned integer
 * @n: an integer
 * Return: a structure
 */

stack_t *insert_dnodeint_at_index(stack_t **h, unsigned int idx, int n)
{
	stack_t *current = *h, *point;

	if (idx == 0)
		return (add_dnodeint(h, n));
	for (; idx != 1; idx--)
	{
		current = current->next;
		if (current == NULL)
			return (NULL);
	}
	if (current->next == NULL)
		return (add_dnodeint_end(h, n));
	point = malloc(sizeof(stack_t));
	if (point == NULL)
		return (NULL);
	point->n = n;
	point->prev = current;
	point->next = current->next;
	current->next->prev = point;
	current->next = point;
	return (point);
}

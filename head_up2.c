#include <stdio.h>
#include "monty.h"
/**
 * delete_dnodeint_at_index - removes the given node
 * @head: pointer
 * @index: integer
 * Return: -1 or 1
 */

int delete_dnodeint_at_index(stack_t **head, unsigned int index)
{
	unsigned int a = 0;
	stack_t *point, *del = *head;

	if (*head && head)
	{
		if (index == 0)
		{
			point = *head;
			*head = (*head)->next;
			if (*head)
				(*head)->prev = NULL;
			free(point);
		}
		else
		{
			for (a = 0; a != index && del; a++)
			{
				point = del;
				del = point->next;
			}
			if (a == index && del)
			{
				point->next = del->next;
				if (del->next)
					del->next->prev = point;
				free(del);
			}
			else
				return (-1);
		}
		return (1);
	}
	return (-1);
}

/**
 * free_dlistint - function that frees a dlistint_t list.
 * @head: head of the list
 * Return: void
 */

void free_dlistint(stack_t *head)
{
	stack_t *current;

	current = NULL;
	while (head)
	{
		current = head;
		head = head->next;
		free(current);
	}
}

/**
 * stack - Sets the format of the data to stack and queue.
 * @stak: A double to the begining of the stack
 * @l: The line number
 * Return: void
 */

void stack(stack_t **stak, unsigned int l)
{
	(void)stak;
	(void)l;

	if (strcmp((ens.c), "queue") != 0)
		(ens.a) = 0;
}

/**
 * queue - Sets the format of the data to queue.
 * @stak: A double to the begining of the stack
 * @l: The line number
 * Return: void
 */

void queue(stack_t **stak, unsigned int l)
{
        (void)stak;
        (void)l;

	if (strcmp((ens.c), "queue") == 0)
		(ens.a) = 1;
}

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
 * run - execute the opcode command
 * @string: The line instruction read from the given file.
 * @l: The line number.
 * Return: void
 */

void run(char *string, unsigned int l)
{
	char * c, *val;
	stack_t *h;

	void (*func)(stack_t**, unsigned int);

	c = strtok(string, " \r\t\n");
	if ( c[0] != '#' && c)
	{
		func = ob_funct(c);
		if (func != NULL)
		{
			if (strcmp(c, "push") == 0)
				val = strtok(NULL, " \r\t\n");
			func(&h, l);
		}
		else
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", l, c);
			if (string)
				free(string);
			if (h)
				free_dlistint(h);
			exit(EXIT_FAILURE);
		}
	}
}

/**
 * stack_queue - Sets the format of the data to stack and queue.
 * @stack: A double to the begining of the stack
 * @l: The line number
 * Return: void
 */

void stack_queue(stack_t **stak, unsigned int l)
{
	int a;
	char *c;

	(void)stak;
	(void)l;

	if (strcmp(c, "queue") != 0)
		a = 0;
}

/**
 * queue - Sets the format of the data to queue.
 * @stack: A double to the begining of the stack
 * @l: The line number
 * Return: void
 */

void queue(stack_t **stak, unsigned int l)
{
        int a;
        char *c;

        (void)stak;
        (void)l;

        if (strcmp(c, "queue") == 0)
                a = 1;
                a = 0;
}

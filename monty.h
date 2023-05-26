#ifndef MONTY_H
#define MONTY_H

/*
 * File: monty.h
 *
 * Description: This header file contains all the structure definations, header files,
 * and all the function prototypes used for the 0x19. C - Stacks,
 * Queues - LIFO, FIFO project.
 *
 * Author: Hadjara Maman Moussa
 */

#define _POSIX_C_SOURCE  200809L
#define _GNU_SOURCE
#include <string.h>
#include <stdarg.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;

} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
*struct ensemb_t - a program of variables -args, file, line content
*@val: value
*@file: pointer to monty file
*@c: line content
*@a: flag change stack <-> queue
*Description: carries values through the program
*/
typedef struct ensemb_t
{
		char *val;
		FILE *file;
		char *c;
		int a;
		stack_t *h;
} ensemb;

extern ensemb ensemble;

void pusher(stack_t **stak, unsigned int l);
void pallium(stack_t **stak, unsigned int l);
void pinte(stack_t **stak, unsigned int l);
void popu(stack_t **stak, unsigned int l);
void swaps(stack_t **stak, unsigned int l);
void addi(stack_t **stak, unsigned int l);
void nop(stack_t **stak, unsigned int l);
void subtract(stack_t **stak, unsigned int l);
void divi(stack_t **stak, unsigned int l);
void mult(stack_t **stak, unsigned int l);
void modu(stack_t **stak, unsigned int l);
void prchar(stack_t **stak, unsigned int l);
void pstring(stack_t **stak, unsigned int l);
void rotal(stack_t **stak, unsigned int l);
void rotar(stack_t **stak, unsigned int l);
void stack(stack_t **stak, unsigned int l);
void queue(stack_t **stak, unsigned int l);

size_t dlistint_len(const stack_t *h);
stack_t *add_dnodeint(stack_t **head, const int n);
stack_t *add_dnodeint_end(stack_t **head, const int n);
void free_dlistint(stack_t *head);
stack_t *get_dnodeint_at_index(stack_t *head, unsigned int index);
stack_t *insert_dnodeint_at_index(stack_t **h, unsigned int idx, int n);
int delete_dnodeint_at_index(stack_t **head, unsigned int index);

#endif

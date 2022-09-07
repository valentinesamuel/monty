#ifndef MONTY
#define MONTY

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#define UNUSED(x) (void)(x)

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
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
 * for stack, queues, LIFO, FIFO Holberton project
 */

typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct buffer -buffers
 * @fd: File descriptor
 * @line: Line buffer for input read in
 * @stack: Double pointer for stack of struct stack_s
 * Description: various buffers to hold inputs
 */

typedef struct buffer
{
	 FILE *fd;
	 char *line;
	 stack_t **stack;

} global_buf;

extern global_buf buf;

void pall(stack_t **stack, unsigned int line_num);
void pint(stack_t **stack, unsigned int line_num);
void pop(stack_t **stack, unsigned int line_num);
void add(stack_t **stack, unsigned int line_num);
void swap(stack_t **stack, unsigned int line_num);
void nop(stack_t **stack, unsigned int line_num);
void sub(stack_t **stack, unsigned int line_num);
void mydiv(stack_t **stack, unsigned int line_num);
void mymul(stack_t **stack, unsigned int line_num);
void mymod(stack_t **stack, unsigned int line_num);
void pstr(stack_t **stack, unsigned int line_num);
void pchar(stack_t **stack, unsigned int line_num);


void free_dlistint(stack_t *head);
void add_dnodeint(stack_t **head, const int n);

unsigned int linecount(FILE *fd);
void err_msg(char *msg, char *file, int status);

void push(char *token, unsigned int line_num);
void others(char *token, unsigned int line_num);

void free_all(void);

#endif

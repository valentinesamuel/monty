#include "monty.h"

/**
 * pall - print all elements of the stack
 * @stack: the stack of elements
 * @line_num: line number
 */
void pall(stack_t **stack, unsigned int line_num)
{
	stack_t *full_stack;
	(void)line_num;

	if (*stack == NULL)
		return;
	full_stack = *stack;
	while (full_stack != NULL)
	{
		printf("%d\n", full_stack->n);
		full_stack = full_stack->next;
	}
}

/**
 * pint - print the top element of the stack
 * @stack: stack of elements
 * @line_num: line number
 */
void pint(stack_t **stack, unsigned int line_num)
{
	if (stack == NULL || *stack == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't pint, stack empty\n",
			line_num);
		free_all();
		exit(EXIT_FAILURE);
	}
	else
		printf("%d\n", (*stack)->n);
}

/**
 * pop - remove element from stack
 * @stack: stack of elements
 * @line_num: line number
 */
void pop(stack_t **stack, unsigned int line_num)
{
	stack_t *next = NULL;

	if (stack == NULL || *stack == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't pop an empty stack\n",
			line_num);
		free_all();
		exit(EXIT_FAILURE);
	}

	next = (*stack)->next;
	free(*stack);
	*stack = next;

	if (*stack == NULL)
		return;
	(*stack)->prev = NULL;
}

/**
 * swap - swap top 2 numbers
 * @stack: input stack address
 * @line_num: current line number
 */
void swap(stack_t **stack, unsigned int line_num)
{
	stack_t *current = NULL;
	int hold = 0;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't swap, stack too short\n",
			line_num);
		free_all();
		exit(EXIT_FAILURE);
	}
	current = *stack;

	hold = current->n;

	current->n = hold;
	current->n = current->next->n;
	current->next->n = hold;
}

/**
 * add - adding first two elements
 * @stack: stack of elements
 * @line_num: line number
 */
void add(stack_t **stack, unsigned int line_num)
{
	stack_t *current = NULL;
	int total = 0;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't add, stack too short\n",
			line_num);
		free_all();
		exit(EXIT_FAILURE);
	}

	current = *stack;

	total = current->n + current->next->n;

	pop(stack, line_num);

	(*stack)->n = total;
}

#include "monty.h"

/**
 * sub - subtract top 2 numbers
 * @stack: stack of elements
 * @line_num: line number
 */
void sub(stack_t **stack, unsigned int line_num)
{
	stack_t *current = NULL;
	int total = 0;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't sub, stack too short\n",
			line_num);
		free_all();
		exit(EXIT_FAILURE);
	}
	current = *stack;
	total = current->next->n - current->n;
	pop(stack, line_num);
	(*stack)->n = total;
}

/**
 * mydiv - division of top 2 numbers
 * @stack: stack of elements
 * @line_num: line number
 */
void mydiv(stack_t **stack, unsigned int line_num)
{
	stack_t *current = NULL;
	int total = 0;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't div, stack too short\n",
			line_num);
		free_all();
		exit(EXIT_FAILURE);
	}

	current = *stack;

	if (current->n == 0)
	{
		dprintf(STDERR_FILENO, "L%d: division by zero\n",
			line_num);
		free_all();
		exit(EXIT_FAILURE);
	}

	total = current->next->n / current->n;
	pop(stack, line_num);
	(*stack)->n = total;
}

/**
 * mymul - multiplication of top 2 numbers
 * @stack: stack of elements
 * @line_num: line number
 */
void mymul(stack_t **stack, unsigned int line_num)
{
	stack_t *current = NULL;
	int total = 0;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't mul, stack too short\n",
			line_num);
		free_all();
		exit(EXIT_FAILURE);
	}

	current = *stack;

	total = current->next->n * current->n;
	pop(stack, line_num);
	(*stack)->n = total;
}

/**
 * mymod - modulo of top 2 numbers
 * @stack: stack of elements
 * @line_num: line number
 */
void mymod(stack_t **stack, unsigned int line_num)
{
	stack_t *current = NULL;
	int total = 0;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		dprintf(STDERR_FILENO, "L%d: can't mod, stack too short\n",
			line_num);
		free_all();
		exit(EXIT_FAILURE);
	}

	current = *stack;

	if (current->n == 0)
	{
		dprintf(STDERR_FILENO, "L%d: division by zero\n",
			line_num);
		free_all();
		exit(EXIT_FAILURE);
	}

	total = current->next->n % current->n;
	pop(stack, line_num);
	(*stack)->n = total;
}
/**
 * pchar - main function
 * @stack: stack of elements
 * @line_num: line number
 */
void pchar(stack_t **stack, unsigned int line_num)
{
	if (stack == NULL || *stack == NULL)
	{
		dprintf(STDERR_FILENO, "L%u: can't pchar, stack empty\n",
			line_num);
		free_all();
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n > 127 || (*stack)->n < 0)
	{
		dprintf(STDERR_FILENO, "L%u: can't pchar, value out of range\n",
			line_num);
		free_all();
		exit(EXIT_FAILURE);
	}

	printf("%c\n", (*stack)->n);

}

#include "monty.h"
/**
 * pstr - main function
 * @stack: stack of elements
 * @line_num: line number
 */
void pstr(stack_t **stack, unsigned int line_num)
{
	stack_t *full_stack;
	(void)line_num;

	full_stack = *stack;

	if (stack == NULL || *stack == NULL)
	{
		putchar('\n');
		return;
	}

	while (full_stack != NULL)
	{
		if (full_stack->n < 1 || full_stack->n > 127)
		{
			putchar('\n');
			return;
		}
		putchar(full_stack->n);
		full_stack = full_stack->next;
	}

	putchar('\n');
}

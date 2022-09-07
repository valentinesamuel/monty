#include "monty.h"

/**
 * isdig - function that determines if a string contains a digit or not
 * @token: Char pointer to be checked
 * Return: 0 if a non-digit character is present, 1 otherwise
 */

int isdig(char *token)
{
	int i = 0;

	while (token[i])
	{
		if (token[0] == '-')
		{
			++i;
			continue;
		}

		if (token[i] < '0' || token[i] > '9')
			return (0);

		++i;
	}

	return (1);
}

/**
 * push - function that pushes an element to the stack
 * @token: Char pointer for token read from file
 * @line_num: line number of type unsigned int
 * Return: Void
 */

void push(char *token, unsigned int line_num)
{
	int n;

	if (strcmp(token, "push") == 0)
	{
		token = strtok(NULL, " \t\n");

		if (token == NULL)
		{
			dprintf(STDERR_FILENO, "L%u: usage: push integer\n",
				line_num);
			free_all();
			exit(EXIT_FAILURE);
		}

		n = isdig(token);

		if (n == 0)
		{
			dprintf(STDERR_FILENO, "L%u: usage: push integer\n",
				line_num);
			free_all();
			exit(EXIT_FAILURE);
		}

		n = atoi(token);
		add_dnodeint(buf.stack, n);
		return;
	}

	else
		return;
}

/**
 * others - function that executes opcodes from tokens other than push
 * @token: Char pointer for token read from file
 * @line_num: line number of type unsigned int
 * Return: Void
 */

void others(char *token, unsigned int line_num)
{
	int j = 0;

	instruction_t ops[] = {
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"add", add},
		{"swap", swap},
		{"nop", nop},
		{"sub", sub},
		{"div", mydiv},
		{"mul", mymul},
		{"mod", mymod},
		{"pstr", pstr},
		{"pchar", pchar}
	};

	while (j < 12)
	{
		if (strcmp(token, ops[j].opcode) == 0)
		{
			ops[j].f(buf.stack, line_num);
			return;
		}

		++j;
	}

	dprintf(STDERR_FILENO, "L%u: unknown instruction %s\n", line_num,
		token);
	free_all();
	exit(EXIT_FAILURE);
}

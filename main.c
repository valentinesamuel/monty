#include "monty.h"

global_buf buf;

/**
 * main - program that copies the content of a file to another file
 * @argc: - Int of arguments passed into program including command
 * @argv: - Array of pointers to the strings of arguments passed
 * Return: 0
 */

int main(int argc, char *argv[])
{
	char *line = NULL, *token;
	unsigned int count, i;
	size_t len = 0;
	stack_t *stack = NULL;

	buf.stack = &stack;

	if (argc != 2)
		err_msg("USAGE: monty ", "file", EXIT_FAILURE);

	buf.fd = fopen(argv[1], "r");

	if (buf.fd == NULL)
		err_msg("Error: Can't open file ", argv[1], EXIT_FAILURE);

	count = linecount(buf.fd);
	buf.fd = fopen(argv[1], "r");

	for (i = 1; i < count + 1; i++)
	{
		getline(&line, &len, buf.fd);
		buf.line = line;
		token = strtok(buf.line, " \t\n");

		if (token == NULL)
			continue;

		else if (token[0] == '#')
			continue;

		else if (strcmp(token, "push") == 0)
			push(token, i);
		else
			others(token, i);
	}
	free(line);
	free_dlistint(*buf.stack);
	fclose(buf.fd);
	return (0);
}

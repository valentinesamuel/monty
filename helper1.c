#include "monty.h"

/**
 * free_all - function that frees all malloc'd memory used and closes the file
 * descriptor
 * Return: Void
 */

void free_all(void)
{
	free(buf.line);
	free_dlistint(*buf.stack);
	fclose(buf.fd);
}

/**
 * free_dlistint - function that free a dlistint_t list
 * @head: Const pointer to head node for linked dlistint_t list
 * Return: Void
 */

void free_dlistint(stack_t *head)
{
	stack_t *temp;

	temp = head;

	if (head == NULL)
		return;

	while (temp != NULL)
	{
		temp = head->next;
		free(head);
		head = temp;
	}

}

/**
 * add_dnodeint - function that adds a new node at the beginning of a
 * stack_t list
 * @head: Const pointer to head node for linked stack_t list
 * @n: Const integer of node to be added
 * Return: void
 */

void add_dnodeint(stack_t **head, const int n)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));

	if (new == NULL)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		free_all();
		exit(EXIT_FAILURE);
	}

	new->n = n;
	new->prev = NULL;

	if (*head == NULL)
	{
		new->next = NULL;
		*head = new;
		return;
	}

	(*head)->prev = new;
	new->next = *head;

	*head = new;
}

/**
 * linecount - function that returns the total line count read
 * @fd: - File descriptor for file to be read
 * Return: Unisgned int of the line number
 */

unsigned int linecount(FILE *fd)
{
	unsigned int count = 0;
	char c;

	for (c = getc(fd); c != EOF; c = getc(fd))
		if (c == '\n')
			count = count + 1;
	fclose(fd);
	return (count);
}

/**
 * err_msg - function that returns an error message and exits with the
 * appropriate exit status
 * @msg: - Char pointer for error message to be printed
 * @file: Char pointer for file name that can't be opened
 * @status: Int for proper status code to exit with
 * Return: Void
 */

void err_msg(char *msg, char *file, int status)
{
	dprintf(STDERR_FILENO, "%s%s\n", msg, file);
	exit(status);
}

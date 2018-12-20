#include "monty.h"

/**
 * print_stack - print the elements of a doubly linked list
 * @h: a pointer to the head node of the list
 * Return: the number of nodes
 */
size_t print_stack(const stack_t *h)
{
	int i;

	if (h == NULL)
		return (0);
	for (i = 0; h; i++, h = h->next)
		printf("%d\n", h->n);
	return (i);
}

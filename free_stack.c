#include "monty.h"

/**
 * free_stack - frees a doubly linked list
 * @head: a pointer to the first node in the list
 * Return: No Value
 */
void free_stack(stack_t *head)
{
	if (head == NULL)
		return;
	for (; head->next; head = head->next)
	{
		if (head->prev)
			free(head->prev);
	}
	free(head->prev);
	free(head);
}

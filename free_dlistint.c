#include "lists.h"

/**
 * free_dlistint - frees a doubly linked list
 * @head: a pointer to the first node in the list
 * Return: No Value
 */
void free_dlistint(dlistint_t *head)
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

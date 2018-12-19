#include "monty.h"
/**
 * push - pushes an element onto the stack
 * @stack: pointer to a pointer to a stack
 * @line_number: line number
 * Return: nothing
*/
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *newNode;

	newNode = malloc(sizeof(stack_t));

	if (!newNode)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(*stack);
		free(glo->ipt);
		exit(EXIT_FAILURE);
	}
	else if (!glo->iptint)
	{
		fprintf(stderr, "L%u: usage: push integer", line_number);
		free(glo->ipt);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	newNode->n = glo->iptint;
	newNode->prev = NULL;
	newNode->next = *stack;

	if (*stack)
		(*stack)->prev = newNode;
	*stack = newNode;
}

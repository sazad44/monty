#include "monty.h"

/**
 * push - pushes an element onto the stack
 * @stack: pointer to a pointer to a stack
 * @line_number: line number
 * Return: No Value
*/
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *newNode;

	(void)line_number;
	newNode = malloc(sizeof(stack_t));

	if (!newNode)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(*stack);
		free(glo->ipt);
		exit(EXIT_FAILURE);
	}
	newNode->n = glo->iptint;
	newNode->prev = NULL;
	newNode->next = *stack;

	if (*stack)
		(*stack)->prev = newNode;
	*stack = newNode;
}

/**
 * pall - pushes an element onto the stack
 * @stack: pointer to a pointer to a stack
 * @line_number: line number
 * Return: No Value
*/
void pall(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	print_stack(*stack);
}

/**
 * pint - prints the top value of the stack
 * @stack: pointer to a pointer to a stack
 * @line_number: line number
 * Return: No Value
*/
void pint(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		free(glo->ipt), free(glo->tokop), free(glo);
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * pop - deletes the top element of the stack
 * @stack: pointer to a pointer to a stack
 * @line_number: line number
 * Return: No Value
*/
void pop(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		free(glo->ipt), free(glo->tokop), free(glo);
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->next)
	{
		*stack = (*stack)->next;
		free((*stack)->prev);
		(*stack)->prev = NULL;
	}
	else
	{
		free(*stack);
		*stack = NULL;
	}
}

/**
 * nop - no effect
 * @stack: pointer to a pointer to a stack
 * @line_number: line number
 * Return: No Value
*/
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * swap - swaps the top two elements of the stack
 * @stack: pointer to a pointer to a stack
 * @line_number: line number
 * Return: No Value
*/
void swap(stack_t **stack, unsigned int line_number)
{
	int tmpint;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		free(glo->ipt), free(glo->tokop), free(glo), free_stack(*stack);
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmpint = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = tmpint;
}

/**
 * add - adds the top two elements of the stack and pops the first one
 * @stack: pointer to a pointer to a stack
 * @line_number: line number
 * Return: No Value
*/
void add(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		free(glo->ipt), free(glo->tokop), free(glo), free_stack(*stack);
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	*stack = (*stack)->next;
	(*stack)->n = (*stack)->n + (*stack)->prev->n;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

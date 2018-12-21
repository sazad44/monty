#include "monty.h"

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

/**
 * sub - subtracts top two elements in the stack
 * @stack: stack
 * @line_number: line number
 * Return: nothing
*/
void sub(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		free(glo->ipt), free(glo->tokop), free(glo);
		if (*stack)
			free_stack(*stack);
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	*stack = (*stack)->next;
	(*stack)->n = (*stack)->n - (*stack)->prev->n;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

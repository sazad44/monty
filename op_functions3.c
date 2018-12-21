#include "monty.h"

/**
 * mod - divides top two elements in the stack
 * @stack: pointer to a pointer to the top of the stack
 * @line_number: line number
 * Return: No Value
 */
void mod(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		free(glo->ipt), free(glo->tokop), free(glo);
		if (*stack)
			free_stack(*stack);
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	else if ((*stack)->n == 0)
	{
		free(glo->ipt), free(glo->tokop), free(glo);
		if (*stack)
			free_stack(*stack);
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	*stack = (*stack)->next;
	(*stack)->n = (*stack)->n % (*stack)->prev->n;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

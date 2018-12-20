#include "monty.h"

/**
 * swap - swaps first two elements on top of the stack
 * @stack: stack
 * @line_number: line number
 * Return: nothing
*/
void swap(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (stack == NULL || (*stack)->next == NULL || *stack == NULL)
	{
		printf("L%d: can't swap, stack too short\n", line_number);
		free(glo->ipt), free(glo->tokop), free(glo);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}
/**
 * add- adds top two elements in the stack
 * @stack: stack
 * @line_number: line number
 * Return: nothing
*/
void add(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || (*stack)->next == NULL || *stack == NULL)
        {
		printf("L%d: can't swap, stack too short\n", line_number);
		free(glo->ipt), free(glo->tokop), free(glo);
		exit(EXIT_FAILURE);
        }
	*stack = (*stack)->next;
	(*stack)->n = (*stack)->n + (*stack)->prev->n;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
void sub(stack_t **stack, unsigned int line_number)
{
	 if (stack == NULL || (*stack)->next == NULL || *stack == NULL)
	 {
                printf("L%d: can't swap, stack too short\n", line_number);
                free(glo->ipt), free(glo->tokop), free(glo);
                exit(EXIT_FAILURE);
	 }
	*stack = (*stack)->next;
        (*stack)->n = (*stack)->n - (*stack)->prev->n;
        free((*stack)->prev);
        (*stack)->prev = NULL;
}

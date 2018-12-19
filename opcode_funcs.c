#include "monty.h"

void push(stack_t **stack, unsigned int line_number)
{
	if (*stack && line_number)
	{
		printf("%d\n", line_number);
		(*stack)->n = line_number;
	}
	else
	{
		fprintf(stderr, "L%u: usage: push integer\n", lnum);
		exit(EXIT_FAILURE);
	}
}

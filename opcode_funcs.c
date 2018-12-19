#include "monty.h"

void push(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	if (glo->iptint)
	{
		printf("%d\n", glo->iptint);
	}
	else
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
}

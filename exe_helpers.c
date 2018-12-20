#include "monty.h"

/**
 * bc_exe - tokenizes string and executes operations specified
 * @ipt: the input string to be tokenized
 * @stack: a pointer to a pointer to the linked list stack
 * Return: 1 for success and 0 for failure
 */
int bc_exe(char *ipt, stack_t **stack)
{
	unsigned int toklen = 0, i = 0, j = 0, lnum = 1, flag = 0;
	instruction_t instarr[] = {
		{"push", push}, {"pall", pall},
		{"pint", pint}, {"pop", pop},
		{"nop", nop}, {"swap", swap},
		{"add", add}, {NULL, NULL}
	};
	char *tok;

	tok = strtok(ipt, "\n");
	while (tok)
	{
		for (i = 0; tok[i] == ' '; i++)
			;
		for (toklen = i; tok[toklen] && tok[toklen] != ' '; toklen++)
			;
		glo->tokop = malloc(sizeof(char) * toklen - i + 1);
		if (glo->tokop == NULL)
			return (0);
		glo->tokop = memset(glo->tokop, 0, toklen - i + 1);
		glo->tokop = strncpy(glo->tokop, tok + i, toklen - i);
		for (j = 0; instarr[j].opcode; j++)
		{
			if (!strcmp(glo->tokop, "push"))
			{
				for (; tok[toklen] && tok[toklen] == ' '; toklen++)
					;
				if (!isdigit(tok[toklen]))
				{
					fprintf(stderr, "L%u: usage: push integer\n", lnum);
					free(glo->ipt), free_stack(*stack), free(glo->tokop), free(glo);
					exit(EXIT_FAILURE);
				}
				glo->iptint = ((glo->iptint * 10) + atoi(tok + toklen)); 
			}
			if (!strcmp(glo->tokop, instarr[j].opcode))
			{
				instarr[j].f(stack, lnum);
				flag = 1;
			}
		}
		if (instarr[j].opcode == NULL && !flag && *(glo->tokop))
		{
			free(glo->ipt);
			free_stack(*stack);
			fprintf(stderr, "L%u: unknown instruction %s\n", lnum, glo->tokop);
			free(glo->tokop);
			free(glo);
			exit(EXIT_FAILURE);
		}
		tok = strtok(NULL, "\n"), glo->iptint = 0;
		lnum++;
		flag = 0;
		free(glo->tokop);
	}
	return (lnum);
}

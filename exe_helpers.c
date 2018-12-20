#include "monty.h"

/**
 * bc_exe - tokenizes string and executes operations specified
 * @ipt: the input string to be tokenized
 * @stack: a pointer to a pointer to the linked list stack
 * Return: 1 for success and 0 for failure
 */
int bc_exe(char *ipt, stack_t **stack)
{
	unsigned int toklen = 0, i = 0, j = 0, lnum = 1;
	instruction_t instarr[] = {
		{"push", push}, {"pall", pall},
		{NULL, NULL}
	};
	char *tok, *tokop;

	tok = strtok(ipt, "\n");
	while (tok)
	{
		for (i = 0; tok[i] == ' '; i++)
			;
		for (toklen = i; tok[toklen] != ' ' && tok[toklen]; toklen++)
			;
		tokop = malloc(sizeof(char) * toklen - i + 1);
		if (tokop == NULL)
			return (0);
		tokop = memset(tokop, 0, toklen - i + 1);
		tokop = strncpy(tokop, tok + i, toklen - i);
		for (j = 0; instarr[j].opcode; j++)
		{
			if (!strcmp(tokop, "push"))
			{
				for (; tok[toklen] && tok[toklen] == ' '; toklen++)
					;
				if (!isdigit(tok[toklen]))
				{
					fprintf(stderr, "L%u: usage: push integer\n", lnum);
					free(glo->ipt), free_stack(*stack);
					exit(EXIT_FAILURE);
				}
				glo->iptint = ((glo->iptint * 10) + atoi(tok + toklen)); }
			if (!strcmp(tokop, instarr[j].opcode))
				instarr[j].f(stack, lnum); }
		tok = strtok(NULL, "\n"), glo->iptint = 0;
		lnum++; }
	free(tokop);
	if (instarr[j].opcode == NULL)
		return (-1);
	return (lnum);
}

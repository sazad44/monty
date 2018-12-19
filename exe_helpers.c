#include "monty.h"

/**
 * bc_exe - tokenizes string and executes operations specified
 * @ipt: the input string to be tokenized
 * @stack: a pointer to a pointer to the linked list stack
 * Return: 1 for success and 0 for failure
 */
int bc_exe(char *ipt, stack_t **stack)
{
	unsigned int toklen, i, j, lnum = 1;
	instruction_t instarr[] = {
		{"push", push}, {NULL, NULL}
	};
	char *tok, *tokop;

	tok = strtok(ipt, "\n");
	for (i = 0; tok[i] == ' '; i++)
		;
	for (toklen = i; tok[toklen] != ' '; toklen++)
		;
	tokop = malloc(sizeof(char) * toklen - i + 1);
	if (tokop == NULL)
		return (0);
	tokop = memset(tokop, 0, toklen - i + 1);
	tokop = strncpy(tokop, tok + i, toklen - i);
	for (j = 0; instarr[j].opcode; j++)
	{
		for (; tok[toklen] == ' ' && tok[toklen]; toklen++)
			;
		glo->iptint = ((glo->iptint * 10) + atoi(tok + toklen));
		if (!strcmp(tokop, instarr[j].opcode))
			instarr[j].f(stack, lnum);
		lnum++;
	}
	free(tokop);
	if (instarr[j].opcode == NULL)
		return (-1);
	return (lnum);
}

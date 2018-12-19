#include "monty.h"

unsigned int lnum = 1;
/**
 * bc_exe - tokenizes string and executes operations specified
 * @ipt: the input string to be tokenized
 * @stack: a pointer to a pointer to the linked list stack
 * Return: 1 for success and 0 for failure
 */
int bc_exe(char *ipt, stack_t **stack)
{
	unsigned int toklen, i, j, iptint = 0;
	instruction_t instarr[] = {
		{"push", push}, {NULL, NULL}
	};
	char *tok, *tokop;

	tok = strtok(ipt, "\n");
	for (i = 0; tok[i] == ' '; i++)
		;
	for (toklen = i; tok[toklen] != ' '; toklen++)
		;
	tokop = malloc(sizeof(char) * toklen);
	if (tokop == NULL)
		return (0);
	tokop = strncpy(tokop, tok + i, toklen - i - 1);
	for (j = 0; instarr[j].opcode; j++)
	{
		if (!strcmp(tokop, "sh"))
			printf("hi %d\n", iptint);
		else if (strcmp(tokop, instarr[j].opcode))
			instarr[j].f(stack, lnum);
	}
	free(tokop);
	return (0);
}

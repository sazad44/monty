#include "monty.h"

/**
 * bc_exe - tokenizes string and executes operations specified
 * @ipt: the input string to be tokenized
 * @stack: a pointer to a pointer to the linked list stack
 * Return: 1 for success and 0 for failure
 */
int bc_exe(char *ipt, stack_t **stack)
{
	unsigned int toklen = 0, i, j = 0, lnum = 1, flag = 0, lnumx = 0, toklenx = 0;
	instruction_t instarr[] = {
		{"push", push}, {"pall", pall},	{"pint", pint}, {"pop", pop},
		{"nop", nop}, {"swap", swap}, {"add", add},{"sub",sub}, {NULL, NULL}
	};
	char *tok;

	for (toklenx = 0; ipt[toklenx] == '\n'; toklenx++)
		lnumx++;
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
				for (toklenx = toklen; tok[toklenx] != ' ' && tok[toklenx]; toklenx++)
					if ((!isdigit(tok[toklenx]) && tok[toklenx] != '-'))
						free_exit(*stack, lnum + lnumx, "L%u: usage: push integer\n");
				glo->iptint = ((glo->iptint * 10) + atoi(tok + toklen)); }
			if (!strcmp(glo->tokop, instarr[j].opcode))
				instarr[j].f(stack, lnum + lnumx), flag = 1; }
		if (instarr[j].opcode == NULL && !flag && *(glo->tokop))
			free_exit_ui(*stack, lnum + lnumx, "L%u: unknown instruction %s\n");
		lnumx += nl_count(tok);
		tok = strtok(NULL, "\n"), glo->iptint = 0;
		lnum++, flag = 0, free(glo->tokop);
	}
	return (lnum + lnumx);
}

/**
 * free_exit_ui - frees and exits with message and opcode
 * @stack: a pointer to the top of the stack
 * @lnum: line number
 * @mssg: message to be printed to stderr
 * Return: No Value
 */
void free_exit_ui(stack_t *stack, unsigned int lnum, char *mssg)
{
	fprintf(stderr, mssg, lnum, glo->tokop);
	free(glo->ipt);
	free(glo->tokop);
	free(glo);
	if (stack)
		free_stack(stack);
	exit(EXIT_FAILURE);
}

/**
 * free_exit - frees and exits with message
 * @stack: a pointer to the top of the stack
 * @lnum: line number
 * @mssg: message to be printed to stderr
 * Return: No Value
 */
void free_exit(stack_t *stack, unsigned int lnum, char *mssg)
{
	fprintf(stderr, mssg, lnum);
	free(glo->ipt);
	free(glo->tokop);
	free(glo);
	if (stack)
		free_stack(stack);
	exit(EXIT_FAILURE);
}

/**
 * nl_count - counts new lines after a certain line
 * @tok: a pointer to the token before the new lines to be counted
 * Return: number of new lines counted
 */
int nl_count(char *tok)
{
	int toklenx, i, lnumx = 0;

	for (toklenx = 0; tok[toklenx]; toklenx++)
		;
	for (i = 1; tok[toklenx + i] == '\n'; i++)
		lnumx++;
	return (lnumx);
}

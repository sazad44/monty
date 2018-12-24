#include "monty.h"

/**
 * read_file - reads file contents into buffer
 * @fd: the file descriptor for a certain file
 * Return: a pointer to the buffer created
 */
char *read_file(int fd)
{
	int bufsize = 64, rd;
	char *ret, *tmp;

	ret = malloc(sizeof(char) * bufsize);
	if (ret == NULL)
		return (NULL);
	ret = memset(ret, 0, bufsize);
	rd = read(fd, ret, bufsize);
	if (rd == -1)
	{
		free(ret);
		return (NULL);
	}
	while (rd == bufsize)
	{
		bufsize += bufsize;
		tmp = malloc(sizeof(char) * bufsize);
		if (tmp == NULL)
		{
			free(ret);
			return (NULL);
		}
		tmp = memset(tmp, 0, bufsize);
		strncpy(tmp, ret, (bufsize / 2));
		free(ret);
		ret = tmp;
		rd += read(fd, ret + bufsize / 2, bufsize / 2);
		if (rd == -1)
			return (NULL);
	}
	return (ret);
}

/**
 * push_check - checks to see if push is being used correctly
 * @toklenx: the index at which the input for push begins
 * @tok: a pointer to the token being analyzed
 * @stack: a pointer to the first element of the stack
 * @lnum: the line number at the time
 * Return: No Value
 */
void push_check(int toklenx, char *tok, stack_t *stack, int lnum)
{
	for (; tok[toklenx] != ' ' && tok[toklenx]; toklenx++)
		if ((!isdigit(tok[toklenx]) && tok[toklenx] != '-'))
			free_exit(stack, lnum, "L%u: usage: push integer\n");
}

/**
 * comment_check - checks for comments and ignores them
 * @lnum: the address of lnum to be changed in this function
 * @i: the index which the token is moved to to avoid spaces
 * @tok: a pointer to a pointer to the token to change it
 * Return: a boolean value for true or false
 */
bool comment_check(unsigned int *lnum, int i, char **tok)
{
	if ((*tok)[i] == '#')
	{
		*lnum += nl_count(*tok) + 1;
		*tok = strtok(NULL, "\n");
		return (true);
	}
	return (false);
}

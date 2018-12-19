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

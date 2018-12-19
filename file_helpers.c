#include "monty.h"

char *read_file(int fd)
{
	int bufsize = 64, rd;
	char *ret, *tmp;

	ret = malloc(sizeof(char) * bufsize);
	if (ret == NULL)
		return (NULL);
	rd = read(fd, ret, bufsize);
	if (rd == -1)
		return (NULL);
	while (rd == bufsize)
	{
		bufsize += bufsize;
		tmp = malloc(sizeof(char) * bufsize);
		strcpy(tmp, ret);
		free(ret);
		ret = tmp;
		free(tmp);
		rd += read(fd, ret, bufsize);
		if (rd == -1)
			return (NULL);
	}
}

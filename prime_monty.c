#include "monty.h"

glo_t *glo = NULL;

/**
 * main - Entry point for program
 * @argc: the number of argument provided to the program
 * @argv: a pointer to pointers to the different arguments provided
 * Return: 0 (Always Success)
 */
int main(int argc, char *argv[])
{
	int fd1, res;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd1 = open(argv[1], O_RDONLY);
	if (fd1 == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	glo = malloc(sizeof(glo_t));
	if (glo == NULL)
	{
		close(fd1);
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	glo->ipt = NULL, glo->tokop = NULL;
	glo->iptint = 0;
	glo->ipt = read_file(fd1);
	res = bc_exe(glo->ipt, &stack);
	if (res == 0)
	{
		free(glo->ipt);
		free_stack(stack);
		free(glo);
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	close(fd1);
	free_stack(stack);
	free(glo->ipt);
	free(glo);
	return (0);
}

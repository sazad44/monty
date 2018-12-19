#include "monty.h"

/**
 * main - Entry point for program
 * @argc: the number of argument provided to the program
 * @argv: a pointer to pointers to the different arguments provided
 * Return: 0 (Always Success)
 */
int main(int argc, char *argv[])
{
	int fd1;

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
	close(fd1);
	return (0);
}
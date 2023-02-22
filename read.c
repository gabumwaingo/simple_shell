#include "main.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
/**
 * read_line - reads input from the user
 * Return: pointer to the buffer storing the line
 * that was read
 */
char *read_line(void)
{
	char *buff = NULL;
	size_t n = 0;

	if (getline(&buff, &n, stdin) == -1)
	{
		if (feof(stdin))
		{
			exit(0);
		}
		else
		{
			perror("Error");
			exit(1);
		}
	}
	return (buff);
}

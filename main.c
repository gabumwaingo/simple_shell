#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * main - entry point
 * Return: 0 always
 */
int main(void)
{
	char **arr;
	char *buff;
	int status;

	while (status)
	{
		printf("$");
		buff = read_line();
		arr = split_line(buff);
		status = bind(arr);

		free(buff);
		free(arr);
	}
	return (0);
}

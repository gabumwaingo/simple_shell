#include "main.h"
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
/**
 * split_line - splits the inputed line
 * @buff: the line to be split
 * Return: array of words thatwere split
 */
char **split_line(char *buff)
{
	char **arr;
	char *stkn;
	int i;

	arr = malloc(sizeof(char) * 32);
	stkn = strtok(buff, " \n");
	arr[0] = stkn;

	i = 1;
	while (stkn != NULL)
	{
		stkn = strtok(NULL, " \n");
		arr[i] = stkn;
		++i;
	}
	arr[i] = NULL;
	return (arr);
}

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include "main.h"

char *builtin_list[] = {
	"exit"
};
int (*builtin_fun[])(char **) = {
	&ls_exit
};

/**
 * num_builtins - counts the number of builtins
 * Return: number of builtins
 */
int num_builtins(void)
{
	return (sizeof(builtin_list) / sizeof(char *));
}
/**
 * bind - incoporates all functions
 * @arr:  user input
 * Return: executed commands
 */
int bind(char **arr)
{
	int i;

	if (arr[0] == NULL)
	{
		return (1);
	}

	for (i = 0; i < num_builtins(); i++)
	{
		if (strcmp(arr[0], builtin_list[i]) == 0)
			return (builtin_fun[i](arr));
	}
	return (execute(arr));
}

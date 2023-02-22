#include "main.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>

/**
 * execute - executes the commands inputted
 * by the users
 * @arr: source of the commands and arguments
 * Return: 1 on success
 */
int execute(char **arr, environ)
{
	pid_t my_pid;
	int status;

	my_pid = fork();

	if (my_pid == 0)
	{
		if (execve(arr[0], arr, NULL) == -1)
		{
			perror("Error");
		}
		exit(EXIT_FAILURE);
	}
	else if (my_pid < 0)
	{
		perror("Error");
	}
	else
	{
		wait(&status);
	}
	return (1);
}

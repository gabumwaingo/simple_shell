#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>

int _cd(char **arr);
int _alias(char **arr);
int ls_exit(char **arr);
int _env(char **arr);
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
/**
 * execute - executes the commands inputted
 * by the users
 * @arr: source pof the commands and arguments
 * Return: 1 on success
 */
int execute(char **arr)
{
	pid_t my_pid;
	int status;

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
 * ls_exit -  exits the shell
 * @arr: user input
 * Return: 0
 */
int ls_exit(char **arr)
{
	return (0);
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

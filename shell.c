#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(int argc, char **argv)
{
	char *buff = NULL;
	size_t n = 0;
	char *stkn;
	pid_t my_pid;
	int status, i;

	while (1)
	{
		printf("$ ");
		getline(&buff, &n, stdin);

		stkn = strtok(buff, " \n");

		char **arr = malloc(sizeof(char *) * 32);
		arr[0] = stkn;

		if (strcmp(arr[0], "exit") == 0)
			exit(0);

		i = 1;
		while (stkn != NULL)
		{
			stkn = strtok(NULL, " \n");
			arr[i] = stkn;
			++i;
		}

		my_pid = fork();
		if (my_pid == -1)
		{
			perror("Error");
			return (1);
		}
		else if (my_pid == 0)
		{
			execve(arr[0], arr, NULL);
		}
		else
		{
			wait(&status);
		}
	}
	free(buff);
	return (0);
}

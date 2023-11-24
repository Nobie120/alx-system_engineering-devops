#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

/**
 * infinite_while - loops infinitely
 *
 * Return: 0
 */

int infinite_while(void)
{
	while (1)
	{
		sleep(1);
	}
	return (0);
}

/**
 * main - creates five zombie proess
 *
 * Return:0 if succesful
 */

int main(void)
{
	int count = 0;
	pid_t child_pid;

	while (count < 5)
	{
		child_pid = fork();
		if (child_pid > 0)
		{
			printf("Zombie process created, PID: %d\n", child_pid);
			sleep(1);
			count++;
		}
		else
			exit(0);
	}
	infinite_while();

	return (EXIT_SUCCESS);
}

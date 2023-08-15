#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#define MAX_COMMAND_LENGTH 100
/**
 * main - simple shell
 * Return: 1 or 0
 */

int main(void)
{
	while (1)
	{
		char *command;
		pid_t child_pid;
		size_t len;
		ssize_t read;

		printf("$ "); /* Affiche le prompt*/
		command = NULL;
		len = 0;
		read = getline(&command, &len, stdin);
		if (read == -1)
		{perror("getline failed");
			exit(1); }
		if (read > 0 && command[read - 1] == '\n')
		{command[read - 1] = '\0'; }
		child_pid = fork();
		if (child_pid == -1)
		{perror("fork failed");
			exit(1); }
		else if (child_pid == 0)
		{
			char *argv[4];

			argv[0] = "/bin/sh";
			argv[1] = "-c";
			argv[2] = command;
			argv[3] = NULL;
			execve("/bin/sh", argv, NULL);
			perror("execve failed");
			exit(1);
		}
		else
		{int status;
		waitpid(child_pid, &status, 0); }
		free(command);
	}
	return (0);
}

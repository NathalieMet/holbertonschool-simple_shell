#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#define MAX_COMMAND_LENGTH 100
/**
 * display_prompt - displays the prompt
 * Return: void
 */
/* Affiche le prompt */
void display_prompt(void)
{
	printf("$ "); /* Affiche le prompt */
}
/**
 * read_command - read the command
 * Return: command
 */
/* Lit la commande entrée par l'utilisateur */
char *read_command(void)
{
	char *command;
	size_t len;
	ssize_t read;

	len = 0;
	command = NULL;
	read = getline(&command, &len, stdin);
	if (read == -1)
	{
		{perror("getline failed");
		exit(1);
		}
	}
	if (read > 0 && command[read - 1] == '\n')
	{
		command[read - 1] = '\0';
	}
	return (command);
}
/* Exécute la commande en créant un nouveau processus */
/**
 * execute_command - execute the command
 * @command : the command
 * Return: void
 */
void execute_command(char *command)
{
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("fork failed");
		exit(1);
	}
	else if (child_pid == 0)
	{
		/* Configuration des arguments pour execve*/
		char *argv[4];

		argv[0] = "/bin/sh";
		argv[1] = "-c";
		argv[2] = command;
		argv[3] = NULL;
		/* Exécute la commande en utilisant le shell*/
		execve("/bin/sh", argv, NULL);
		/* En cas d'échec de execve */
		perror("execve failed");
		exit(1);
	}
	else
	{
		/* Attends que le processus enfant se termine*/
		waitpid(child_pid, &status, 0);
	}
}
/**
 * main - simple shell
 * Return: void
 */
int main(void)
{
	char *command;

	while (1)
	{
		/* Affiche le prompt */
		if (isatty(STDIN_FILENO))
		display_prompt();
		/* Lit la commande entrée par l'utilisateur*/
		command = read_command();
		/* Exécute la commande seulement si elle n'est pas vide*/
		if (command == NULL)
		{break; }
		if (command[0] != '\0')
		{
			execute_command(command);
		}
		free(command); /* Libère la mémoire allouée par getline*/
	}
	return (0);
}

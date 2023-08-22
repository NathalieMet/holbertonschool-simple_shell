#include "main.h"
/**
 * execute_command - name of the function
 * Description: use fork to execute the command
 * @exe: executable
 * @argv: arguments
 * Return: return 0 if it succed
 */
int execute_command(char *exe, char **argv)
{
	int status;
	pid_t child_pid;

	child_pid = fork(); /* Crée un nouveau processus enfant */

	if (child_pid == -1)
	{
		perror("fork failed");
		exit(1);
	}
	else if (child_pid == 0) /* Code exécuté par le processus enfant */
	{
		if_executable(exe, argv); /* Exécute la commande */
	}
	else /* Code exécuté par le processus parent */
	{
		waitpid(child_pid, &status, 0); /* Attend la fin du processus enfant */
		/* Libération de la mémoire allouée pour exe et argv */
		if (WIFEXITED(status) && WEXITSTATUS(status) == 2)
			status = 2;
	}
	return (status);
}

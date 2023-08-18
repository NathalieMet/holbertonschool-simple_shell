#include "main.h"
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
		free(command);
		printf("\n");
		return (NULL);
	}
	if (read > 0 && command[read - 1] == '\n')
	{
		command[read - 1] = '\0';
	}
	return (command);
}

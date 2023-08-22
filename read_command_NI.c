#include "main.h"
/**
 * read_command_ni - read the command in ni mode
 * Description: read the command in NI mode
 * @command: the command inputed
 * @status: status
 * Return: command
 */
/* Lit la commande entrée par l'utilisateur */
char *read_command_ni(char *command, int status)
{
	size_t len;
	ssize_t read;

	len = 0;
	read = getline(&command, &len, stdin);

	if (read == -1)
	{
		free(command);
		perror("getline a échoué");
		exit(status);
	}
	if (read > 0 && command[read - 1] == '\n')
	{
		command[read - 1] = '\0';
	}
	return (command);
}

/**
 * check_exit - name of the function
 * Description: check exit
 * @command: the command
 * Return: 0 on success, 1 on error
*/
#include "main.h"

char *check_exit(char *command)
{
	char **commande;
	char *str;

	commande = tokenize_command(command);
	str = commande[1];
	if (str == NULL)
	{
		free(command);
		exit(0);
	}
	else
	return (str);
}

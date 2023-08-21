/**
 * check_exit - name of the function
 * Description: check exit
 * @command: the command
 * @result: nnnn
 * Return: 0 on success, 1 on error
*/
#include "main.h"

char *check_exit(char *command, char *result)
{
	char **commande;
	char *str;

	commande = tokenize_command(command);
	str = commande[1];
	if (str == NULL)
	{
		free(result);
		free(command);
		exit(0);
	}
	else
	return (str);
}

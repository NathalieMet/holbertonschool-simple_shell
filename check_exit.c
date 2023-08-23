/**
 * check_exit - name of the function
 * Description: check exit
 * @command: the command
 * @result: nnnn
 * @status: status
 * Return: 0 on success, 1 on error
*/
#include "main.h"

char *check_exit(char *command, char *result, int status)
{
	char **commande;
	char *str;

	commande = tokenize_command(command);
	str = commande[1];
	if (str == NULL)
	{
		free_tokens(commande);
		free(result);
		free(command);
		exit(status);
	}
	else
	{
		free_tokens(commande);
		return (str);
	}
}

#include "main.h"
/**
 * get_first_word - name of the function
 * Description: get the first token
 * @command: the string checked
 * @count: number of commands typed
 * @status: status
 * Return: the token
 */
char *get_first_word(char *command, int count, int status)
{
	char *copy;
	char *first_word;
	char *result;
	char *str;

	copy = strdup(command); /* Duplique la chaîne pour la manipulation */
	if (copy == NULL)
	{free(command);
		perror("strdup failed");
		exit(1); }
	first_word = strtok(copy, " ");
	if (first_word == NULL)
	{free(copy);
		exit(status); }
	result = strdup(first_word); /* Duplique le premier mot pour le retourner */
	free(copy);
	if (result == NULL)
	{free(command);
		perror("strdup failed");
		exit(1); }
	if (strcmp(result, "env") == 0)
	{free(result);
		free(command);
		print_environ(environ);
		return (NULL); }
	if (strcmp(result, "exit") == 0)
	{str = check_exit(command, result, status);
		if (str != NULL)
		{free(result);
			fprintf(stderr, "./hsh: %d: exit: Illegal number: %s\n", count, str);
			free(str);
			return (NULL); }
			}
	return (result);
}

#include "main.h"
/**
 * get_first_word - name of the function
 * Description: get the first token
 * @command: the string checked
 * Return: the token
 */
char *get_first_word(char *command)
{
	char *copy;
	char *first_word;
	char *result;

	copy = strdup(command); /* Duplique la chaîne pour la manipulation */
	if (copy == NULL)
	{
		free(command);
		perror("strdup failed");
		exit(1);
	}
	first_word = strtok(copy, " ");
	if (first_word == NULL)
	{
		fprintf(stderr, "No word found.\n");
		free(copy);
		exit(1);
	}

	result = strdup(first_word); /* Duplique le premier mot pour le retourner */
	free(copy);
	if (result == NULL)
	{
		perror("strdup failed");
		exit(1);
	}

	if (strcmp(result, "exit") == 0)
	{
		free(result);
		exit(0);
	}
	return (result);
}

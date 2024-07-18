/**
 * tokenize_command - name of the function
 * Description: tokenize the command
 * @command: the command
 * Return: tokens on success, 1 on error
*/
#include "main.h"

char **tokenize_command(const char *command)
{
	char **tokens;
	char *token;
	int token_count;
	char *command_copy;

	tokens = malloc(150 * sizeof(char *));
	if (tokens == NULL)
	{
		perror("Allocation error");
		exit(1);
	}
	token_count = 0;
	command_copy = strdup(command);
	if (command_copy == NULL)
	{
		free(tokens);
		perror("strdup failed");
		exit(1);
	}
	token = strtok(command_copy, " ");
	while (token != NULL && token_count < 150)
	{
		tokens[token_count] = strdup(token);
		if (tokens[token_count] == NULL)
		{
			free_tokens(tokens);
			free(command_copy);
			perror("strdup failed");
			exit(1);
		}
		token_count++;
		token = strtok(NULL, " ");
	}
	tokens[token_count] = NULL;
	free(command_copy);
	return (tokens);
}

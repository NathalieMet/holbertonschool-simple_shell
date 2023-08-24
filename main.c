#include "main.h"
/**
 * main - name of the function
 * Description: main function of simple shell
 * Return: void
 */
int main(void)
{
	char *command;
	char *first_word;
	char *exe;
	char **argv;
	int command_count = 1;
	int status = 0;

	while (1)
	{ /* Boucle infinie */
		if (isatty(STDIN_FILENO))
			printf("$ ");
		command = read_command();
		if (command == NULL)
			break; /* Sortir de la boucle en cas d'erreur de lecture */
		if (is_it_empty(command))
		{
			free(command);
			continue; /* Ignorer les commandes vides */
		}
		first_word = get_first_word(command, command_count, status);
		if (first_word != NULL)
		{
			argv = tokenize_command(command);
			exe = check_first_word(first_word);
			free(command); /* Libérer la mémoire allouée pour command */
			if (exe != NULL)
			{
				status = execute_command(exe, argv);
			}
			else
			{
				fprintf(stderr, "./hsh: %d: %s: not found\n", command_count, first_word);
				status = 127;
			}
			free_tokens(argv);
			free(exe);
			free(first_word);
		} command_count++;
	}
	return (status);
}

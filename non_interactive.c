#include "main.h"
/**
 * non_interactive - name of the function
 * Description read the command in non-interactive mode
 * Return: status
 */
int non_interactive(void)
{
	char *command;
	char *first_word;
	char *exe;
	char **argv;
	int command_count = 1;
	int status;

	while (1)
	{ /* Boucle infinie */
		command = read_command(status);
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
			exe = check_dir_path(first_word);
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
		}
		command_count++;
	}
	return (status);
}

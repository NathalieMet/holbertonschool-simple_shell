#include "main.h"
/**
 * non_interactive - name of the function
 * Description: read the command in non-interactive mode
 */
void non_interactive(void)
{
	int count = 1;
	char *command;
	char *commande_lue;
	char *first_word;
	char *exe;
	char **argv;
	int status = 0;

	command = (char *)malloc(MAX_COMMAND_LENGTH * sizeof(char));
	if (command == NULL)
	{
		perror("malloc a échoué");
		exit(1);
	}
	commande_lue = read_command_ni(command, status);

	/* Exécuter la commande seulement si elle n'est pas vide */
	if (commande_lue[0] != '\0')
	{
		first_word = get_first_word(commande_lue, count, status);
		if (first_word != NULL)
		{
			argv = tokenize_command(commande_lue);
			exe = check_dir_path(first_word);
			if (exe != NULL)
			{
				execute_command(exe, argv);
			}
			else
			{
				fprintf(stderr, "./hsh: 1: %s: not found\n", first_word);
				status = 127;
			}
			free(first_word);

			free_tokens(argv);
		}
	}
	free(command); /* Libérer la mémoire */
	exit(status);
}

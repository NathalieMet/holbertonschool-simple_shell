#include "main.h"
/**
 * interactive - name of the function
 * Description: treat an input in interactive mode
 * Return: 0
*/
int interactive(void)
{
	char *command;
	char *first_word;
	char *exe;
	char **argv;
	int i, command_count = 1;

	while (1)
	{ /* Boucle infinie */
		display_prompt();

		command = read_command();
		if (command == NULL)
			break; /* Sortir de la boucle en cas d'erreur de lecture */

		if (is_it_empty(command))
			continue; /* Ignorer les commandes vides */

		first_word = get_first_word(command);

		if (first_word != NULL)
		{
			argv = tokenize_command(command);
			exe = check_dir_path(first_word);
			if (exe != NULL)
			{
				execute_command(exe, argv);
			}
			else
			{
				fprintf(stderr, "hsh: %d: %s: not found\n", command_count, first_word);
			}
			free(first_word);
			for (i = 0; argv[i] != NULL; i++)
			free(argv[i]);

			free(argv);
		}
		command_count++;
	}
	return (0);
}

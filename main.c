#include "main.h"

int main()
{
	char *command;
	char *first_word;
	char *exe;
	char **argv;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			display_prompt();

		command = read_command();

		first_word = get_first_word(command);

		if (first_word != NULL)
		{
			argv = tokenize_command(command);
			exe = check_dir_path(first_word);

			if (exe != NULL)
			{
				printf("Le premier mot de la commande est dans le chemin /bin/\n");
				if_executable(exe, argv);
			}
			else
			{
				printf("Le premier mot de la commande n'est pas dans le chemin /bin/\n");
			}
			free(first_word);
		}
		free(command);
	}
	return 0;
}

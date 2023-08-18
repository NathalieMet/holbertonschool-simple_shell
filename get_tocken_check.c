#include "main.h"
/**
 * read_command - read the command
 * Return: command
 */
/* Lit la commande entrée par l'utilisateur */
char *read_command(void)
{
	char *command;
	size_t len;
	ssize_t read;
	len = 0;
	command = NULL;
	read = getline(&command, &len, stdin);
	if (read == -1)
	{
		perror("getline failed");
		exit(1);
	}
	if (read > 0 && command[read - 1] == '\n')
	{
		command[read - 1] = '\0';
	}
	return (command);
}

int main()
{
	char *command;
	char *token;
	char *first_word;
	char *exe;
	char **argv;
	// ... (autres parties du code, comme l'affichage du prompt et la lecture de la commande)

	command = read_command(); // Supposons que vous avez une fonction read_command() pour lire l'entrée utilisateur

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

	return 0;
}

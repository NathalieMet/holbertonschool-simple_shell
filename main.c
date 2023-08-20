#include "main.h"
/**
 * main - function main
 * Description: simple shell main function
 * Return: 1
 */
int main(void)
{
	char *command;
	char *first_word;
	char *exe;
	char **argv;
	int command_count = 1; /* Initialisation du compteur de commandes */

	while (1)
	{
		if (isatty(STDIN_FILENO))
			display_prompt();
		if (command != NULL)
		{
			free(command);
			command = NULL;
		}
		command = read_command();
		if (command == NULL)
			break;
		if (is_it_empty(command))
			continue;
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
				fprintf(stderr, "hsh: %d: %s: not found\n", command_count, first_word);
			free(first_word);
		}
		command_count++;
		if (!isatty(STDIN_FILENO))
		return (0);
	}
	return (0);
}

#include <sys/stat.h> // Inclure sys/stat.h pour struct stat et constantes
#include "main.h"
#define MAX_COMMAND_LENGTH 100

// ... (déclarations de fonctions display_prompt et read_command)

char *check_dir_path(char *first_word)
{
	char full_path[MAX_COMMAND_LENGTH];
	char *path_env = _getenv("PATH");
	char *dir;
	struct stat file_stat;
	int found = 0;

	if (path_env != NULL)
	{
		dir = strtok(path_env, ":");
		while (dir != NULL)
		{

			snprintf(full_path, sizeof(full_path), "%s/%s", dir, first_word);

			if (stat(full_path, &file_stat) == 0)
			{
				if (S_ISREG(file_stat.st_mode) && (file_stat.st_mode & S_IXUSR))
					return (strdup(full_path));
			}
			if (stat(first_word, &file_stat) == 0)
			return (strdup(first_word));

			dir = strtok(NULL, ":");
		}
	}

	return (NULL);
}

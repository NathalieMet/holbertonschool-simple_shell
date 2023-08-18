#include <sys/stat.h>
#include "main.h"
#define MAX_COMMAND_LENGTH 100
/**
 * check_dir_path - name of the function
 * Description: check if the token is an executable
 * @first_word: the string checked
 * Return: return the executable or NULL
 */
char *check_dir_path(char *first_word)
{
	char full_path[MAX_COMMAND_LENGTH];
	char *path_env = _getenv("PATH");
	char *path_copy;
	char *dir;
	struct stat file_stat;

	if (path_env != NULL)
	{
		path_copy = strdup(path_env);
		dir = strtok(path_copy, ":");
		while (dir != NULL)
		{

			snprintf(full_path, sizeof(full_path), "%s/%s", dir, first_word);

			if (stat(full_path, &file_stat) == 0)
			{
				if (S_ISREG(file_stat.st_mode) && (file_stat.st_mode & S_IXUSR))
				{
					free(path_copy);
					return (strdup(full_path));
				}
			}
			if (stat(first_word, &file_stat) == 0)
			{
				free(path_copy);
				return (strdup(first_word));
			}

			dir = strtok(NULL, ":");
		}
		free(path_copy);
	}
	return (NULL);
}

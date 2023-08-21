#include "main.h"
/**
 * if_executable - name of the function
 * Description: use the execve function
 * @exe: thje executable
 * @argv: the arguments
 * Return: return 0 if it's true
*/
int if_executable(char *exe, char **argv)
{
	int i;

	if (execve(exe, argv, environ) == -1)
	{
		/* En cas d'échec de execve */
		perror("execve failed");
		free(exe);
		for (i = 0; argv[i] != NULL; i++)
		{
			free(argv[i]);
		}
		free(argv);
		exit(1);
	}
	return (0);
}

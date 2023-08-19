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
	if (execve(exe, argv, environ) == -1)
	{
		/* En cas d'échec de execve */
		perror("execve failed");
		exit(1);
	}
	return (0);
}

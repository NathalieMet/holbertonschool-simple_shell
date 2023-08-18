#include "main.h"

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

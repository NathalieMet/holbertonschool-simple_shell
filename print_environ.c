#include "main.h"
/**
 * print_environ - name of the function
 * Description: print the environ
 * @environ: environ
 * Return: 0 if it works
*/
void print_environ(char **environ)
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		printf("%s\n", environ[i]);
	}
}

#include <stdio.h>
#include <string.h>
#include "main.h"
/**
 * _getenv - searches for the environment string pointed to by name and returns
 * the associated value to the string.
 * Description: _getenv function
 * @name: the string checked
 * Return: environnement string ou NULL
 */

char *_getenv(const char *name)
{
	int i;
	int len;

	len = strlen(name);

	for (i = 0 ; environ[i] ; i++)
	{
		if (strncmp(name, environ[i], len) == 0 && environ[i][len] == '=')
		{
			return (&environ[i][len + 1]);
		}
	}
	return (NULL);
}

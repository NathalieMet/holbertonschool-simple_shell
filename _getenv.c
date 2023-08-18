#include <stdio.h>
#include <string.h>
#include "main.h"

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

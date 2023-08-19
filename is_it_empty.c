#include "main.h"
/**
 * is_it_empty - name of the function
 * Description: check if the string is empty
 * @str: the string checked
 * Return: return 0 if it's true
*/
int is_it_empty(const char *str)
{
	while (*str != '\0')
	{
		if (*str != ' ' && *str != '\t' && *str != '\n')
			if (*str != '\r' && *str != '\v' && *str != '\f')
			return (0);
		str++;
	}
	return (1);
}

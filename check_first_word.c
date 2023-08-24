#include "main.h"
/**
 * check_first_word - name of the function
 * Description: print the prompt's logo
 * @first_word: variable
 * Return: return NULL ou first_word
 */
char *check_first_word(char *first_word)
{
	char *first_token;

	first_token = check_dir_path(first_word);

	if (first_token == NULL)
	{
		if (first_word[0] == '/' || first_word[0] == '.')
		{
			return (strdup(first_word));
		}
	}
	if (first_token != NULL)
	{

		return (first_token);
	}
	return (NULL);
}

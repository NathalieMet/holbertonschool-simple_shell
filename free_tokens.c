#include "main.h"
/**
 * free_tokens - name of the function
 * Description: free the tokens
 * @tokens: the arguments's string
*/
void free_tokens(char **tokens)
{
	int i;

	for (i = 0; tokens[i] != NULL ; i++)
	{
		free(tokens[i]);
	}
	free(tokens);
}

#include "main.h"

char *get_first_word(const char *command)
{
	char *copy;
	char *first_word;
	char *result;

	copy = strdup(command); /* Duplique la chaîne pour la manipulation */
	if (copy == NULL)
	{
		perror("strdup failed");
		exit(1);
	}

	first_word = strtok(copy, " ");
	if (first_word == NULL)
	{
		fprintf(stderr, "No word found.\n");
		free(copy);
		exit(1);
	}

	result = strdup(first_word); /* Duplique le premier mot pour le retourner */
	if (result == NULL)
	{
		perror("strdup failed");
		free(copy);
		exit(1);
	}

	free(copy); /* Libère la mémoire de la copie temporaire */
	return (result);
}

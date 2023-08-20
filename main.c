#include "main.h"
/**
 * main - main function
 * Description: description
 * Return: 0
*/
int main(void)
{
	if (isatty(STDIN_FILENO))
	{
		interactive();
	}
	else
	{
		non_interactive();
	}
	return (0);
}

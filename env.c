#include "main.h"

/**
 * display_prompt - Displays a shell prompt
 *
 * Description: Writes the shell prompt to the standard output.
 */
void display_prompt(void)
{
	write(STDOUT_FILENO, "$ ", 2);
}

/**
 * read_line - Reads a line of input from the user
 *
 * Description: Reads a line of input from the standard input
 * using the getline function.
 *
 * Return: A pointer to the allocated buffer containing the input.
 */
char *read_line(void)
{
	char *buffer = NULL;
	size_t bufsize = 0;

	getline(&buffer, &bufsize, stdin);
	return (buffer);
}

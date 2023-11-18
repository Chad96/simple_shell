#include "main.h"

/**
 * main - Entry point of the program
 *
 * Description: Calls functions from different modules
 * to run a basic shell.
 *
 * Return: Always 0
 */
int main(void)
{
	char *input;

	while (1)
	{
		display_prompt();
		input = read_line();

		if (!input)
			return (1);

		if (strcmp(input, "exit") == 0)
		{
			free(input);
			break;
		}
		execute_command(input);
		free(input);
	}
	exit_shell();
	return (0);
}

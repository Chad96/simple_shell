#include "main.h"

/**
 * parse_command - Parse the input command into arguments
 * @input: The input command string
 * @args: An array to store the parsed arguments
 * @arg_count: A pointer to store the count of arguments
 *
 * Return: 0 on success, -1 on failure
 */
int parse_command(char *input, char **args, int *arg_count)
{
	char *token;

	*arg_count = 0;

	token = strtok(input, " ");

	while (token != NULL)
	{
		if (*arg_count >= MAX_ARGS)
		{
			char error_message[] = "Error: Too many arguments\n";

			write(STDERR_FILENO, error_message, sizeof(error_message) - 1);
			return (-1);
		}
		args[*arg_count] = token;
		(*arg_count)++;
		token = strtok(NULL, " ");
	}
	args[*arg_count] = NULL;
	return (0);
}
/**
 * run_shell - Executes the shell with the given command
 * @command: The command to execute
 */
void run_shell(char *command)
{
	char message[256];

	snprintf(message, sizeof(message), "Executing: %s\n", command);
	write(STDOUT_FILENO, message, strlen(message));
}

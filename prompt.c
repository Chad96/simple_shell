#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "main.h"

#define MAX_COMMAND_LENGTH 100

/**
 * run_prompt - Runs a simple shell prompt
 * @command: The command to execute
 * execute_command - Executes the given command using fork and execve
 *
 * Description: Displays a prompt and executes a command entered by the user.
 */
void execute_command(char *command);

void run_prompt(void)
{
	char command[MAX_COMMAND_LENGTH];

	while (1)
	{
		char prompt[] = "#cisfun$ ";

		write(fileno(stdout), prompt, strlen(prompt));
		if (fgets(command, MAX_COMMAND_LENGTH, stdin) == NULL)
		{
			write(fileno(stdout), "\n", 1);
			break;
		}
		command[strcspn(command, "\n")] = '\0';
		if (strlen(command) == 0)
		{
			continue;
		}
		execute_command(command);
	}
}
/**
 * execute_command - Executes a command in a child process
 * @command: The command to be executed
 *
 * Description: Forks a child process and executes the command.
 */
void execute_command(char *command)
{
	char **args;
	char exec_error[] = "execve error\n";

	pid_t child_pid;

	if (!command)
		return;

	args = malloc(4 * sizeof(char *));

	if (args == NULL)
	{
		perror("malloc");
		return;
	}
	args[0] = "/bin/sh";
	args[1] = "-c";
	args[2] = command;
	args[3] = NULL;

	child_pid = fork();

	if (child_pid == -1)
	{
		perror("fork");
		free(args);
		return;
	}
	if (child_pid == 0)
	{
		if (execve(args[0], args, NULL) == -1)
		{
			write(STDERR_FILENO, exec_error, sizeof(exec_error) - 1);
			_exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(NULL);
	}
	free(args);
}

#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "main.h"

#define MAX_COMMAND_LENGTH 100
#define MAX_ARGS 10

/**
 * implement_command - Executes a command in a child process
 * @command: The command to be executed
 *
 * Description: Tokenizes the command, forks a child process, and
 * executes the command using execvp.
 */
void implement_command(char *command)
{
	char *args[MAX_ARGS];
	int i = 0;
	char *token = strtok(command, " ");

	while (token != NULL && i < MAX_ARGS)
	{
		args[i] = token;
		token = strtok(NULL, " ");
		i++;
	}
	args[i] = NULL;

	if (i > 0)
	{
		pid_t pid = fork();

		if (pid == 0)
		{
			execvp(args[0], args);
			perror("execvp");
			exit(1);
		}
		else if (pid > 0)
		{
			int status;

			waitpid(pid, &status, 0);
		}
		else
		{
			perror("fork");
		}
	}
}

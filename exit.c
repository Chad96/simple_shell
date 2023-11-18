#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "main.h"
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100

/**
 * exit_shell - Exits the shell
 *
 * Description: Prints a message and exits the shell.
 */
void exit_shell(void)
{
	printf("Exiting the shell\n");
	exit(0);
}

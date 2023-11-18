#ifndef MAIN_H
#define MAIN_H
#define MAX_ARGS 10 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

char *read_line(void);
void run_shell(char *command);
void display_prompt(void);
void leo_print(const char *message);
void read_command(char *command, size_t size);
void execute_command(char *command);
void exit_shell(void);
void run_prompt(void);
void implement_command(char *command);
#endif /* MAIN_ H*/

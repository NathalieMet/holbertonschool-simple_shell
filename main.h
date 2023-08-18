#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <features.h>
extern char **environ;

#define _GNU_SOURCE

#define MAX_COMMAND_LENGTH 100
char *check_dir_path(char *first_word);
char *get_first_word(const char *command);
char *read_command(void);
void display_prompt(void);
void execute_command(char *command);
char *_getenv(const char *name);
char **tokenize_command(const char *command);
int if_executable(char *exe, char **argv);

#endif /* MAIN_H */

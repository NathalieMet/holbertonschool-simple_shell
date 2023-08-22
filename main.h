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
char *get_first_word(char *command, int count, int status);
char *read_command(void);
void display_prompt(void);
char *_getenv(const char *name);
char **tokenize_command(const char *command);
int if_executable(char *exe, char **argv);
int execute_command(char *exe, char **argv);
int is_it_empty(const char *str);
int non_interactive(void);
int interactive(void);
char *read_command_ni(char *command, int status);
char *check_exit(char *command, char *result, int status);
void free_tokens(char **tokens);

#endif /* MAIN_H */

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
char *check_first_word(char *first_word);
char *_getenv(const char *name);
char **tokenize_command(const char *command);
int execute_command(char *exe, char **argv);
int is_it_empty(const char *str);
char *check_exit(char *command, char *result, int status);
void free_tokens(char **tokens);
void print_environ(char **environ);

#endif /* MAIN_H */

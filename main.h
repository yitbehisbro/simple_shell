#ifndef _MAIN_H_
#define _MAIN_H_

#define _GNU_SOURCE
#define TOKEN_BUFSIZE 64
#define TOKEN_DELIM "\" \t\r\n\a"
#define BUFSIZE 1024

#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>

void hsh_loop(void);
char **split_line(char *line);
char *read_line(void);
int hsh_execute(char **args);
int hsh_launch(char **args);
int hsh_exit(char **args);
int hsh_help(char **args);
int hsh_cd(char **args);
int hsh_num_builtins(void);
int hsh_clear(char **args);
char *_strtok(char *str, char *delim);
unsigned int is_delim(char str, char *delim);
char *_strchr(char *s, char c);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
ssize_t _getline(char **lineptr, ssize_t *n, FILE *stream);
char *read_loop(void);
int hsh_env(char __attribute__((unused)) **args);
int _strcmp(char *s1, char *s2);
int _atoi(char *s);
int _unsetenv(char **args);
int _setenv(char **args);
int count_args(char **argv);
int create_file(const char *filename, char *text_content);

#endif

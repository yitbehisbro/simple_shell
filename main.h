#ifndef _MAIN_H_
#define _MAIN_H_

#define LSH_TOK_BUFSIZE 64
#define LSH_TOK_DELIM "\" \t\r\n\a"

#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void lsh_loop(void);
char **lsh_split_line(char *line);
char *lsh_read_line(void);
int lsh_execute(char **args);
int lsh_launch(char **args);
int lsh_exit(char **args);
int lsh_help(char **args);
int lsh_cd(char **args);
int lsh_num_builtins(void);

#endif

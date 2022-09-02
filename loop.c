#include "main.h"

/**
 * hsh_loop - read input until exit
 *
 * Return: void no return
 */
void hsh_loop(void)
{
	char *line;
	char **args;
	int status;

	do{
		printf("$ ");
		line = read_line();
		args = split_line(line);
		status = hsh_execute(args);

		free(line);
		free(args);
	} while (status);
}

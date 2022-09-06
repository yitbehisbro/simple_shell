#include "main.h"

/**
 * echo_argv - prints the argument vectors
 * @argv: argument vector
 *
 * Return: 1 in success else -1
 */
int echo_argv(char **argv, pid_t child_pid, int status)
{
	char *ch[] = {"echo", "$$", "$?", "$PATH", NULL};
	int exit_status = WEXITSTATUS(status);

	if (argv == NULL)
		return (-1);
	if (strcmp(argv[0], ch[0]) == 0)
	{
		if (strcmp(argv[1], ch[1]) == 0)
			printf("%d\n", child_pid);
		else if (strcmp(argv[1], ch[2]) == 0)
			printf("%d\n", exit_status);
		else if (strcmp(argv[1], ch[3]) == 0)
			printf("%s\n", getenv("PATH"));
		else
			perror("sh:");
	}
	
}

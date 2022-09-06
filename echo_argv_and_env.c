#include "main.h"

/**
 * echo_argv - prints the argument vectors
 * @argv: argument vector
 * @child_pid: child process id
 *
 * Return: 1 in success else -1
 */
int echo_argv(char **argv, pid_t child_pid)
{
	char *ch[] = {"echo", "$$", "$?", "$PATH", NULL};

	if (argv == NULL)
		return (-1);
	if (strcmp(argv[0], ch[0]) == 0)
	{
		if (strcmp(argv[1], ch[1]) == 0)
			printf("%d\n", child_pid);
		else if (strcmp(argv[1], ch[2]) == 0)
			printf("%s\n", getenv("EXIT_STATUS"));
		else if (strcmp(argv[1], ch[3]) == 0)
			printf("%s\n", getenv("PATH"));
		else
			perror("sh:");
	}
	return (1);
}

#include "main.h"

/**
 * echo_argv - prints the argument vectors
 * @argv: argument vector
 * @status: exit status
 *
 * Return: 1 in success else -1
 */
int echo_argv(char **argv, int status)
{
	pid_t pid;
	char *ch[] = {"echo", "$$", "$?", "$PATH", NULL};

	pid = getppid();
	if (argv == NULL)
		return (-1);

	if (strcmp(argv[0], ch[0]) == 0)
	{
		if (strcmp(argv[1], ch[1]) == 0)
		{
			printf("%u\n", pid);
			exit(EXIT_SUCCESS);
		}
		else if (strcmp(argv[1], ch[3]) == 0)
		{
			printf("%s\n", getenv("PATH"));
			exit(EXIT_SUCCESS);
		}
		else if (strcmp(argv[1], ch[2]) == 0)
		{
			printf("%d\n", op_exit_status(status));
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror("sh");
			exit(EXIT_FAILURE);
		}
	}
	return (1);
}
/**
 * op_exit_status - prints the exit status
 * @status: exit status
 *
 * Return: exit status in success else -1
 */
int op_exit_status(int status)
{
	int exit_status;

	if (!WIFEXITED(status))
	{
		return (-1);
	}
	exit_status = WEXITSTATUS(status);
	return (exit_status);
}

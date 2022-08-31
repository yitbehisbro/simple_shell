#include "main.h"

/**
 * hsh_launch - launchs a program
 * @args: NULL terminated list of arguments
 *
 * Return: Always returns 1
 */
int hsh_launch(char **args)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		if (execvpe(args[0], args, NULL) == -1)
		{
			fprintf(stderr, "%s: not found\n", args[0]);
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		fprintf(stderr, "not found\n");
	}
	else
	{
		do
		{
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (1);
}

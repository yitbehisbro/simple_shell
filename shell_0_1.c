#include "main.h"

int hsh_launch(char **args)
{
	pid_t pid;
	int status;
	char *env_var[] = {"HOME", "USER", "LOGNAME", "PATH", "SESSION", "LANG", NULL};

	pid = fork();
	if (pid == 0)
	{
		if (execve(args[0], args, env_var) == -1)
		{
			perror("./shell");
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		perror("./shell");
	}
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (1);
}

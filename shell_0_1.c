#include "main.h"

int shell_launch(char **args)
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

/**
 * shell_loop - read input until exit
 *
 * Return: void no return
 */
void shell_loop(void)
{
	char *line;
	char **args;
	int status;

	do {
		printf("#cisfun$ ");
		line = read_shell_line();
		args = split_line(line);
		status = shell_execute(args);

		free(line);
		free(args);
	} while (status);
}
/**
 * read_shell_line - read a line
 *
 * Return: Null-terminated
 */
char *read_shell_line(void)
{
	char *line = NULL;
	ssize_t bufsize = 0;

	if (_getline(&line, &bufsize, stdin) == -1)
	{
		if (feof(stdin))
		{
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror("getline\n");
			exit(EXIT_FAILURE);
		}
	}
	return (line);
	return (read_shell_loop());
}

/**
 * read_shell_loop - reads the line
 *
 * Return: buffer
 */
char *read_shell_loop(void)
{
	int c, position = 0, bufsize = BUFSIZE;
	char *buffer = malloc(sizeof(char) * bufsize);

	if (!buffer)
	{
		fprintf(stderr, "allocation error\n");
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		c = getchar();
		if (c == EOF)
		{
			exit(EXIT_SUCCESS);
		}
		else if (c == '\n')
		{
			buffer[position] = '\0';
			return (buffer);
		}
		else
		{
			buffer[position] = c;
		}
		position++;
		if (position >= bufsize)
		{
			bufsize += BUFSIZE;
			buffer = realloc(buffer, bufsize);
			if (!buffer)
			{
				fprintf(stderr, "allocation error\n");
				exit(EXIT_FAILURE);
			}
		}
	}
}

#include "main.h"

/**
 * _atoi - prints integers
 * @s: character that holds string values
 * Return: Always 0.
 */
int _atoi(char *s)
{
	unsigned int size, length, outp, signs, x, y;

	length = 0;
	size = 0;
	outp = 0;
	signs = 1;
	x = 1;

	while (*(s + length) != '\0')
	{
		if (size > 0 && (*(s + length) < '0' || *(s + length) > '9'))
			break;

		if (*(s + length) == '-')
			signs *= -1;

		if ((*(s + length) >= '0') && (*(s + length) <= '9'))
		{
			if (size > 0)
				x *= 10;
			size++;
		}
		length++;
	}

	for (y = length - size; y < length; y++)
	{
		outp = outp + ((*(s + y) - 48) * x);
		x /= 10;
	}
	return (outp * signs);
}

/**
 * hsh_exit_status - exit a program
 * @status: status for exit
 *
 * Return: exit status
 */
int hsh_exit_status(int status)
{
	exit(status);
	return (status);
}
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
	char *exit_status[] = {"exit", NULL}, *setenv_var[] = {"setenv", NULL};
	char *unsetenv_var[] = {"unsetenv", NULL}, *argv_exit[] = {"echo", "$$", NULL};

	pid = fork();
	if (pid == 0)
	{
		echo_argv(args, status, 0);
		if (execvp(args[0], args) == -1)
		{
			if (((args[0] == exit_status[0]) && (_atoi(args[1]) >= 0 ||
							     _atoi(args[1]) <= 0)) && (args[2] == NULL))
				hsh_exit_status(_atoi(args[1]));
			else if ((args[0] == exit_status[0]) && (args[1] == NULL))
				hsh_exit(args);
			else if (args[0] == setenv_var[0])
				_setenv(args);
			else if (args[0] == unsetenv_var[0] && args[1] != NULL && args[2] == NULL)
				_unsetenv(args);
			else
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
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
		echo_argv(argv_exit, op_exit_status(status), 1);
	}
	return (1);
}

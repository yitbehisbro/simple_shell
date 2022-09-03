#include "main.h"

/**
 * _atoi - prints integers
 * @s: character that holds string values
 * Return: Always 0.
 */
int _atoi(char **s)
{
	unsigned int size, lengt, outp, signs, x, y;

	lengt = 0;
	size = 0;
	outp = 0;
	signs = 1;
	x = 1;

	while (s[lengt] != NULL)
	{
		if (size > 0 && (s[lengt] < '0' || s[lengt] > '9'))
			break;

		if (s[lengt] == '-')
			signs *= -1;

		if (s[lengt] >= '0') && (s[lengt] <= '9'))
		{
			if (size > 0)
				x *= 10;
			size++;
		}
		lengt++;
	}

	for (y = lengt - size; y < lengt; y++)
	{
		outp = outp + (s[y] - 48) * x);
		x /= 10;
	}
	return (outp * signs);
}

/**
 * hsh_exit_status - exit a program
 * @args: NULL terminated list of arguments
 *
 * Return: exit status
 */
int hsh_exit_status(char **args)
{
	exit(_atoi(args[0]));
	return (_atoi(args[0]));
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
	char **exit = "exit";

	pid = fork();
	if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
		{
			if (args[0] == exit && _atoi(args[1]) >= 0 || _atoi(args[1]) <= 0 && args[2] == NULL)
				hsh_exit_status(args[1]);
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
	}
	return (1);
}

#include "main.h"

/**
 * red - set colors to red
 *
 * Return: no return
 */
void red(void)
{
	printf("\033[1;31m");
}

/**
 * reset - set colors to orginal
 *
 * Return: no return
 */
void reset(void)
{
	printf("\033[0m");
}

/**
 * count_args - counts the parameter passed
 * @argv: argument vector
 *
 * Return: number of word else 1
 */
int count_args(char **argv)
{
	int i = 0;

	if (argv == NULL)
	{
		return (1);
	}
	while (argv[i] != NULL)
	{
		i++;
	}
	/** printf("Counter: %d\nIteration: %d\n", counter, i);*/
	return (i);
}
/**
 * _setenv - set envirnomental variable
 * @args: arguments vector
 *
 * Return: -1 in error and 1 to enable prompt
 */
int _setenv(char **args)
{
	int argc = count_args(args);

	if (args == NULL)
	{
		return (1);
	}
	if (argc == 1)
		fprintf(stderr, "hsh: Very few argument for: %s.\nTry 'man setenv' for more information.\n", args[0]);
	if (argc == 2)
		fprintf(stderr, "hsh: Very few argument for: %s.\nTry 'man setenv' for more information.\n", args[0]);
	if (argc > 3)
		fprintf(stderr, "hsh: Too much argument for: %s.\nTry 'man setenv' for more information.\n", args[0]);
	if (argc == 3)
	{
		if (setenv(args[1], args[2], 1) == -1)
		{
			red();
			fprintf(stderr, "error: ");
			reset();
			fprintf(stderr, "Failed to set the variable\n");
		}
	}
	return (1);
}

/**
 * _unsetenv - set envirnomental variable
 * @args: arguments vector
 *
 * Return: -1 in error, 0 for success and 1 to enable prompt
 */
int _unsetenv(char **args)
{
	int argc = count_args(args);

	if (args == NULL)
	{
		return (1);
	}
	if (argc == 1)
		fprintf(stderr, "hsh: Very few argument for: %s.\nTry 'man unsetenv' for more information.\n", args[0]);
	if (argc > 2)
		fprintf(stderr, "hsh: Too much argument for: %s.\nTry 'man unsetenv' for more information.\n", args[0]);
	if (argc == 2)
	{
		if (unsetenv(args[1]) == -1)
		{
			red();
			fprintf(stderr, "error: ");
			reset();
			fprintf(stderr, "Failed to unset the variable\n");
		}
	}
	return (1);
}

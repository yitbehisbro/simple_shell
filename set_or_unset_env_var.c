#include "main.h"

/**
 * count_args - counts the parameter passed
 * @argv: argument vector
 *
 * Return: number of word else 1
 */
int count_args(char **argv)
{
	int counter = 1, i = 0;

	if (argv == NULL)
	{
		return (1);
	}
	while (argv[i] != NULL)
	{
		counter++;
		i++;
	}
	return (counter);
}
/**
 * _setenv - set envirnomental variable
 * @args: arguments vector
 *
 * Return: -1 in error and 1 to enable prompt
 */
int _setenv(char **args)
{
	if (count_args(args) < 2 || count_args(args) > 3)
	{
		fprintf(stderr, "hsh: Failed to set the variable\n");
	}	
	if (args == NULL)
	{
		return (1);
	}
	if (setenv(args[1], args[2], 1) == -1)
	{
		fprintf(stderr, "hsh: Failed to set the variable\n");
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
	if (args == NULL)
	{
		return (1);
	}
	if (unsetenv(args[1]) == -1)
	{
		fprintf(stderr, "hsh: Failed to unset the variable\n");
	}
	return (1);
}

#include "main.h"

/**
 * _setenv - set envirnomental variable
 * @args: arguments vector
 *
 * Return: -1 in error and 1 to enable prompt
 */
int _setenv(char **args)
{
	if (setenv(args[1], args[2], 1) == -1)
	{
		fprintf(stderr, "Failed to set the variable"); 
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
	if (unsetenv(args[1]) == -1)
	{
		fprintf(stderr, "Failed to unset the variable"); 
	}
	return (1);
}

#include "main.h"

/**
 * _strcmp - compare two strings
 * @s1: pointer to character var 1
 * @s2: pointer to character var 2
 * Return: Always 0.
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && (*s1 != '\0' && *s2 != '\0'))
	{
		s1++;
		s2++;
	}

	if (*s1 != *s2)
	{
		return (*s1 - *s2);
	}
	else
	{
		return (0);
	}
}

/**
 * hsh_execute - execute built-in command or launch program
 * @args: NULL terminated list of arguments
 *
 * Return: 1 if the shell should continue running,
 * 0 if it should terminate
 */
int hsh_execute(char **args)
{
	int i;
	char *builtin_str[] = {"cd", "help", "exit", "clear", "env"};

	int (*builtin_func[]) (char **) = {&hsh_cd, &hsh_help, &hsh_exit, &hsh_clear, &hsh_env};

	if (args[0] == NULL)
	{
		return (1);
	}
	for (i = 0; i < hsh_num_builtins(); i++)
	{
		if (_strcmp(args[0], builtin_str[i]) == 0)
		{
			return ((*builtin_func[i])(args));
		}
	}
	return (hsh_launch(args));
}

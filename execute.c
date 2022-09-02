#include "main.h"

/**
 * @builtin_func: catch in array built-in command
 *
 * Return: always 0
 */
int (*builtin_func[]) (char **) = {&hsh_cd, &hsh_help, &hsh_exit, &hsh_clear};

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
	char *builtin_str[] = {"cd", "help", "exit", "clear"};

	if (args[0] == NULL)
	{
		return (1);
	}
	for (i = 0; i < hsh_num_builtins(); i++)
	{
		if (strcmp(args[0], builtin_str[i]) == 0)
		{
			return ((*builtin_func[i])(args));
		}
	}
	return (hsh_launch(args));
}

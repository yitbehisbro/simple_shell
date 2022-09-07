#include "main.h"

/**
 * shell_execute - execute built-in command or launch program
 * @args: NULL terminated list of arguments
 *
 * Return: 1 if the shell should continue running,
 * 0 if it should terminate
 */
int shell_execute(char **args)
{
	/*int i;
	char *builtin_str[] = {
		"cd", "help", "clear", "exit", "env", "setenv", "unsetenv"
		};

	int (*builtin_func[]) (char **) = {
		&hsh_cd, &hsh_help, &hsh_clear, &hsh_exit, &hsh_env, &_setenv, &_unsetenv
		};

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
	}*/
	return (shell_launch(args));
}

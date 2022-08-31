#include "main.h"

/**
 * List of builtin commands, followed by their
 * corresponding functions.
 */
char *builtin_str1[] = {"cd", "help", "exit", NULL};

/**
 * hsh_num_builtins - evaluate the size of bultins
 *
 * Return: size of the bultins
 */
int hsh_num_builtins(void)
{
	return (sizeof(builtin_str1) / sizeof(char *));
}

/**
 * hsh_cd - change directory.
 * @args: List of arguments.
 *
 * Return: Always 1
 */
int hsh_cd(char **args)
{
	if (args[1] == NULL)
	{
		fprintf(stderr, "expected argument to \"cd\"\n");
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			perror("lsh");
		}
	}
	return (1);
}

/**
 * hsh_help - print help.
 * @args: list of args.
 *
 * Return: Always 1
 */
int hsh_help(char __attribute__((unused)) **args)
{
	int i;
	printf("Group Project for ALX Software Engineering\n");
	printf("Type a program names and arguments, and hit ENTER.\n");
	printf("The following are built in:\n");

	for (i = 0; i < lsh_num_builtins(); i++)
	{
		printf("  %s\n", builtin_str1[i]);
	}
	printf("Use the man command for information on other programs.\n");
	return (1);
}

/**
 * hsh_exit - exit the execusion
 * @args: list of args
 *
 * Return: Always returns 0
 */
int hsh_exit(char __attribute__((unused)) **args)
{
	return 0;
}

#include "main.h"

/**
 * hsh_num_builtins - evaluate the size of bultins
 *
 * Return: size of the bultins
 */
int hsh_num_builtins(void)
{
	char *builtin_str1[] = {
		"cd",
		"help",
		"clear",
		"exit",
		"env",
		"setenv",
		"unsetenv"
		};

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
			perror("hsh: failed");
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
	char *builtin_str1[] = {
		"cd",
		"help",
		"clear",
		"exit",
		"env",
		"setenv",
		"unsetenv"
		};

	printf("Group Project for ALX Software Engineering\n");
	printf("Type a program names and arguments, and then hit the ENTER.\n");
	printf("The following are built in:\n");

	for (i = 0; i < hsh_num_builtins(); i++)
	{
		printf("\t=> %s\n", builtin_str1[i]);
	}
	printf("Use 'man <argument>' for more information on each program.\n");
	printf("Copyright © 2022 Yitbarek Wendimu and Mubarak Olajuwon");
	return (1);
}

/**
 * hsh_exit - exit the execution
 * @args: list of args
 *
 * Return: Always returns 0
 */
int hsh_exit(char **args)
{
	if (args != NULL && args[1] != NULL)
		exit(_atoi(args[1]));
	else if (args != NULL && args[1] == NULL)
		exit(0);
	else
		return (1);
}

/**
 * hsh_clear - clear the console
 * @args: list of args
 *
 * Return: Always returns 1
 */
int hsh_clear(char __attribute__((unused)) **args)
{
	system("clear");
	return (1);
}

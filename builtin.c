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
	char *filename = "cd_helper", *home[] = {"~", "-", NULL}, cwd[256], *buffer;

	getcwd(cwd, sizeof(cwd));
	printf("%s\n",  read_file(filename, sizeof(cwd)));
	if (args[1] == NULL)
	{
		chdir(getenv("HOME"));
		/** fprintf(stderr, "expected argument to \"cd\"\n"); */
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			if (strcmp(args[1], home[0]) == 0)
			{
				chdir(getenv("HOME"));
			}
			else if (strcmp(args[1], home[1]) == 0)
			{
				if (strcmp(cwd, getenv("HOME")) != 0)
				{
					if (create_file(filename, cwd) == 1)
					{
						printf("%s\n",  read_file(filename, sizeof(cwd)));
						chdir(getenv("HOME"));
						printf("%s\n", getenv("HOME"));
					}
				}
				else
				{
					printf("Sorry\n");
					buffer = malloc(1024);
					buffer = read_file(filename, 18);
					printf("%s\n", buffer);
				}
			}		
			else
			{
				perror("hsh: failed");
			}
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
	printf("Copyright © 2022 Yitbarek Wendimu and Mubarak Olajuwon\n");
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

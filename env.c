#include "main.h"

/**
 * _env - prints the result for env
 *
 * Result: Always 0
 */
int _env(void)
{
	if (setenv("C_IS", "Fun_:)", 1) == -1)
	{
		fprintf(stderr, "Error: C_IS not setted\");
	}
        printf("USER=%s\n", getenv("USER"));
        printf("LANGUAGE=%s\n", getenv("LANG"));
        printf("SESSION=%s\n", getenv("SESSION"));
        printf("COMPIZ_CONFIG_PROFILE=%s\n", getenv("COMPIZ_CONFIG_PROFILE"));
        printf("SHLVL=%s\n", getenv("SHLVL"));
        printf("HOME=%s\n", getenv("HOME"));
        printf("C_IS=%s\n", getenv("C_IS"));
        printf("DESKTOP_SESSION=%s\n", getenv("DESKTOP_SESSION"));
        printf("LOGNAME=%s\n", getenv("LOGNAME"));
        printf("TERM=%s\n", getenv("TERM"));
        printf("PATH=%s\n", getenv("PATH"));
        printf("DISPLAY=%s\n", getenv("DISPLAY"));

        return (0);
}
/**
 * hsh_env - list the env variables value
 * @args: list of args
 *
 * Return: Always returns 1
 */
int hsh_env(char __attribute__((unused)) **args)
{
	_env();
	return (1);
}

#include "main.h"

/**
 * _env - prints the result for env
 *
 * Result: Always 0
 */
int _env(void)
{
	
        printf("ME=%s\n", getenv("ME"));
        printf("USER=%s\n", getenv("USER"));
        printf("LANGUAGE=%s\n", getenv("LANG"));
        printf("SESSION=%s\n", getenv("SESSION"));
        printf("COMPIZ_CONFIG_PROFILE=%s\n", getenv("COMPIZ_CONFIG_PROFILE"));
        printf("SHLVL=%s\n", getenv("SHLVL"));
        printf("HOME=%s\n", getenv("HOME"));
        printf("C_IS=Fun_:)\n");
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

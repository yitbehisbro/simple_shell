#include "main.h"

/**
 * is_delim - checks if delimitor
 * @str: string to be checked
 * @delim: delimitor
 *
 * Return: 1 if delimitor else 0
 */
unsigned int is_delim(char str, char *delim)
{
	while (*delim != '\0')
	{
		if (str == *delim)
			return (1);
		delim++;
	}
	return (0);
}

/**
 * _strtok - breaks a string into a sequence of
 * zero or more nonempty tokens
 * @str: pointer to string to be break
 * @delim: argument specifies a set of bytes
 * that delimit the tokens in the parsed string
 *
 * Return: pointer to the next token,
 * or NULL if there are no more tokens.
 */
char *_strtok(char *str, char *delim)
{
	char *result = NULL;
	static char *backup_string;

	if (!str)
	{
		str = backup_string;
	}
	if (!str)
	{
		return (NULL);
	}
	while (1)
	{
		if (is_delim(*str, delim))
		{
			str++;
			continue;
		}
		if (*str == '\0')
		{
			return (NULL);
		}
		break;
	}
	result = str;
	while (1)
	{
		if (*str == '\0')
		{
			backup_string = str;
			return (result);
		}
		if (is_delim(*str, delim))
		{
			*str = '\0';
			backup_string = str + 1;
			return (result);
		}
		str++;
	}
}

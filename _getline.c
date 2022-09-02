#include "main.h"

/**
 * _strchr - search the first occernance of c
 * @s: pointer to char string
 * @c: character to be find
 * Return: pointer to s or NULL
 */
char *_strchr(char *s, char c)
{
	unsigned int a = 0;

	for (; *(s + a) != '\0'; a++)
		if (*(s + a) == c)
			return (s + a);
	if (*(s + a) == c)
		return (s + a);
	return ('\0');
}

/**
 * _strlen - prints the length of string
 * @s: variable that holds string values
 *
 * Return: the length of the given string
 */
int _strlen(char *s)
{
	int length;

	length = 0;

	while (*(s + length) != '\0')
	{
		length++;
	}
	return (length);
}

/**
 * _strcpy - copies the string pointed to by src
 * @dest: variable that holds the value of variable
 * @src: sting values
 * Return: Always 0.
 */
char *_strcpy(char *dest, char *src)
{
	int length;

	length = 0;

	while (length >= 0)
	{
		*(dest + length) = *(src + length);
		if (*(src + length) == '\0')
			break;
		length++;
	}
	return (dest);
}

/**
 * _getline - reads an entire line from stream
 * @lineptr: pointer to the line
 * @n: size of buffer
 *
 * Return: the number of characters read,
 * including the delimiter character, but not
 * including the terminating null byte
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	static char line[256];
	char *ptr;
	unsigned int len;

	if (lineptr == NULL || n == NULL)
	{
		errno = EINVAL;
		return (-1);
	}

	if (ferror(stream))
		return (-1);

	if (feof(stream))
		return (-1);

	fgets(line, 256, stream);

	ptr = _strchr(line, '\n');
	if (ptr)
		*ptr = '\0';

	len = _strlen(line);

	if ((len + 1) < 256)
	{
		ptr = realloc(*lineptr, 256);
		if (ptr == NULL)
			return (-1);
		*lineptr = ptr;
		*n = 256;
	}
	_strcpy(*lineptr, line);
	return (len);
}

#include "main.h"

/**
 * read_line - read a line
 *
 * Return: Null-terminated
 */
char *read_line(void)
{
	#ifdef LSH_USE_STD_GETLINE

	char *line = NULL;
	ssize_t bufsize = 0;

	if (_getline(&line, &bufsize, stdin) == -1)
	{
		if (feof(stdin))
		{
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror("getline\n");
			exit(EXIT_FAILURE);
		}
	}
	return (line);
	#else
	#define BUFSIZE 1024
	int c, position = 0, bufsize = BUFSIZE;
	char *buffer = malloc(sizeof(char) * bufsize);

	if (!buffer)
	{
		fprintf(stderr, "allocation error\n");
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		c = getchar();
		read_loop(&buffer, bufsize, position, c);
	}
	#endif
}

/**
 * read_loop - helper function
 * @buffer: line of string
 * @bufsize: size of the buffer
 *
 * Return: buffer
 */
char read_loop(char *buffer, int bufsize, int position, int c)
{
	if (c == EOF)
	{
		exit(EXIT_SUCCESS);
	}
	else if (c == '\n')
	{
		buffer[position] = '\0';
		return (buffer);
	}
	else
	{
		buffer[position] = c;
	}
	position++;

	if (position >= bufsize)
	{
		bufsize += BUFSIZE;
		buffer = realloc(buffer, bufsize);
		if (!buffer)
		{
			fprintf(stderr, "allocation error\n");
			exit(EXIT_FAILURE);
		}
	}
}

#include "main.h"

/**
 * read_line - read a line
 *
 * Return: Null-terminated
 */
char *read_line(void)
{
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
	return (read_loop());
}

/**
 * read_loop - reads the line
 *
 * Return: buffer
 */
char *read_loop(void)
{
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
	#endif
}

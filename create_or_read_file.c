#include "main.h"

/**
 * create_file - creates a file.
 * @filename: name of the file to create
 * @text_content: NULL terminated string to write to the file
 *
 * Return: 1 on success, -1 on failure (file can not be created,
 * file can not be written, write "fails", etc...)
 */
int create_file(const char *filename, char *text_content)
{
	int file_d, size = 0, buff;

	if (filename == NULL)
		return (-1);

	file_d = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);

	if (file_d == -1)
		return (-1);

	if (text_content == NULL)
		text_content = "";

	/** to get the size of text_content */
	while (*(text_content + size) != '\0')
		size++;

	buff = write(file_d, text_content, size);
	if (buff == -1)
		return (-1);

	close(file_d);
	return (1);
}

/**
 * read_file - reads a text file
 * @filename: the name of file
 * @letters: the number of letters it should read and print
 *
 * Return: buffer of strings
 */
char *read_file(const char *filename, size_t letters)
{
	ssize_t r_len;
	int file_d;
	char *buffer;

	if (filename == NULL)
	{
		return (0);
	}
	file_d = open(filename, O_RDONLY);
	if (file_d == -1)
	{
		return (0);
	}
	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
	{
		close(file_d);
		return (0);
	}
	r_len = read(file_d, buffer, letters);
	close(file_d);

	if (r_len == -1)
	{
		free(buffer);
		return (0);
	}
	return (buffer);
}

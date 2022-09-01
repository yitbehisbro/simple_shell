
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * main - reads all the arguments
 * @ac: a NULL terminated array of strings
 * @av: the number of items in av
 *
 * Return: Always 0.
 */
int main(void)
{
	char *buffer;
	size_t len = 32;
	/** size_t chars; */

	buffer = (char *)malloc(len * sizeof(char));
	if (buffer == NULL)
		return (-1);
	printf("$ ");
	/** chars = getline(&buffer, &len, stdin); used to get the size of char read for the return value of getline is the size of char read*/
	/** printf("%zu\n", chars); prints number of chars readed */
	getline(&buffer, &len, stdin);
	printf("%s", buffer);

	return (0);
}

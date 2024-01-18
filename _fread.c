#include "monty.h"

/**
 * _fread - reads a file
 * @fd: pointer to file descriptor
 * Return: void
 */

void _fread(FILE *fd)
{
	int line_number, format = 0;
	char *buffer = NULL;
	size_t len = 0;

	for (line_number = 1; getline(&buffer, &len, fd) != -1; line_number++)
	{
		format = _lparse(buffer, line_number, format);
	}
	free(buffer);
}

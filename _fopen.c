#include "monty.h"

/**
 * _fopen - open a file
 * @file_name: namepath
 */

void _fopen(char *file_name)
{
	FILE *fd = fopen(file_name, "r");

	if (file_name == NULL || fd == NULL)
		_er(2, file_name);

	_fread(fd);
	fclose(fd);
}

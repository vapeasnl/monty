#include "monty.h"

/**
 * _lparse - Separates each line into tokens to call function.
 * @buffer: line from the file
 * @line_number: line number
 * @format:  storage format. If 0 Nodes >> stack.
 * if 1 nodes >> queue.
 * Return: Returns 0 = stack. 1 i= queue.
 */

int _lparse(char *buffer, int line_number, int format)
{
	char *opcode, *value;
	const char *delim = "\n ";

	if (buffer == NULL)
		_er(4);

	opcode = strtok(buffer, delim);
	if (opcode == NULL)
		return (format);
	value = strtok(NULL, delim);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	_sfunc(opcode, value, line_number, format);
	return (format);
}

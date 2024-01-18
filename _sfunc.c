#include "monty.h"
/**
 * _sfunc - find the appropriate function for the opcode
 * @opcode: opcode
 * @value: argument of opcode
 * @format:  storage format. If 0 > stack.
 * @ln: line number
 * if 1 >> queue.
 * Return: void
 */
void _sfunc(char *opcode, char *value, int ln, int format)
{
	int i;
	int flag;

	instruction_t func_list[] = {
		{"push", _stkadd},
		{"pall", _printstk},
		{"pint", _printtop},
		{"pop", _tpop},
		{"nop", nop},
		{"swap", _nswap},
		{"add", _nadd},
		{"sub", _nsub},
		{"div", _ndiv},
		{"mul", _nmul},
		{"mod", _nmod},
		{"pchar", _printchar},
		{"pstr", _printstr},
		{"_rotl", _rotl},
		{"_rotr", _rotr},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (flag = 1, i = 0; func_list[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, func_list[i].opcode) == 0)
		{
			_exefunc(func_list[i].f, opcode, value, ln, format);
			flag = 0;
		}
	}
	if (flag == 1)
		_er(3, ln, opcode);
}

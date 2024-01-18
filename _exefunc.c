#include "monty.h"

/**
 * _exefunc - Call the function.
 * @func: Point func.
 * @op: string of opcode.
 * @val: num string.
 * @ln: line num.
 * @format: Format specifier. If 0 Nodes >> stack.
 * if 1 nodes >> queue.
 */
void _exefunc(op_func func, char *op, char *val, int ln, int format)
{
	stack_t *node;
	int flag;
	int i;

	flag = 1;
	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			flag = -1;
		}
		if (val == NULL)
			_er(5, ln);
		for (i = 0; val[i] != '\0'; i++)
		{
			if (isdigit(val[i]) == 0)
				_er(5, ln);
		}
		node = create_node(atoi(val) * flag);
		if (format == 0)
			func(&node, ln);
		if (format == 1)
			add_to_queue(&node, ln);
	}
	else
		func(&head, ln);
}

#include "monty.h"
/**
 * _nadd - Adds the top two elements of the stk.
 * @stk: Pointer to a pointer pointing to top node of the stk.
 * @line_number: Interger representing the line number of of the opcode.
 */
void _nadd(stack_t **stk, unsigned int line_number)
{
	int t;

	if (stk == NULL || *stk == NULL || (*stk)->next == NULL)
		_erA(8, line_number, "add");

	(*stk) = (*stk)->next;
	t = (*stk)->n + (*stk)->prev->n;
	(*stk)->n = t;
	free((*stk)->prev);
	(*stk)->prev = NULL;
}

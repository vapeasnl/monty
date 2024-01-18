#include "main.h"

/**
 * _nmul - Adds the top two elements of the stk.
 * @stk: Pointer to a pointer pointing to top node of the stk.
 * @line_number: Interger representing the line number of of the opcode.
 */
void _nmul(stack_t **stk, unsigned int line_number)
{
	int sum;

	if (stk == NULL || *stk == NULL || (*stk)->next == NULL)
		_erA(8, line_number, "mul");

	(*stk) = (*stk)->next;
	sum = (*stk)->n * (*stk)->prev->n;
	(*stk)->n = sum;
	free((*stk)->prev);
	(*stk)->prev = NULL;
}


/**
 * _nmod - Adds the top two elements of the stk.
 * @stk: Pointer to a pointer pointing to top node of the stk.
 * @line_number: Interger representing the line number of of the opcode.
 */
void _nmod(stack_t **stk, unsigned int line_number)
{
	int sum;

	if (stk == NULL || *stk == NULL || (*stk)->next == NULL)

		_erA(8, line_number, "mod");


	if ((*stk)->n == 0)
		_erA(9, line_number);
	(*stk) = (*stk)->next;
	sum = (*stk)->n % (*stk)->prev->n;
	(*stk)->n = sum;
	free((*stk)->prev);
	(*stk)->prev = NULL;
}

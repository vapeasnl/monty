#include "main.h"

/**
 * nop - Does nothing.
 * @stk: Pointer to a pointer pointing to top node of the stk.
 * @line_number: Interger representing the line number of of the opcode.
 */
void nop(stack_t **stk, unsigned int line_number)
{
	(void)stk;
	(void)line_number;
}


/**
 * _nsawp - Swaps the top two elements of the stk.
 * @stk: Pointer to a pointer pointing to top node of the stk.
 * @line_number: Interger representing the line number of of the opcode.
 */
void _nsawp(stack_t **stk, unsigned int line_number)
{
	stack_t *tmp;

	if (stk == NULL || *stk == NULL || (*stk)->next == NULL)
		_erA(8, line_number, "swap");
	tmp = (*stk)->next;
	(*stk)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *stk;
	tmp->next = *stk;
	(*stk)->prev = tmp;
	tmp->prev = NULL;
	*stk = tmp;
}

/**
 * _nadd - Adds the top two elements of the stk.
 * @stk: Pointer to a pointer pointing to top node of the stk.
 * @line_number: Interger representing the line number of of the opcode.
 */
void _nadd(stack_t **stk, unsigned int line_number)
{
	int sum;

	if (stk == NULL || *stk == NULL || (*stk)->next == NULL)
		_erA(8, line_number, "add");

	(*stk) = (*stk)->next;
	sum = (*stk)->n + (*stk)->prev->n;
	(*stk)->n = sum;
	free((*stk)->prev);
	(*stk)->prev = NULL;
}


/**
 * _nsub - Adds the top two elements of the stk.
 * @stk: Pointer to a pointer pointing to top node of the stk.
 * @line_number: Interger representing the line number of of the opcode.
 */
void _nsub(stack_t **stk, unsigned int line_number)
{
	int sum;

	if (stk == NULL || *stk == NULL || (*stk)->next == NULL)

		_erA(8, line_number, "sub");


	(*stk) = (*stk)->next;
	sum = (*stk)->n - (*stk)->prev->n;
	(*stk)->n = sum;
	free((*stk)->prev);
	(*stk)->prev = NULL;
}


/**
 * _ndiv - Adds the top two elements of the stk.
 * @stk: Pointer to a pointer pointing to top node of the stk.
 * @line_number: Interger representing the line number of of the opcode.
 */
void _ndiv(stack_t **stk, unsigned int line_number)
{
	int sum;

	if (stk == NULL || *stk == NULL || (*stk)->next == NULL)
		_erA(8, line_number, "div");

	if ((*stk)->n == 0)
		_erA(9, line_number);
	(*stk) = (*stk)->next;
	sum = (*stk)->n / (*stk)->prev->n;
	(*stk)->n = sum;
	free((*stk)->prev);
	(*stk)->prev = NULL;
}

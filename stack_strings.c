#include "main.h"

/**
 * _charprint - Prints the Ascii value.
 * @stk: Pointer to a pointer pointing to top node of the stk.
 * @line_number: Interger representing the line number of of the opcode.
 */
void _charprint(stack_t **stk, unsigned int line_number)
{
	int ascii;

	if (stk == NULL || *stk == NULL)
		_erS(11, line_number);

	ascii = (*stk)->n;
	if (ascii < 0 || ascii > 127)
		_erS(10, line_number);
	printf("%c\n", ascii);
}

/**
 * _strprint - Prints a string.
 * @stk: Pointer to a pointer pointing to top node of the stk.
 * @ln: Interger representing the line number of of the opcode.
 */
void _strprint(stack_t **stk, __attribute__((unused))unsigned int ln)
{
	int ascii;
	stack_t *tmp;

	if (stk == NULL || *stk == NULL)
	{
		printf("\n");
		return;
	}

	tmp = *stk;
	while (tmp != NULL)
	{
		ascii = tmp->n;
		if (ascii <= 0 || ascii > 127)
			break;
		printf("%c", ascii);
		tmp = tmp->next;
	}
	printf("\n");
}

/**
 * rotl - Rotates the first node of the stk to the bottom.
 * @stk: Pointer to a pointer pointing to top node of the stk.
 * @ln: Interger representing the line number of of the opcode.
 */
void rotl(stack_t **stk, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (stk == NULL || *stk == NULL || (*stk)->next == NULL)
		return;

	tmp = *stk;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *stk;
	(*stk)->prev = tmp;
	*stk = (*stk)->next;
	(*stk)->prev->next = NULL;
	(*stk)->prev = NULL;
}


/**
 * rotr - Rotates the last node of the stk to the top.
 * @stk: Pointer to a pointer pointing to top node of the stk.
 * @ln: Interger representing the line number of of the opcode.
 */
void rotr(stack_t **stk, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (stk == NULL || *stk == NULL || (*stk)->next == NULL)
		return;

	tmp = *stk;

	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *stk;
	tmp->prev->next = NULL;
	tmp->prev = NULL;
	(*stk)->prev = tmp;
	(*stk) = tmp;
}

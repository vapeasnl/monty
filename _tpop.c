#include "monty.h"

/**
 * _tpop - Adds a node to the stack.
 * @stack: Top node of the stack.
 * @line_number: Opcode line number.
 */
void _tpop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
		_erA(7, line_number);

	tmp = *stack;
	*stack = tmp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(tmp);
}

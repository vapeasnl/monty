#include "monty.h"

/**
 * _printtop - Prints the top node of the stack.
 * @stack: Top node of the stack.
 * @line_number: Opcode line number.
 */
void _printtop(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
		_erA(6, line_number);
	printf("%d\n", (*stack)->n);
}


#include "monty.h"

/**
 * _printtop - Prints the top node of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void _printtop(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
		_erA(6, line_number);
	printf("%d\n", (*stack)->n);
}


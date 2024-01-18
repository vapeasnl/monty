#include "monty.h"

/**
 * _printchar - Prints the Ascii value.
 * @stack: Top node of the stack.
 * @line_number: Opcode line number.
 */
void _printchar(stack_t **stack, unsigned int line_number)
{
	int ascii;

	if (stack == NULL || *stack == NULL)
		_erS(11, line_number);

	ascii = (*stack)->n;
	if (ascii < 0 || ascii > 127)
		_erS(10, line_number);
	printf("%c\n", ascii);
}

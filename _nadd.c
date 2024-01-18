#include "monty.h"
/**
 * _nadd - Add the top two elements of the stack.
 * @stack: Top node of the stack - P.
 * @line_number: Opcode line number.
 */
void _nadd(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		_erA(8, line_number, "add");

	(*stack) = (*stack)->next;
	sum = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

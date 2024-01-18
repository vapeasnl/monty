#include "monty.h"

/**
 * _ndiv - Adds the top two elements of the stack.
 * @stack: Top node of the stack.
 * @line_number: Opcode line number.
 */
void _ndiv(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		_erA(8, line_number, "div");

	if ((*stack)->n == 0)
		_erA(9, line_number);
	(*stack) = (*stack)->next;
	sum = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

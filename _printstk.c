#include "monty.h"

/**
 * _printstk - Adds a node to the stack.
 * @stack: Top node of the stack.
 * @line_number: Opcode line number.
 */
void _printstk(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	(void) line_number;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	tmp = *stack;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

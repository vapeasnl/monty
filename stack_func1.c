#include "main.h"


/**
 * _stkadd - Adds a node to the stack.
 * @nn: Pointer to the new node.
 * @ln: Interger representing the line number of of the opcode.
 */
void _stkadd(stack_t **nn, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (nn == NULL || *nn == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *nn;
		return;
	}
	tmp = head;
	head = *nn;
	head->next = tmp;
	tmp->prev = head;
}


/**
 * _stkprint - Adds a node to the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: line number of  the opcode.
 */
void _stkprint(stack_t **stack, unsigned int line_number)
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

/**
 * _tpop - Adds a node to the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
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

/**
 * _tprint - Prints the top node of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void _tprint(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
		_erA(6, line_number);
	printf("%d\n", (*stack)->n);
}

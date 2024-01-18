#include "monty.h"


/**
 * _stkadd - Adds a node to the stack.
 * @new_node: Pointer to the new node.
 * @ln: Opcode line number.
 */
void _stkadd(stack_t **new_node, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	tmp = head;
	head = *new_node;
	head->next = tmp;
	tmp->prev = head;
}

#include "monty.h"

/**
 * free_stack - Frees a doubly linked list.
 * @head: Pointer to the head of the stack.
 *
 * Return: void
 */
void free_stack(stack_t *head)
{
	stack_t *current = head;

	while (current)
	{
		stack_t *temp = current;
		current = current->next;
		free(temp);
	}
}

/**
 * opcode_stack - Sets the stack mode (top of the stack is the head).
 * @stack: Pointer to the head of the stack.
 * @line_number: Line number being executed.
 *
 * Return: void
 */
void opcode_stack(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	// monty
}

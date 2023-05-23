#include "monty.h"

/**
 * addOp - adds the top two elements together
 * @stack: pointer to the head node pointer of stack
 * @lineNumber: the line number
 * Return: Nothing.
 */
void addOp(stack_t **stack, unsigned int lineNumber)
{
    stack_t *temp;

    if (!(*stack) || !(*stack)->next)
    {
        fprintf(stderr, "L%d: can't add, stack too short\n", lineNumber);
        exit(EXIT_FAILURE);
    }

    temp = *stack;
    (*stack)->next->value += (*stack)->value;
    *stack = (*stack)->next;
    (*stack)->prev = NULL;
    free(temp);
}

/**
 * subOp - subtracts the top two elements and stores the result in the second element
 * @stack: pointer to the head node pointer of stack
 * @lineNumber: the line number
 * Return: Nothing.
 */
void subOp(stack_t **stack, unsigned int lineNumber)
{
    stack_t *temp;

    if (!(*stack) || !(*stack)->next)
    {
        fprintf(stderr, "L%d: can't sub, stack too short\n", lineNumber);
        exit(EXIT_FAILURE);
    }

    temp = *stack;
    (*stack)->next->value -= (*stack)->value;
    *stack = (*stack)->next;
    (*stack)->prev = NULL;
    free(temp);
}

/**
 * divOp - divides the top two elements and stores the result in the second element
 * @stack: pointer to the head node pointer of stack
 * @lineNumber: the line number
 * Return: Nothing.
 */
void divOp(stack_t **stack, unsigned int lineNumber)
{
    stack_t *temp;

    if (!(*stack) || !(*stack)->next)
    {
        fprintf(stderr, "L%d: can't div, stack too short\n", lineNumber);
        exit(EXIT_FAILURE);
    }

    if ((*stack)->value == 0)
    {
        fprintf(stderr, "L%d: division by zero\n", lineNumber);
        exit(EXIT_FAILURE);
    }

    temp = *stack;
    (*stack)->next->value /= (*stack)->value;
    *stack = (*stack)->next;
    (*stack)->prev = NULL;
    free(temp);
}

/**
 * mulOp - multiplies the top two elements and stores the result in the second element
 * @stack: pointer to the head node pointer of stack
 * @lineNumber: the line number
 * Return: Nothing.
 */
void mulOp(stack_t **stack, unsigned int lineNumber)
{
    stack_t *temp;

    if (!(*stack) || !(*stack)->next)
    {
        fprintf(stderr, "L%d: can't mul, stack too short\n", lineNumber);
        exit(EXIT_FAILURE);
    }

    temp = *stack;
    (*stack)->next->value *= (*stack)->value;
    *stack = (*stack)->next;
    (*stack)->prev = NULL;
    free(temp);
}

/**
 * modOp - computes the modulus of the top two elements and stores the result in the second element
 * @stack: pointer to the head node pointer of stack
 * @lineNumber: the line number
 * Return: Nothing.
 */
void modOp(stack_t **stack, unsigned int lineNumber)
{
    stack_t *temp;

    if (!(*stack) || !(*stack)->next)
    {
        fprintf(stderr, "L%d: can't mod, stack too short\n", lineNumber);
        exit(EXIT_FAILURE);
    }

    if ((*stack)->value == 0)
    {
        fprintf(stderr, "L%d: division by zero\n", lineNumber);
        exit(EXIT_FAILURE);
    }

    temp = *stack;
    (*stack)->next->value %= (*stack)->value;
    *stack = (*stack)->next;
    (*stack)->prev = NULL;
    free(temp);
}

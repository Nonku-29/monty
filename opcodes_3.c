#include "monty.h"

/**
 * rotateLeft - rotates the stack to the top
 * @stack: pointer to the head node pointer of the stack
 * @lineNumber: the line number
 *
 * Return: Nothing.
 */
void rotateLeft(stack_t **stack, unsigned int lineNumber)
{
    stack_t *tempNode;
    int holdValue, holdValueAgain;
    (void)lineNumber;

    if (stack == NULL || *stack == NULL)
    {
        nop(stack, lineNumber);
        return;
    }

    holdValue = (*stack)->value;
    tempNode = *stack;

    while (tempNode)
    {
        if (tempNode->next == NULL)
            break;
        tempNode = tempNode->next;
    }

    holdValueAgain = tempNode->value;
    (*stack)->value = holdValueAgain;
    tempNode->value = holdValue;
}

/**
 * rotateLeftOp - rotates the stack to the left
 * @stack: pointer to the head node pointer of the stack
 * @lineNumber: the line number
 *
 * Return: Nothing.
 */
void rotateLeftOp(stack_t **stack, unsigned int lineNumber)
{
    stack_t *last, *tmp;
    (void)lineNumber;

    if (!stack || !(*stack) || !((*stack)->next))
        return;

    tmp = *stack;
    last = tmp;

    while (last->next)
    {
        last = last->next;
    }

    last->next = tmp;
    tmp->prev = last;
    tmp->next->prev = NULL;
    *stack = tmp->next;
    tmp->next = NULL;
}

/**
 * rotateRightOp - rotates the stack to the right
 * @stack: pointer to the head node pointer of the stack
 * @lineNumber: the line number
 *
 * Return: Nothing.
 */
void rotateRightOp(stack_t **stack, unsigned int lineNumber)
{
    stack_t *last, *tmp;
    (void)lineNumber;

    if (!stack || !(*stack) || !((*stack)->next))
        return;

    tmp = *stack;
    last = tmp;

    while (last->next)
    {
        last = last->next;
    }

    last->prev->next = NULL;
    last->prev = NULL;
    tmp->prev = last;
    last->next = tmp;
    *stack = last;
}

/**
 * enqueue - pushes a node to the end of the stack (queue behavior)
 * @stack: pointer to the head node pointer of the stack
 * @lineNumber: the line number
 *
 * Return: Nothing.
 */
void enqueue(stack_t **stack, unsigned int lineNumber)
{
    stack_t *last, *newNode;

    if (stack == NULL)
    {
        fprintf(stderr, "L%d: stack not found\n", lineNumber);
        exit(EXIT_FAILURE);
    }

    newNode = malloc(sizeof(stack_t));
    if (newNode == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        freeStack(stack);
        exit(EXIT_FAILURE);
    }

    last = NULL;
    if (*stack)
    {
        last = *stack;
        while (last->next)
            last = last->next;
        last->next = newNode;
    }
    else
    {
        *stack = newNode;
    }

    newNode->prev = last;
    newNode->next = NULL;
    newNode->value = arg.arg;
}

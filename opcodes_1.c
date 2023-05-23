#include "monty.h"

/**
 * pushNode - pushes a node to the top of the stack
 * @stack: pointer to the head node pointer of the stack
 * @lineNumber: the line number
 *
 * Return: Nothing.
 */
void pushNode(stack_t **stack, unsigned int lineNumber)
{
    stack_t *newNode;

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

    newNode->next = *stack;
    newNode->prev = NULL;
    newNode->value = argument.argument;
    if (*stack != NULL)
        (*stack)->prev = newNode;
    *stack = newNode;
}

/**
 * printAllNodes - prints the data of all nodes in the stack
 * @stack: pointer to the head node pointer of the stack
 * @lineNumber: the line number
 *
 * Return: Nothing.
 */
void printAllNodes(stack_t **stack, unsigned int lineNumber)
{
    stack_t *tempNode;
    (void)lineNumber;

    tempNode = *stack;
    while (tempNode != NULL)
    {
        printf("%d\n", tempNode->value);
        tempNode = tempNode->next;
    }
}

/**
 * freeStack - frees all nodes in the stack
 * @stack: pointer to the head node pointer of the stack
 *
 * Return: Nothing.
 */
void freeStack(stack_t **stack)
{
    stack_t *tempNode = NULL;

    if (stack == NULL || *stack == NULL)
        return;

    while (*stack != NULL)
    {
        tempNode = (*stack)->next;
        free(*stack);
        *stack = tempNode;
    }
}

/**
 * doNothing - does literally nothing
 * @stack: pointer to the head node pointer of the stack
 * @lineNumber: the line number
 *
 * Return: Nothing.
 */
void doNothing(stack_t **stack, unsigned int lineNumber)
{
    (void)stack;
    (void)lineNumber;
}

/**
 * isAlphabetic - checks if an integer is alphabetic
 * @c: integer
 *
 * Return: 1 if it is alphabetic, 0 otherwise
 */
int isAlphabetic(int c)
{
    if (((c >= 'a') && (c <= 'z')) || ((c >= 'A') && (c <= 'Z')))
        return 1;
    else
        return 0;
}

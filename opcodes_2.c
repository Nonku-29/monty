#include "monty.h"

/**
 * printTop - prints the value at the top of the stack
 * @stack: pointer to the head node pointer of the stack
 * @lineNumber: the line number
 *
 * Return: Nothing.
 */
void printTop(stack_t **stack, unsigned int lineNumber)
{
    stack_t *tempNode;

    if (stack == NULL || *stack == NULL)
    {
        fprintf(stderr, "L%d: can't print, stack empty\n", lineNumber);
        exit(EXIT_FAILURE);
    }

    tempNode = *stack;
    while (tempNode)
    {
        if (tempNode->prev == NULL)
            break;
        tempNode = tempNode->prev;
    }

    printf("%d\n", tempNode->value);
}

/**
 * removeTop - removes the top element of the stack
 * @stack: pointer to the head node pointer of the stack
 * @lineNumber: the line number
 *
 * Return: Nothing.
 */
void removeTop(stack_t **stack, unsigned int lineNumber)
{
    if (stack == NULL || *stack == NULL)
    {
        fprintf(stderr, "L%d: can't pop an empty stack\n", lineNumber);
        exit(EXIT_FAILURE);
    }

    if ((*stack)->next != NULL)
    {
        *stack = (*stack)->next;
        free((*stack)->prev);
        (*stack)->prev = NULL;
    }
    else
    {
        free(*stack);
        *stack = NULL;
    }
}

/**
 * swapTopTwo - swaps the top two elements of the stack
 * @stack: pointer to the head node pointer of the stack
 * @lineNumber: the line number
 *
 * Return: Nothing.
 */
void swapTopTwo(stack_t **stack, unsigned int lineNumber)
{
    int tempValue;

    if (stack == NULL || *stack == NULL || !((*stack)->next))
    {
        fprintf(stderr, "L%d: can't swap, stack too short\n", lineNumber);
        exit(EXIT_FAILURE);
    }

    tempValue = (*stack)->value;
    (*stack)->value = (*stack)->next->value;
    (*stack)->next->value = tempValue;
}

/**
 * printChar - prints the character at the top of the stack
 * @stack: pointer to the head node pointer of the stack
 * @lineNumber: the line number
 *
 * Return: Nothing.
 */
void printChar(stack_t **stack, unsigned int lineNumber)
{
    char c;
    stack_t *tempNode;

    if (stack == NULL || *stack == NULL)
    {
        fprintf(stderr, "L%d: can't print, stack empty\n", lineNumber);
        exit(EXIT_FAILURE);
    }

    tempNode = *stack;
    while (tempNode)
    {
        if (tempNode->prev == NULL)
            break;
        tempNode = tempNode->prev;
    }

    c = tempNode->value;
    if (isAlphabetic(tempNode->value) == 0)
    {
        fprintf(stderr, "L%d: can't print, value out of range\n", lineNumber);
        exit(EXIT_FAILURE);
    }
    printf("%c\n", c);
}

/**
 * printString - prints a string starting from the top of the stack
 * @stack: pointer to the head node pointer of the stack
 * @lineNumber: the line number
 *
 * Return: Nothing.
 */
void printString(stack_t **stack, unsigned int lineNumber)
{
    int index = 0;
    char result[] = "";
    char c;
    stack_t *tempNode;

    tempNode = *stack;
    (void)lineNumber;

    while (tempNode)
    {
        if (tempNode->value == 0)
            break;
        if (isAlphabetic(tempNode->value) == 0)
            break;
        c = tempNode->value;
        printf("%c", c);
        result[index] += c;
        tempNode = tempNode->next;
        index++;
    }
    printf("\n");
}

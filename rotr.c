#include "monty.h"

/**
 * f_rotr - Function that rotates the stack to the bottom
 * @head: Double pointer to the head of the stack
 * @counter: Line count
 *
 * Return: Nothing
 */
void f_rotr(stack_t **head, __attribute__((unused)) unsigned int counter)
{
    stack_t *copy;

    copy = *head;
    if (*head == NULL || (*head)->next == NULL)
    {
        return;
    }
    while (copy->next)
    {
        copy = copy->next;
    }
    copy->next = *head;
    copy->prev->next = NULL;
    copy->prev = NULL;
    (*head)->prev = copy;
    (*head) = copy;
}

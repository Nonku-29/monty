#include "monty.h"

/**
 * f_pall - Function that prints all elements in the stack
 * @head: Double pointer to the head of the stack
 * @counter: Unused line count
 *
 * Return: Nothing
 */
void f_pall(stack_t **head, unsigned int counter)
{
    stack_t *h;
    (void) counter;

    h = *head;
    while (h)
    {
        printf("%d\n", h->n);
        h = h->next;
    }
}

/**
 * f_swap - Function that swaps the top two elements of the stack
 * @head: Double pointer to the head of the stack
 * @counter: Line count
 *
 * Return: Nothing
 */
void f_swap(stack_t **head, unsigned int counter)
{
    stack_t *h;
    int length = 0, temp;

    h = *head;
    while (h)
    {
        h = h->next;
        length++;
    }
    if (length < 2)
    {
        fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }
    h = *head;
    temp = h->n;
    h->n = h->next->n;
    h->next->n = temp;
}

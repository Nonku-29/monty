#include "monty.h"

/**
 * f_queue - Function that sets the stack mode to queue (FIFO)
 * @head: Double pointer to the head of the stack
 * @counter: Line count
 *
 * Return: Nothing
 */
void f_queue(stack_t **head, unsigned int counter)
{
    (void)head;
    (void)counter;
    bus.lifi = 1;
}

/**
 * addqueue - Function that adds a node to the tail of the queue
 * @head: Double pointer to the head of the queue
 * @n: New value
 *
 * Return: Nothing
 */
void addqueue(stack_t **head, int n)
{
    stack_t *new_node, *temp;

    temp = *head;
    new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        printf("Error\n");
    }
    new_node->n = n;
    new_node->next = NULL;
    if (temp)
    {
        while (temp->next)
            temp = temp->next;
    }
    if (!temp)
    {
        *head = new_node;
        new_node->prev = NULL;
    }
    else
    {
        temp->next = new_node;
        new_node->prev = temp;
    }
}

#ifndef TADEM_H
#define TADEM_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - Doubly linked list representation of a stack or queue
 * @n: Integer value
 * @prev: Pointer to the previous element in the stack or queue
 * @next: Pointer to the next element in the stack or queue
 *
 * Description: This structure defines a node in a doubly linked list,
 * which can be used to implement a stack (LIFO) or a queue (FIFO).
 */
typedef struct stack_s
{
    int n;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;


/**
 * struct instruction_s - Opcode and its corresponding function
 * @opcode: The opcode
 * @f: The function that handles the opcode
 *
 * Description: This structure defines an opcode and its corresponding function,
 * which can be used for stack, queue, LIFO, and FIFO operations.
 */
typedef struct instruction_s
{
    char *opcode;
    void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


/**
 * struct bus_s - Variables for carrying values through the program
 * @arg: Value
 * @file: Pointer to the monty file
 * @line: Line content
 * @lifo: Flag to change between stack and queue behavior
 *
 * Description: This structure defines variables used to carry values
 * through the program. It includes the value itself (arg), a pointer to
 * the monty file (file), the content of the current line (line), and a
 * flag (lifo) that can be used to switch between stack and queue behavior.
 */

typedef struct bus_s
{
    char *arg;
    FILE *file;
    char *content;
    int lifi;
} bus_t;

extern bus_t bus;

char *_realloc(char *ptr, unsigned int old_size, unsigned int new_size);
ssize_t getstdin(char **lineptr, int file);
char *clean_line(char *content);
void f_push(stack_t **head, unsigned int number);
void f_pall(stack_t **head, unsigned int number);
void f_pint(stack_t **head, unsigned int number);
int execute(char *content, stack_t **head, unsigned int counter, FILE *file);
void free_stack(stack_t *head);
void f_pop(stack_t **head, unsigned int counter);
void f_swap(stack_t **head, unsigned int counter);
void f_add(stack_t **head, unsigned int counter);
void f_nop(stack_t **head, unsigned int counter);
void f_sub(stack_t **head, unsigned int counter);
void f_div(stack_t **head, unsigned int counter);
void f_mul(stack_t **head, unsigned int counter);
void f_mod(stack_t **head, unsigned int counter);
void f_pchar(stack_t **head, unsigned int counter);
void f_pstr(stack_t **head, unsigned int counter);
void f_rotl(stack_t **head, unsigned int counter);
void f_rotr(stack_t **head, __attribute__((unused)) unsigned int counter);
void addnode(stack_t **head, int n);
void addqueue(stack_t **head, int n);
void f_queue(stack_t **head, unsigned int counter);
void f_stack(stack_t **head, unsigned int counter);

#endif

#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <ctype.h>

typedef struct argument_s
{
    int argument;
    int flag;
} argument_t;

extern argument_t argument;

typedef struct stack_s
{
    int value;
    struct stack_s *previous;
    struct stack_s *next;
} stack_t;

typedef struct instruction_s
{
    char *opcode;
    void (*function)(stack_t **stack, unsigned int line_number);
} instruction_t;

typedef struct line_s
{
    unsigned int number;
    char **content;
} line_t;

typedef struct metadata_s
{
    char *buffer;
    stack_t *stack;
    FILE *file;
} metadata_t;

void (*getOperationFunction(line_t line, metadata_t *metadata))(stack_t **stack, unsigned int);
int isAlphabetic(int c);

void parseFile(FILE *file);
void parseLine(line_t *line, char *buffer);

bool isComment(line_t line);
void checkPush(line_t line, metadata_t *metadata, char *opcode);

void push(stack_t **stack, unsigned int lineNumber);
void printAll(stack_t **stack, unsigned int lineNumber);
void printTop(stack_t **stack, unsigned int lineNumber);
void pop(stack_t **stack, unsigned int lineNumber);
void swap(stack_t **stack, unsigned int lineNumber);
void noOperation(stack_t **stack, unsigned int lineNumber);
void rotateLeft(stack_t **stack, unsigned int lineNumber);
void rotateLeftOnce(stack_t **stack, unsigned int lineNumber);
void rotateRightOnce(stack_t **stack, unsigned int lineNumber);
void printChar(stack_t **stack, unsigned int lineNumber);
void printString(stack_t **stack, unsigned int lineNumber);
void freeStack(stack_t **stack);
void noOperation(stack_t **stack, unsigned int lineNumber);
void queuePush(stack_t **stack, unsigned int lineNumber);
void switchToQueue(stack_t **stack, unsigned int lineNumber);
void switchToStack(stack_t **stack, unsigned int lineNumber);

void subtract(stack_t **stack, unsigned int lineNumber);
void add(stack_t **stack, unsigned int lineNumber);
void divide(stack_t **stack, unsigned int lineNumber);
void multiply(stack_t **stack, unsigned int lineNumber);
void modulo(stack_t **stack, unsigned int lineNumber);

#endif /* MONTY_H */

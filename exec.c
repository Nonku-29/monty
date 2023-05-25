#include "monty.h"

/**
 * process_opcode - Executes the opcode operation.
 * @opcode: The opcode to be executed.
 * @stack: Pointer to the head of the stack.
 * @line_number: The current line number.
 * @file: Pointer to the monty file stream.
 *
 * Return: 0 if successful, 1 otherwise.
 */
int process_opcode(char *opcode, stack_t **stack, unsigned int line_number, FILE *file)
{
	instruction_t opcodes[] = {
		{"push", opcode_push}, {"pall", opcode_pall}, {"pint", opcode_pint},
		{"pop", opcode_pop}, {"swap", opcode_swap}, {"add", opcode_add},
		{"nop", opcode_nop}, {"sub", opcode_sub}, {"div", opcode_div},
		{"mul", opcode_mul}, {"mod", opcode_mod}, {"pchar", opcode_pchar},
		{"pstr", opcode_pstr}, {"rotl", opcode_rotl}, {"rotr", opcode_rotr},
		{"queue", opcode_queue}, {"stack", opcode_stack},
		{NULL, NULL}
	};
	unsigned int i = 0;
	char *argument;

	argument = strtok(NULL, " \n\t");
	while (opcodes[i].opcode && opcode)
	{
		if (strcmp(opcode, opcodes[i].opcode) == 0)
		{
			opcodes[i].f(stack, line_number);
			return 0;
		}
		i++;
	}
	if (opcode && opcodes[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
		fclose(file);
		free_opcode(opcode);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	return 1;
}

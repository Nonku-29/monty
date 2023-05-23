#include "monty.h"

/**
 * main - opens a Monty script file for parsing
 * @argc: count of arguments
 * @argv: array of arguments
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */
int main(int argc, char *argv[])
{
    FILE *scriptFile;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    scriptFile = fopen(argv[1], "r");
    if (!scriptFile)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    parseScript(scriptFile);
    return (EXIT_SUCCESS);
}

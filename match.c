#include "monty.h"

/**
 * findOperation - searches for a matching opcode and returns the corresponding function
 * @line: struct containing line contents and line number
 * @meta: struct containing all allocated memory
 *
 * Return: pointer to the matching function
 */
void (*findOperation(line_t line, meta_t *meta))(stack_t **, unsigned int)
{
    unsigned int i = 0;
    instruction_t operations[] = {
        {"push", pushFunc},
        {"pall", printAll},
        {"pint", printTop},
        {"pop", popFunc},
        {"swap", swapFunc},
        {"add", addFunc},
        {"sub", subFunc},
        {"div", divFunc},
        {"mul", mulFunc},
        {"mod", modFunc},
        {"nop", nopFunc},
        {"pchar", pcharFunc},
        {"pstr", pstrFunc},
        {"rotl", rotlFunc},
        {"rotr", rotrFunc},
        {"stack", stackMode},
        {"queue", queueMode},
        {NULL, NULL}
    };

    if (checkForComment(line))
        return (nopFunc);

    while (operations[i].opcode)
    {
        if (strcmp(operations[i].opcode, line.content[0]) == 0)
        {
            checkForPush(line, meta, operations[i].opcode);
            if (arg.flag == 1 && strcmp(operations[i].opcode, "push") == 0)
            {
                if (line.content)
                    free(line.content);
                return (queuePush);
            }
            free(line.content);
            return (operations[i].f);
        }

        i++;
    }

    fprintf(stderr, "L%d: unknown instruction %s\n", line.number, line.content[0]);
    free(line.content);
    free(meta->buf);
    freeStack(&(meta->stack));
    fclose(meta->file);
    free(meta);
    exit(EXIT_FAILURE);
}

#include "monty.h"

/** QUESTION
on ta monty

**/
int main(int argc, char *argv[])
{
    void (*cp_get_op_code)(stack_t * *stack, unsigned int line);
    FILE *fp = NULL;
    char *c = NULL;
    unsigned int line = 1;
    size_t sizeC = 0;
    stack_t *stackMonty = NULL;
    stackMonty = NULL;


    if (argc != 2)
    {
        printf("USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }
    fp = fopen(argv[1], "r");
    while ((int)getline(&c, &sizeC, fp) != -1)
    {
        cp_get_op_code = (*get_op_code)(c);
        if (cp_get_op_code)
        {
            (*cp_get_op_code)(&stackMonty, line);
        }
        

        line++;
    }
    free(c);
    fclose(fp);

    return (0);
}
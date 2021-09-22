#include "monty.h"
#include <stdio.h>

/**
 * get_op_code - functi to select operations
 * Return: int
 */
void (*get_op_code())(stack_t **stack, unsigned int line)
{
	int i = 0, j = 0, k = 0;
	int val = 0;
	int tok = 0;
	char *tokenize[1024];
	instruction_t opCodes[] = {
		{"push", op_push},
		{"pall", op_pall},
		{"pop", op_pop},
		{"pint", op_pint},
		{"swap", op_swap},
		{"add", op_add},
		{"sub", op_sub},
		{"div", op_div},
		{"mul", op_mul},
		{"mod", op_mod},
		{"pchar", op_pchar},
		{"pstr", op_pstr},
		{NULL, NULL}};

	tokenize_line(dataStruct.lineTokenized, tokenize);

	while (i < 12)
	{
		j = 0;
		while (tokenize[j])
		{
			if (tokenize[j + 1])
			{
				while (tokenize[j + 1][k])
				{
					if ((tokenize[j + 1][k] < 48 || tokenize[j + 1][k] > 57)
					&& tokenize[j + 1][k] != 45)
					{
						printf("ENTRO");
						tok = 1;
						break;
					}
					k++;
				}
			}
			if (strcmp(opCodes[i].opcode, tokenize[j]) == 0)
			{
				if (tokenize[j + 1] && !tok)
				{
					val = atoi(tokenize[j + 1]);
					dataStruct.dataToSave = val;
				}
				else
				{
					dataStruct.valDataToSave = 1;
				}
				tok = 0;
				return (opCodes[i].f);
			}
			j++;
		}
		i++;
	}

	return (NULL);
}

/**
 * tokenize_line - get a line and save info to validate
 * @line: character to validate symbol
 * @tokenize: pointer array to save tokenized line
 * Return: void
 */
void tokenize_line(char *line, char **tokenize)
{
	int i = 0;

	tokenize[i] = strtok(line, " ");
	i++;
	while (line != NULL)
	{
		line = strtok(NULL, " ");
		tokenize[i] = line;
		i++;
	}
}

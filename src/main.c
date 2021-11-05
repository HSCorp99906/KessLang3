#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../include/Token.h"
#include "../include/Lexer.h"
#include "../include/Parser.h"
#include "../include/Executer.h"


unsigned int lineNum = 0;


int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Too little arguments.\n");
        return 1;
    }

    FILE* fp = fopen(argv[1], "r");

    char lineBuffer[500];
    struct Instruction* instructions = calloc(35, sizeof(struct Instruction));
    size_t instructionlist_size = 35;

    unsigned short int error = 0;

    while (fgets(lineBuffer, 500, fp)) {
        ++lineNum;
        struct _Token* tokens = tokenize(lineBuffer, lineNum);
        instructions[lineNum - 1] = parse(tokens, lineNum);

        if (!(instructions[lineNum - 1].approved)) {
            error = 1;
        }

        if (lineNum -1 >= instructionlist_size - 4) {
            instructions = realloc(instructions, instructionlist_size += 10);
            printf("Instructions re-allocated to a size of %d", instructionlist_size);
        }

        free(tokens);
    }

    instructions[lineNum].type = _EOF;

    if (!(error)) {
        execute(instructions);
    }

    fclose(fp);
    free(instructions);
}

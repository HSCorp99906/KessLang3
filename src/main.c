#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../include/Token.h"
#include "../include/Lexer.h"
#include "../include/Parser.h"


unsigned int lineNum = 0;


int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Too little arguments.\n");
        return 1;
    }

    FILE* fp = fopen(argv[1], "r");

    char lineBuffer[500];
    struct Instruction* instructions = calloc(5, sizeof(struct Instruction));

    while (fgets(lineBuffer, 500, fp)) {
        ++lineNum;
        struct _Token* tokens = tokenize(lineBuffer, lineNum);
        instructions[lineNum - 1] = parse(tokens, lineNum);

        if (!(instructions[lineNum - 1].approved)) {
            free(instructions);
            free(tokens);
            fclose(fp);
            return 1;
        }

        free(tokens);
    }

    fclose(fp);
    free(instructions);

    printf("Instructions de-allocated from memory\n");
}

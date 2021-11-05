#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../include/Token.h"
#include "../include/Lexer.h"

unsigned int lineNum = 0;


int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Too little arguments.\n");
        return 1;
    }

    FILE* fp = fopen(argv[1], "r");

    char lineBuffer[500];

    while (fgets(lineBuffer, 490, fp)) {
        ++lineNum;
        printf("Allocated memory for tokens on heap.\n");
        struct _Token* tokens = tokenize(lineBuffer, lineNum);

        for (int i = 0; i < sizeof(tokens); ++i) {
            printf("%c\n", tokens[i].character);
        }

        free(tokens);
        printf("De-allocated tokens.\n");
    }

    fclose(fp);
}

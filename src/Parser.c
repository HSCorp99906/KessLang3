#include "../include/Parser.h"


struct Instruction parse(struct _Token* tokenliststream, unsigned int lineNum) {
    typedef short unsigned int bool_t;
    struct Instruction retInstruction;
    char reconstructed[500];

    bool_t end_statement_reached = 0;
    bool_t out_identifer_match = 0;

    char value[1024];

    unsigned int lparenCount = 0;
    unsigned int rparenCount = 0;

    retInstruction.approved = 1;

    for (int i = 0; tokenliststream[i].character != '\0'; ++i) {
        if (tokenliststream[i].character == ';') {
            end_statement_reached = 1;
        } else if (tokenliststream[i].character == '(') {
            ++lparenCount;
        } else if (tokenliststream[i].character == ')') {
            ++rparenCount;
        }

        if (tokenliststream[i].type == T_IDENTIFIER && tokenliststream[i].builtInCall == OUT) {
            out_identifer_match = 1;
            unsigned int index = 0;
            for (int j = i + 4; tokenliststream[j].character != '"' && tokenliststream[j].character != '\0'; ++j) {
                switch (tokenliststream[j].character) {
                    case 'a':
                    case 'b':
                    case 'c':
                    case 'd':
                    case 'e':
                    case 'f':
                    case 'g':
                    case 'h':
                    case 'i':
                    case 'j':
                    case 'k':
                    case 'l':
                    case 'm':
                    case 'n':
                    case 'o':
                    case 'p':
                    case 'q':
                    case 'r':
                    case 's':
                    case 't':
                    case 'u':
                    case 'v':
                    case 'x':
                    case 'y':
                    case 'z':
                    case 'A':
                    case 'B':
                    case 'C':
                    case 'D':
                    case 'E':
                    case 'F':
                    case 'G':
                    case 'H':
                    case 'I':
                    case 'J':
                    case 'K':
                    case 'L':
                    case 'M':
                    case 'N':
                    case 'O':
                    case 'P':
                    case 'Q':
                    case 'R':
                    case 'S':
                    case 'T':
                    case 'U':
                    case 'V':
                    case 'X':
                    case 'Y':
                    case 'Z':
                    case '1':
                    case '2':
                    case '3':
                    case '4':
                    case '5':
                    case '6':
                    case '7':
                    case ' ':
                    case '8':
                    case '9':
                    case '.':
                    case '!':
                    case '@':
                    case '$':
                    case '%':
                    case '^':
                    case '&':
                    case ',':
                    case '?':
                        value[index] = tokenliststream[j].character;
                }

                ++index;
            }
        }
    }

    if (out_identifer_match) {
        strcpy(retInstruction.value, value);
        retInstruction.type = BUILT_IN_CALL;
        retInstruction.type1 = OUTPUT;
    }

    if (!(end_statement_reached)) {
        printf("ERROR: Missing semicolon on line %d\n", lineNum);
        retInstruction.approved = 0;
    } else if (lparenCount != rparenCount) {
        printf("ERROR: Unmatched parenthesis on line %d", lineNum);
        retInstruction.approved = 0;
    }

    return retInstruction;


}

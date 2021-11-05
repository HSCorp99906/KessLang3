#include "../include/Parser.h"


struct Instruction parse(struct _Token* tokenliststream, unsigned int lineNum) {
    typedef short unsigned int bool_t;
    struct Instruction retInstruction;
    char reconstructed[500];

    bool_t end_statement_reached = 0;
    bool_t awaitingValue = 0;
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

#ifndef KESS_PARSER_H_
#define KESS_PARSER_H_

#include "Token.h"

#include <stdio.h>
#include <string.h>


enum InstructionTypes {
    BUILT_IN_CALL,
    OUTPUT
};


struct Instruction {
    int type;
    int type1;
    char value[1024];
    unsigned short int approved;
};


struct Instruction parse(struct _Token* tokenstream, unsigned int lineNum);


#endif // KESS_PARSER_H_

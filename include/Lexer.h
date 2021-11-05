#ifndef KESS_LEXER_H_
#define KESS_LEXER_H_

#include "Token.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


struct TokenListInitData {
    struct _Token* tokenlist;
    size_t size;
};


void tokenize(char line[], unsigned int lineNum, struct Token** tokenlist);


#endif  // KESS_LEXER_H_

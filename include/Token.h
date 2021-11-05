#ifndef KESS_TOKEN_H_
#define KESS_TOKEN_H_


enum TokenType {
    T_CHAR,
    T_LPAREN,
    T_RPAREN,
    T_QUOTE,
    T_END_STATEMENT,
    T_INTEGER,
    T_IDENTIFIER,
    T_SPECIAL_CHAR,
    T_SPACE,
    T_UNLISTED
};


enum BuiltInCalls {
    OUT,
};


struct _Token {
    char character;
    int type;
    int builtInCall;
    char* line;
    unsigned int lineNum;
};


#endif  // KESS_TOKEN_H_

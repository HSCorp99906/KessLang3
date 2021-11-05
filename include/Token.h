#ifndef KESS_TOKEN_H_
#define KESS_TOKEN_H_


enum TokenType {
    T_CHAR,
    T_LPAREN,
    T_RPAREN,
    T_QUOTE,
    T_END_STATEMENT,
    T_INTEGER
};


struct _Token {
    char character;
    int type;
    char* line;
    unsigned int lineNum;
};


#endif  // KESS_TOKEN_H_

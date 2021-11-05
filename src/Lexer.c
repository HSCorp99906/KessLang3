#include "../include/Lexer.h"

struct _Token* tokenize(char line[], unsigned int lineNum) {
    struct _Token* tokenlist = calloc(24, sizeof(struct _Token));

    size_t tokenlist_size = 24;
    unsigned int index = 0;

    for (int i = 0; i < strlen(line); ++i) {
        if (i >= tokenlist_size - 5) {
            tokenlist = (struct _Token*)realloc(tokenlist, tokenlist_size += 5);
        }

        switch (line[i]) {
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                tokenlist[index].character = line[i];
                tokenlist[index].type = T_INTEGER;
                tokenlist[index].lineNum = lineNum;
                ++index;
                break;
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
                tokenlist[index].character = line[i];
                tokenlist[index].type = T_CHAR;
                tokenlist[index].lineNum = lineNum;
                ++index;
                break;
            case '(':
                tokenlist[index].character = line[i];
                tokenlist[index].type = T_LPAREN;
                tokenlist[index].lineNum = lineNum;
                ++index;
                break;
            case ')':
                tokenlist[index].character = line[i];
                tokenlist[index].type = T_RPAREN;
                tokenlist[index].lineNum = lineNum;
                ++index;
                break;
            case '"':
                tokenlist[index].character = line[i];
                tokenlist[index].type = T_QUOTE;
                tokenlist[index].lineNum = lineNum;
                ++index;
                break;
            case ';':
                tokenlist[index].character = line[i];
                tokenlist[index].type = T_END_STATEMENT;
                tokenlist[index].lineNum = lineNum;
                ++index;
                break;
        }
    }

    tokenlist[index + 1].character = '\0';

    return tokenlist;
}
